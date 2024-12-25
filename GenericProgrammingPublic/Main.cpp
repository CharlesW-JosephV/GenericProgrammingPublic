//CWJ06OCT2024
//Developing a "Generic Programming" library predominantly informed from Andrei Alexandrescu's wonderful work "Modern C++ Design" 
//But also referencing Scott Meyer's works to approach more of a C++14 standard
//CWJ24DEC2024 - took a second pass at a full rewrite to understand what was causing the issues with bound. Found and corrected.

//CWJ libs
#include "Typelist.hpp"
#include "Functor.hpp"

//STD libs
#include <vector>
#include <iostream>


//Typelists perform template meta-programming to allow the application developer to easily specify a list of types for which the object needs to be constructed
//Typelist have been miniamlly implmented to meet the requirements of functor
//Functors follow the GoF "Command Pattern" which divorce the execution of a function object from the caller
//Functors also allow for binding of the arguments to the command, reducing the information that the caller needs to provide for each execution request

//define a test functor 
struct TestFunctor //can be a struct
{
	void operator()(int i, double d)
	{
		std::cout << "TestFunctor:operator()(" << i << "," << d << ") called." << std::endl;
	}
};

struct EmptyFunctor
{
	void operator()()
	{
		std::cout << "I am an empty functor with no arguments." << std::endl;
	}
};

struct OneArgFunctor
{
	void operator()(int i)
	{
		std::cout << "I have one argument : " << i << std::endl;
	}
};

void TestFunction(int i, double d) //can also be just a funciton
{
	std::cout << "TestFunction(" << i << ", " << d << ") called." << std::endl;
}

class CatDog
{
public:
	void Bark()
	{
		std::cout << "Woof woof!" << std::endl;
	}
	void Meow()
	{
		std::cout << "Meow." << std::endl;
	}
};

class CatDogwArgs
	//I'm not sure how to pass empty arguments yet. This is a poor workaround...
{
public:
	void Bark(int i)
	{
		std::cout << "Woof woof!" << std::endl;
	}
	void Meow(int i)
	{
		std::cout << "Meow." << std::endl;
	}
};

const char* TestConversionFunction(double, double)
{
	static const char buffer[] = "Hello World!";
	//according to Andrei Alexandrescu static buffers are safe to return a handel to
	return buffer;
}

const char* Fun(int i, int j)
{
	std::cout << "Fun(" << i << "," << j << ") called\n";
	return "0";
}

