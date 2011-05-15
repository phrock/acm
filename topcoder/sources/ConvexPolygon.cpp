#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class ConvexPolygon
{ 
public: 
  double findArea(vector <int> x, vector <int> y);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.5; verify_case(0, Arg2, findArea(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {-10000,-10000,10000,10000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10000,-10000,-10000,10000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 4.0E8; verify_case(1, Arg2, findArea(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {100,80,30,-30,-80,-100,-80,-30,30,80}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,58,95,95,58,0,-58,-95,-95,-58}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 29020.0; verify_case(2, Arg2, findArea(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {-1646,-9172,-9830,-9802,-9749,-9474,-8668,-6832,120,8380,9338,9307,8042}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-9998,-8619,-7863,3976,4541,5975,8127,9500,9612,8734,5216,-9042,-9689}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 3.55115104E8; verify_case(3, Arg2, findArea(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {-6010,-7937,-8782,-9506,-9654,-9852,-9854,-9998,-9999,-9996,-9901,-9811,
-9444,-8798,-8580,-2085,6842,8339,9827,9946,9993,9959,9940,9855,9657,
8504,8262,7552,6326,5537,4723}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-9976,-9947,-9873,-9739,-9654,-8501,-8475,-5009,475,4926,7078,8673,9417,
9785,9820,9974,9986,9979,9862,9211,-5070,-6599,-7121,-8624,-8912,-9710,
-9766,-9863,-9914,-9941,-9962}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 3.939960635E8; verify_case(4, Arg2, findArea(Arg0, Arg1)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  ConvexPolygon ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

double heron(double a, double b, double c)
{
  double p=(a+b+c)/2;
  return sqrt(p*(p-a)*(p-b)*(p-c));
}

double ConvexPolygon :: findArea(vector <int> x, vector <int> y)
{
  vector<double> a, b;
  for (unsigned i=0; i<(x).size(); ++i) a.push_back(x[i]);
  for (unsigned i=0; i<(y).size(); ++i) b.push_back(y[i]);
  double res=0;
  // for (unsigned i=2; i<(a).size(); ++i) {
  //   double l1=sqrt((a[i]-a[i-1])*(a[i]-a[i-1])+(b[i]-b[i-1])*(b[i]-b[i-1]));
  //   double l2=sqrt((a[i]-a[0])*(a[i]-a[0])+(b[i]-b[0])*(b[i]-b[0]));
  //   double l3=sqrt((a[i-1]-a[0])*(a[i-1]-a[0])+(b[i-1]-b[0])*(b[i-1]-b[0]));
  //   res+=heron(l1, l2, l3);
  // }
  for (unsigned i=0; i<(a).size(); ++i) {
    if (i==a.size()-1) res+=a[i]*b[0]-a[0]*b[i];
    else res+=a[i]*b[i+1]-a[i+1]*b[i];
  }
  res/=2;
  return abs(res);
}
