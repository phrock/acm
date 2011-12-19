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

class ColorfulDecoration
{ 
public: 
    int getMaximum(vector <int> xa, vector <int> ya, vector <int> xb, vector <int> yb);
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 10,  0,  7 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {  0, 19,  6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 20, 10, 25 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 20, 35, 25 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 19; verify_case(0, Arg4, getMaximum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = { 464, 20 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 464, 10 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 464,  3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 464, 16 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 461; verify_case(1, Arg4, getMaximum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = { 0, 0, 1, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0, 0, 1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 1, 1, 0, 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 1, 1, 0, 0 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(2, Arg4, getMaximum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = { 0, 3, 0, 5, 6 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1, 6, 0, 8, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 6, 1, 7, 4, 7 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 5, 9, 2, 8, 9 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(3, Arg4, getMaximum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = { 1000000000, 0 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0, 1000000000 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0, 1000000000 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 0, 1000000000 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1000000000; verify_case(4, Arg4, getMaximum(Arg0, Arg1, Arg2, Arg3)); }

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
    ColorfulDecoration ___test; 
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

// int n;
// int res;
// int v[55];
// vector<int> xa, ya, xb, yb;

// void dfs(int cur, int tmp)
// {
//     if (cur == n) {
//         res = max(res, tmp);
//         return;
//     }
//     if (cur == 0) {
//         for (int i = 0; i < 2; ++i) {
//             int backup = v[cur];
//             v[cur] = i;
//             dfs(cur + 1, tmp);
//             v[cur] = backup;
//         }
//     } else {
//         for (int i = 0; i < 2; ++i) {
//             int backup = v[cur];
//             v[cur] = i;
//             int x, y;
//             if (v[cur] == 0) {
//                 x = xa[cur];
//                 y = ya[cur];
//             } else {
//                 x = xb[cur];
//                 y = yb[cur];
//             }
//             int tmp_backup = tmp;
//             for (int j = 0; j < cur; ++j)
//                 if (v[j] == 0)
//                     tmp = min(tmp, max(abs(xa[j] - x), abs(ya[j] - y)));
//                 else
//                     tmp = min(tmp, max(abs(xb[j] - x), abs(yb[j] - y)));
//             if (tmp > res)
//                 dfs(cur + 1, tmp);
//             tmp = tmp_backup;
//             v[cur] = backup;
//         }
//     }
// }

// int ColorfulDecoration :: getMaximum(vector <int> _xa, vector <int> _ya, vector <int> _xb, vector <int> _yb)
// {
//     n = (int)(_xa).size();
//     res = 0;
//     memset(v, 0, sizeof(v));
//     xa = _xa, ya = _ya, xb = _xb, yb = _yb;

//     dfs(0, INT_MAX);
//     return res;
// }

int ColorfulDecoration :: getMaximum(vector <int> xa, vector <int> ya, vector <int> xb, vector <int> yb)
{
    int n = (int)(xa).size();
    int low = 0, high = INT_MAX;
    while (low + 1 < high) {
        int mid = low + (high - low) / 2;
        vector< vector<int> > g(2 * n, vector<int>(2 * n));
        for (int i = 0; i < (int)(g).size(); ++i)
            for (int j = 0; j < (int)(g[i]).size(); ++j) {
                if (i == j) {
                    g[i][j] = 1;
                    continue;
                }
                if (i % n == j & n)
                    continue;
                int x1 = i < n ? xa[i] : xb[i - n];
                int y1 = i < n ? ya[i] : yb[i - n];
                int x2 = j < n ? xa[j] : xb[j - n];
                int y2 = j < n ? ya[j] : yb[j - n];
                if (abs(x1 - x2) < mid && abs(y1 - y2) < mid)
                    g[i][j < n ? j + n : j - n] = 1;
            }
        for (int k = 0; k < 2 * n; ++k)
            for (int i = 0; i < 2 * n; ++i)
                for (int j = 0; j < 2 * n; ++j)
                    if (g[i][k] && g[k][j])
                        g[i][j] = 1;
        bool ok = true;
        for (int i = 0; i < n; ++i)
            if (g[i][i + n] && g[i + n][i])
                ok = false;
        if (ok)
            low = mid;
        else
            high = mid;
    }
    return low;
}
