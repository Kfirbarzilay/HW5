#include "mathexception.h"
//************************************
// Method:    mathexception
// FullName:  mathexception::mathexception
// Access:    public 
// Description: mathexception constructor
//************************************
mathexception::mathexception()
{

}

//************************************
// Method:    ~mathexception
// FullName:  mathexception::~mathexception
// Access:    public 
// Description: mathexception destructor 
//************************************
mathexception::~mathexception() throw()
{

}

//************************************
// Method:    what
// FullName:  mathexception::what
// Access:    virtual public 
// Description: throws a devision by zero error.
//				used to prevent a non valid output
// Returns:   const char*
// Qualifier: const throw ()
//************************************
const char* mathexception::what() const throw ()
{
	return "divide by zero";
}
