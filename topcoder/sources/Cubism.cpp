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

class Cubism
{ 
public: 
  int lines(vector <string> lattice, string color);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"BBBBBWWWBWWWBWWW",
 "BWWWWWWWWWWWWWWW",
 "BWWWWWWWWWWWWWWW",
 "BWWWWWWWWWWWWWWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "black"; int Arg2 = 3; verify_case(0, Arg2, lines(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"BWWWWWWWWWWWWWWW",
 "WWWWWBWWWWWWWWWW",
 "WWWWWWWWWWBWWWWW",
 "WWWWWWWWWWWWWWWB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "black"; int Arg2 = 1; verify_case(1, Arg2, lines(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"WWWWWWWWWWWWWWWW",
 "WWWWWWWWWWWWWWWW",
 "WWWWWWWWWWWWWWWW",
 "WWWWWWWWWWWWWWWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "black"; int Arg2 = 0; verify_case(2, Arg2, lines(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"WWWWWWWWWWWWWWWW",
 "WWWWWWWWWWWWWWWW",
 "WWWWWWWWWWWWWWWW",
 "WWWWWWWWWWWWWWWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "white"; int Arg2 = 76; verify_case(3, Arg2, lines(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"WWWWWWWWWBWWWWWW",
 "WWWBWWWWWWWWWWWW",
 "WWWWWWWWWWWWBWWW",
 "WWWBWWWWWWWWWWWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "white"; int Arg2 = 58; verify_case(4, Arg2, lines(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"BWBWBWBWBWBWBWBW","BWBWBWBWBWBWBWBW",
 "BWBWBWBWBWBWBWBW","BWBWBWBWBWBWBWBW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "white"; int Arg2 = 20; verify_case(5, Arg2, lines(Arg0, Arg1)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  Cubism ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

int Cubism :: lines(vector <string> lattice, string color)
{
  vector<vector<string > > v;
  for (int i=0; i<(int)(lattice).size(); ++i) {
    vector<string > tmp;
    for (int k=0; k<4; ++k)
      tmp.push_back(lattice[i].substr(k*4, 4));
    v.push_back(tmp);
  }
  // print2(v);
  char target=color=="black"?'B':'W';
  int res=0;
  for (int i=0; i<(int)(v).size(); ++i)
    for (int j=0; j<(int)(v[i]).size(); ++j)
      for (int k=0; k<(int)(v[i][j]).size(); ++k) {
	for (int a=-1; a<2; ++a)
	  for (int b=-1; b<2; ++b)
	    for (int c=-1; c<2; ++c) {
	      if (!a && !b && !c) continue;
	      if (i+3*a<4 && j+3*b<4 && k+3*c<4 &&
		  i+3*a>=0 && j+3*b>=0 && k+3*c>=0) {
		bool ok=true;
		for (int p=0; p<4; ++p) {
		  if (v[i+a*p][j+b*p][k+c*p]!=target) {
		    ok=false;
		    break;
		  }
		}
		if (ok) {
		  res++;
		}
	      }
	    }
      }
  return res/2;
}
