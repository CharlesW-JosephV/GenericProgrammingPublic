#pragma once


//Binder First
//Takes a functor with N arguments, and returns a functor with N-1 arguments, with the first (Head) having been bound to a given value 
//This allows for storing a portion of the call environment directly inside the functor

namespace Hephaestus
{
	template <class Incoming>
	class BinderFirst : public FunctorImpl<typename Incoming::ResultType, typename Incoming::ParmList::Tail>
	{
		using Outgoing = Functor<typename Incoming::ResultType, typename Incoming::ParmList::Tail>;
		using ResultType = typename Incoming::ResultType;
		using Bound = typename Incoming::Parm1;

	public:
		BinderFirst() = delete; //must have a functor and value to construct 

		//typical constructor provides a functor and the value the first argument should be bound to
		BinderFirst(const Incoming& fun, Bound& bound) : fun_(fun), bound_(bound) {}
		//copy constructor
		BinderFirst(const BinderFirst& other) : bound_(other.bound_), fun_(other.fun_) { ; }
		//BinderFirst(const BinderFirst& other) : bound_(other.bound_)//copy constructor
		//{
			//fun_ = other.fun_.clone(); 
		//}
		BinderFirst& operator=(BinderFirst& other)
		{
			bound_ = other.bound_;
			fun_ = other.fun_.clone();
			return(this);
		}
		BinderFirst(BinderFirst&& other) // move constructor
		{
			fun_ = std::move(other.fun_);
			bound_ = std::move(other.bound_);
		}
		BinderFirst& operator=(BinderFirst&& other) //move assignment operator
		{
			fun_ = std::move(other.fun_);
			bound_ = std::move(other.bound_);
			return(this);
		}

		//need to define a clone function since we inherit from FunctorImpl
		std::unique_ptr < FunctorImpl<typename Incoming::ResultType, typename Incoming::ParmList::Tail>> clone() const override
		{
			return std::make_unique<BinderFirst>(*this);
		}

		//forward calls to functor implementation using the bound argument
		ResultType operator()()
		{
			return(fun_(bound_));
		}
		ResultType operator()(typename Outgoing::Parm1 p1)
		{
			return(fun_(bound_, p1));
		}
		ResultType operator()(typename Outgoing::Parm1 p1, typename Outgoing::Parm2 p2)
		{
			return(fun_(bound_, p1, p2));
		}
		ResultType operator()(typename Outgoing::Parm1 p1, typename Outgoing::Parm2 p2, typename Outgoing::Parm3 p3)
		{
			return(fun_(bound_, p1, p2, p3));
		}
		ResultType operator()(typename Outgoing::Parm1 p1, typename Outgoing::Parm2 p2, typename Outgoing::Parm3 p3, typename Outgoing::Parm4 p4)
		{
			return(fun_(bound_, p1, p2, p3, p4));
		}
		ResultType operator()(typename Outgoing::Parm1 p1, typename Outgoing::Parm2 p2, typename Outgoing::Parm3 p3, typename Outgoing::Parm4 p4, typename Outgoing::Parm5 p5)
		{
			return(fun_(bound_, p1, p2, p3, p4, p5));
		}
		ResultType operator()(typename Outgoing::Parm1 p1, typename Outgoing::Parm2 p2, typename Outgoing::Parm3 p3, typename Outgoing::Parm4 p4, typename Outgoing::Parm5 p5, typename Outgoing::Parm6 p6)
		{
			return(fun_(bound_, p1, p2, p3, p4, p5, p6));
		}
		ResultType operator()(typename Outgoing::Parm1 p1, typename Outgoing::Parm2 p2, typename Outgoing::Parm3 p3, typename Outgoing::Parm4 p4, typename Outgoing::Parm5 p5, typename Outgoing::Parm6 p6, typename Outgoing::Parm7 p7)
		{
			return(fun_(bound_, p1, p2, p3, p4, p5, p6, p7));
		}
		ResultType operator()(typename Outgoing::Parm1 p1, typename Outgoing::Parm2 p2, typename Outgoing::Parm3 p3, typename Outgoing::Parm4 p4, typename Outgoing::Parm5 p5, typename Outgoing::Parm6 p6, typename Outgoing::Parm7 p7,
			typename Outgoing::Parm8 p8)
		{
			return(fun_(bound_, p1, p2, p3, p4, p5, p6, p7, p8));
		}
		ResultType operator()(typename Outgoing::Parm1 p1, typename Outgoing::Parm2 p2, typename Outgoing::Parm3 p3, typename Outgoing::Parm4 p4, typename Outgoing::Parm5 p5, typename Outgoing::Parm6 p6, typename Outgoing::Parm7 p7,
			typename Outgoing::Parm8 p8, typename Outgoing::Parm9 p9)
		{
			return(fun_(bound_, p1, p2, p3, p4, p5, p6, p7, p8, p9));
		}
		ResultType operator()(typename Outgoing::Parm1 p1, typename Outgoing::Parm2 p2, typename Outgoing::Parm3 p3, typename Outgoing::Parm4 p4, typename Outgoing::Parm5 p5, typename Outgoing::Parm6 p6, typename Outgoing::Parm7 p7,
			typename Outgoing::Parm8 p8, typename Outgoing::Parm9 p9, typename Outgoing::Parm10 p10)
		{
			return(fun_(bound_, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10));
		}
		ResultType operator()(typename Outgoing::Parm1 p1, typename Outgoing::Parm2 p2, typename Outgoing::Parm3 p3, typename Outgoing::Parm4 p4, typename Outgoing::Parm5 p5, typename Outgoing::Parm6 p6, typename Outgoing::Parm7 p7,
			typename Outgoing::Parm8 p8, typename Outgoing::Parm9 p9, typename Outgoing::Parm10 p10, typename Outgoing::Parm11 p11)
		{
			return(fun_(bound_, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11));
		}
		ResultType operator()(typename Outgoing::Parm1 p1, typename Outgoing::Parm2 p2, typename Outgoing::Parm3 p3, typename Outgoing::Parm4 p4, typename Outgoing::Parm5 p5, typename Outgoing::Parm6 p6, typename Outgoing::Parm7 p7,
			typename Outgoing::Parm8 p8, typename Outgoing::Parm9 p9, typename Outgoing::Parm10 p10, typename Outgoing::Parm11 p11, typename Outgoing::Parm12 p12)
		{
			return(fun_(bound_, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12));
		}
		ResultType operator()(typename Outgoing::Parm1 p1, typename Outgoing::Parm2 p2, typename Outgoing::Parm3 p3, typename Outgoing::Parm4 p4, typename Outgoing::Parm5 p5, typename Outgoing::Parm6 p6, typename Outgoing::Parm7 p7,
			typename Outgoing::Parm8 p8, typename Outgoing::Parm9 p9, typename Outgoing::Parm10 p10, typename Outgoing::Parm11 p11, typename Outgoing::Parm12 p12, typename Outgoing::Parm13 p13)
		{
			return(fun_(bound_, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13));
		}

	private:
		Incoming fun_;
		Bound bound_;

	};

	//Bind First utility function
	template <class R, class TList>
	Functor<R, typename TList::Tail> BindFirst(const Functor<R, TList>& fun, typename TList::Head bound)
	{
		using Incoming = Functor<R, TList>;
		using Outgoing = Functor<R, typename TList::Tail>;

		return BinderFirst<Incoming>(fun, bound);
	}

}