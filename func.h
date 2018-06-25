#ifndef _FUNC_
#define _FUNC_
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
#include "mathexception.h"
using std::map;
using std::ostream;

//an abstract class of functions of all types. Holds inserted points of derived functions.
class func {
public:
//************************************
// Method:    operator<<
// FullName:  func::operator<<
// Access:    virtual public 
// Description: supports concatenation of functions to prints. 
//				called from main.
// Returns:   friend ostream&
// Parameter: ostream & o
// Parameter: const func & f
//************************************
friend ostream& operator<<(ostream& o, const func& f);

virtual ~func();

//************************************
// Method:    operator<<
// FullName:  func::operator<<
// Access:    virtual public 
// Description: inserts a point to the map after calculating f(x) (fmap_).
// Returns:   func &
// Parameter: const int & x
//************************************
virtual func & operator<<(const int& x)=0;

//************************************
// Method:    operator=
// FullName:  func::operator=
// Access:    virtual public 
// Description: Calculating f(x) without inserting point to map
// Returns:   int
// Qualifier: = 0
// Parameter: const int &
//************************************
virtual int operator=(const int&) = 0;

protected:
int maxVal_; //maximum of all inputs
int minVal_; //minimum of all inputs
bool firstinput;
map<int,int> fmap_; //holds inputs and corresponding outputs

//************************************
// Method:    plot
// FullName:  func::plot
// Access:    protected 
// Description: plotting inserted points of fmap_
// Returns:   void
// Qualifier: const
// Parameter: ostream & os
//************************************
void plot(ostream& os) const ; //plot fmap_

//************************************
// Method:    print
// FullName:  func::print
// Access:    virtual protected 
// Description: pure virtual method. used by derived classes.
// Returns:   void
// Qualifier: const
// Parameter: ostream & os
//************************************
virtual void print(ostream& os)const = 0;
};


#endif
