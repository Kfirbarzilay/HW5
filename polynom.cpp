#include "polynom.h"

//constructor
polynom::polynom(int n, int * arr) : n_(n), coefs_(arr) { minVal_ = 0; maxVal_ = 0; }

//copy constructor
polynom::polynom(const polynom & poli):	n_(poli.n_)
{
	coefs_ = new int[n_ + 1];
	for (int i = 0; i <= n_; ++i) {
		coefs_[i] = poli.coefs_[i];
	}

	//min and max inputs values
	minVal_ = poli.minVal_;
	maxVal_ = poli.maxVal_;
}


func & polynom::operator<<(const int & x)		//TODO: check if math::pow is needed.
{
	//res holds the final result. power is the computation of power of x in each rank
	int power = x, res = 0;

	for (int i = 0; i <= n_; i++)
	{
		//computing the power of x
		for (int j = 0; j < i; ++j)
		{
			power *= power;
		}

		res += this->coefs_[i] * power;  
	}

	//adding the point
	fmap_[x] = res;

	//checking for maximum values.
	if (x < minVal_) minVal_ = x;
	if (x > maxVal_) maxVal_ = x;
	return (*this);
}


//addition overload
polynom & polynom::operator+(const polynom & secondpoly)
{
	int n = (*this).n_ > secondpoly.n_ ? (*this).n_ : secondpoly.n_; //max len polynom order
	int* arr = new int[n + 1];
	arr = { 0 };
	polynom add_Pol(n, arr);

	//copying the first array and adding the second one
	for (int i = 0; i <= (*this).n_; ++i) add_Pol.coefs_[i] += (*this).coefs_[i];
	for (int i = 0; i <= secondpoly.n_; ++i) add_Pol.coefs_[i] += secondpoly.coefs_[i];
	return add_Pol;
}

//substraction overload
polynom & polynom::operator-(const polynom & secondpoly)
{
	int n = (*this).n_ > secondpoly.n_ ? (*this).n_ : secondpoly.n_; //max len polynom order
	int* arr = new int[n + 1];
	arr = { 0 };
	polynom sub_Pol(n, arr);

	//copying the first array and adding the second one
	for (int i = 0; i <= (*this).n_; ++i) sub_Pol.coefs_[i] += (*this).coefs_[i];
	for (int i = 0; i <= secondpoly.n_; ++i) sub_Pol.coefs_[i] -= secondpoly.coefs_[i];
	return sub_Pol;
	// TODO: insert return statement here
}

polynom & polynom::operator*(const polynom & secondpoly)
{
	int n = (*this).n_ + secondpoly.n_; //max len polynom order
	int *arr = new int[n + 1]; //allocating memory
	arr = { 0 };

	//creating the new polynom
	polynom mul_poly(n, arr);

	//multiplying the elements
	for (int i = 0; i <= (*this).n_; ++i)
	{
		for (int j = 0; j <= secondpoly.n_; ++j)
		{
			mul_poly.coefs_[i + j] += (*this).coefs_[i] * secondpoly.coefs_[j];
		}
	}
	return mul_poly;
}

polynom& polynom::Derivative() {
	//polynom is const (rank = 0)
	if (n_ == 0) {
		int *coefs = new int[1];
		*coefs = 0;
		polynom derpoli(0, coefs);
		return derpoli;
	}

	//polynom isn't const
	int * newArr = new int[n_]; //size of n-1
	for (int i = 0; i < n_; i++) {
		newArr[i] = ((i + 1)*coefs_[i + 1]);
	}
	polynom derivpoli(n_ - 1, newArr);
	return derivpoli;
}

polynom & polynom::Integral()
{
	int *coefs = new int[n_ + 2];    //when integrating number of coefs is (n+1)+1

	coefs[0] = 0; //first coefficient is always zero

	//integrating
	for(int i = 1; i <= n_+1; ++i)
	{
		coefs[i] = coefs_[i - 1] / i;
	}

	//creating the polynom
	polynom integ_Poly(n_ + 2, coefs);
	return integ_Poly;
}


void polynom::printcoefs(ostream& os)  const {
  int allZero = 1;
  for (int i = n_ ; i>=0; i--) {
    if (coefs_[i]>0) {
      allZero = 0;
      if(i!=n_){
	os << "+";
      }
      if (coefs_[i]!=1 || i==0){
	os << coefs_[i];
      }
      if(i>0) {
	os << "x";
	if (i>1) 
	  os << "^" << i ;
      }
    }
    else if(coefs_[i]<0) {
      allZero = 0;
      if (coefs_[i]!=-1 || i==0){
	os << coefs_[i];
      }
      else 
	os << "-";
      if(i>0) {
	os << "x";
	if (i>1) 
	  os << "^" << i ;
      }
    }
    else if(i==0 && allZero == 1){ //zero polynom
        os << "0";
	continue;
    }
  }
}

void polynom::plot(ostream & os) const
{
	printcoefs(os);
	func::plot(os);
}
