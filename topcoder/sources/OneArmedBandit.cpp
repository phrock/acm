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

class OneArmedBandit
{ 
public: 
    double progressiveJackpot(vector <string> wheels, string jackpotLine, vector <string> payoffTable);
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"ABC", "ABC", "ABC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AAA"; string Arr2[] = {"BBB 5", "CCC 2"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 20.0; verify_case(0, Arg3, progressiveJackpot(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"ABC", "ABC", "ABC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AAA"; string Arr2[] = {"AAB 4", "AA- 3", "AB- 2"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 8.0; verify_case(1, Arg3, progressiveJackpot(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"ABC", "ABC", "ABC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AAA"; string Arr2[] = {"AA- 5", "A-- 2"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 0.0; verify_case(2, Arg3, progressiveJackpot(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"ABC", "ABC", "BBC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AAA"; string Arr2[] = {"AAB 4", "AA- 3", "AB- 2"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = -1.0; verify_case(3, Arg3, progressiveJackpot(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"DABCDBCDCD", "BCDBDACDCD", "DCDADBCDBC", "DBDCABCDCD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AAAA"; string Arr2[] = {}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 10000.0; verify_case(4, Arg3, progressiveJackpot(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"DABCDBCDCD", "BCDBDACDCD", "DCDADBCDBC", "DBDCABCDCD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AAAA"; string Arr2[] = {"AAAE 20"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 10000.0; verify_case(5, Arg3, progressiveJackpot(Arg0, Arg1, Arg2)); }
	void test_case_6() { string Arr0[] = {"KACACEIBGCVDAKMACAAW",
 "CECMBDBJCLHFNDCBDDNB",
 "BYAGBJFDAGBHEGEFVXDR",
 "UDWFABFAHDXACICQHAEH",
 "EBHOCHABAHBDAUBZHHAB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "KJ--Z"; string Arr2[] = {"Z-U-U 23",
 "YUBSA 142",
 "Q-AN- 92",
 "ZA-CX 133",
 "-BE-Z 125"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 3500.0; verify_case(6, Arg3, progressiveJackpot(Arg0, Arg1, Arg2)); }

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
    OneArmedBandit ___test; 
    ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

/*******************************************************************************
 *                                                                             *
 *                  To see the world in a grain of sand,                       *
 *                  And a heaven in a wild flower;                             *
 *                  Hold infinity in the palm of your hand,                    *
 *                  And eternity in an hour.                                   *
 *                                                                             *
 ******************************************************************************/

double OneArmedBandit :: progressiveJackpot(vector <string> wheels, string jackpotLine, vector <string> payoffTable)
{
    return 0;
}
