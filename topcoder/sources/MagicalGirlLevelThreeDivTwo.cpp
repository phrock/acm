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

class MagicalGirlLevelThreeDivTwo
{ 
public: 
    int theCount(vector <string> first, int n, long long lo, long long hi);
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1", "11", "111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; long long Arg2 = 0LL; long long Arg3 = 0LL; int Arg4 = 2; verify_case(0, Arg4, theCount(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {"01", "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; long long Arg2 = 4LL; long long Arg3 = 5LL; int Arg4 = 1; verify_case(1, Arg4, theCount(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {"1", "11", "111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 46; long long Arg2 = 10000LL; long long Arg3 = 11000LL; int Arg4 = 1001; verify_case(2, Arg4, theCount(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arr0[] = {"0", "00", "000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 46; long long Arg2 = 10000LL; long long Arg3 = 11000LL; int Arg4 = 0; verify_case(3, Arg4, theCount(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arr0[] = {"00110110101101001111101101001011010011111011010010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; long long Arg2 = 999999999999915LL; long long Arg3 = 1000000000000000LL; int Arg4 = 50; verify_case(4, Arg4, theCount(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { string Arr0[] = {"10000", "011011001011000001101000010100000111000110110", 
"000001010001011000001101110", "100100000110100001010000", 
"011011010", "01100000010101101110000011100011001000",
"0001010", "010011000", "000101001", "00", "1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 91; long long Arg2 = 123456LL; long long Arg3 = 123654LL; int Arg4 = 76; verify_case(5, Arg4, theCount(Arg0, Arg1, Arg2, Arg3)); }

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
    MagicalGirlLevelThreeDivTwo ___test; 
    // ___test.run_test(-1); 
    ___test.run_test(0); 
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


char func(const vector<string> &first, const vector<long long> &len, int n, long long idx)
{
    if (n < (int)(first).size())
        return first[n][idx];
    int aux = n - 1;
    while (idx >= len[aux]) {
        idx = idx - len[aux];
        aux -= (int)(first).size();
    }
    return func(first, len, aux, idx);
}

int MagicalGirlLevelThreeDivTwo :: theCount(vector <string> first, int n, long long lo, long long hi)
{
    int k = (int)(first).size();
    vector<long long> len(max(n + 1, k));
    for (int i = 0; i < k; ++i)
        len[i] = (int)(first[i].size());
    #ifdef DEBUG
    print(first);
    print(len);    
    #endif
    for (int i = k; i <= n; ++i) {
        int idx = i - 1;
        while (idx >= 0) {
            len[i] = len[i] + len[idx];
            len[i] = min(len[i], hi + 1);
            idx -= k;
        }
    }
    #ifdef DEBUG
    print(len);
    #endif
    int res = 0;
    for (long long i = lo; i <= hi; ++i) {
        if (func(first, len, n, i) == '1')
            ++res;
    }
    return res;
}
