//CWJ15DEC2024
#pragma once


namespace Hephaestus
{

	//forward declare FunctorImpl
	template <typename R, class TList>
	class FunctorImpl;

	//FunctorHandler is used to assist with the copy constructor of Functor, allowing for one functor to be copied from another
	//It is quite a bit like functor, but stores the request by value instead of a pointer
	template <class ParentFunctor, typename Fun>
	class FunctorHandler : public FunctorImpl<typename ParentFunctor::ResultType, typename ParentFunctor::ParmList>
	{
	public:
		using ResultType = typename ParentFunctor::ResultType;

		FunctorHandler() = delete; //Must have an implmentation to have a FunctorHandler object

		//~FunctorHandler(), default is okay so long as base has been marked virtual
		FunctorHandler(const Fun& fun) : fun_(fun) { ; } //Andrei's original copy constructor //TODO using the below gives a compiler error 
		//FunctorHandler(const Fun& fun) :fun_(fun.clone()) { ; } //new copy constructor, use the clone() function of the implmentation functor
		FunctorHandler& operator=(Fun& other) //copy assignment operator
		{
			fun_ = other.fun_.clone();
			return(this);
		}
		FunctorHandler(Fun&& fun) : fun_(std::move(fun)) { ; } //move constructor
		FunctorHandler& operator=(Fun&& other)//move assignment operator
		{
			fun_ = std::move(other.fun_); //take ownership of the other's implementation 
			return(this);
		}

		//need to define a clone function since we inherit from FunctorImpl
		std::unique_ptr<FunctorImpl<typename ParentFunctor::ResultType, typename ParentFunctor::ParmList>> clone() const override
		{
			return std::make_unique<FunctorHandler>(*this);
		}


		//same trick as functor, define all possible versions but compiler will only instantiate those which are used
		ResultType operator()()
		{
			return fun_();
		}
		ResultType operator()(typename ParentFunctor::Parm1 p1)
		{
			return fun_(p1);
		}
		ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2)
		{
			return fun_(p1, p2);
		}
		ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2, typename ParentFunctor::Parm3 p3)
		{
			return fun_(p1, p2, p3);
		}
		ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2, typename ParentFunctor::Parm3 p3, typename ParentFunctor::Parm4 p4)
		{
			return fun_(p1, p2, p3, p4);
		}
		ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2, typename ParentFunctor::Parm3 p3, typename ParentFunctor::Parm4 p4, typename ParentFunctor::Parm5 p5)
		{
			return fun_(p1, p2, p3, p4, p5);
		}
		ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2, typename ParentFunctor::Parm3 p3, typename ParentFunctor::Parm4 p4, typename ParentFunctor::Parm5 p5
			, typename ParentFunctor::Parm6 p6)
		{
			return fun_(p1, p2, p3, p4, p5, p6);
		}
		ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2, typename ParentFunctor::Parm3 p3, typename ParentFunctor::Parm4 p4, typename ParentFunctor::Parm5 p5
			, typename ParentFunctor::Parm6 p6, typename ParentFunctor::Parm7 p7)
		{
			return fun_(p1, p2, p3, p4, p5, p6, p7);
		}
		ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2, typename ParentFunctor::Parm3 p3, typename ParentFunctor::Parm4 p4, typename ParentFunctor::Parm5 p5
			, typename ParentFunctor::Parm6 p6, typename ParentFunctor::Parm7 p7, typename ParentFunctor::Parm8 p8)
		{
			return fun_(p1, p2, p3, p4, p5, p6, p7, p8);
		}
		ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2, typename ParentFunctor::Parm3 p3, typename ParentFunctor::Parm4 p4, typename ParentFunctor::Parm5 p5
			, typename ParentFunctor::Parm6 p6, typename ParentFunctor::Parm7 p7, typename ParentFunctor::Parm8 p8, typename ParentFunctor::Parm9 p9)
		{
			return fun_(p1, p2, p3, p4, p5, p6, p7, p8, p9);
		}
		ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2, typename ParentFunctor::Parm3 p3, typename ParentFunctor::Parm4 p4, typename ParentFunctor::Parm5 p5
			, typename ParentFunctor::Parm6 p6, typename ParentFunctor::Parm7 p7, typename ParentFunctor::Parm8 p8, typename ParentFunctor::Parm9 p9, typename ParentFunctor::Parm10 p10)
		{
			return fun_(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);
		}
		ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2, typename ParentFunctor::Parm3 p3, typename ParentFunctor::Parm4 p4, typename ParentFunctor::Parm5 p5
			, typename ParentFunctor::Parm6 p6, typename ParentFunctor::Parm7 p7, typename ParentFunctor::Parm8 p8, typename ParentFunctor::Parm9 p9, typename ParentFunctor::Parm10 p10
			, typename ParentFunctor::Parm11 p11)
		{
			return fun_(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);
		}
		ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2, typename ParentFunctor::Parm3 p3, typename ParentFunctor::Parm4 p4, typename ParentFunctor::Parm5 p5
			, typename ParentFunctor::Parm6 p6, typename ParentFunctor::Parm7 p7, typename ParentFunctor::Parm8 p8, typename ParentFunctor::Parm9 p9, typename ParentFunctor::Parm10 p10
			, typename ParentFunctor::Parm11 p11, typename ParentFunctor::Parm12 p12)
		{
			return fun_(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
		}
		ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2, typename ParentFunctor::Parm3 p3, typename ParentFunctor::Parm4 p4, typename ParentFunctor::Parm5 p5
			, typename ParentFunctor::Parm6 p6, typename ParentFunctor::Parm7 p7, typename ParentFunctor::Parm8 p8, typename ParentFunctor::Parm9 p9, typename ParentFunctor::Parm10 p10
			, typename ParentFunctor::Parm11 p11, typename ParentFunctor::Parm12 p12, typename ParentFunctor::Parm13 p13)
		{
			return fun_(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13);
		}
	private:
		Fun fun_;

	};


} //namespace Hephaestus 