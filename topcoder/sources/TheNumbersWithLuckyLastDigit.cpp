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

class TheNumbersWithLuckyLastDigit
{ 
public: 
    int find(int n);
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 99; int Arg1 = 4; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { int Arg0 = 11; int Arg1 = 2; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { int Arg0 = 999999999; int Arg1 = -1; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { int Arg0 = 1234567; int Arg1 = 1; verify_case(3, Arg1, find(Arg0)); }

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
    TheNumbersWithLuckyLastDigit ___test; 
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

bool check(int n, int x)
{
    // int y = x;
    // int p = 1;
    // while (x) p *= 10, x /= 10;
    // if (n % p == y) return true;
    // else return false;
    return n % 10 == x % 10;
}

int TheNumbersWithLuckyLastDigit :: find(int n)
{
    set<int> st;
    queue<pair<int, int> > q;
    q.push(make_pair(4, 1));
    q.push(make_pair(7, 1));
    st.insert(4);
    st.insert(7);
    while (!q.empty()) {
        pair<int, int> x = q.front();
        q.pop();
        if (n >= x.first && check(n, x.first)) return x.second;
        int aux = x.first + 4;
        if (!((st).find(aux) != (st).end()) && aux <= n) {
            q.push(make_pair(aux, x.second + 1));
            st.insert(aux);
        }
        aux = x.first + 7;
        if (!((st).find(aux) != (st).end()) && aux <= n) {
            q.push(make_pair(aux, x.second + 1));
            st.insert(aux);
        }
    }
    return -1;
}
