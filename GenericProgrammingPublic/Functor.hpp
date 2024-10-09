//CWJ07OCT2024
//Predominantly informed from Andrei Alexandrescu's wonderful work "Modern C++ Design" 
//Developing a header only version of "Functor" 
//A generic programing object allowing for use of the Command Design Pattern
//Note, by convention using typename inside template means primitive types can be used, whereas class designates that it must be user defined types

//TODO
//Figure out how to properly implment cloning so that BindFirst funciton calls work 
//Figure out how to build a FunctorChain class to chain calls together 
//Figure out how to write a Typetrait, so that all arguments can be passed by reference to avoid copy overhead! Probably the most important

#pragma once

#include "TypeList.hpp" //Functor requires Typelists

#include <memory> //needed for unique_ptr

namespace Hephaestus //Greek god of the forge 
{

	//FunctorImpl is used to provide a polymorphic interface for abstracted function calls
	//forward declare here so Functor knows it's a thing 
	template <typename R, class TList>
	class FunctorImpl;

	//We must define an explicit specalization for each number of parameters
	//arbitrary decision to cap at 13 as that's as far as I've taken the TYPELIST_X macro
	template<typename R>
	class FunctorImpl<R, NullType>
	{
	public:
		virtual R operator()() = 0;
		//virtual FunctorImpl* Clone() const = 0;
		virtual std::unique_ptr<FunctorImpl> Clone() const = 0;
		virtual ~FunctorImpl() {};
	};

	template<typename R, typename P1>
	class FunctorImpl<R, TYPELIST_1(P1)>
	{
	public:
		virtual R operator()(P1) = 0;
		//virtual FunctorImpl* Clone() const = 0;
		virtual std::unique_ptr<FunctorImpl> Clone() const = 0;
		virtual ~FunctorImpl() {};
	};

	template<typename R, typename P1, typename P2>
	class FunctorImpl<R, TYPELIST_2(P1, P2)>
	{
	public:
		virtual R operator()(P1, P2) = 0;
		//virtual FunctorImpl* Clone() const = 0;
		virtual std::unique_ptr<FunctorImpl> Clone() const = 0;
		virtual ~FunctorImpl() {};
	};

	template<typename R, typename P1, typename P2, typename P3>
	class FunctorImpl<R, TYPELIST_3(P1, P2, P3)>
	{
	public:
		virtual R operator()(P1, P2, P3) = 0;
		//virtual FunctorImpl* Clone() const = 0;
		virtual std::unique_ptr<FunctorImpl> Clone() const = 0;
		virtual ~FunctorImpl() {};
	};

	template<typename R, typename P1, typename P2, typename P3, typename P4>
	class FunctorImpl<R, TYPELIST_4(P1, P2, P3, P4)>
	{
	public:
		virtual R operator()(P1, P2, P3, P4) = 0;
		//virtual FunctorImpl* Clone() const = 0;
		virtual std::unique_ptr<FunctorImpl> Clone() const = 0;
		virtual ~FunctorImpl() {};
	};

	template<typename R, typename P1, typename P2, typename P3, typename P4, typename P5>
	class FunctorImpl<R, TYPELIST_5(P1, P2, P3, P4, P5)>
	{
	public:
		virtual R operator()(P1, P2, P3, P4, P5) = 0;
		//virtual FunctorImpl* Clone() const = 0;
		virtual std::unique_ptr<FunctorImpl> Clone() const = 0;
		virtual ~FunctorImpl() {};
	};

	template<typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
	class FunctorImpl<R, TYPELIST_6(P1, P2, P3, P4, P5, P6)>
	{
	public:
		virtual R operator()(P1, P2, P3, P4, P5, P6) = 0;
		//virtual FunctorImpl* Clone() const = 0;
		virtual std::unique_ptr<FunctorImpl> Clone() const = 0;
		virtual ~FunctorImpl() {};
	};

	template<typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
	class FunctorImpl<R, TYPELIST_7(P1, P2, P3, P4, P5, P6, P7)>
	{
	public:
		virtual R operator()(P1, P2, P3, P4, P5, P6, P7) = 0;
		//virtual FunctorImpl* Clone() const = 0;
		virtual std::unique_ptr<FunctorImpl> Clone() const = 0;
		virtual ~FunctorImpl() {};
	};

