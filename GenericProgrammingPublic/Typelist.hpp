//CWJ05OCT2024 
//Predominantly informed from Andrei Alexandrescu's wonderful work "Modern C++ Design"  
//First attempt at Typelists as a stepping block towards Functor
//This is a template based header only library
//When the user instantiates a template, the complier will generate the needed code for that instance
#pragma once

namespace Hephaestus //Greek god of the forge 
{

	class NullType; //declaration only, intentionally left outside of namespace TL. The idea is to force a compile error if something attempts to instantiate this class
	struct  EmptyType {}; //this is a valid type reflecting that it provides no type information 


	namespace TL
	{

		template <class T, class U>
		struct Typelist
		{
			//prefer alias declarations over typdef Scott Meyers item 9.
			using Head = T;
			using Tail = U;
		};

		//**************************************************************************************************************************************************************

		//Here we manually spell out lots of combos so that the user can avoid typing 
		//using T3nums2 = TL::Typelist<int,TL::Typelist<long, TL::Typelist<double, NullType>>>;
		//and instead use
		//using T3nums2 = TYPELIST_3(int, long, double); 
		//It's important to get the namespace right in the macro, and the macro code needs to go under the proper namespace
#define TYPELIST_1( T1) TL::Typelist<T1, NullType> 
#define TYPELIST_2( T1, T2) TL::Typelist<T1, TYPELIST_1(T2)> 
#define TYPELIST_3( T1, T2, T3) TL::Typelist<T1, TYPELIST_2(T2, T3)>
#define TYPELIST_4( T1, T2, T3, T4) TL::Typelist<T1, TYPELIST_3(T2, T3, T4)>
#define TYPELIST_5( T1, T2, T3, T4, T5) TL::Typelist<T1, TYPELIST_4(T2, T3, T4, T5)>
#define TYPELIST_6( T1, T2, T3, T4, T5, T6) TL::Typelist<T1, TYPELIST_5(T2, T3, T4, T5, T6)>
#define TYPELIST_7( T1, T2, T3, T4, T5, T6, T7) TL::Typelist<T1, TYPELIST_6(T2, T3, T4, T5, T6, T7)>
#define TYPELIST_8( T1, T2, T3, T4, T5, T6, T7, T8) TL::Typelist<T1, TYPELIST_7(T2, T3, T4, T5, T6, T7, T8)>
#define TYPELIST_9( T1, T2, T3, T4, T5, T6, T7, T8, T9) TL::Typelist<T1, TYPELIST_8(T2, T3, T4, T5, T6, T7, T8, T9)>
#define TYPELIST_10(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10) TL::Typelist<T1, TYPELIST_9(T2, T3, T4, T5, T6, T7, T8, T9, T10)>
#define TYPELIST_11(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11) TL::Typelist<T1, TYPELIST_10(T2, T3, T4, T5, T6, T7, T8, T9, T10, T11)>
#define TYPELIST_12(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12) TL::Typelist<T1, TYPELIST_11(T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12)>
#define TYPELIST_13(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13) TL::Typelist<T1, TYPELIST_12(T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13)>
//If you need more than 13 types you should be able to determine the pattern. You cannot have a space before the "(" in "TYPELIST_1(T1)"

//**************************************************************************************************************************************************************

//Now using Template Metaproraming (recursion and partial template specialization) to compute the length of a Typelist as a compile time constant
		template <class TList> struct Length; //This struct stores the length of the typelist in value

		//template specialization 1, end of the typelist 
		template <> struct Length<NullType> //this is a fully specalized template, can only match NullType
		{
			enum { value = 0 }; //TODO, see if I can replace unscoped with scoped enums
		};

		//template specalization 2, not the end of the typelist 
		template<class T, class U> //this is a partial specialization which can math any input types T and U, which allows U to be a compond typelist
		struct Length <Typelist<T, U>>
		{
			enum { value = 1 + Length<U>::value };
		};

		//**************************************************************************************************************************************************************

		//now allow index access via a struct "TypeAt" which returns the type at the given array position
		template <class TList, unsigned int index > struct TypeAt;
		//I'm stickign with typdefs since an out of access error will generate one compiler message with the amount of overshoot

		template <class Head, class Tail> //partial specialization
		struct TypeAt<Typelist<Head, Tail>, 0> //position 0 is defined as the first head
		{
			//using Result = Head; //I suppose "head" is the most outside part according to the above definition Typelist_3(int, long, double) would have head = int, tail = (long, double)
			typedef Head Result;
		};

		template <class Head, class Tail, unsigned int i> //more generic partial specialization
		struct TypeAt<Typelist<Head, Tail>, i>
		{
			//using Result = typename TypeAt<Tail, i - 1>::Result; //so this is working, but I'd like to avoid needing the typename. This is an alias declaration, but perhaps an alias template declaration is what is needed
			typedef typename TypeAt<Tail, i - 1>::Result Result;
		};

		//**************************************************************************************************************************************************************

		//same index acess but hopefully not strict so we can return a null type if we don't have a type there
		//TypeAtNotStrict<TList, index>::Result, returns the type at position index or NullType if out of bounds
		//TypeAtNotStrict<Tlist, index, D>::Result, returns the type at position index or type D if out of bounds
		template <class TList, unsigned int index, typename DefaultType = NullType> struct TypeAtNotStrict
		{
			typedef DefaultType Result; //if an out of access bounds occurs this will be returned instead
		};
		//I'm sticking with typdefs since an out of access error will generate one compiler message with the amount of overshoot

		//more flexible exit specialization from TypeAt. Eventually 
		template <class Head, class Tail, typename DefaultType> //partial specialization
		struct TypeAtNotStrict<Typelist<Head, Tail>, 0, DefaultType> //position 0 is defined as the first head
		{
			//using Result = Head; //I suppose "head" is the most outside part according to the above definition Typelist_3(int, long, double) would have head = int, tail = (long, double)
			typedef Head Result;
		};


		template <class Head, class Tail, unsigned int i, typename DefaultType> //more generic partial specialization
		struct TypeAtNotStrict<Typelist<Head, Tail>, i, DefaultType>
		{
			//using Result = typename TypeAt<Tail, i - 1>::Result; //so this is working, but I'd like to avoid needing the typename. This is an alias declaration, but perhaps an alias template declaration is what is needed
			typedef typename TypeAtNotStrict<Tail, i - 1, DefaultType>::Result Result;
		};


	} //namespace TL
} //namespace Hephaestus