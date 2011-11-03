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

class ParameterSubstitution
{ 
public: 
    string processParams(string code, vector <string> params);
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "if ($1 == $2) $3;"; string Arr1[] = {"12", "12", "doWhatIWant()"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "if (12 == 12) doWhatIWant();"; verify_case(0, Arg2, processParams(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "$3+$1*$2-$7=$10"; string Arr1[] = {"myvar", "490jri", "e09jd9", "dlkjfoiej"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "e09jd9+myvar*490jri-$7=myvar0"; verify_case(1, Arg2, processParams(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "12342123$13231232$2123211242$a$dlkj$"; string Arr1[] = {"$2", "$1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "12342123$23231232$1123211242$a$dlkj$"; verify_case(2, Arg2, processParams(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "{[(+.*-,/\\:;<=>?@)]}_`~|$$1"; string Arr1[] = {"1{[(+.*-,/\\:;<=>?@)]}_`~|"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "{[(+.*-,/\\:;<=>?@)]}_`~|$1{[(+.*-,/\\:;<=>?@)]}_`~|"; verify_case(3, Arg2, processParams(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "$01"; string Arr1[] = {"abc"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "$01"; verify_case(4, Arg2, processParams(Arg0, Arg1)); }

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
    ParameterSubstitution ___test; 
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

string ParameterSubstitution :: processParams(string code, vector <string> params)
{
    
}
