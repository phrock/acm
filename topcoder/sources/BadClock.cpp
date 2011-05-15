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

class BadClock
{ 
public: 
  double nextAgreement(string trueTime, string skewTime, int hourlyGain);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "07:07:07"; string Arg1 = "07:07:07"; int Arg2 = 1776; double Arg3 = 0.0; verify_case(0, Arg3, nextAgreement(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "11:59:58"; string Arg1 = "12:03:28"; int Arg2 = -3; double Arg3 = 70.0; verify_case(1, Arg3, nextAgreement(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "12:03:28"; string Arg1 = "11:59:58"; int Arg2 = 3; double Arg3 = 70.0; verify_case(2, Arg3, nextAgreement(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "03:03:02"; string Arg1 = "03:01:47"; int Arg2 = 5; double Arg3 = 15.0; verify_case(3, Arg3, nextAgreement(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "03:03:02"; string Arg1 = "03:01:47"; int Arg2 = -5; double Arg3 = 8625.0; verify_case(4, Arg3, nextAgreement(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "07:08:09"; string Arg1 = "09:08:07"; int Arg2 = -321; double Arg3 = 22.42367601246106; verify_case(5, Arg3, nextAgreement(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  BadClock ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 
vector<string> split( const string& s, const string& delim =" " ) {
  vector<string> res;
  string t;
  for ( int i = 0 ; i != (int)s.size() ; i++ ) {
    if ( delim.find( s[i] ) != string::npos ) {
      if ( !t.empty() ) {
	res.push_back( t );
	t = "";
      }
    } else {
      t += s[i];
    }
  }
  if ( !t.empty() ) {
    res.push_back(t);
  }
  return res;
}

vector<int> splitInt( const string& s, const string& delim =" " ) {
  vector<string> tok = split( s, delim );
  vector<int> res;
  for ( int i = 0 ; i != (int)tok.size(); i++ )
    res.push_back( atoi( tok[i].c_str() ) );
  return res;
}

double BadClock :: nextAgreement(string trueTime, string skewTime, int hourlyGain)
{
  vector<int> v1=splitInt(trueTime, ":");
  vector<int> v2=splitInt(skewTime, ":");
  v1[0]%=12; v2[0]%=12;
  int x=v1[0]*3600+v1[1]*60+v1[2];
  int y=v2[0]*3600+v2[1]*60+v2[2];
  int z=0;
  if (hourlyGain>0) z=(x+12*3600-y)%(12*3600);
  else z=(y+12*3600-x)%(12*3600);
  // cout<<x<<" "<<y<<" "<<z<<endl;
  double res=1.0*z/abs(hourlyGain);
  return res;
}
