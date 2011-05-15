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

class FoldThePaper
{ 
public: 
    int getValue(vector <string> paper);
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
"1 1 1",
"1 1 1"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(0, Arg1, getValue(Arg0)); }
	void test_case_1() { string Arr0[] = {
"1 -1",
"1 -1"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, getValue(Arg0)); }
	void test_case_2() { string Arr0[] = {
"1 -1 -1 1",
"-1 -1 -1 -1",
"-1 -1 -1 -1",
"1 -1 -1 1"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, getValue(Arg0)); }
	void test_case_3() { string Arr0[] = {
"20 13 -2 100",
"-12 0 4 -3",
"4 1 -36 21"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 131; verify_case(3, Arg1, getValue(Arg0)); }
	void test_case_4() { string Arr0[] = {
"0"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(4, Arg1, getValue(Arg0)); }

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
    FoldThePaper ___test; 
    ___test.run_test(0); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

template<class T> vector<T> split(const string& s, const string& delim =" ") {
    vector<string> aux;
    string t;
    for (int i=0; i!=(int)(s).size(); i++)
	if (delim.find(s[i])!=string::npos) { if (!t.empty()) { aux.push_back(t); t=""; } }
	else t+=s[i];
    if (!t.empty()) aux.push_back(t);
    vector<T> res;
    for (int i=0; i<(int)(aux).size(); ++i)
	res.push_back(*({stringstream ss; ss<<(aux[i]); static T _; ss>>_; &_;}));
    return res;
}

set<vector<vector<int> > > st;
void dfs(const vector<vector<int> > &v, int &res)
{
    if (((st).find(v)!=(st).end())) return;
    st.insert(v);
    #ifdef DEBUG
    print2(v);    
    #endif
    for (int i=0; i<(int)(v).size(); ++i)
	for (int j=0; j<(int)(v[i]).size(); ++j)
	    res=max(res, v[i][j]);
    for (int i=1; i<(int)(v).size(); ++i) {
	int a=i, b=(int)(v).size()-a, x=max(a, b), y=(int)(v[0]).size();
	vector<vector<int> > next(x, vector<int>(y));
	for (int p=0; p<x; ++p)
	    for (int q=0; q<y; ++q) {
		int t1=p<=b?v[p+a][q]:0, t2=p<=a-1?v[a-1-p][q]:0;
		next[p][q]=t1+t2;
	    }
	dfs(next, res);
    }
    for (int j=1; j<(int)(v[0]).size(); ++j) {
	int a=j, b=(int)(v[0]).size()-a, x=(int)(v).size(), y=max(a, b);
	vector<vector<int> > next(x, vector<int>(y));
	for (int p=0; p<x; ++p)
	    for (int q=0; q<y; ++q) {
		int t1=q<=b?v[p][q+a]:0, t2=q<=a-1?v[p][a-1-q]:0;
		next[p][q]=t1+t2;
	    }
	dfs(next, res);
    }
}

int FoldThePaper :: getValue(vector <string> paper)
{
    vector<vector<int> > v;
    for (int i=0; i<(int)(paper).size(); ++i) {
	vector<int> aux=split<int>(paper[i]);
	v.push_back(aux);
    }
    #ifdef DEBUG
    print2(v);    
    #endif
    st.clear();
    int res=INT_MIN;
    dfs(v, res);
    return res;
}
