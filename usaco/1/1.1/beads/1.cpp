/*
  ID:	rock2to1
  LANG:	C++
  PROG:	beads
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


int collect(int n, string beads)
{
	int m = 0;
	R(i, n) {
		int tmp = 0;
		
		char color;
		bool determined = false;
		F(j, i, i+n) {
			if (!determined) {
				color = beads[j];
				if (color != 'w') determined = true;
				tmp++;
				continue;
			}
			int k = j%n;
			if (beads[k] == color || beads[k] == 'w') tmp++;
			else break;
		}
		// cout << i<<": F: "<<tmp<<endl;

		determined = false;
		FD(j, i-1, i-n) {
			if (!determined) {
				color = beads[(j+n)%n];
				if (color != 'w') determined = true;
					tmp++;
					continue;
			}
			int k = (j+n)%n;
			if (beads[k] == color || beads[k] == 'w') tmp++;
			else break;
		}
		// cout << i<<": B: "<<tmp<<endl;
		if (tmp > m) m = tmp;
	}
	return m>n ? n : m;
}

int main()
{
	ifstream fin("beads.in");
	ofstream fout("beads.out");

	int n;
	string beads;
	fin >> n >> beads;

	fout << collect(n, beads) << endl;
	
	return 0;
}
