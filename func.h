#ifndef _F
#define _F
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>

using std::map;
using std::ostream;


class func {
public:
friend ostream& operator<<(ostream& o, const func& f);
virtual func & operator<<(const int& x) = 0;

 protected:
   
  int maxVal_; //maximum of all inputs
  int minVal_; //minimum of all inputs
  map<int,int> fmap_; //holds inputs and corresponding outputs
  void plot(ostream& os) const ; //plot fmap_
};


#endif