int main()
{

	using namespace Hephaestus; //Greek god of the forge gives us some nice template tools


	//*************************************************************************************
	//Typelists

	//Typelists live in the TL namespace
	//Using the older approach, they can be created via typedefs
	//typedef TL::Typelist<double, int> T2nums;
	//And chained together to create lists longer than two types
	//typedef TL::Typelist<long, TL::Typelist<double, int>> T3nums;

	//A more modern approach leverages alias declarations
	//using T2nums =  TL::Typelist<double, int>;
	//using T3nums = TL::Typelist<long, TL::Typelist<double, int>>;
	//However, if you want to perform template meta programming, you'll need to abide by the convention that the list terminates with "NullType" 
	//This allows for partial template specialization to detect the end of the typelist (as it will contain NullType)
	//And therefore we have a condition that allows for template metaprograming as we can use recursion and distinguish between the general case and the terminal case
	using TLOneOnly = TL::Typelist<double, NullType>;
	using TLNums = TL::Typelist<int, TL::Typelist<long, TL::Typelist<double, NullType>>>;

	std::cout << "The length of " << "TLOneOnly is " << TL::Length<TLOneOnly>::value << "\n"; //Length is a recursive template 
	std::cout << "The length of " << "TLNums is " << TL::Length<TLNums>::value << "\n";

	//It's a bit clunky to constantly access the TL namespace and pad the list with NUllType
	//the alternative is to use a MACRO to have the preprocessor write the code for you 
	//again you can use typedefs
	typedef TYPELIST_1(signed char) OneType;
	typedef TYPELIST_2(signed char, short int) TwoType;
	//or alias declarations
	using SignedIntegrals = TYPELIST_4(signed char, short int, int, long int);
	using T3nums = TYPELIST_3(int, long, double);

	//So what's the use of typelists?
	//TwoType instance; //typelists are not meant to be instantiated, but it does no harm

	std::vector<long> vec[TL::Length<T3nums>::value]; //make a vector with a position for each type in T3nums2

	//TL::TypeAt allows for the return of a type at a particular location in the typelist
	std::vector<TL::TypeAt<SignedIntegrals, 0>> test; //allows one to make a vector of an arbitrary type at a position within a typelist
	//std::vector<TL::TypeAt<SignedIntegrals, TL::Length<SignedIntegrals>::value +1>> test2; //TypeAt generates a compiler error if one attempts out of bound accesss. The error should report the magnitude of the violation
	//The above should generate C2027 "Use of undefined type 'Hephaestus::TL::TypeAt<Tail,1>'" where 1 is the amount of overshoot

	//TypeAtNotStrict allows for out of bounds requests to be converted to a default type specified as the third argument
	std::vector<TL::TypeAtNotStrict<SignedIntegrals, 7, int>> test3; //This works, 7 is too long so defaults to type int

	//*************************************************************************************
	//Functors

	//Functors allow for a nicer interface to manage call timing and arguments passed to functions and function objects

	//One usecase is for an alternative calling interface into a function in a structor
	OneArgFunctor fd; //instantiate the struct 
	Functor<void, TYPELIST_1(int)> myOneArgFunctor(fd); //make a functor which matches the struct return and args, initalize with the struct
	myOneArgFunctor(3); //call, should write to console 

	//Here is a similar proceedure for a functor with a different call signature
	TestFunctor f;
	Functor<void, TYPELIST_2(int, double)> cmd(f);
	cmd(4, 4.5);

	//If you'd like to assign a functor which takes zero arguments use the NullType instead of a Typelist

	//Okay, looks like there are some limitations when working with a function
	//According to Andrei Alexandrescu in Modern C++ Design I should just be able to pass in the funciton to the ctor
	// but MSVC thows up compiler error C2207
	//Looks like someone else stumbled across this with a microsoft compiler, and the community response was "it's illegal"
	//https://stackoverflow.com/questions/19958146/acquire-a-function-type-for-a-member-of-a-class-template
	//It is unclear if this is a compiler or langauge limit. I suspect it might be a compiler limitation
	//Functor<void, TYPELIST_2(int, double)> cmd1(TestFunction);
	//cmd1(4, 8.9);

	//Alternative 1) is to use a typedef and a pointer to the funciton
	typedef void (*TpFun)(int, double);
	TpFun pF = TestFunction;
	Functor<void, TYPELIST_2(int, double)> cmd1a(pF);
	cmd1a(4, 9.8);

	//Alternative 2) is to just pass the address of the function without constructing a temporary
	Functor<void, TYPELIST_2(int, double)> cmd1b(&TestFunction);
	cmd1b(2, 3.9);

	//Functors also support implicit type conversions
	Functor<std::string, TYPELIST_2(int, int)> cmds(&TestConversionFunction); //pass a (string, (int, int)) functor a (char* (double, double)) function 
	std::cout << cmds(5, 2).substr(8) << std::endl; //should print "rld!" 


	//Functor with pointer to member functions
	//First let us review how pointers to member functons work
	typedef void(CatDog::* TpMemFun)(); //type definiton for a pointer to a member function returning void and taking no args
	TpMemFun pVocalization = &CatDog::Bark; //create an object with the new typedef, initalize with the address of the CatDog::Bark member funciton
	CatDog catDog; //now create a catdog (my mom never let me watch that show, but I guess the name of the titular character is offically CatDog, we'll keep that as the class name and use catDog for the instance)
	CatDog* pcatDog = &catDog; //and a pointer to the catDog instance

	(catDog.*pVocalization)(); //call the bark function of our current instance
	//(pcatDog->*pVocalization)(); //can also be done using the pointer 
	pVocalization = &CatDog::Meow; //change the address to the other member function 
	(catDog.*pVocalization)(); //should meow now

	//let us now try with the Functor by leveraging MemFunHandler
	Functor<void, NullType> cmd_bark(&catDog, &CatDog::Bark), cmd_meow(&catDog, &CatDog::Meow);
	std::cout << "Now with a functor:\n";
	cmd_bark();
	cmd_meow();

	//now test out the assignemnet operator, overwrite the bark command with meow 
	cmd_bark = cmd_meow;
	std::cout << "Overwrote bark with meow, calling again: \n";
	cmd_bark(); //now will generate meow
	cmd_meow();

	//The most useful aspect is that particular arguments can be bound with a given value
	//So that less information is needed at call time to perform the work of the function 
	//Now let us test binding along with implicit type conversions
	Functor<const char*, TYPELIST_2(char, int)> f1(&Fun); //remember to pass as a function pointer!
	Functor<std::string, TYPELIST_1(double)> f2(BindFirst(f1, 9));
	std::cout << "Now calling a functor with the first argument bound\n";
	f2(12);

	return(0); //all is good 
}