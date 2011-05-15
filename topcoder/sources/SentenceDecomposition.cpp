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

class SentenceDecomposition
{ 
public: 
    int decompose(string sentence, vector <string> validWords);
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "neotowheret"; string Arr1[] = {"one", "two", "three", "there"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; verify_case(0, Arg2, decompose(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "abba"; string Arr1[] = {"ab", "ac", "ad"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, decompose(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "thisismeaningless"; string Arr1[] = {"this", "is", "meaningful"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, decompose(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ommwreehisymkiml"; string Arr1[] = {"we", "were", "here", "my", "is", "mom", "here", "si", "milk", "where", "si"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(3, Arg2, decompose(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "ogodtsneeencs"; string Arr1[] = {"go", "good", "do", "sentences", "tense", "scen"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; verify_case(4, Arg2, decompose(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "sepawaterords"; string Arr1[] = {"separate","words"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(5, Arg2, decompose(Arg0, Arg1)); }

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
    SentenceDecomposition ___test; 
    ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

int res;
string s;
vector<string> va;
vector<string> vb;

const int inf=1000000;

int func(string a, string b)
{
    string a2=a, b2=b;
    sort((a2).begin(), (a2).end());
    sort((b2).begin(), (b2).end());
    if (a2!=b2) return inf;
    int cnt=0;
    for (int i=0; i<(int)(a).size(); ++i)
	if (a[i]!=b[i]) cnt++;
    return cnt;
}

int SentenceDecomposition :: decompose(string sentence, vector <string> validWords)
{
    int n=(int)(sentence).size();
    vector<int> dp(n+1, inf);
    dp[0]=0;
    for (int i=0; i<n; ++i)
	if (dp[i]!=inf) {
	    for (int j=i; j<n; ++j)
		for (int k=0; k<(int)(validWords).size(); ++k)
		    dp[j+1]=min(dp[j+1], dp[i]+func(validWords[k], sentence.substr(i, j-i+1)));
	}
    return dp[n]==inf?-1:dp[n];
}
