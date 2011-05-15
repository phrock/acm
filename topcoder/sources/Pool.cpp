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

class Pool
{ 
public: 
  int rackMoves(vector <int> triangle);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {6, 12, 14, 1, 8, 2, 11, 3, 9, 4, 7, 13, 5, 15, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, rackMoves(Arg0)); }
	void test_case_1() { int Arr0[] = {2, 10, 7, 1, 8, 12, 6, 11, 4, 9, 13, 3, 14, 15, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, rackMoves(Arg0)); }
	void test_case_2() { int Arr0[] = {8, 15, 9, 4, 10, 6, 11, 3, 14, 7, 2, 1, 13, 12, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, rackMoves(Arg0)); }
	void test_case_3() { int Arr0[] = {15, 5, 8, 13, 2, 14, 10, 3, 4, 6, 7, 9, 1, 12, 11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, rackMoves(Arg0)); }
	void test_case_4() { int Arr0[] = {1, 5, 15, 6, 10, 9, 11, 13, 7, 4, 3, 8, 2, 12, 14}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(4, Arg1, rackMoves(Arg0)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void printv(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  Pool ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

int Pool :: rackMoves(vector <int> triangle)
{
  int a[]={1, 0, 0, 1, 8, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0};
  vector<int> v1(a, a+sizeof(a)/sizeof(a[0]));
  vector<int> v2=v1;
  for (int i=0; i<(int)(v2).size(); ++i) if (v2[i]!=(int)8) v2[i]^=1;
  int p=0, q=0;
  for (int i=0; i<(int)(triangle).size(); ++i)
    if (triangle[i]<8) triangle[i]=0;
    else if (triangle[i]>8) triangle[i]=1;
  if (triangle[4]!=8) p++, q++;
  for (int i=0; i<(int)(triangle).size(); ++i) {
    if (triangle[i]!=v1[i]) p++;
    if (triangle[i]!=v2[i]) q++;
  }
  return min(p/2, q/2);
}
