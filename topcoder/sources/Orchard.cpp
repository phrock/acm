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

class Orchard
{ 
public: 
  vector <int> nextTree(vector <string> orchard);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = { "----" , "T---" , "----" , "----" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 2,  3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, nextTree(Arg0)); }
	void test_case_1() { string Arr0[] = {"---T--","------","------","----T-","------","------"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 3,  3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, nextTree(Arg0)); }
	void test_case_2() { string Arr0[] = {"------------","------------","------------","------------",
"------------","------------","------------","------------",
"------------","------------","------------","------------"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 6,  6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, nextTree(Arg0)); }
	void test_case_3() { string Arr0[] = {"-T----T",
 "T---T--",
 "-----TT",
 "---TT--",
 "T-----T",
 "-------",
 "T-T--T-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 2,  3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, nextTree(Arg0)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  Orchard ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

vector <int> Orchard :: nextTree(vector <string> orchard)
{
  int n=orchard.size();
  int m=orchard[0].size();
  int p[]={-1, 0, 0, 1};
  int q[]={0, -1, 1, 0};
  vector< vector<int> > a(n, vector<int> (m, INT_MAX/2));
  for (unsigned i=0; i<(a).size(); ++i)
    for (unsigned j=0; j<(a[i]).size(); ++j)
      if (orchard[i][j]=='T') a[i][j]=0;
  while (true) {
    bool updated=false;
    for (int i=0; i<n; ++i)
      for (int j=0; j<m; ++j) {
	if (orchard[i][j]=='T') continue;
	int aux=INT_MAX;
	if (i==0 || i==n-1 || j==0 || j==m-1) aux=1;
	else {
	  for (int k=0; k<4; ++k) 
	    aux=min(aux, a[i+p[k]][j+q[k]]+1);
	}
	if (aux<a[i][j]) {
	  updated=true;
	  a[i][j]=aux;
	}
      }
    if (!updated) break;
  }
  int x=0;
  int y=0;
  int w=-1;
  for (int i=0; i<n; ++i)
    for (int j=0; j<m; ++j)
      if (orchard[i][j]!='T' && a[i][j]>w) { x=i; y=j; w=a[i][j]; }
  vector<int> res;
  res.push_back(x+1);
  res.push_back(y+1);
  return res;
}
