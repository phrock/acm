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

class MarriageProblemRevised
{ 
public: 
  int neededMarriages(vector <string> preferences);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5();}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, neededMarriages(Arg0)); }
	void test_case_1() { string Arr0[] = {"100", "010", "001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, neededMarriages(Arg0)); }
	void test_case_2() { string Arr0[] = {"00", "00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, neededMarriages(Arg0)); }
	void test_case_3() { string Arr0[] = {"0001", "0001", "0001", "1111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, neededMarriages(Arg0)); }
	void test_case_4() { string Arr0[] = {"11101011","00011110","11100100","01010000","01000010","10100011","01110110","10111111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(4, Arg1, neededMarriages(Arg0)); }
	void test_case_5() { string Arr0[] = {"100000000000", "010000000000", "001000000000", "000100000000", "010010000000", "000001000000", "000000100000", "000000010000", "000000001000", "000000000100", "000000000010", "000000000001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(4, Arg1, neededMarriages(Arg0)); }

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
  MarriageProblemRevised ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

int MarriageProblemRevised :: neededMarriages(vector <string> preferences)
{
  int n=(int)(preferences).size(), m=(int)(preferences[0]).size();
  for (int i=0; i<n; ++i) {
    bool ok=false;
    for (int j=0; j<m; ++j) if (preferences[i][j]=='1') { ok=true; break; }
    if (!ok) return -1;
  }
  for (int i=0; i<m; ++i) {
    bool ok=false;
    for (int j=0; j<n; ++j) if (preferences[j][i]=='1') { ok=true; break; }
    if (!ok) return -1;
  }
  int res=INT_MAX;
  for (int i=0; i<(1<<n); ++i) {
    for (int j=0; j<(1<<m); ++j) {
      if (__builtin_popcount(i)+__builtin_popcount(j)>=res) continue;
      int x=i, y=j;
      for (int p=0; p<n; ++p) {
	if ((1<<p)&i) continue;
	for (int q=0; q<m; ++q) if (preferences[p][q]=='1' && (1<<q)&j) { x|=1<<p; break; }
	if (~x&(1<<p)) break;
      }
      if (x<(1<<n)-1) continue;
      for (int q=0; q<m; ++q) {
	if ((1<<q)&j) continue;
	for (int p=0; p<n; ++p) if (preferences[p][q]=='1' && (1<<p)&i) { y|=1<<q; break; }
	if (~y&(1<<q)) break;
      }
      if (y<(1<<m)-1) continue;
      res=min(res, __builtin_popcount(i)+__builtin_popcount(j));
    }
  }
  return res;
}
