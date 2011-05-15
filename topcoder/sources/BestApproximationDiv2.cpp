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

class BestApproximationDiv2
{ 
public: 
  string findFraction(int maxDen, string number);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 42; string Arg1 = "0.141592658"; string Arg2 = "1/7 has 3 exact digits"; verify_case(0, Arg2, findFraction(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; string Arg1 = "0.1337"; string Arg2 = "0/1 has 1 exact digits"; verify_case(1, Arg2, findFraction(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 80000; string Arg1 = "0.1234567891011121314151617181920"; string Arg2 = "10/81 has 8 exact digits"; verify_case(2, Arg2, findFraction(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1000; string Arg1 = "0.42"; string Arg2 = "3/7 has 3 exact digits"; verify_case(3, Arg2, findFraction(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 100; string Arg1 = "0.420"; string Arg2 = "21/50 has 4 exact digits"; verify_case(4, Arg2, findFraction(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 100000; string Arg1 = "0.999999999999999999999999999999999999999999999999"; string Arg2 = "16/113 has 7 exact digits"; verify_case(5, Arg2, findFraction(Arg0, Arg1)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  BestApproximationDiv2 ___test; 
  ___test.run_test(3);
  //___test.run_test(0); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

string BestApproximationDiv2 :: findFraction(int maxDen, string number)
{
  string target=number.substr(2);
  int n=(int)(target).size();
  int m=-1;
  int p=1;
  int q=0;
  long double d=*({stringstream ss; ss<<(number); static long double r; ss>>r; &r;});
  for (int b=1; b<=maxDen; ++b) {
    int app=b*d;
    for (int a=app-5; a<=app+5; ++a) {
      if (a<0 || a>=b) continue;
      int x=a, y=b;
      int aux=0;
      for (int i=0; i<n; ++i) {
	x*=10;
	#ifdef DEBUG
	cout<<a<<" "<<b<<" "<<x/y<<" "<<target[i]<<endl;
#endif
	if (x/y!=target[i]-'0') { break; }
	else aux++;
	x%=y;
      }
      #ifdef DEBUG
      cout<<a<<" "<<b<<" "<<aux<<endl;
#endif
      if (aux>m) { m=aux; p=b; q=a; }
    }
  }
  // cout<<m<<" "<<p<<" "<<q<<endl;
  string res=*({stringstream ss; ss<<(q); static string r; ss>>r; &r;})+"/"+*({stringstream ss; ss<<(p); static string r; ss>>r; &r;})+" has "+*({stringstream ss; ss<<(m+1); static string r; ss>>r; &r;})+" exact digits";
  return res;
}
