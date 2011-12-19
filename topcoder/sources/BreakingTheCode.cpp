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

class BreakingTheCode
{ 
public: 
    string decodingEncoding(string code, string message);
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "abcdefghijklmnopqrstuvwxyz"; string Arg1 = "test"; string Arg2 = "20051920"; verify_case(0, Arg2, decodingEncoding(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "abcdefghijklmnopqrstuvwxyz"; string Arg1 = "20051920"; string Arg2 = "test"; verify_case(1, Arg2, decodingEncoding(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "qesdfvujrockgpthzymbnxawli"; string Arg1 = "mwiizkelza"; string Arg2 = "19242626171202251723"; verify_case(2, Arg2, decodingEncoding(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "faxmswrpnqdbygcthuvkojizle"; string Arg1 = "02170308060416192402"; string Arg2 = "ahxpwmtvza"; verify_case(3, Arg2, decodingEncoding(Arg0, Arg1)); }

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
    BreakingTheCode ___test; 
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

string BreakingTheCode :: decodingEncoding(string code, string message)
{
    map<char, string> mp;
    map<string, char> mp2;
    for (int i = 0; i < 26; ++i) {
        string x = *({stringstream ss; ss << (i + 1); static string _; ss >> _; &_;});
        if ((int)(x).size() == 1)
            x = "0" + x;
        mp[code[i]] = x;
        mp2[x] = code[i];
    }
    #ifdef DEBUG
    printp(mp);
    #endif
    string res;
    if (isdigit(message[0])) {
        for (int i = 0; i < (int)(message).size(); ++i, ++i)
            res += mp2[message.substr(i, 2)];
    } else {
        for (int i = 0; i < (int)(message).size(); ++i)
            res += mp[message[i]];
    }
    return res;
}
