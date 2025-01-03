//CWJ15DEC2024
#pragma once

namespace Hephaestus
{
	//FunctorImpl is used to proved a polymorphic interface for abstracted function calls 
	//this class template is for a family of abstract base classes
	//with additional tempaltes manually declared for up to 13 arguments as inputs
	//This class must define a clone function so that it can be "owned" and ownership may be transfered 

	template <typename R, class TList>
	class FunctorImpl;

	//We must define an explicit specalization for each number of parameters
	//arbitrary decision to cap at 13 as that's as far as I've taken the TYPELIST_X macro
	template<typename R>
	class FunctorImpl<R, NullType>
	{
	public:
		//default constructor is alright
		//default copy constructor is alright
		//default copy assignment operator is alright
		virtual ~FunctorImpl() {}; //always declare BaseClass destructors as virtual to avoid undefined behavior
		virtual R operator()() = 0;
		virtual std::unique_ptr<FunctorImpl> clone() const = 0;


	};

	template<typename R, typename P1>
	class FunctorImpl<R, TYPELIST_1(P1)>
	{
	public:
		virtual ~FunctorImpl() {};
		virtual R operator()(P1) = 0;
		virtual std::unique_ptr<FunctorImpl> clone() const = 0;

	};

	template<typename R, typename P1, typename P2>
	class FunctorImpl<R, TYPELIST_2(P1, P2)>
	{
	public:
		virtual ~FunctorImpl() {};
		virtual R operator()(P1, P2) = 0;
		virtual std::unique_ptr<FunctorImpl> clone() const = 0;

	};

	template<typename R, typename P1, typename P2, typename P3>
	class FunctorImpl<R, TYPELIST_3(P1, P2, P3)>
	{
	public:
		virtual ~FunctorImpl() {};
		virtual R operator()(P1, P2, P3) = 0;
		virtual std::unique_ptr<FunctorImpl> clone() const = 0;
	};

	template<typename R, typename P1, typename P2, typename P3, typename P4>
	class FunctorImpl<R, TYPELIST_4(P1, P2, P3, P4)>
	{
	public:
		virtual ~FunctorImpl() {};
		virtual R operator()(P1, P2, P3, P4) = 0;
		virtual std::unique_ptr<FunctorImpl> clone() const = 0;
	};

	template<typename R, typename P1, typename P2, typename P3, typename P4, typename P5>
	class FunctorImpl<R, TYPELIST_5(P1, P2, P3, P4, P5)>
	{
	public:
		virtual ~FunctorImpl() {};
		virtual R operator()(P1, P2, P3, P4, P5) = 0;
		virtual std::unique_ptr<FunctorImpl> clone() const = 0;
	};

	template<typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
	class FunctorImpl<R, TYPELIST_6(P1, P2, P3, P4, P5, P6)>
	{
	public:
		virtual ~FunctorImpl() {};
		virtual R operator()(P1, P2, P3, P4, P5, P6) = 0;
		virtual std::unique_ptr<FunctorImpl> clone() const = 0;

	};

	template<typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
	class FunctorImpl<R, TYPELIST_7(P1, P2, P3, P4, P5, P6, P7)>
	{
	public:
		virtual ~FunctorImpl() {};
		virtual R operator()(P1, P2, P3, P4, P5, P6, P7) = 0;
		virtual std::unique_ptr<FunctorImpl> clone() const = 0;
	};

	template<typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
	class FunctorImpl<R, TYPELIST_8(P1, P2, P3, P4, P5, P6, P7, P8)>
	{
	public:
		virtual ~FunctorImpl() {};
		virtual R operator()(P1, P2, P3, P4, P5, P6, P7, P8) = 0;
		virtual std::unique_ptr<FunctorImpl> clone() const = 0;
	};

	template<typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
	class FunctorImpl<R, TYPELIST_9(P1, P2, P3, P4, P5, P6, P7, P8, P9)>
	{
	public:
		virtual ~FunctorImpl() {};
		virtual R operator()(P1, P2, P3, P4, P5, P6, P7, P8, P9) = 0;
		virtual std::unique_ptr<FunctorImpl> clone() const = 0;
	};

	template<typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10>
	class FunctorImpl<R, TYPELIST_10(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10)>
	{
	public:
		virtual ~FunctorImpl() {};
		virtual R operator()(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) = 0;
		virtual std::unique_ptr<FunctorImpl> clone() const = 0;
	};

	template<typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11>
	class FunctorImpl<R, TYPELIST_11(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11)>
	{
	public:
		virtual ~FunctorImpl() {};
		virtual R operator()(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) = 0;
		virtual std::unique_ptr<FunctorImpl> clone() const = 0;
	};

	template<typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12>
	class FunctorImpl<R, TYPELIST_12(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12)>
	{
	public:
		virtual ~FunctorImpl() {};
		virtual R operator()(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) = 0;
		virtual std::unique_ptr<FunctorImpl> clone() const = 0;
	};

	template<typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13>
	class FunctorImpl<R, TYPELIST_13(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13)>
	{
	public:
		virtual ~FunctorImpl() {};
		virtual R operator()(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) = 0;
		virtual std::unique_ptr<FunctorImpl> clone() const = 0;
	};
}