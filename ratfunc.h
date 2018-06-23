#ifndef _RATFUNC_Q
#define _RATFUNC_Q

#include "polynom.h"

using namespace std;

class ratfunc : public func {
public:
	ratfunc(const polynom& polimechani , const polynom& polimone); //the ratfunc constructor
	func & operator<<(const int& x);
	ratfunc& operator=(const ratfunc&); 
	virtual int operator=(const int&);
	ratfunc operator+(const ratfunc &secondratfunc)const; // operator+ the adds two rat funcs together
	ratfunc operator-(const ratfunc &secondratfunc)const; //
	ratfunc operator*(const ratfunc &secondratfunc)const; //
	ratfunc operator/(const ratfunc &secondratfunc)const; //
	ratfunc Derivative()const;
	virtual void print(ostream& os)const;
protected:
	  polynom a_;
	  polynom b_;
};


#endif
 
