#ifndef _NOT_FOUND_EXCEPTION
#define _NOT_FOUND_EXCEPTION

#include <stdexcept>
#include <string>

using std::logic_error;
using std::string;

class NotFoundException : public logic_error
{
public:

	NotFoundException(const string& message);

};

#endif
