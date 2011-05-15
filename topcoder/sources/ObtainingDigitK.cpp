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

class ObtainingDigitK
{ 
public: 
  int minNumberToAdd(string originalNumber, int k);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "153"; int Arg1 = 7; int Arg2 = 4; verify_case(0, Arg2, minNumberToAdd(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "158"; int Arg1 = 7; int Arg2 = 9; verify_case(1, Arg2, minNumberToAdd(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "7853192"; int Arg1 = 2; int Arg2 = 0; verify_case(2, Arg2, minNumberToAdd(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "99999999999999999999999999999999999999999999999"; int Arg1 = 0; int Arg2 = 1; verify_case(3, Arg2, minNumberToAdd(Arg0, Arg1)); }

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
  ObtainingDigitK ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

int ObtainingDigitK :: minNumberToAdd(string originalNumber, int k)
{
  vector<int> v;
  for (int i=(int)(originalNumber).size()-1; i>=0; --i) 
    v.push_back(originalNumber[i]-'0');
  for (int i=0; i<10; ++i) {
    vector<int> aux=v;
    int x=i, cur=0;
    while (true) {
      if (cur<(int)(v).size()) aux[cur]+=x;
      else aux.push_back(x);
      if (aux[cur]>9) aux[cur]%=10, x=1, cur++;
      else break;
    }
    #ifdef DEBUG
    cout<<i<<endl;
    print(aux);
    #endif
    if ((find((aux).begin(), (aux).end(), k)!=(aux).end())) return i;
  }
}
