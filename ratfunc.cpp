#include "ratfunc.h"

//************************************
// Method:    ratfunc
// FullName:  ratfunc::ratfunc
// Access:    public 
// Description: A ratfunc constructor 
// Parameter: const polynom & polimechani
// Parameter: const polynom & polimone
//************************************
ratfunc::ratfunc(const polynom& polimechani, const polynom& polimone) : a_(polimone),b_(polimechani) {
	firstinput = false;
}

ratfunc::~ratfunc()
{

}

//************************************
// Method:    operator<<
// FullName:  ratfunc::operator<<
// Access:    public 
// Description: inherited from func. Adds a point 
// Returns:   func &
// Parameter: const int & x
//************************************
func & ratfunc::operator<<(const int & x)
{
	int bottom = b_ = x;
	if (bottom == 0) //check exception
	{
		mathexception devzero;
		throw devzero;
	}

	if (!firstinput) {
		firstinput = true;
		minVal_ = x;
		maxVal_ = x;
	}

	int res = 0;
	int top = a_ = x;
	

	res = top/bottom;
	fmap_[x] = res;

	if (x < minVal_) minVal_ = x;
	if (x > maxVal_) maxVal_ = x;

	return *this;
}

//************************************
// Method:    operator=
// FullName:  ratfunc::operator=
// Access:    virtual public 
// Description: Assignment operator
// Returns:   ratfunc&
// Qualifier:
// Parameter: const ratfunc &
//************************************
ratfunc& ratfunc::operator=(const ratfunc& rat)
{
	if (this != &rat) {
		if (&this->a_ != &(rat.a_))
			a_ = rat.a_;
		if(&this->b_ != &(rat.b_))
			b_ = rat.b_;
	}

	return *this;
}

//************************************
// Method:    operator=
// FullName:  ratfunc::operator=
// Access:    virtual public 
// Description: Calculates f(x). doesn't store the point.
// Returns:   int
// Parameter: const int &
//************************************
int ratfunc::operator=(const int& x)
{
	int bottom = b_ = x;
	if (bottom == 0) //check exception
	{
		mathexception devzero;
		throw devzero;
	}

	int res = 0;
	int top = a_ = x;

	res = top/bottom;

	return res;
}

//************************************
// Method:    operator+
// FullName:  ratfunc::operator+
// Access:    public 
// Description: adds two rational functions.
// Returns:   ratfunc
// Qualifier: const
// Parameter: const ratfunc & secondratfunc
//************************************
ratfunc ratfunc::operator+(const ratfunc &secondratfunc) const{
	polynom mechani = ((*this).b_)*(secondratfunc.b_);
	polynom mone1 = ((*this).a_)*(secondratfunc.b_);
	polynom mone2 = ((*this).b_)*(secondratfunc.a_);

	polynom addtwomone = mone1 + mone2;

	ratfunc newratfunc = ratfunc(mechani, addtwomone);

	return newratfunc;
}

//************************************
// Method:    operator-
// FullName:  ratfunc::operator-
// Access:    public 
// Description: creates a new rational function by subtraction
// Returns:   ratfunc
// Qualifier: const
// Parameter: const ratfunc & secondratfunc
//************************************
ratfunc ratfunc::operator-(const ratfunc &secondratfunc) const{
	polynom mechani = ((*this).b_)*(secondratfunc.b_);
	polynom mone1 = ((*this).a_)*(secondratfunc.b_);
	polynom mone2 = ((*this).b_)*(secondratfunc.a_);

	polynom addtwomone = mone1 - mone2;

	ratfunc newratfunc = ratfunc(mechani, addtwomone);

	return newratfunc;
}

//************************************
// Method:    operator*
// FullName:  ratfunc::operator*
// Access:    public 
// Description: creates a new rational function by multiplication
// Returns:   ratfunc
// Qualifier: const
// Parameter: const ratfunc & secondratfunc
//************************************
ratfunc ratfunc::operator*(const ratfunc &secondratfunc)const {
	polynom mone = ((*this).a_)*(secondratfunc.a_);
	polynom mechani = ((*this).b_)*(secondratfunc.b_);

	ratfunc newratfunc = ratfunc(mechani, mone);

	return newratfunc;
}

//************************************
// Method:    operator/
// FullName:  ratfunc::operator/
// Access:    public 
// Description: creates a new rational function by quotient of two rational functions  
// Returns:   ratfunc
// Qualifier: const
// Parameter: const ratfunc & secondratfunc
//************************************
ratfunc ratfunc::operator/(const ratfunc &secondratfunc)const {
	polynom mone = ((*this).a_)*(secondratfunc.b_);
	polynom mechani = ((*this).b_)*(secondratfunc.a_);
	ratfunc newratfunc = ratfunc(mechani, mone);
	return newratfunc;
}

//************************************
// Method:    Derivative
// FullName:  ratfunc::Derivative
// Access:    public 
// Description: creates a new rational function by deriving the original rational function
// Returns:   ratfunc
// Qualifier: const
//************************************
ratfunc ratfunc::Derivative()const {
	polynom mone1 = (((*this).a_).Derivative())*((*this).b_);
	polynom mone2 = (((*this).a_))*(((*this).b_).Derivative());
	polynom mone3 = mone1 - mone2;
	polynom mechani = ((*this).b_)*((*this).b_);
	ratfunc newratfunc = ratfunc(mechani, mone3);
	return newratfunc;
}

//************************************
// Method:    print
// FullName:  ratfunc::print
// Access:    virtual public 
// Description: prints the rational function and it's derivative.
// Returns:   void
// Qualifier: const
// Parameter: ostream & os
//************************************
void ratfunc::print(ostream & os) const
{
	ratfunc derfunc = Derivative();

	//printing ratfunc coefficients.
	os << "(";
	a_.printcoefs(os);
	os << ")/"<< "(";
	b_.printcoefs(os); 
	os<< ")"<<endl;

	//printing derivative  coefs
	os << "Derivative: ";
	os << "(";
	derfunc.a_.printcoefs(os);
	os << ")/" << "(";
	derfunc.b_.printcoefs(os);
	os << ")" << endl;

	//plot the ratfunc
	plot(os);
	
}
