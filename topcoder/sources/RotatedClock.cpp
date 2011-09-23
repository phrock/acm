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

class RotatedClock
{ 
public: 
    string getEarliest(int hourHand, int minuteHand);
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 70; int Arg1 = 300; string Arg2 = "08:20"; verify_case(0, Arg2, getEarliest(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 90; int Arg1 = 120; string Arg2 = "11:00"; verify_case(1, Arg2, getEarliest(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 240; int Arg1 = 36; string Arg2 = ""; verify_case(2, Arg2, getEarliest(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 19; int Arg1 = 19; string Arg2 = ""; verify_case(3, Arg2, getEarliest(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 12; string Arg2 = "00:02"; verify_case(4, Arg2, getEarliest(Arg0, Arg1)); }

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
    RotatedClock ___test; 
    ___test.run_test(-1); 
    // ___test.run_test(0); 
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

string func(int h, int m)
{
    if (m % 12)
        return "";
    int h1 = h / 30, h2 = h - h1 * 30;
    if (h2 * 12 == m) {
        cout << h << " " << m << endl;
        stringstream is;
        is << setw(2) << setfill('0') << h1 << ":" << setw(2) << setfill('0') << m / 6;
        return is.str();
    } else {
        return "";
    }
}
    

string RotatedClock :: getEarliest(int hourHand, int minuteHand)
{
    string res;
    for (int i = 0; i < 360; i += 30) {
        int h = (hourHand + i) % 360, m = (minuteHand + i) % 360;
        string aux = func(h, m);
        if (!aux.empty()) {
            cout << aux << endl;
            if (res.empty())
                res = aux;
            else
                res = min(res, aux);
        }
    }
    return res;
}
