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

class BagOfDevouring
{ 
public: 
  double expectedYield(vector <int> values, vector <int> weights);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5();  }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	// void test_case_0() { int Arr0[] = {100,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100,100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 150.0; verify_case(0, Arg2, expectedYield(Arg0, Arg1)); }
	 void test_case_0() { int Arr0[] = {2880, 3210, 3660, 5190, 520, 290, 7220, 1150, 720, 5210, 3980, 6150}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6400, 100, 600, 1500, 5200, 8100, 2200, 1500, 4000, 8500, 2200, 7900}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 150.0; verify_case(0, Arg2, expectedYield(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {100,200,300}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100,200,300}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 462.5; verify_case(1, Arg2, expectedYield(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {100,200,300}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {300,200,100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 470.8333333333333; verify_case(2, Arg2, expectedYield(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(3, Arg2, expectedYield(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {10,100,150,250,500,750,1000,2500,5000,7500,10000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100,200,300,400,500,1000,2000,1500,3000,6000,4000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 20622.364509064962; verify_case(4, Arg2, expectedYield(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {150, 140, 130, 120, 110, 100, 90, 80, 70, 60, 50, 40, 30, 20, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 20622.364509064962; verify_case(4, Arg2, expectedYield(Arg0, Arg1)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }
template<class T> inline void print(T A[], int n) { cout<<"{ "; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", ";} cout<<" }"<<endl; }
template<class T> inline void print2(T A[], int n, int m) { cout<<"{"<<endl; for (int i=0; i<n; ++i) {cout<<" { "; for (int j=0; j<m; ++j) { cout<<A[i][j]; if (j+1<m) cout<<", ";} cout<<" } "<<endl; } cout<<"}"<<endl; }

int main()
{
  BagOfDevouring ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

map<int, double> mm;

double helper(const vector<int> &values, const vector<int> &weights, int &mask, double p)
{
  if (((mm).find(mask)!=(mm).end())) return mm[mask]*p;
  double w=0;;
  for (int i=0; i<(int)(values).size(); ++i) if (!(mask & (1<<i))) w+=weights[i];
  double res=0;
  for (int i=0; i<(int)(values).size(); ++i)
    if (!(mask & (1<<i))) {
      double aux=0;
      aux+=values[i];
      mask^=1<<i;
      double tmp=0;
      for (int j=0; j<(int)(values).size(); ++j)
	if (!(mask & (1<<j))) {
	  mask^=1<<j;
	  tmp+=weights[j]/(w-weights[i]+100);
	  aux+=helper(values, weights, mask, (weights[j]/(w-weights[i]+100)));
	  mask^=1<<j;
	}
      aux+=helper(values, weights, mask, (1-tmp));
      mask^=1<<i;
      res=max(res, aux);
    }
  mm[mask]=res;
  return res*p;
}

double BagOfDevouring :: expectedYield(vector <int> values, vector <int> weights)
{
  mm.clear();
  int mask=0;
  double res=helper(values, weights, mask, 1);
  return res;
}
