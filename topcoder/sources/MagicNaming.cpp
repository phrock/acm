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

class MagicNaming
{ 
public: 
    int maxReindeers(string magicName);
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aba"; int Arg1 = 2; verify_case(0, Arg1, maxReindeers(Arg0)); }
	void test_case_1() { string Arg0 = "babbaba"; int Arg1 = 2; verify_case(1, Arg1, maxReindeers(Arg0)); }
	void test_case_2() { string Arg0 = "philosophersstone"; int Arg1 = 5; verify_case(2, Arg1, maxReindeers(Arg0)); }
	void test_case_3() { string Arg0 = "knuthmorrispratt"; int Arg1 = 7; verify_case(3, Arg1, maxReindeers(Arg0)); }
	void test_case_4() { string Arg0 = "acrushpetrtourist"; int Arg1 = 7; verify_case(4, Arg1, maxReindeers(Arg0)); }
	void test_case_5() { string Arg0 = "zzzzz"; int Arg1 = 5; verify_case(5, Arg1, maxReindeers(Arg0)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
/////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }
template<class T> inline void print(T A[], int n) { cout<<"{ "; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", ";} cout<<" }"<<endl; }
template<class T> inline void print2(T A[], int n, int m) { cout<<"{"<<endl; for (int i=0; i<n; ++i) {cout<<" { "; for (int j=0; j<m; ++j) { cout<<A[i][j]; if (j+1<m) cout<<", ";} cout<<" } "<<endl; } cout<<"}"<<endl; }

int main()
{
    MagicNaming ___test; 
    ___test.run_test(-1); 
} 
/////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

/****************************************************************************
 *                                                                          *
 *                To see the world in a grain of sand,                      *
 *                And a heaven in a wild flower;                            *
 *                Hold infinity in the palm of your hand,                   *
 *                And eternity in an hour.                                  *
 *                                                                          *
 ***************************************************************************/

int dp[55][55];

int MagicNaming :: maxReindeers(string magicName)
{
    int n = (int)(magicName).size();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dp[i][j] = INT_MIN;
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j) {
            if (!i) {
                dp[i][j] = 1;
                continue;
            }
            for (int k = 0; k < i; ++k) {
                string a = magicName.substr(k, i - k);
                string b = magicName.substr(i, j - i + 1);
                if (a + b <= b + a)
                    dp[i][j] = max(dp[i][j], dp[k][i - 1] + 1);
            }
        }
    int res = 0;
    for (int i = 0; i < n; ++i)
        res = max(res, dp[i][n - 1]);
    return res;
}
