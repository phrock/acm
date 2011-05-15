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

class PermutationCounter
{ 
public: 
  long long count(string n);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "1020"; long long Arg1 = 7LL; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arg0 = "50000000000000"; long long Arg1 = 13LL; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arg0 = "1030000040000"; long long Arg1 = 1414LL; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arg0 = "1901712530271201432987123"; long long Arg1 = 141588146596382454LL; verify_case(3, Arg1, count(Arg0)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void printv(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  PermutationCounter ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

long long ncr[55][55];

long long helper(const vector<int> &v, int n)
{
  long long res=1;
  for (int i=0; i<(v).size(); ++i)
    res*=ncr[n][v[i]], n-=v[i];
  return res;
}

long long PermutationCounter :: count(string n)
{
  vector<int> v(10);
  for (int i=0; i<(n).size(); ++i) v[n[i]-'0']++;
  for (int i=0; i<55; ++i) ncr[i][0]=1;
  for (int i=1; i<55; ++i)
    for (int j=1; j<=55; ++j)
      ncr[i][j]=ncr[i-1][j]+ncr[i-1][j-1];
  long long res=0;
  for (int i=0; i<n.size(); ++i) {
    int m=n.size()-i;
    for (int j=0; j<10; ++j) {
      if (j<n[i]-'0' && v[j]>0) {
	v[j]--;
	res+=helper(v, m-1);
	v[j]++;
      }
    }
    v[n[i]-'0']--;
    // cout<<i<<" "<<n[i]<<" "<<res<<endl;
    // cout<<endl;
  }
  // cout<<ncr[5][3]<<endl;
  return res;
}
