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

class MagicalGirlLevelOneDivTwo
{ 
public: 
    double theMinDistance(int d, int x, int y);
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 10; int Arg2 = 10; double Arg3 = 7.0710678118654755; verify_case(0, Arg3, theMinDistance(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 10; int Arg2 = 3; double Arg3 = 5.0; verify_case(1, Arg3, theMinDistance(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = -8; int Arg2 = -6; double Arg3 = 3.1622776601683795; verify_case(2, Arg3, theMinDistance(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 3; int Arg2 = 2; double Arg3 = 0.0; verify_case(3, Arg3, theMinDistance(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 24; int Arg1 = 24; int Arg2 = -24; double Arg3 = 0.0; verify_case(4, Arg3, theMinDistance(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 345; int Arg1 = -471; int Arg2 = 333; double Arg3 = 126.0; verify_case(5, Arg3, theMinDistance(Arg0, Arg1, Arg2)); }

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
    MagicalGirlLevelOneDivTwo ___test; 
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

double dist(double x1,double y1, double x2, double y2)
{
    return hypot(x1 - x2, y1 - y2);
}

double MagicalGirlLevelOneDivTwo :: theMinDistance(int d, int x, int y)
{
    if (x <= d && x >= -d && y >= -d && y <= d)
        return 0;
    if (x <= d && x >= -d)
        return min(abs(y - d), abs(y + d));
    if (y >= -d && y <= d)
        return min(abs(x - d), abs(x + d));
    int a[][2] = {{-d, -d}, {-d, d}, {d, -d}, {d, d}};

    double res = INT_MAX;
    for (int i = 0; i < 4; ++i)
        res = min(res, dist(a[i][0], a[i][1], x, y));
    return res;
}
