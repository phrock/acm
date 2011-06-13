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

class NumberLabyrinthDiv2
{ 
public: 
    int getMinimumNumberOfMoves(vector <string> board, int r1, int c1, int r2, int c2, int K);
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"...2",
 "....",
 "3..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = 2; int Arg4 = 3; int Arg5 = 0; int Arg6 = -1; verify_case(0, Arg6, getMinimumNumberOfMoves(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { string Arr0[] = {"...2",
 "....",
 "3..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = 2; int Arg4 = 3; int Arg5 = 1; int Arg6 = 2; verify_case(1, Arg6, getMinimumNumberOfMoves(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { string Arr0[] = {"...3",
 "....",
 "2..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = 2; int Arg4 = 3; int Arg5 = 3; int Arg6 = 3; verify_case(2, Arg6, getMinimumNumberOfMoves(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { string Arr0[] = {"55255",
 ".0.0.",
 "..9..",
 "..3..",
 "3.9.3",
 "44.44"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; int Arg3 = 4; int Arg4 = 2; int Arg5 = 10; int Arg6 = 6; verify_case(3, Arg6, getMinimumNumberOfMoves(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { string Arr0[] = {".8810608221.25202658111258166.85.8.12..861...2.618"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 46; int Arg3 = 0; int Arg4 = 5; int Arg5 = 2; int Arg6 = 7; verify_case(4, Arg6, getMinimumNumberOfMoves(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

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
    NumberLabyrinthDiv2 ___test; 
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
// {".8810608221.25202658111258166.85.8.12..861...2.618"}, 0, 46, 0, 5, 2}

int dirx[] = {-1, 0, 0, 1};
int diry[] = {0, -1, 1, 0};


int NumberLabyrinthDiv2 :: getMinimumNumberOfMoves(vector <string> board, int r1, int c1, int r2, int c2, int K)
{
    int a[55][55][55];
    for (int i = 0; i < 55; ++i)
        for (int j = 0; j < 55; ++j)
            for (int k = 0; k < 55; ++k)
                a[i][j][k] = INT_MAX;
    int n = (int)(board).size(), m = (int)(board[0]).size();
    for (int i = 0; i <= K; ++i) 
        a[r1][c1][i] = 0;
    queue<pair<int, int> > q;
    q.push(make_pair(r1, c1));
    while (!q.empty()) {
        pair<int, int> ft = q.front();
        q.pop();
        for (int k = 0; k <= K; ++k) {
        int cnt = a[ft.first][ft.second][k];
        // cout << ft.first << " " << ft.second << " " << cnt << " " << k << " " << board[ft.first][ft.second] << endl;
        if (board[ft.first][ft.second] >= '1' && board[ft.first][ft.second] <= '9') {
            int delta = board[ft.first][ft.second] - '0';
                if (a[ft.first][ft.second][k] == INT_MAX) continue;
                for (int i = 0; i < 4; ++i) {
                    int nextx = ft.first + delta * dirx[i], nexty = ft.second + delta * diry[i];
                    if (nextx >= 0 && nexty >= 0 && nextx < n && nexty < m && cnt + 1 < a[nextx][nexty][k]) {
                        a[nextx][nexty][k] = cnt + 1;
                        q.push(make_pair(nextx, nexty));
                }
            }
        }
        if (board[ft.first][ft.second] == '.') {
                if (a[ft.first][ft.second][k] == INT_MAX) continue;
                for (int delta = 1; delta <= 9; ++delta) {
                    for (int i = 0; i < 4; ++i) {
                        int nextx = ft.first + delta * dirx[i], nexty = ft.second + delta * diry[i];
                        if (nextx >= 0 && nexty >= 0 && nextx < n && nexty < m && cnt + 1 < a[nextx][nexty][k + 1]) {
                            a[nextx][nexty][k + 1] = cnt + 1;
                            q.push(make_pair(nextx, nexty));
                    }
                }
            }
        }
    }
    }
    int res = INT_MAX;
    for (int i = 0; i <= K; ++i) res = min(res, a[r2][c2][i]);
    return res == INT_MAX ? -1 : res;
}
