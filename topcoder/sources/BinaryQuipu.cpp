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

class BinaryQuipu
{ 
public: 
  int fewestKnots(vector <string> inventory);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"bsb", "bbs", "sbbs", "sbs"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(0, Arg1, fewestKnots(Arg0)); }
	void test_case_1() { string Arr0[] = {"s", "b"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, fewestKnots(Arg0)); }
	void test_case_2() { string Arr0[] = {"bs", "sb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(2, Arg1, fewestKnots(Arg0)); }
	void test_case_3() { string Arr0[] = {"bs", "sb", "bb", "ss"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, fewestKnots(Arg0)); }
	void test_case_4() { string Arr0[] = {"bssbs", "ssbs", "sbb", "bbs", "sbs", "ssbb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(4, Arg1, fewestKnots(Arg0)); }
	void test_case_5() { string Arr0[] = {"bbbsssbbsbbssbbbbs",
"bssssbbbbsbbsbbbbbbsbbsbsssbbbsbbbbbsbbssbsb",
"sbbbbbsbbbsbsssbssssbssbbsssssssbbssss",
"sbbbbbsbsbssbssbsssbsbbsbssbsbbbsbsbs",
"bsbbbbbssbsbbbbsbbs",
"bbsbbsbsssbsbbsbbssbbbsbsssbsbbsbsbssbsbsssbsbsbs"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 181; verify_case(5, Arg1, fewestKnots(Arg0)); }

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
  BinaryQuipu ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

int res;
set<set<string> > st;

void dfs(const set<string> &a)
{
  // print(a);
  st.insert(a);
  res++;
  set<string> p, q;
  for (__typeof((a).begin()) i=(a).begin(); i!=(a).end(); ++i)
    if ((int)(*i).size()>1) {
      if ((*i)[1]=='b') p.insert((*i).substr(1));
      else q.insert((*i).substr(1));
    }
  if (!p.empty() && !((st).find(p)!=(st).end())) dfs(p);
  if (!q.empty() && !((st).find(q)!=(st).end())) dfs(q);
}  

int BinaryQuipu :: fewestKnots(vector <string> inventory)
{
  for (int i=0; i<(int)(inventory).size(); ++i) inventory[i]="a"+inventory[i];
  res=0;
  set<string> start((inventory).begin(), (inventory).end());
  st.clear();
  dfs(start);
  return res;
}
