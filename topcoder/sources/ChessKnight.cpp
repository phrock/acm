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

class ChessKnight
{ 
public: 
  double probability(int x, int y, int n);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 2; double Arg3 = 0.1875; verify_case(0, Arg3, probability(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 1; double Arg3 = 1.0; verify_case(1, Arg3, probability(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 10; double Arg3 = 0.0522148497402668; verify_case(2, Arg3, probability(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 3; int Arg2 = 50; double Arg3 = 8.356427906809618E-7; verify_case(3, Arg3, probability(Arg0, Arg1, Arg2)); }

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
  ChessKnight ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

double ChessKnight :: probability(int x, int y, int n)
{
  int tab[][2]={{-1, -2}, {1, -2}, {-1, 2}, {1, 2},
		{-2, -1}, {2, -1}, {-2, 1}, {2, 1}};
  double a[8][8];
  double b[8][8];
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  a[x-1][y-1]=1;
  for (int loop=0; loop<n; ++loop) {
    memset(b, 0, sizeof(b));
    for (int i=0; i<8; ++i)
      for (int j=0; j<8; ++j) {
	if (a[i][j]>0) {
	  for (int k=0; k<8; ++k) {
	    int x=i+tab[k][0], y=j+tab[k][1];
	    if (x>=0 && y>=0 && x<8 && y<8) b[x][y]+=(double)a[i][j]/8;
	  }
	}
      }
    memcpy(a, b, sizeof(a));
  }
  double res=0;
  for (int i=0; i<8; ++i)
    for (int j=0; j<8; ++j) res+=a[i][j];
  return res;
}
