/*
  ID:   rock2to1
  LANG: C++
  PROG: namenum
*/

#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef long long LL;
typedef vector< int > VI;
typedef vector< VI > VVI;
typedef vector< LL > VLL;
typedef vector< VLL > VVLL;
typedef vector< double > VD;
typedef vector< string > VS;
typedef istringstream ISS;

#define A(x)  (x).begin(), (x).end()
#define SIZE(x) (int)(x).size()
#define F(i, a, b)  for (int i=(a); i<(b); ++i)
#define R(i, n)  F(i, 0, n)
#define FE(i, a, b)  for (int i=(a); i<=(b); ++i)
#define RE(i, n)  FE(i, 0, n)
#define FD(i, a, b)  for (int i=(a); i>=(b); --i)
#define FSZ(i, a, v)  F(i, a, SIZE(v))
#define RSZ(i, v)  R(i, SIZE(v))
#define FA(i, a, x)  for (__typeof((x).begin()) i=(a); i!=(x).end(); ++i)
#define RA(i, x)  for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define UN(a) sort(A(a)), a.erase(unique(A(a)), a.end())
#define CL(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pf push_front
#define MP(a, b)  make_pair(a, b)

template<class T> inline void checkmin(T &a, T b) { if (b<a) a=b; }
template<class T> inline void checkmax(T &a, T b) { if (b>a) a=b; }
template<class T> void print(T A[], int n) { cout<<"{"; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", ";} cout<<"}"<<endl; }
template<class T> void print(vector<T> A, int n=-1) { if (n==-1) n=A.size(); cout<<"{"; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", "; } cout<<"}"<<endl; }
template<class T> void print(T A) { cout<<"{"; RA(i, A) { cout<<*i<<", "; } cout<<"}"<<endl; }
template<class T> inline void intToString(const T& a, string& s) { stringstream ss; ss<<a; s=ss.str(); }
template<class T> inline void stringToInt(const string& s, T& a) { istringstream iss(s); iss>>a; }
template<class T> inline T gcd(T a, T b) { while (b != 0) { T r=a%b; a=b; b=r; } return a; }


bool check(string x, const set<string>& dict)
{
	int n = x.size();
	RA(i, dict) if (x == (*i).substr(0, n)) return true;
	return false;
}

void dfs(string s, map<char, string>& phone, const set<string>& dict,
	 set<string>& ret, string tmp)
{
	if (tmp.size() == s.size()) {
		if (dict.find(tmp) != dict.end()) ret.insert(tmp);
		return;
	}

	int n = tmp.size();
	char c = s[n];
	RSZ(i, phone[c]) {
		string x = tmp+phone[c][i];
		if (check(x, dict))
			dfs(s, phone, dict, ret, x);
	}
}


set<string> name(string s)
{
	set<string> ret;

	ifstream fin("dict.txt");
	set<string> dict;
	string x;
	while (fin >> x) {
		dict.insert(x);
	}

	map<char, string> phone;
	phone['2'] = "ABC";
	phone['3'] = "DEF";
	phone['4'] = "GHI";
	phone['5'] = "JKL";
	phone['6'] = "MNO";
	phone['7'] = "PRS";
	phone['8'] = "TUV";
	phone['9'] = "WXY";

	string tmp;
	dfs(s, phone, dict, ret, tmp);

	return ret;
}

int main()
{
	ifstream fin("namenum.in");
	ofstream fout("namenum.out");

	string s;
	fin >> s;

	set<string> ret = name(s);
	if (ret.size() == 0) fout << "NONE" << endl;
	else RA(i, ret) fout << *i << endl;
	
	return 0;
}
