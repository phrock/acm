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

class TheBlackJackDivOne
{ 
public: 
  double expected(vector <string> cards);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"JS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 2.105854341736695; verify_case(0, Arg1, expected(Arg0)); }
	void test_case_1() { string Arr0[] = {"KD", "8S"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.08; verify_case(1, Arg1, expected(Arg0)); }
	void test_case_2() { string Arr0[] = {"KD", "2S", "2C", "2D", "2H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.0; verify_case(2, Arg1, expected(Arg0)); }
	void test_case_3() { string Arr0[] = {"AS", "KS", "9S", "JC", "2D"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(3, Arg1, expected(Arg0)); }

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
  TheBlackJackDivOne ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

void func(int sum, vector<int> &a, int num, int k, double p, double &res)
{
  if (sum>=21) { res+=p*k; return; }
  for (int i=2; i<=11; ++i)
    if (a[i]) {
      // cout<<num<<" "<<a[i]<<" "<<i<<"  "<<sum<< " "<<p*a[i]/num<<endl;
      a[i]--;
      func(sum+i, a, num-1, k+1, p*(a[i]+1)/num, res);
      a[i]++;
    }
}

double TheBlackJackDivOne :: expected(vector <string> cards)
{
  vector<int> a(12);
  for (int i=2; i<=11; ++i) a[i]=4;
  a[10]=16;
  // cout<<accumulate((a).begin(), (a).end(), 0);
  int sum=0;
  for (int i=0; i<(int)(cards).size(); ++i) {
    int x=0;
    if (cards[i][0]>='2' && cards[i][0]<='9') x=cards[i][0]-'0';
    else if (cards[i][0]=='A') x=11;
    else x=10;
    a[x]--;
    sum+=x;
  }
  int num=52-(int)(cards).size();
  double res=0;
  func(sum, a, num, 0, 1, res);
  return res;
}
