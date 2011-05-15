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

class Polynomials
{ 
public: 
  long long integralPoints(int ymax, int xmax, string equation);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 5; string Arg2 = "1y^1=1x^1"; long long Arg3 = 6LL; verify_case(0, Arg3, integralPoints(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 65; int Arg1 = 34; string Arg2 = "1y^2=1x^3"; long long Arg3 = 5LL; verify_case(1, Arg3, integralPoints(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1000000; int Arg1 = 1000000; string Arg2 = "1=1x^2"; long long Arg3 = 1000001LL; verify_case(2, Arg3, integralPoints(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 55000; int Arg1 = 15982; string Arg2 = "1y^4+1y^2=5+9+6"; long long Arg3 = 15983LL; verify_case(3, Arg3, integralPoints(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  Polynomials ___test; 
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

void parse(string s, vector<vector<pair<long long ,long long > > >&a, int p)
{
  vector<string> v=split(s, "+");
  for (int i=0; i<(int)(v).size(); ++i) {
    vector<string> t;
    if (!p) t=split(v[i], "y^");
    else t=split(v[i], "x^");
    if ((int)(t).size()==1) t.push_back("0");
    a[p].push_back(make_pair(*({stringstream ss; ss<<(t[0]); static long long  r; ss>>r; &r;}), *({stringstream ss; ss<<(t[1]); static long long  r; ss>>r; &r;})));
  }
}

long long power(long long a, long long x, long long b)
{
  long long res=1;
  for (int i=0; i<b; ++i) res*=x;
  return a*res;
}

long long Polynomials :: integralPoints(int ymax, int xmax, string equation)
{
  vector<string> v=split(equation, "=");
  vector< vector<pair<long long ,long long > > >a(2);
  parse(v[0], a, 0);
  parse(v[1], a, 1);
  map<long long , long long > mm;
  long long res=0;
  for (int i=0; i<=ymax; ++i) {
    long long tmp=0;
    for (int j=0; j<(int)(a[0]).size(); ++j)
      tmp+=power(a[0][j].first, i, a[0][j].second);
    mm[tmp]++;
  }
  // printp(mm);
  for (int i=0; i<=xmax; ++i) {
    long long tmp=0;
    for (int j=0; j<(int)(a[1]).size(); ++j)
      tmp+=power(a[1][j].first, i, a[1][j].second);
    if (((mm).find(tmp)!=(mm).end())) res+=mm[tmp];
  }
  return res;
}
