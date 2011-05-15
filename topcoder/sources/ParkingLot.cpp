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

class ParkingLot
{ 
public: 
  int fastest(vector <string> lot);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".Y...........C",
 ".XUUUUUUUAUUX.",
 ".XUUUAUUAUUUX.",
 "..C...........",
 ".XUUUUUUAUUUX.",
 ".XUUUUUUUUUAX.",
 "......C.......",
 ".............E"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 29; verify_case(0, Arg1, fastest(Arg0)); }
	void test_case_1() { string Arr0[] = {"C..A..Y.E"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, fastest(Arg0)); }
	void test_case_2() { string Arr0[] = {"C..A.Y..E"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(2, Arg1, fastest(Arg0)); }
	void test_case_3() { string Arr0[] = {"Y...C",
 ".XXX.",
 ".....",
 "UUAUU",
 "EA..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 11; verify_case(3, Arg1, fastest(Arg0)); }
	void test_case_4() { string Arr0[] = {".X.U..X....UU.U.XA...UC..U.UA.A.E.A",
 "..U..A.X...XX...U...U...X..U.XUX.X.",
 "U...U.X...U..........A...AXU.U..UUC",
 "UX..XX.AU..XAA.X.U.XCX..UX.......U.",
 "UAUX..UX...X....X.X..C.X..U...AXU..",
 "AA..AA..XUAX..A..XXX..AUUXUAXU.XUAU",
 "..A....A...XUU..A..A.XU..U..A.XX.X.",
 "XX.XU...AX.A.A.....UAA.UX.XA.C....X",
 ".UA.X.A.C...A..UXA.UAX.U.CU.XU....X",
 "..XX....UUU...XX..U..A.......U..A..",
 ".ACCUU.A.A.A.XX.....X..UX..A..U..X.",
 "XCX..UX...X.A.XAUA.UX.X.UA..U..A.A.",
 "UA..X.UC...U..X.AUUAX.U.X.......UA.",
 "..X.XXX..AXX.U..XXU..X...A...UAXX..",
 ".U.A..A.XX....XC.XAUX..AXUX......A.",
 "...X.A..AX.UU.XU......A.........AA.",
 "...UXU..X...U..U.U.X.U...U......UX.",
 "A.U.UA...CA....X..UXUA..X..XX..U...",
 "XXUC.CAU..X.U.......A...U..X.....XA",
 "..XA...U...UXYC.CAU...UXA..A...A...",
 "...XA....U.A.A...CX...A...AX..U..AC",
 "U..X.AX..U..UXX............AA..A..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 52; verify_case(4, Arg1, fastest(Arg0)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  ParkingLot ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

int ParkingLot :: fastest(vector <string> lot)
{
  
}
