#include "compfunc.h"


compfunc::compfunc( func& t,  func& z)
{
	outer = &t;
	inner = &z;
	firstinput = false;
}

func & compfunc::operator<<(const int& x)
{

	int inner_res = *inner = x;
	int outer_res = *outer = inner_res;

	if (!firstinput) {
		firstinput = true;
		minVal_ = x;
		maxVal_ = x;
	}

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
	int inner_res = *inner = x;
	int outer_res = *outer = inner_res;
	return outer_res;
}
