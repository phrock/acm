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

class FairWorkload
{ 
public: 
  int getMostWork(vector <int> folders, int workers);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 170; verify_case(0, Arg2, getMostWork(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 110; verify_case(1, Arg2, getMostWork(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = { 568, 712, 412, 231, 241, 393, 865, 287, 128, 457, 238, 98, 980, 23, 782 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 1785; verify_case(2, Arg2, getMostWork(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1000 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 1000; verify_case(3, Arg2, getMostWork(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = { 50, 50, 50, 50, 50, 50, 50 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 200; verify_case(4, Arg2, getMostWork(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {1,1,1,1,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 100; verify_case(5, Arg2, getMostWork(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = { 950, 650, 250, 250, 350, 100, 650, 150, 150, 700 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 950; verify_case(6, Arg2, getMostWork(Arg0, Arg1)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  FairWorkload ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

// vector<int> a;
// int n;
// int res;

// void dfs(int k, int m, int cnt)
// {
//   if (k==n-1) {
//     int x=0;
//     for (unsigned i=m; i<(a).size(); ++i) x+=a[i];
//     cnt=max(cnt, x);
//     res=min(res, cnt);
//     return;
//   }
//   for (int i=m+1; i<a.size(); ++i) {
//     int x=0;
//     for (int j=m; j<i; ++j) x+=a[j];
//     dfs(k+1, i, max(cnt, x));
//   }
// }

// int FairWorkload :: getMostWork(vector <int> folders, int workers)
// {
//   a=folders;
//   n=workers;
//   res=INT_MAX;
//   dfs(0, 0, 0);
//   return res;
// }

int FairWorkload :: getMostWork(vector <int> folders, int workers)
{
  int n=folders.size();
  int m=workers;
  vector< vector<int> > d(n+1, vector<int> (m+1, INT_MAX/2));
  d[0][0]=0;
  for (int i=1; i<=n; ++i)
    for (int j=1; j<=m; ++j) {
      for (int k=1; k<=i; ++k) {
	int x=0;
	for (int p=0; p<k; ++p) x+=folders[i-p-1];
	d[i][j]=min(d[i][j], max(x, d[i-k][j-1]));
      }
    }
  return d[n][m];
}
