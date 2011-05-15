/*
  ID:   rock2to1
  LANG: C++
  PROG: calfflac
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


bool check(char c)
{
	return (c>='a' && c<='z') || (c>='A' && c<='Z');
}

string palindrome(const string& s, int& num)
{
	int n = s.size();
	cout << n<<endl;
	int m = min(2000, n);
	int x = 0;
	while (!check(s[x]) && x != s.size()) x++;

	while (m > 0) {
		cout <<m<<endl;
		R(i, n-m+1) {
			int j = i;
			while (!check(s[j]) && j != s.size()) j++;
			int k = j;
			string tmp;
			int tm = m;
			while (tm > 0 && j != s.size()) {
				if (check(s[j])) {
					tmp += tolower(s[j]);
					tm--;
				}
				j++;
			}
			if (tm > 0) break;
			//cout <<tmp<<endl;
			if (tmp.size() == m) {
				string rtmp = tmp;
				reverse(A(rtmp));
				if (rtmp == tmp) {
					// cout <<k<<" ** "<<j<<endl;
					num = tmp.size();
					return s.substr(k, j-k);
				}
			}
		}
		m--;
	}
			
}

int main()
{
	ifstream fin("calfflac.in");
	ofstream fout("calfflac.out");

	string s;
	getline(fin, s, '\0');

	int num;
	string ret = palindrome(s, num);
	fout << num <<endl;
	fout << ret << endl;

	return 0;
}
