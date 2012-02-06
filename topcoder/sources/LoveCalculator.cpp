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

class LoveCalculator
{ 
public: 
    string findBoy(string girl, vector <string> boys);
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "LOVE"; string Arr1[] = {"JACOB","FRANK","DANO"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "FRANK"; verify_case(0, Arg2, findBoy(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "JANE"; string Arr1[] = {"THOMAS","MICHAEL","INDY","LIU"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "INDY"; verify_case(1, Arg2, findBoy(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "LILLY"; string Arr1[] = {"PIERRE"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "PIERRE"; verify_case(2, Arg2, findBoy(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "MERYLOV"; string Arr1[] = {"JOHN","DAVE","STEVE","JOHN","DAVE"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "DAVE"; verify_case(3, Arg2, findBoy(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "LLOL"; string Arr1[] = {"BVERON","CVERON","AVERON","DVERON"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "AVERON"; verify_case(4, Arg2, findBoy(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "VELYLEOCEVE"; string Arr1[] = {"YVXHOVE","LCOKO","OGWSJVEVEDLE","WGFVSJEL","VLOLUVCBLLQVESWHEEKC"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "VLOLUVCBLLQVESWHEEKC"; verify_case(5, Arg2, findBoy(Arg0, Arg1)); }

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
    LoveCalculator ___test; 
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

int func(string a, string b)
{
    map<char, int> mp;
    string s = "LOVE";
    for (int i = 0; i < (int)(a).size(); ++i)
        if ((find((s).begin(), (s).end(), a[i]) != (s).end()))
            ++mp[a[i]];
    for (int i = 0; i < (int)(b).size(); ++i)
        if ((find((s).begin(), (s).end(), b[i]) != (s).end()))
            ++mp[b[i]];
    vector<int> v;
    for (__typeof((mp).begin()) i = (mp).begin(); i != (mp).end(); ++i)
        v.push_back(i->second);
    while ((int)(v).size() != 4)
        v.push_back(0);
    int res = 1;
    for (int i = 0; i < 4; ++i)
        for (int j = i + 1; j < 4; ++j)
            res = (res * (v[i] + v[j])) % 100;
    return res;
}

string LoveCalculator :: findBoy(string girl, vector <string> boys)
{
    sort((boys).begin(), (boys).end());
    int res = INT_MIN;
    string s = boys[0];
    for (int i = 0; i < (int)(boys).size(); ++i) {
        int aux = func(girl, boys[i]);
        if (aux > res) {
            res = aux;
            s = boys[i];
        }
    }
    return s;
}
