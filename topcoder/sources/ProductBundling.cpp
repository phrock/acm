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

class ProductBundling
{ 
public: 
  int howManyBundles(vector <string> data);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"11100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, howManyBundles(Arg0)); }
	void test_case_1() { string Arr0[] = {"1010",
 "1100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, howManyBundles(Arg0)); }
	void test_case_2() { string Arr0[] = {"1100000000",
 "1100000000",
 "0011000000",
 "0011000000",
 "0000110000",
 "0000110000",
 "0000001100",
 "0000001100",
 "0000000011",
 "0000000011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(2, Arg1, howManyBundles(Arg0)); }

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
  ProductBundling ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 
const int M=50;
int root[M+5];
int rank[M+5];

void initSet()
{
  for (int i=0; i<=M; ++i) root[i]=i, rank[i]=1;
}

int findRoot(int x)
{
  if (root[x]!=x) root[x]=findRoot(root[x]);
  return root[x];
}

void mergeDisjointSet(int a, int b)
{
  int ra=findRoot(a), rb=findRoot(b);
  if (rank[ra]>rank[rb]) root[rb]=ra, rank[ra]++;
  else root[ra]=rb, rank[rb]++;
}

int ProductBundling :: howManyBundles(vector <string> data)
{
  initSet();
  int n=(int)(data[0]).size();
  for (int i=0; i<n; ++i)
    for (int j=i+1; j<n; ++j) {
      bool ok=true;
      for (int k=0; k<(int)(data).size(); ++k)
	if (data[k][i]!=data[k][j]) { ok=false; break; }
      if (ok) mergeDisjointSet(i, j);
    }
  int res=0;
  for (int i=0; i<n; ++i) if (root[i]==i) res++;
  return res;
}
