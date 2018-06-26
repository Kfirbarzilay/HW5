#include "compfunc.h"

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__)
#define new DBG_NEW
#endif
#endif

//************************************
// Method:    compfunc
// FullName:  compfunc::compfunc
// Access:    public 
// Description: a compfunc constructor
// Parameter: func &
// Parameter: func &
//************************************
compfunc::compfunc( func& t,  func& z)
{
	outer = &t;
	inner = &z;
	firstinput = false;
}

compfunc::~compfunc()
{

}

//************************************
// Method:    operator<<
// FullName:  compfunc::operator<<
// Access:    virtual public 
// Description: inherited from func. adds a point to fmap_
// Returns:   func &
// Parameter: const int & x
//************************************
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

//************************************
// Method:    print
// FullName:  compfunc::print
// Access:    virtual public 
// Description: prints the function
// Returns:   void
// Qualifier: const
// Parameter: ostream & os
//************************************
void compfunc::print(ostream& os) const
{
	os << endl;
	//plot the function points inserted.
	plot(os);
}

//************************************
// Method:    operator=
// FullName:  compfunc::operator=
// Access:    virtual public 
// Description: calculates f(x). doesn't store the point
// Returns:   int
// Parameter: const int &
//************************************
int compfunc::operator=(const int&x)//won't use it
{
	int inner_res = *inner = x;
	int outer_res = *outer = inner_res;
	return outer_res;
}
