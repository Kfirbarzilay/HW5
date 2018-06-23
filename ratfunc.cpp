#include "ratfunc.h"

// constructor 
ratfunc::ratfunc(const polynom& polimechani, const polynom& polimone) :b_(polimechani), a_(polimone) {
	firstinput = false;
}


func & ratfunc::operator<<(const int & x)
{
	if ((b_ = x) == 0) //check exception
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
	(*this).a_ << x;
	(*this).b_ << x;

	res = a_.getfuncval(x)/b_.getfuncval(x);
	fmap_[x] = res;

	if (x < minVal_) minVal_ = x;
	if (x > maxVal_) maxVal_ = x;

	return *this;
}

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

int ratfunc::operator=(const int& x)
{
	int res = 0;
	int top = (*this).a_ = x;
	int bottom = (*this).b_ = x;

	if (bottom == 0) {	//check exception
		mathexception devzero;
		throw devzero;
	}
	res = top/bottom;

	return res;
}

// + operator
ratfunc ratfunc::operator+(const ratfunc &secondratfunc) const{
	polynom mechani = ((*this).b_)*(secondratfunc.b_);
	polynom mone1 = ((*this).a_)*(secondratfunc.b_);
	polynom mone2 = ((*this).b_)*(secondratfunc.a_);

	polynom addtwomone = mone1 + mone2;

	ratfunc newratfunc = ratfunc(mechani, addtwomone);

	return newratfunc;
}

ratfunc ratfunc::operator-(const ratfunc &secondratfunc) const{
	polynom mechani = ((*this).b_)*(secondratfunc.b_);
	polynom mone1 = ((*this).a_)*(secondratfunc.b_);
	polynom mone2 = ((*this).b_)*(secondratfunc.a_);

	polynom addtwomone = mone1 - mone2;

	ratfunc newratfunc = ratfunc(mechani, addtwomone);

	return newratfunc;
}

ratfunc ratfunc::operator*(const ratfunc &secondratfunc)const {
	polynom mone = ((*this).a_)*(secondratfunc.a_);
	polynom mechani = ((*this).b_)*(secondratfunc.b_);

	ratfunc newratfunc = ratfunc(mechani, mone);

	return newratfunc;
}

ratfunc ratfunc::operator/(const ratfunc &secondratfunc)const {
	polynom mone = ((*this).a_)*(secondratfunc.b_);
	polynom mechani = ((*this).b_)*(secondratfunc.a_);
	ratfunc newratfunc = ratfunc(mechani, mone);
	return newratfunc;
}

ratfunc ratfunc::Derivative()const {
	polynom mone1 = (((*this).a_).Derivative())*((*this).b_);
	polynom mone2 = (((*this).a_))*(((*this).b_).Derivative());
	polynom mone3 = mone1 - mone2;
	polynom mechani = ((*this).b_)*((*this).b_);
	ratfunc newratfunc = ratfunc(mechani, mone3);
	return newratfunc;
}

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
