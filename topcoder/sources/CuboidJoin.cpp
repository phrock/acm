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

class CuboidJoin
{ 
public: 
  long long totalVolume(vector <int> cuboids);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0,0,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(0, Arg1, totalVolume(Arg0)); }
	void test_case_1() { int Arr0[] = {0,0,0,1,1,1,1,1,1,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2LL; verify_case(1, Arg1, totalVolume(Arg0)); }
	void test_case_2() { int Arr0[] = {0,0,0,4,4,4,0,0,0,1,1,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 64LL; verify_case(2, Arg1, totalVolume(Arg0)); }
	void test_case_3() { int Arr0[] = {-5000,-5000,-5000,5000,5000,5000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1000000000000LL; verify_case(3, Arg1, totalVolume(Arg0)); }
	void test_case_4() { int Arr0[] = {0,0,0,1,2,3,5,5,5,6,6,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 7LL; verify_case(4, Arg1, totalVolume(Arg0)); }
	void test_case_5() { int Arr0[] = {}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(5, Arg1, totalVolume(Arg0)); }
	void test_case_6() { int Arr0[] = {0,0,0,1,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(6, Arg1, totalVolume(Arg0)); }
	void test_case_7() { int Arr0[] = {-275, -1020, -2918, 921, 2673, 3863, 497, -3921, -1831, 3059, 618, 811, -3106, -1159, -2082, 996, 3280, 3052, 4387, 1735, 244, 4469, 4692, 3278, -369, -366, 2870, 968, -91, 3502}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 129892376024LL; verify_case(6, Arg1, totalVolume(Arg0)); }

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
  CuboidJoin ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

long long CuboidJoin :: totalVolume(vector <int> cuboids)
{
  int n=(int)(cuboids).size()/6;
  vector<vector<long long> > v(n, vector<long long>(6));
  for (int i=0; i<n; ++i)
    for (int j=0; j<6; ++j) v[i][j]=cuboids[i*6+j];
  set<long long> sx, sy, sz;
  for (int i=0; i<(int)(v).size(); ++i) {
    sx.insert(v[i][0]); sx.insert(v[i][3]);
    sy.insert(v[i][1]); sy.insert(v[i][4]);
    sz.insert(v[i][2]); sz.insert(v[i][5]);
  }
  vector<long long> x((sx).begin(), (sx).end()), y((sy).begin(), (sy).end()), z((sz).begin(), (sz).end());
  #ifdef DEBUG
  print(x); print(y); print(z);  
  #endif
  long long res=0;
  for (int i=1; i<(int)(x).size(); ++i)
    for (int j=1; j<(int)(y).size(); ++j)
      for (int k=1; k<(int)(z).size(); ++k) {
	for (int l=0; l<(int)(v).size(); ++l) {
	  if ((x[i-1]>=v[l][0] && x[i]<=v[l][3]) && (y[j-1]>=v[l][1] && y[j]<=v[l][4]) &&
	      (z[k-1]>=v[l][2] && z[k]<=v[l][5])) {
	    res+=(x[i]-x[i-1])*(y[j]-y[j-1])*(z[k]-z[k-1]);
	    break;
	  }
	}
      }
  return res;
}
