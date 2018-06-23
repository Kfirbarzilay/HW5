#ifndef _MATHEXCEPTION_
#define _MATHEXCEPTION_

#include <exception>

using namespace std;

class mathexception: public exception
{
public:
	mathexception();
	virtual const char* what() const throw ();
}mathex;

#endif
