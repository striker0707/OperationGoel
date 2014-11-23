/** @file NotFoundException.cpp */
#include "NotFoundException.h"
#include <iostream>
#include <stdexcept>
#include <string>

using std::exception;
using std::string;


//--------------------------------------------------------------------
//          constructors
//--------------------------------------------------------------------


NotFoundException::NotFoundException(const string & message = "")
	: logic_error("Not Found Exception:" + message)
{
}
