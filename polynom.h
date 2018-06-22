#ifndef _POLY_F
#define _POLY_F

#include "func.h"

using namespace std;


class polynom : public func {
public:
	polynom(int n, int* arr);
	~polynom();
	polynom(const polynom& poly);	//copy constructor
	polynom& operator=(const polynom&);
	virtual int operator=(const int&);
	virtual func & operator<<(const int& x); //adding points. 
	polynom operator+(const polynom &secondpoly)const;
	polynom operator-(const polynom &secondpoly)const;
	polynom operator*(const polynom &secondpoly)const;
	polynom Derivative()const; 
	polynom Integral()const; 
	void printcoefs(ostream&)  const ;
	virtual void print(ostream& os)const;
	int getfuncval(const int& x)const;
 
protected:
	int n_; //order of the polynom
	int* coefs_; //coefficients 
};



#endif
 
