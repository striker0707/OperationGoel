/** @file PrecondViolatedExcep.cpp */
#include "PrecondViolatedExcep.h"
#include <iostream>
#include <stdexcept>
#include <string>

using std::exception;
using std::string;


//--------------------------------------------------------------------
//          constructors
//--------------------------------------------------------------------


PrecondViolatedExcep::PrecondViolatedExcep(const string & message = "")
	: logic_error("Not Found Exception:" + message)
{
}
