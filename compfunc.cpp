#include "compfunc.h"


compfunc::compfunc( func& t,  func& z)
{
	outer = &t;
	inner = &z;
	minVal_ = 0;
	maxVal_ = 0;
}

func & compfunc::operator<<(const int& x)
{
	int inner_res = *inner = x;
	int outer_res = *outer = inner_res;
	fmap_[x] = outer_res;

	if (x < minVal_) minVal_ = x;
	if (x > maxVal_) maxVal_ = x;

	return *this;
}

void compfunc::print(ostream& os) const
{
	os << endl;
	//plot the function points inserted.
	plot(os);
}

int compfunc::operator=(const int&x)//won't use it
{
	return x;
}
