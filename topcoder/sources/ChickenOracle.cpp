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

class ChickenOracle
{ 
public: 
    string theTruth(int n, int eggCount, int lieCount, int liarCount);
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 0; int Arg3 = 0; string Arg4 = "The egg"; verify_case(0, Arg4, theTruth(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 60; int Arg1 = 40; int Arg2 = 0; int Arg3 = 30; string Arg4 = "The oracle is a lie"; verify_case(1, Arg4, theTruth(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 60; int Arg1 = 20; int Arg2 = 5; int Arg3 = 25; string Arg4 = "The chicken"; verify_case(2, Arg4, theTruth(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 1000; int Arg1 = 500; int Arg2 = 250; int Arg3 = 250; string Arg4 = "Ambiguous"; verify_case(3, Arg4, theTruth(Arg0, Arg1, Arg2, Arg3)); }

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
    ChickenOracle ___test; 
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

// string ChickenOracle :: theTruth(int n, int eggCount, int lieCount, int liarCount)
// {
//     int res = 0;
//     int egg = n - lieCount, chicken = lieCount;
//     for (int i = 0; i <= min(liarCount, egg); ++i) {
//         int j = liarCount - i;
//         if (j > chicken) break;
//         if (eggCount == egg - i + j) {
//             res += 1;
//             break;
//         }
//     }

//     egg = lieCount, chicken = n - lieCount;
//     for (int i = 0; i <= min(liarCount, egg); ++i) {
//         int j = liarCount - i;
//         if (j > chicken) break;
//         if (eggCount == egg - i + j) {
//             res += 2;
//             break;
//         }
//     }
    
//     if (res == 0) return "The oracle is a lie";
//     else if (res == 1) return "The egg";
//     else if (res == 2) return "The chicken";
//     else return "Ambiguous";
// }

string ChickenOracle :: theTruth(int n, int eggCount, int lieCount, int liarCount)
{
    int res = 0;
    for (int lie = 0; lie <= eggCount; ++lie) {
        if (lie > liarCount || liarCount - lie > n - eggCount) continue;
        int aux = eggCount - lie + liarCount - lie;
        if (aux == lieCount)
            res |= 2;
        if (aux == n - lieCount)
            res |= 1;
    }
    if (res == 0) return "The oracle is a lie";
    else if (res == 1) return "The egg";
    else if (res == 2) return "The chicken";
    else return "Ambiguous";
}
