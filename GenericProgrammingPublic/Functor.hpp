//CWJ07OCT2024
//Predominantly informed from Andrei Alexandrescu's wonderful work "Modern C++ Design" 
//Developing a header only version of "Functor" 
//A generic programing object allowing for use of the Command Design Pattern
//Note, by convention using typename inside template means primitive types can be used, whereas class designates that it must be user defined types

//TODO
//Figure out how to build a FunctorChain class to chain calls together 
//Figure out how to write a Typetrait, so that all arguments can be passed by reference to avoid copy overhead! Probably the most important

//CWJ23DEC2024 
//Second take at the functor header only library
#pragma once

//This header will serve as a collector header for the individual files which define each class

//All external functor dependencies here 
#include <memory> //needed for unique_ptr

//All external CWJ dependencies here
#include "TypeList.hpp" 
#include "FunctorImpl.hpp"
#include "FunctorFunctor.hpp"
#include "FunctorHandler.hpp"
#include "MemFunHandler.hpp"
#include "BinderFirst.hpp"
