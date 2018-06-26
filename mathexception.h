#ifndef _MATH_EXCEPTION_
#define _MATH_EXCEPTION_

#include <exception>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

using namespace std;
//a special exception class derived from exception class of std.
class mathexception: public exception
{
public:
	//************************************
	// Method:    mathexception
	// FullName:  mathexception::mathexception
	// Access:    public 
	// Description: mathexception constructor
	//************************************
	mathexception();

	//************************************
	// Method:    ~mathexception
	// FullName:  mathexception::~mathexception
	// Access:    public 
	// Description: mathexception destructor 
	//************************************
	~mathexception() throw();

	//************************************
	// Method:    what
	// FullName:  mathexception::what
	// Access:    virtual public 
	// Description: throws a devision by zero error.
	//				used to prevent a non valid output
	// Returns:   const char*
	// Qualifier: const throw ()
	//************************************
	virtual const char* what() const throw ();
};

#endif