	template<typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
	class FunctorImpl<R, TYPELIST_8(P1, P2, P3, P4, P5, P6, P7, P8)>
	{
	public:
		virtual R operator()(P1, P2, P3, P4, P5, P6, P7, P8) = 0;
		//virtual FunctorImpl* Clone() const = 0;
		virtual std::unique_ptr<FunctorImpl> Clone() const = 0;
		virtual ~FunctorImpl() {};
	};

	template<typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
	class FunctorImpl<R, TYPELIST_9(P1, P2, P3, P4, P5, P6, P7, P8, P9)>
	{
	public:
		virtual R operator()(P1, P2, P3, P4, P5, P6, P7, P8, P9) = 0;
		//virtual FunctorImpl* Clone() const = 0;
		virtual std::unique_ptr<FunctorImpl> Clone() const = 0;
		virtual ~FunctorImpl() {};
	};

	template<typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10>
	class FunctorImpl<R, TYPELIST_10(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10)>
	{
	public:
		virtual R operator()(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) = 0;
		//virtual FunctorImpl* Clone() const = 0;
		virtual std::unique_ptr<FunctorImpl> Clone() const = 0;
		virtual ~FunctorImpl() {};
	};

	template<typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11>
	class FunctorImpl<R, TYPELIST_11(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11)>
	{
	public:
		virtual R operator()(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) = 0;
		//virtual FunctorImpl* Clone() const = 0;
		virtual std::unique_ptr<FunctorImpl> Clone() const = 0;
		virtual ~FunctorImpl() {};
	};

	template<typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12>
	class FunctorImpl<R, TYPELIST_12(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12)>
	{
	public:
		virtual R operator()(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) = 0;
		//virtual FunctorImpl* Clone() const = 0;
		virtual std::unique_ptr<FunctorImpl> Clone() const = 0;
		virtual ~FunctorImpl() {};
	};

	template<typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13>
	class FunctorImpl<R, TYPELIST_13(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13)>
	{
	public:
		virtual R operator()(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) = 0;
		//virtual FunctorImpl* Clone() const = 0;
		virtual std::unique_ptr<FunctorImpl> Clone() const = 0;
		virtual ~FunctorImpl() {};
	};

	//***************************************************************************************************************

	//This is the main Functor object consumed by the user. 
	//TList is utilized to generate new class instances for various combiniations and lenghts of input types
	//template <typename ResultType, class TList>
	template <typename R, class TList>
	class Functor
	{
	public:
		//Define type alias's for convience 
		//using ParamList = TList; 
		//TypeAtNotStrict will return the type as the given point in the list or default to EmptyType if the TList bounds would be exceeded
		//using Parm1 = TL::TypeAtNotStrict<TList, 0, EmptyType>::Result; 
		//using Parm2 = TL::TypeAtNotStrict<TList, 1, EmptyType>::Result;
		//using Parm3 = TL::TypeAtNotStrict<TList, 2, EmptyType>::Result;
		//using Parm4 = TL::TypeAtNotStrict<TList, 3, EmptyType>::Result;
		//using Parm5 = TL::TypeAtNotStrict<TList, 4, EmptyType>::Result;
		//using Parm6 = TL::TypeAtNotStrict<TList, 5, EmptyType>::Result;
		//using Parm7 = TL::TypeAtNotStrict<TList, 6, EmptyType>::Result;
		//using Parm8 = TL::TypeAtNotStrict<TList, 7, EmptyType>::Result;
		//using Parm9 = TL::TypeAtNotStrict<TList, 8, EmptyType>::Result;
		//using Parm10 = TL::TypeAtNotStrict<TList, 9, EmptyType>::Result;
		//using Parm11 = TL::TypeAtNotStrict<TList, 10, EmptyType>::Result;
		//using Parm12 = TL::TypeAtNotStrict<TList, 11, EmptyType>::Result;
		//using Parm13 = TL::TypeAtNotStrict<TList, 12, EmptyType>::Result;
		typedef TList ParmList;
		typedef R ResultType;
		typedef typename TL::TypeAtNotStrict<TList, 0, EmptyType>::Result Parm1;
		typedef typename TL::TypeAtNotStrict<TList, 1, EmptyType>::Result Parm2;
		typedef typename TL::TypeAtNotStrict<TList, 2, EmptyType>::Result Parm3;
		typedef typename TL::TypeAtNotStrict<TList, 3, EmptyType>::Result Parm4;
		typedef typename TL::TypeAtNotStrict<TList, 4, EmptyType>::Result Parm5;
		typedef typename TL::TypeAtNotStrict<TList, 5, EmptyType>::Result Parm6;
		typedef typename TL::TypeAtNotStrict<TList, 6, EmptyType>::Result Parm7;
		typedef typename TL::TypeAtNotStrict<TList, 7, EmptyType>::Result Parm8;
		typedef typename TL::TypeAtNotStrict<TList, 8, EmptyType>::Result Parm9;
		typedef typename TL::TypeAtNotStrict<TList, 9, EmptyType>::Result Parm10;
		typedef typename TL::TypeAtNotStrict<TList, 10, EmptyType>::Result Parm11;
		typedef typename TL::TypeAtNotStrict<TList, 11, EmptyType>::Result Parm12;
		typedef typename TL::TypeAtNotStrict<TList, 12, EmptyType>::Result Parm13;
		//Again arbitrary decision to stop at 13 
		typedef FunctorImpl<ResultType, ParmList> Impl; //Andrei Alexandrescu shows this as being in the private members, but also has the explicit constructor? Not sure if that's a typeo or if I'm not understanding how that can be made valid code

