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

class NumberGuesser
{ 
public: 
  int guess(string leftOver);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "087"; int Arg1 = 3; verify_case(0, Arg1, guess(Arg0)); }
	void test_case_1() { string Arg0 = "099"; int Arg1 = 9; verify_case(1, Arg1, guess(Arg0)); }
	void test_case_2() { string Arg0 = "191"; int Arg1 = 7; verify_case(2, Arg1, guess(Arg0)); }
	void test_case_3() { string Arg0 = "689"; int Arg1 = 4; verify_case(3, Arg1, guess(Arg0)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  NumberGuesser ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

bool check(int x)
{
  for (int i=x+1; i<=9998; ++i) {
    int y=i-x;
    vector<int> v1, v2;
    int t=i;
    while (t) { int a=t%10; if (a) v1.push_back(a); t/=10; }
    while (y) { int a=y%10; if (a) v2.push_back(a); y/=10; }
    sort((v1).begin(), (v1).end());
    sort((v2).begin(), (v2).end());
    if (v1==v2) {
      // cout<<i<<" "<<y<<" "<<x<<endl;
      return true;
    }
  }
  return false;
}

int NumberGuesser :: guess(string leftOver)
{
  while (leftOver[0]=='0') leftOver=leftOver.substr(1);
  for (int i=0; i<=leftOver.size(); ++i) 
    for (char j='1'; j<='9'; ++j) {
      string s=leftOver.substr(0, i)+j+leftOver.substr(i);
      cout<<s<<endl;
      bool res=check(*({stringstream ss; ss<<(s); static int r; ss>>r; &r;}));
      if (res) return j-'0';
    }
}
