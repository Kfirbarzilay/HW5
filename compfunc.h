#ifndef _COMPFUNC_H_
#define _COMPFUNC_H_

#include "ratfunc.h"

class compfunc : public func {
public:
	compfunc(func& ,func&);
	virtual func & operator<<(const int& x);
	virtual int operator=(const int&);
	virtual void print(ostream& os)const;
protected:
	func* outer;
	func* inner;
};


#endif // !_COMPFUNC_H_
