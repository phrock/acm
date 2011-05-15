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

class ContinuedFractions
{ 
public: 
  vector <int> squareRoot(int n);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = { 1,  2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, squareRoot(Arg0)); }
	void test_case_1() { int Arg0 = 41; int Arr1[] = { 6,  2,  2,  12 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, squareRoot(Arg0)); }
	void test_case_2() { int Arg0 = 63; int Arr1[] = { 7,  1,  14 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, squareRoot(Arg0)); }
	void test_case_3() { int Arg0 = 158; int Arr1[] = { 12,  1,  1,  3,  12,  3,  1,  1,  24 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, squareRoot(Arg0)); }
	void test_case_4() { int Arg0 = 512; int Arr1[] = { 22,  1,  1,  1,  2,  6,  11,  6,  2,  1,  1,  1,  44 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, squareRoot(Arg0)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  ContinuedFractions ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

vector <int> ContinuedFractions :: squareRoot(int n)
{
  int a=sqrt(n);
  vector<int> res;
  res.push_back(a);
  set<int> st;
  int x=n;
  int y=a;
  int z=1;
  int starty=y;
  int startz=z;
  while (true) {
    // cout<<x<<" "<<y<<" "<<z<<" "<<" "<<endl;
    int p=x-y*y;
    p/=z;
    int tmp=(sqrt(x)+y)/p;
    // cout<<tmp<<" "<<p<<endl;
    res.push_back(tmp);
    y=tmp*p-y;
    z=p;
    // cout<<x<<" "<<y<<" "<<z<<" "<<tmp<<endl;
    if (y==starty && z==startz) break;
  }
  return res;
}
