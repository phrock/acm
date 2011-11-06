#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <deque>
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

#define ALL(x)  (x).begin(), (x).end()
#define SIZE(x) (int)(x).size()
#define F(i, a, b)  for (int i=(a); i<(b); ++i)
#define R(i, n)  F(i, 0, n)
#define FE(i, a, b)  for (int i=(a); i<=(b); ++i)
#define RE(i, n)  FE(i, 0, n)
#define FD(i, a, b)  for (int i=(a); i>=(b); --i)
#define FSZ(i, a, v)  F(i, a, SIZE(v))
#define RSZ(i, v)  R(i, SIZE(v))
#define FA(i, x)  for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define UN(a) sort(ALL(a)), a.erase(unique(ALL(a)), a.end())
#define CL(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pf push_front
#define MP(a, b)  make_pair(a, b)

template<class T> inline void checkmin(T &a, T b) { if (b<a) a=b; }
template<class T> inline void checkmax(T &a, T b) { if (b>a) a=b; }
template<class T> void print(T A[], int n) { cout<<"{"; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", ";} cout<<"}"<<endl; }
template<class T> void print(vector<T> A, int n=-1) { if (n==-1) n=A.size(); cout<<"{"; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", "; } cout<<"}"<<endl; }
template<class T> void print(T A) { cout<<"{"; FA(i, A) { cout<<*i<<", "; } cout<<"}"<<endl; }
template<class T> inline void intToString(const T& a, string& s) { stringstream ss; ss<<a; s=ss.str(); }
template<class T> inline void stringToInt(const string& s, T& a) { istringstream iss(s); iss>>a; }
template<class T> inline T gcd(T a, T b) { while (b != 0) { T r=a%b; a=b; b=r; } return a; }


string romanNumber(int n)
{
    string result;

    int r1000 = n / 1000;
    R(i, r1000) result += "M";
    n %= 1000;

    if (n >= 900) { result += "CM"; n -= 900; }
    if (n >= 500) { result += "D"; n -= 500; }
    if (n >= 400) { result += "CD"; n -= 400; }
    int r100 = n / 100;
    R(i, r100) result += "C";
    n %= 100;

    if (n >= 90) { result += "XC"; n -= 90; }
    if (n >= 50) { result += "L"; n -= 50; }
    if (n >= 40) { result += "XL"; n -= 40; }
    int r10 = n / 10;
    R(i, r10) result += "X";
    n %= 10;

    if (n == 9) { result += "IX"; n -= 9; }
    if (n >= 5) { result += "V"; n -= 5; }
    if (n == 4) { result += "IV"; n-= 4; }
    int r1 = n;
    R(i, r1) result += "I";

    return result;
}

int decode(const string& s)
{
    int n = s.size();
    int result = 0;
    
    int i = 0;
    while (i<n && s[i] == 'M') { result += 1000; i++; }
    if (i+1 < n && s[i]=='C' && s[i+1]=='M') { result += 900; i += 2; }

    while (i<n && s[i] == 'D') { result += 500; i++; }
    if (i+1 < n && s[i]=='C' && s[i+1]=='D') { result += 400; i += 2; }

    while (i<n && s[i] == 'C') { result += 100; i++; }
    if (i+1 < n && s[i]=='X' && s[i+1]=='C') { result += 90; i += 2; }

    while (i<n && s[i] == 'L') { result += 50; i++; }
    if (i+1 < n && s[i]=='X' && s[i+1]=='L') { result += 40; i += 2; }

    while (i<n && s[i] == 'X') { result += 10; i++; }
    if (i+1 < n && s[i]=='I' && s[i+1]=='X') { result += 9; i += 2; }

    while (i<n && s[i] == 'V') { result += 5; i++; }
    if (i+1 < n && s[i]=='I' && s[i+1]=='V') { result += 4; i += 2; }

    while (i<n && s[i] == 'I') { result++; i++; }

    return result;
}

int main()
{
    // map<string, int> m;
    // FE(i, 1, 5000) m[romanNumber(i)]++;

    int result = 0;
    string s;
    while (cin >> s) {
	int n = decode(s);
	string r = romanNumber(n);
	result += s.size()-r.size();
    }
    
    cout << result << endl;

    // FE(i, 1, 5000) { cout << i<<" "<<romanNumber(i)<<" "<<decode(romanNumber(i))<<endl;  if (i != decode(romanNumber(i))) {cout<<"XXXXXXX"<<endl;break;}}
}
