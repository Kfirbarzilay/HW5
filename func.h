#ifndef _FUNC_
#define _FUNC_
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
#include "mathexception.h"
using std::map;
using std::ostream;


class func {
public:
friend ostream& operator<<(ostream& o, const func& f);
virtual func & operator<<(const int& x)=0;
virtual int operator=(const int&) = 0;
protected:
int maxVal_; //maximum of all inputs
int minVal_; //minimum of all inputs
bool firstinput;
map<int,int> fmap_; //holds inputs and corresponding outputs
void plot(ostream& os) const ; //plot fmap_
virtual void print(ostream& os)const = 0;
};


#endif