		//public:
		Functor() = delete; //disallowing default constructor, otherwise you might not end up with an implmentation and generate a linker error
		//template copy constructor to make a functor from another functor
		//Functor(const Functor&); //need to use a template constructor parameterized by the type of functor to be constructed
		template <typename Fun>
		Functor(const Fun& fun);
		//template constructor to make a functor from objects and pointer to member functions
		template <typename PointerToObj, typename PointerToMemFn>
		Functor(const PointerToObj& pointerToObj, const PointerToMemFn pointerToMemFn);
		//assignment operator
		Functor& operator=(const Functor& LHS)
		{
			//because we are using a unique_ptr to the implmentation, asignment with a new pointer should deallocate the prior implmentation
			this->spImpl_ = LHS.spImpl_->Clone(); //use the special Clone funciton to duplicate the implmentation 
			return(*this); //by convention return this to allow chaining 
		}

		//Honestly at this point IDK how to write the explicit constructor so I'm disabling
		//explicit Functor(std::unique_ptr<Impl> spImpl); //"extenstion constructor" allows for functor to wrap classes derived from FunctorImpl
		//no destructor since unique_ptr will clean up the implementation as required

		//define operator(), using the trick that we define all possible versions and rely on the compiler to only instantiate the version which is used
		//since Funtor is a wrapper class we simply forward the request to the implmentation
		R operator()()
		{
			return(*spImpl_)();
		}
		R operator()(Parm1 p1)
		{
			return(*spImpl_)(p1);
		}
		R operator()(Parm1 p1, Parm2 p2)
		{
			return(*spImpl_)(p1, p2);
		}
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
	private:
		//typedef FunctorImpl<R, TList> Impl;  //moved to just under class defitiiong, explicit constructor needs knowledge of this definition
		std::unique_ptr<Impl> spImpl_; //pointer to implmentation idiom 
		//std::unique_ptr<FunctorImpl<R, TList>> spImpl_;
	};



	//***************************************************************************************************************
	//FunctorHandler is used to assist with the copy constructor of Functor, allowing for one functor to be copied from another
	//It is quite a bit like functor, but stores the request by value instead of a pointer
	template <class ParentFunctor, typename Fun> //again class means must be user defined, typname means can be a builtin
	class FunctorHandler : public FunctorImpl<typename ParentFunctor::ResultType, typename ParentFunctor::ParmList>
	{
	public:
		//using ResultType = ParentFunctor::ResultType; 
		typedef typename ParentFunctor::ResultType ResultType;

