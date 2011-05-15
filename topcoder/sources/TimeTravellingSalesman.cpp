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

class TimeTravellingSalesman
{ 
public: 
  long long determineCost(int N, vector <string> roads);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; string Arr1[] = {"0,1,1 0,2,1 1,2,2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 2LL; verify_case(0, Arg2, determineCost(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 6; string Arr1[] = {"0,1,2 1,4,2 4,3,3 2,4,4 0,5,3"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 14LL; verify_case(1, Arg2, determineCost(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; string Arr1[] = {"0,2,2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = -1LL; verify_case(2, Arg2, determineCost(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 4; string Arr1[] = {"1,0",",10","0 2,1",",584 3,2",",754"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1438LL; verify_case(3, Arg2, determineCost(Arg0, Arg1)); }

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
  TimeTravellingSalesman ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

long long TimeTravellingSalesman :: determineCost(int N, vector <string> roads)
{
  string s=accumulate((roads).begin(), (roads).end(), string());
  vector<vector<int> > g(N, vector<int>(N, -1));
    int a, b, cost;
    for (int j=0; j<(int)(s).size(); ++j) if (s[j]==',') s[j]=' ';
    stringstream is(s);
    while (is>>a>>b>>cost) g[a][b]=g[b][a]=cost;

  vector<int> v(N);
  vector<int> c(N, INT_MAX/2);
  c[0]=0;
  v[0]=1;
  set<pair<int, int> > st;
  st.insert(make_pair(0, 0));
  int res=0;
  while (!st.empty()) {
    pair<int, int> top=*st.begin();
    st.erase(st.begin());
    res+=top.first;
    int x=top.second;
    for (int i=0; i<N; ++i) {
      if (i!=x && g[x][i]!=-1) {
	if (g[x][i]<c[i]) {
	  if (((st).find(make_pair(c[i], i))!=(st).end())) st.erase(make_pair(c[i], i));
	  c[i]=g[x][i];
	  st.insert(make_pair(c[i], i));
	}
      }
    }
  }
  for (int i=0; i<N; ++i) if (c[i]==INT_MAX/2) return -1;
  return res;
}
