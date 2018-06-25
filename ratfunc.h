#ifndef _RATFUNC_Q
#define _RATFUNC_Q

#include "polynom.h"

using namespace std;

//a func derived class, rational function composed of two polynomials
class ratfunc : public func {
public:
	//************************************
	// Method:    ratfunc
	// FullName:  ratfunc::ratfunc
	// Access:    public 
	// Description: A ratfunc constructor 
	// Parameter: const polynom & polimechani
	// Parameter: const polynom & polimone
	//************************************
	ratfunc(const polynom& polimechani , const polynom& polimone); 

	~ratfunc();

	//************************************
	// Method:    operator<<
	// FullName:  ratfunc::operator<<
	// Access:    public 
	// Description: inherited from func. Adds a point 
	// Returns:   func &
	// Parameter: const int & x
	//************************************
	func & operator<<(const int& x);

	//************************************
	// Method:    operator=
	// FullName:  ratfunc::operator=
	// Access:    virtual public 
	// Description: Assignment operator
	// Returns:   ratfunc&
	// Qualifier:
	// Parameter: const ratfunc &
	//************************************
	ratfunc& operator=(const ratfunc&); 

	//************************************
	// Method:    operator=
	// FullName:  ratfunc::operator=
	// Access:    virtual public 
	// Description: Calculates f(x). doesn't store the point.
	// Returns:   int
	// Parameter: const int &
	//************************************
	virtual int operator=(const int&);

	//************************************
	// Method:    operator+
	// FullName:  ratfunc::operator+
	// Access:    public 
	// Description: adds two rational functions.
	// Returns:   ratfunc
	// Qualifier: const
	// Parameter: const ratfunc & secondratfunc
	//************************************
	ratfunc operator+(const ratfunc &secondratfunc)const; // operator+ the adds two rat funcs together
	
	//************************************
	// Method:    operator-
	// FullName:  ratfunc::operator-
	// Access:    public 
	// Description: creates a new rational function by subtraction
	// Returns:   ratfunc
	// Qualifier: const
	// Parameter: const ratfunc & secondratfunc
	//************************************
	ratfunc operator-(const ratfunc &secondratfunc)const; 

	//************************************
	// Method:    operator*
	// FullName:  ratfunc::operator*
	// Access:    public 
	// Description: creates a new rational function by multiplication
	// Returns:   ratfunc
	// Qualifier: const
	// Parameter: const ratfunc & secondratfunc
	//************************************
	ratfunc operator*(const ratfunc &secondratfunc)const; 

	//************************************
	// Method:    operator/
	// FullName:  ratfunc::operator/
	// Access:    public 
	// Description: creates a new rational function by quotient of two rational functions  
	// Returns:   ratfunc
	// Qualifier: const
	// Parameter: const ratfunc & secondratfunc
	//************************************
	ratfunc operator/(const ratfunc &secondratfunc)const; 

	//************************************
	// Method:    Derivative
	// FullName:  ratfunc::Derivative
	// Access:    public 
	// Description: creates a new rational function by deriving the original rational function
	// Returns:   ratfunc
	// Qualifier: const
	//************************************
	ratfunc Derivative()const;

	//************************************
	// Method:    print
	// FullName:  ratfunc::print
	// Access:    virtual public 
	// Description: prints the rational function and it's derivative.
	// Returns:   void
	// Qualifier: const
	// Parameter: ostream & os
	//************************************
	virtual void print(ostream& os)const;
protected:
	  polynom a_; //the  numerator polynom
	  polynom b_; //the  denominator polynom
};


#endif
 
