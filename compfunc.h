#ifndef _COMPFUNC_H_
#define _COMPFUNC_H_

#include "func.h"
template<class T, class Z>
class compfunc : public func {
public:
	compfunc(const T& t,const Z& z);
	virtual func & operator<<(const int& x);
	virtual int operator=(const int&);
	virtual void print(ostream& os)const;
protected:
	T outer;
	Z inner;
};

template<class T, class Z>
int compfunc<T, Z>::operator=(const int& x)
{
	//don't need to implement this
}

template<class T, class Z>
func & compfunc<T, Z>::operator<<(const int& x)
{
	int inner_res = inner = x;
	int outer_res = outer = inner_res;
	fmap_[x] = outer_res;
}

template<class T, class Z>
compfunc<T, Z>::compfunc(const T& t, const Z& z)
{
	outer = t;
	inner = z;
}

#endif // !_COMPFUNC_H_
