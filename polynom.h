#ifndef _POLY_F
#define _POLY_F

#include "func.h"

using namespace std;

//a func derived class
class polynom : public func {
public:
	//************************************
	// Method:    polynom
	// FullName:  polynom::polynom
	// Access:    public 
	// Description: A polynom function constructor
	// Parameter: int n
	// Parameter: int * arr
	//************************************
	polynom(int n, int* arr);

	//************************************
	// Method:    ~polynom
	// FullName:  polynom::~polynom
	// Access:    public 
	// Description: A polynom Destructor
	//************************************
	~polynom();

	//************************************
	// Method:    polynom
	// FullName:  polynom::polynom
	// Access:    public 
	// Description: A polynom copy constructor
	// Parameter: const polynom & poly
	//************************************
	polynom(const polynom& poly);	

	//************************************
	// Method:    operator=
	// FullName:  polynom::operator=
	// Access:    virtual public 
	// Description: A polynom assignment operator
	// Returns:   polynom&
	// Parameter: const polynom &
	//************************************
	polynom& operator=(const polynom&);

	//************************************
	// Method:    operator=
	// FullName:  polynom::operator=
	// Access:    virtual public 
	// Description: calculates a function value for inserted point. 
	//				doesn't store it
	// Returns:   int
	// Parameter: const int &
	//************************************
	virtual int operator=(const int&);


	//************************************
	// Method:    operator<<
	// FullName:  polynom::operator<<
	// Access:    virtual public 
	// Description: inherited from class func. Adding points to fmap_
	// Returns:   func &
	// Qualifier:
	// Parameter: const int & x
	//************************************
	virtual func & operator<<(const int& x); 

	//************************************
	// Method:    operator+
	// FullName:  polynom::operator+
	// Access:    public 
	// Description: Creates a polynom by adding two existing polynomials
	// Returns:   polynom
	// Qualifier: const
	// Parameter: const polynom & secondpoly
	//************************************
	polynom operator+(const polynom &secondpoly)const;

	//************************************
	// Method:    operator-
	// FullName:  polynom::operator-
	// Access:    public 
	// Description: Creates a polynom by subtracting one polynom from another
	// Returns:   polynom
	// Qualifier: const
	// Parameter: const polynom & secondpoly
	//************************************
	polynom operator-(const polynom &secondpoly)const;

	//************************************
	// Method:    operator*
	// FullName:  polynom::operator*
	// Access:    public 
	// Description: Creates a new polynom by multiplying two
	// Returns:   polynom
	// Qualifier: const
	// Parameter: const polynom & secondpoly
	//************************************
	polynom operator*(const polynom &secondpoly)const;

	//************************************
	// Method:    Derivative
	// FullName:  polynom::Derivative
	// Access:    public 
	// Description: creates a new polynom that is a derivative of another polynom
	// Returns:   polynom
	// Qualifier: const
	//************************************
	polynom Derivative()const; 

	//************************************
	// Method:    Integral
	// FullName:  polynom::Integral
	// Access:    public 
	// Description: creates a new polynom that is the integral of another polynom
	// Returns:   polynom
	// Qualifier: const
	//************************************
	polynom Integral()const; 

	//************************************
	// Method:    printcoefs
	// FullName:  polynom::printcoefs
	// Access:    public 
	// Description: prints the polynom coefficients 
	// Returns:   void
	// Qualifier: const
	// Parameter: ostream &
	//************************************
	void printcoefs(ostream&)  const ;

	//************************************
	// Method:    print
	// FullName:  polynom::print
	// Access:    virtual public 
	// Description: prints the function with it's derivative and integral. 
	//				plots the points
	// Returns:   void
	// Qualifier: const
	// Parameter: ostream & os
	//************************************
	virtual void print(ostream& os)const;
	
	//************************************
	// Method:    getfuncval
	// FullName:  polynom::getfuncval
	// Access:    public 
	// Description: gets the f(x) value
	// Returns:   int
	// Qualifier: const
	// Parameter: const int & x
	//************************************
	int getfuncval(const int& x)const;
 
protected:
	int n_; //order of the polynom
	int* coefs_; //coefficients 
};



#endif
 
