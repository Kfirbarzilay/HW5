#ifndef _MATH_EXCEPTION_
#define _MATH_EXCEPTION_

#include <exception>

using namespace std;

class mathexception: public exception
{
public:
	mathexception();
	~mathexception();
	virtual const char* what() const throw ();
};

#endif
