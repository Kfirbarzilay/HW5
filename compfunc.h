#ifndef _COMPFUNC_H_
#define _COMPFUNC_H_

#include "ratfunc.h"

//a derived class of func. creates a function composition.
class compfunc : public func {
public:
	//************************************
	// Method:    compfunc
	// FullName:  compfunc::compfunc
	// Access:    public 
	// Description: a compfunc constructor
	// Parameter: func &
	// Parameter: func &
	//************************************
	compfunc(func& ,func&);

	~compfunc();

	//************************************
	// Method:    operator<<
	// FullName:  compfunc::operator<<
	// Access:    virtual public 
	// Description: inherited from func. adds a point to fmap_
	// Returns:   func &
	// Parameter: const int & x
	//************************************
	virtual func & operator<<(const int& x);

	//************************************
	// Method:    operator=
	// FullName:  compfunc::operator=
	// Access:    virtual public 
	// Description: calculates f(x). doesn't store the point
	// Returns:   int
	// Parameter: const int &
	//************************************
	virtual int operator=(const int&);

	//************************************
	// Method:    print
	// FullName:  compfunc::print
	// Access:    virtual public 
	// Description: prints the function
	// Returns:   void
	// Qualifier: const
	// Parameter: ostream & os
	//************************************
	virtual void print(ostream& os)const;
protected:
	func* outer; //the outer function
	func* inner; //the inner function
};


#endif // !_COMPFUNC_H_
