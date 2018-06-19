#ifndef _POLY_F
#define _POLY_F

#include "func.h"

using namespace std;


class polynom : public func {
public:
	polynom(int n, int* arr);
	polynom(const polynom& poly);	//copy constructor
	virtual func & operator<<(const int& x); //adding points. 
	polynom& operator+(const polynom &secondpoly);
	polynom& operator-(const polynom &secondpoly);
	polynom& operator*(const polynom &secondpoly);
	polynom& Derivative(); 
	polynom& Integral(); 
	void printcoefs(ostream&)  const ;
	void plot(ostream& os) const;
  protected:

  int n_; //order of the polynom
  int* coefs_; //coefficients 
};



#endif
 
