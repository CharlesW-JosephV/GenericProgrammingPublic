//CWJ15DEC2024
#pragma once

namespace Hephaestus
{
	//forward declaration of FunctorHandler so the Functor template copy constructor knows it's a thing
	template <class ParentFunctor, typename Fun>
	class FunctorHandler;
	//forward declaration of MemberFunHandler so that Functor template copy constructor knows it's a thing too
	template <class ParentFunctor, typename PointerToObj, typename PointerToMemFn>
	class MemFunHandler;


	//This is the main Functor object which is consumed by the user
	template <typename R, class TList>
	class Functor
	{
	public:
		using ParmList = TList;
		using ResultType = R;
		using Parm1 = typename TL::TypeAtNotStrict<TList, 0, EmptyType>::Result;
		using Parm2 = typename TL::TypeAtNotStrict<TList, 1, EmptyType>::Result;
		using Parm3 = typename TL::TypeAtNotStrict<TList, 2, EmptyType>::Result;
		using Parm4 = typename TL::TypeAtNotStrict<TList, 3, EmptyType>::Result;
		using Parm5 = typename TL::TypeAtNotStrict<TList, 4, EmptyType>::Result;
		using Parm6 = typename TL::TypeAtNotStrict<TList, 5, EmptyType>::Result;
		using Parm7 = typename TL::TypeAtNotStrict<TList, 6, EmptyType>::Result;
		using Parm8 = typename TL::TypeAtNotStrict<TList, 7, EmptyType>::Result;
		using Parm9 = typename TL::TypeAtNotStrict<TList, 8, EmptyType>::Result;
		using Parm10 = typename TL::TypeAtNotStrict<TList, 9, EmptyType>::Result;
		using Parm11 = typename TL::TypeAtNotStrict<TList, 10, EmptyType>::Result;
		using Parm12 = typename TL::TypeAtNotStrict<TList, 11, EmptyType>::Result;
		using Parm13 = typename TL::TypeAtNotStrict<TList, 12, EmptyType>::Result;
		using Impl = FunctorImpl<ResultType, ParmList>;
	private:
		std::unique_ptr<Impl> spImpl_; //pointer to implmentation idiom
	public:

		Functor() = delete; //must be provided an implmentation 

		//template copy constructor 
		template <typename Fun>
		Functor(const Fun& fun) : spImpl_(std::make_unique < FunctorHandler<Functor, Fun>>(fun))
		{
			;
		} //since this is a copy constructor we will make a new FunctorHandler to to the provided functor
			   //no need to move since we are not taking owenership only duplicating functionality 

			   //template copy constructor for a object and pointer to member function
		template <typename PointerToObj, typename PointerToMemFn>
		Functor(const PointerToObj& pointerToObj, const PointerToMemFn pointerToMemFn) : spImpl_(std::make_unique<MemFunHandler<Functor, PointerToObj, PointerToMemFn>>(pointerToObj, pointerToMemFn)) { ; }

		//copy constructor from another functor, can take advantage of the clone function here since all functors should contain a functorhandler
		Functor(const Functor& other) : spImpl_(other.spImpl_->clone()) { ; }

		//assignment operator
		Functor& operator=(const Functor& RHS)
		{
			//because we are using a unique_ptr to the implmentation if the 
			this->spImpl_ = RHS.spImpl_->clone();
			return(*this); //by convention return this to allow chaining
		}
		explicit Functor(std::unique_ptr<Impl> spImpl) : spImpl_(std::move(spImpl)) {}; //"extension constructor" Functor takes ownership of a given implementation
		//~Functor(); destructor not required as unique_ptw will clean up the implmentation as needed

		//define as many forwarding operators as needed, compiler will only instantiate as needed
		R operator()() { return(*spImpl_)(); }
		R operator()(Parm1 p1) { return(*spImpl_)(p1); }
		R operator()(Parm1 p1, Parm2 p2) { return(*spImpl_)(p1, p2); }
		R operator()(Parm1 p1, Parm2 p2, Parm3 p3)
		{
			return(*spImpl_)(p1, p2, p3);
		}
		R operator()(Parm1 p1, Parm2 p2, Parm3 p3, Parm4 p4)
		{
			return(*spImpl_)(p1, p2, p3, p4);
		}
		R operator()(Parm1 p1, Parm2 p2, Parm3 p3, Parm4 p4, Parm5 p5)
		{
			return(*spImpl_)(p1, p2, p3, p4, p5);
		}
		R operator()(Parm1 p1, Parm2 p2, Parm3 p3, Parm4 p4, Parm5 p5, Parm6 p6)
		{
			return(*spImpl_)(p1, p2, p3, p4, p5, p6);
		}
		R operator()(Parm1 p1, Parm2 p2, Parm3 p3, Parm4 p4, Parm5 p5, Parm6 p6, Parm7 p7)
		{
			return(*spImpl_)(p1, p2, p3, p4, p5, p6, p7);
		}
		R operator()(Parm1 p1, Parm2 p2, Parm3 p3, Parm4 p4, Parm5 p5, Parm6 p6, Parm7 p7, Parm8 p8)
		{
			return(*spImpl_)(p1, p2, p3, p4, p5, p6, p7, p8);
		}
		R operator()(Parm1 p1, Parm2 p2, Parm3 p3, Parm4 p4, Parm5 p5, Parm6 p6, Parm7 p7, Parm8 p8, Parm9 p9)
		{
			return(*spImpl_)(p1, p2, p3, p4, p5, p6, p7, p8, p9);
		}
		R operator()(Parm1 p1, Parm2 p2, Parm3 p3, Parm4 p4, Parm5 p5, Parm6 p6, Parm7 p7, Parm8 p8, Parm9 p9, Parm10 p10)
		{
			return(*spImpl_)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);
		}
		R operator()(Parm1 p1, Parm2 p2, Parm3 p3, Parm4 p4, Parm5 p5, Parm6 p6, Parm7 p7, Parm8 p8, Parm9 p9, Parm10 p10, Parm11 p11)
		{
			return(*spImpl_)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);
		}
		R operator()(Parm1 p1, Parm2 p2, Parm3 p3, Parm4 p4, Parm5 p5, Parm6 p6, Parm7 p7, Parm8 p8, Parm9 p9, Parm10 p10, Parm11 p11, Parm12 p12)
		{
			return(*spImpl_)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
		}
		R operator()(Parm1 p1, Parm2 p2, Parm3 p3, Parm4 p4, Parm5 p5, Parm6 p6, Parm7 p7, Parm8 p8, Parm9 p9, Parm10 p10, Parm11 p11, Parm12 p12, Parm13 p13)
		{
			return(*spImpl_)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13);
		}

	};

}