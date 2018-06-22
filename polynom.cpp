#include "polynom.h"

//constructor
polynom::polynom(int n, int * arr) : n_(n) 
{
	minVal_ = 0;
	maxVal_ = 0;
	coefs_ = new int[n_ + 1];
	for (int i = 0; i <= n_ ; ++i)
	{
		coefs_[i] = arr[i];
	}
}

polynom::~polynom()
{
	delete[]coefs_;
}

//copy constructor
polynom::polynom(const polynom& poli):	n_(poli.n_)
{
	coefs_ = new int[n_ + 1];
	for (int i = 0; i <= n_; ++i) {
		coefs_[i] = poli.coefs_[i];
	}

	//min and max inputs values
	minVal_ = poli.minVal_;
	maxVal_ = poli.maxVal_;
}

polynom & polynom::operator=(const polynom & poly)
{
	if (this != &poly) {
		n_ = poly.n_;
		delete[]coefs_;
		coefs_ = new int[n_ + 1];
		for (int i = 0; i <= n_; ++i)
		{
			coefs_[i] = poly.coefs_[i];
		}
	}

	return *this;
}


int polynom::operator=(const int& x)
{
	//res holds the final result. power is the computation of power of x in each rank
	int power = x, res = 0;

	for (int i = 1; i <= n_; i++)
	{
		//computing the power of x
		for (int j = 1; j < i; ++j)
		{
			power *= power;
		}

		res += this->coefs_[i] * power;
		power = x;
	}

	//adding const coefficient
	res += coefs_[0];

	//adding the point
	return res;
}

func & polynom::operator<<(const int & x)		//TODO: check if math::pow is needed.
{
	//res holds the final result. power is the computation of power of x in each rank
	int power = x, res = 0;

	for (int i = 1; i <= n_; i++)
	{
		//computing the power of x
		for (int j = 1; j < i; ++j)
		{
			power *= power;
		}

		res += this->coefs_[i] * power; 
		power = x;
	}
	
	//adding const coefficient
	res += coefs_[0];

	//adding the point
	fmap_[x] = res;

	//checking for maximum values.
	if (x < minVal_) minVal_ = x;
	if (x > maxVal_) maxVal_ = x;
	return (*this);
}


//addition overload
polynom  polynom::operator+(const polynom & secondpoly)const
{
	int counter = 0;
	if (n_ == secondpoly.n_) //if they are the same rank the new polynom can ve shorter
	{
		for (int i = 0; i <= n_; ++i)
		{
			if (coefs_[n_ - i] == (-1)*secondpoly.coefs_[n_ - i])counter++;
			else break;
		}
	}
	
	int n = (*this).n_ > secondpoly.n_ ? (*this).n_-counter : secondpoly.n_-counter; //max len polynom order
	int* arr = new int[n + 1];
	for (int i = 0; i <= n; ++i)arr[i] = 0;

	polynom add_Pol(n, arr);

	//copying the first array and adding the second one
	for (int i = 0; i <= (*this).n_; ++i) add_Pol.coefs_[i] += (*this).coefs_[i];
	for (int i = 0; i <= secondpoly.n_; ++i) add_Pol.coefs_[i] += secondpoly.coefs_[i];
	
	delete[]arr;

	return add_Pol;
}

//subtraction overload
polynom  polynom::operator-(const polynom & secondpoly)const
{
	int counter = 0;
	if (n_ == secondpoly.n_) //if they are the same rank the new polynom can ve shorter
	{
		for (int i = 0; i <= n_; ++i)
		{
			if (coefs_[n_ - i] == secondpoly.coefs_[n_ - i])counter++;
			else break;
		}
	}

	int n = (*this).n_ > secondpoly.n_ ? (*this).n_ - counter : secondpoly.n_ - counter; //max len polynom order
	int* arr = new int[n + 1];
	for (int i = 0; i <= n; ++i)arr[i] = 0;

	polynom sub_Pol(n, arr);

	//copying the first array and adding the second one
	for (int i = 0; i <= (*this).n_; ++i) sub_Pol.coefs_[i] += (*this).coefs_[i];
	for (int i = 0; i <= secondpoly.n_; ++i) sub_Pol.coefs_[i] -= secondpoly.coefs_[i];

	delete[]arr;

	return sub_Pol;
	// TODO: insert return statement here
}

polynom  polynom::operator*(const polynom & secondpoly)const
{
	int n = (*this).n_ + secondpoly.n_; //max len polynom order
	int *arr = new int[n + 1]; //allocating memory
	for (int i = 0; i <= n; ++i)arr[i] = 0;

	

	//multiplying the elements
	for (int i = 0; i <= (*this).n_; ++i)
	{
		for (int j = 0; j <= secondpoly.n_; ++j)
		{
			arr[i + j] += (*this).coefs_[i] * secondpoly.coefs_[j];
		}
	}

	//check actual polynom order
	int counter = 0;
	for (int i = 0; i <= n; ++i)
	{
		if (arr[n - i] == 0)counter++;
		
		else break;
	}

	//creating the new polynom
	polynom mul_poly(n - counter, arr);

	delete[]arr;

	return mul_poly;
}

polynom polynom::Derivative()const {
	//polynom is const (rank = 0)
	if (n_ == 0) {
		int *coefs = new int[1];
		*coefs = 0;
		polynom derpoli(0, coefs);
		delete[]coefs;
		return derpoli;
	}

	//polynom isn't const
	int * newArr = new int[n_]; //one less coefficient.
	for (int i = 0; i < n_; i++) {
		newArr[i] = ((i + 1)*coefs_[i + 1]);
	}

	//check order of polynom
	int counter = 0;
	for (int i = 0; i <= n_; ++i)
	{
		if (newArr[n_ - 1 - i] == 0)counter++;
		else break;
	}

	polynom derivpoli(n_ - 1 - counter, newArr); 
	delete[] newArr;
	return derivpoli;
}

polynom polynom::Integral()const
{
	int *coefs = new int[n_ + 2];    //when integrating number of coefs is (n+1)+1

	coefs[0] = 0; //first coefficient is always zero

	//integrating
	for(int i = 1; i <= n_+1; ++i)
	{
		coefs[i] = coefs_[i - 1] / i;
	}


	//check order of polynom
	int counter = 0;
	for (int i = 0; i <= n_; ++i)
	{
		if (coefs_[n_ + 1 - i] == 0)counter++;
		else break;
	}
	
	//creating the polynom
	polynom new_poly(n_ + 1 - counter, coefs);

	delete[]coefs;

	return new_poly;
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


void polynom::print(ostream & os)const
{
	//derivative and the integral
	polynom I = Integral();
	polynom d = Derivative();
	

	//printing polynom coefs.
	printcoefs(os);
	os <<endl;

	//printing derivative and Integral coefs
	os << "Derivative: ";
	d.printcoefs(os);
	os << endl;
	
	os << "Integral: ";
	I.printcoefs(os);
	os << "+C" << endl;

	//plot the function points inserted.
	plot(os);
}

int polynom::getfuncval(const int & x)const
{
	int val = fmap_.at(x);
	return val ;
}