		FunctorHandler(const Fun& fun) : fun_(fun) { ; }
		//FunctorHandler* Clone() const 
		//Need <typename ParentFunctor::ResultType, typename ParentFunctor::ParmList> otherwise compiler error C3203 is generated
		std::unique_ptr<FunctorImpl<typename ParentFunctor::ResultType, typename ParentFunctor::ParmList>> Clone() const //this inherits from FunctorImpl, so we should be okay returning a base pointer 
		{
			return  std::make_unique<FunctorHandler>(*this);
			//return new FunctorHandler(*this); //also generates C2555
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

	//***************************************************************************************************************
	//Support for pointer to member functions 
	template <class ParentFunctor, typename PointerToObj, typename PointerToMemFn> //template class
	class MemFunHandler : public FunctorImpl <typename ParentFunctor::ResultType, typename ParentFunctor::ParmList> //expands the implmentation 
	{
	public:
		typedef typename ParentFunctor::ResultType ResultType;
		MemFunHandler(const PointerToObj& pObj, PointerToMemFn pMemFn) : pObj_(pObj), pMemFn_(pMemFn) {}
		std::unique_ptr<FunctorImpl<typename ParentFunctor::ResultType, typename ParentFunctor::ParmList>> Clone() const
		{
			return std::make_unique<MemFunHandler>(*this);
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
	private:
		PointerToObj pObj_;
		PointerToMemFn pMemFn_;
	};

	//***************************************************************************************************************
	//Binder First
	//Takes a functor with N arguments, and returns a functor with N-1 arguments, with the first (Head) having been bound to a given value 
	//This allows for storing a portion of the call environment directly inside the functor

	template <class Incoming>
	class BinderFirst : public FunctorImpl<typename Incoming::ResultType, typename Incoming::ParmList::Tail>
	{
		typedef Functor<typename Incoming::ResultType, typename Incoming::ParmList::Tail> Outgoing;
		typedef typename Incoming::Parm1 Bound;
		typedef typename Incoming::ResultType ResultType;

	public:
		BinderFirst(const Incoming& fun, Bound bound) : fun_(fun), bound_(bound) {}
		//DEFINE_CLONE_FUNCTORIMPL(BinderFirst); //Not sure what Andrei is up to here, guess it's stating that the library designer needs to define this for a derived class from the ABC of FunctorImpl?
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

	//***************************************************************************************************************
	//Bind First (not Binder First!)

	template <class R, class TList>
	Functor<R, typename TList::Tail> BindFirst(const Functor<R, TList>& fun, typename TList::Head bound)
	{
		typedef Functor<R, TList> Incoming;
		typedef Functor<R, typename TList::Tail> Outgoing;

		return Outgoing(std::make_unique<typename Outgoing::Impl>(BinderFirst<Incoming>(fun, bound))); //TODO This is so close to compiling but is currently attempting to instantiate an abstract class
		//I need to do a little more reading and thinking to determine the proper path forward. 
	}

	//***************************************************************************************************************
	//Chaining -To be done later

	//Need to define a class FunctorChain to hold the chain 
	//FunctorChain::operator() would then call the functors in series
	//using a helper funciton with a definition like below to generate the chain
	//template <class R, class TL>
	//Functor<R, TL> Chain(
	//	const Functor<R, TL>& fun1,
	//	const Functor<R, TL>& fun2); 

	//***************************************************************************************************************
	//Implementations 

	//implementation of template copy constructor of Functor
	template <typename R, class TList>
	template <typename Fun> //out of class member template definition
	Functor<R, TList>::Functor(const Fun& fun) : spImpl_(std::make_unique<FunctorHandler<Functor, Fun>>(fun)) { ; }

	//implmenation of constructor for object and pointer to member function 
	template <typename R, class TList>
	template <typename PointerToObj, typename PointerToMemFn>
	Functor<R, TList>::Functor(const PointerToObj& pointerToObj, const PointerToMemFn pointerToMemFn) : spImpl_(std::make_unique<MemFunHandler<Functor, PointerToObj, PointerToMemFn>>(pointerToObj, pointerToMemFn)) { ; }


} //namespace Hephaestus 
