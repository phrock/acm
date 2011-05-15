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

class BoxLoader
{ 
public: 
  int mostItems(int boxX, int boxY, int boxZ, int itemX, int itemY, int itemZ);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 100; int Arg1 = 98; int Arg2 = 81; int Arg3 = 3; int Arg4 = 5; int Arg5 = 7; int Arg6 = 7560; verify_case(0, Arg6, mostItems(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 10; int Arg3 = 9; int Arg4 = 9; int Arg5 = 11; int Arg6 = 0; verify_case(1, Arg6, mostItems(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 201; int Arg1 = 101; int Arg2 = 301; int Arg3 = 100; int Arg4 = 30; int Arg5 = 20; int Arg6 = 100; verify_case(2, Arg6, mostItems(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 913; int Arg1 = 687; int Arg2 = 783; int Arg3 = 109; int Arg4 = 93; int Arg5 = 53; int Arg6 = 833; verify_case(3, Arg6, mostItems(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { int Arg0 = 6; int Arg1 = 5; int Arg2 = 4; int Arg3 = 3; int Arg4 = 2; int Arg5 = 1; int Arg6 = 20; verify_case(4, Arg6, mostItems(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

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
  BoxLoader ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

int BoxLoader :: mostItems(int boxX, int boxY, int boxZ, int itemX, int itemY, int itemZ)
{
  vector<int> a(3);
  a[0]=itemX; a[1]=itemY; a[2]=itemZ;
  sort((a).begin(), (a).end());
  int res=0;
  do {
    // int tmp=boxX/a[0];
    // tmp*= boxY/a[1];
    // tmp*=boxZ/a[2];
    // res=max(res, tmp);
    // #ifdef DEBUG
    // print(a);
    // cout<<tmp<<endl;
    // #endif
    res=max(res, (boxX/a[0])*(boxY/a[1])*(boxZ/a[2]));
  } while (next_permutation((a).begin(), (a).end()));
  return res;
}
