//CWJ24DEC2025
//Functor support for pointer to member functions
#pragma once

namespace Hephaestus
{
	template <class ParentFunctor, typename PointerToObj, typename PointerToMemFn>
	class MemFunHandler : public FunctorImpl <typename ParentFunctor::ResultType, typename ParentFunctor::ParmList>
	{
	private:
		PointerToObj pObj_;
		PointerToMemFn pMemFn_;
	public:
		using ResultType = typename ParentFunctor::ResultType;

		MemFunHandler() = delete; //cannot have an empty implementation
		//typical constructor
		MemFunHandler(const PointerToObj& pObj, PointerToMemFn pMemFn) : pObj_(pObj), pMemFn_(pMemFn) { ; }
		//copy constructor
		MemFunHandler(const MemFunHandler& other) : pObj_(other.pObj_), pMemFn_(other.pMemFn_) { ; }
		//copy assignment operator
		MemFunHandler& operator=(MemFunHandler& other)
		{
			pObj_ = other.pObj_;
			pMemFn_ = other.pMemFn_;
			return(this);
		}
		//move constructor
		MemFunHandler(const MemFunHandler&& other) : pObj_(std::move(other.pObj_)), pMemFn_(std::move(other.pMemFn_)) { ; }
		//move assignment operator
		MemFunHandler& operator=(MemFunHandler&& other)
		{
			pObj_ = std::move(other.pObj_);
			pMemFn_ = std::move(other.pMemFn_);
			return(this);
		}
		//need to define a clone function since we inherit from FunctorImpl
		std::unique_ptr<FunctorImpl<typename ParentFunctor::ResultType, typename ParentFunctor::ParmList>> clone() const override
		{
			return std::make_unique <MemFunHandler>(*this);
		}


		//again using the trick of defining all possible operator()()'s and letting the compiler limit to only the valid calls 
		ResultType operator()()
		{
			return((*pObj_).*pMemFn_)();
		}
		ResultType operator()(typename ParentFunctor::Parm1 p1)
		{
			return((*pObj_).*pMemFn_)(p1);
		}
		ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2)
		{
			return((*pObj_).*pMemFn_)(p1, p2);
		}
		ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2, typename ParentFunctor::Parm3 p3)
		{
			return((*pObj_).*pMemFn_)(p1, p2, p3);
		}
		ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2, typename ParentFunctor::Parm3 p3, typename ParentFunctor::Parm4 p4)
		{
			return((*pObj_).*pMemFn_)(p1, p2, p3, p4);
		}
		ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2, typename ParentFunctor::Parm3 p3, typename ParentFunctor::Parm4 p4, typename ParentFunctor::Parm5 p5)
		{
			return((*pObj_).*pMemFn_)(p1, p2, p3, p4, p5);
		}
		ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2, typename ParentFunctor::Parm3 p3, typename ParentFunctor::Parm4 p4, typename ParentFunctor::Parm5 p5, typename ParentFunctor::Parm6 p6)
		{
			return((*pObj_).*pMemFn_)(p1, p2, p3, p4, p5, p6);
		}
		ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2, typename ParentFunctor::Parm3 p3, typename ParentFunctor::Parm4 p4, typename ParentFunctor::Parm5 p5, typename ParentFunctor::Parm6 p6,
			typename ParentFunctor::Parm7 p7)
		{
			return((*pObj_).*pMemFn_)(p1, p2, p3, p4, p5, p6, p7);
		}
		ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2, typename ParentFunctor::Parm3 p3, typename ParentFunctor::Parm4 p4, typename ParentFunctor::Parm5 p5, typename ParentFunctor::Parm6 p6,
			typename ParentFunctor::Parm7 p7, typename ParentFunctor::Parm8 p8)
		{
			return((*pObj_).*pMemFn_)(p1, p2, p3, p4, p5, p6, p7, p8);
		}
		ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2, typename ParentFunctor::Parm3 p3, typename ParentFunctor::Parm4 p4, typename ParentFunctor::Parm5 p5, typename ParentFunctor::Parm6 p6,
			typename ParentFunctor::Parm7 p7, typename ParentFunctor::Parm8 p8, typename ParentFunctor::Parm9 p9)
		{
			return((*pObj_).*pMemFn_)(p1, p2, p3, p4, p5, p6, p7, p8, p9);
		}
		ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2, typename ParentFunctor::Parm3 p3, typename ParentFunctor::Parm4 p4, typename ParentFunctor::Parm5 p5, typename ParentFunctor::Parm6 p6,
			typename ParentFunctor::Parm7 p7, typename ParentFunctor::Parm8 p8, typename ParentFunctor::Parm9 p9, typename ParentFunctor::Parm10 p10)
		{
			return((*pObj_).*pMemFn_)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);
		}
		ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2, typename ParentFunctor::Parm3 p3, typename ParentFunctor::Parm4 p4, typename ParentFunctor::Parm5 p5, typename ParentFunctor::Parm6 p6,
			typename ParentFunctor::Parm7 p7, typename ParentFunctor::Parm8 p8, typename ParentFunctor::Parm9 p9, typename ParentFunctor::Parm10 p10, typename ParentFunctor::Parm11 p11)
		{
			return((*pObj_).*pMemFn_)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);
		}
		ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2, typename ParentFunctor::Parm3 p3, typename ParentFunctor::Parm4 p4, typename ParentFunctor::Parm5 p5, typename ParentFunctor::Parm6 p6,
			typename ParentFunctor::Parm7 p7, typename ParentFunctor::Parm8 p8, typename ParentFunctor::Parm9 p9, typename ParentFunctor::Parm10 p10, typename ParentFunctor::Parm11 p11, typename ParentFunctor::Parm12 p12)
		{
			return((*pObj_).*pMemFn_)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
		}
		ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2, typename ParentFunctor::Parm3 p3, typename ParentFunctor::Parm4 p4, typename ParentFunctor::Parm5 p5, typename ParentFunctor::Parm6 p6,
			typename ParentFunctor::Parm7 p7, typename ParentFunctor::Parm8 p8, typename ParentFunctor::Parm9 p9, typename ParentFunctor::Parm10 p10, typename ParentFunctor::Parm11 p11, typename ParentFunctor::Parm12 p12, typename ParentFunctor::Parm13 p13)
		{
			return((*pObj_).*pMemFn_)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13);
		}
	};
}