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

class LongNumber
{ 
public: 
  int findDigit(int k);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; verify_case(0, Arg1, findDigit(Arg0)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 1; verify_case(1, Arg1, findDigit(Arg0)); }
	void test_case_2() { int Arg0 = 78; int Arg1 = 5; verify_case(2, Arg1, findDigit(Arg0)); }
	void test_case_3() { int Arg0 = 1000000; int Arg1 = 6; verify_case(3, Arg1, findDigit(Arg0)); }
	void test_case_4() { int Arg0 = 1780243932; int Arg1 = 1; verify_case(4, Arg1, findDigit(Arg0)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  LongNumber ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

long long f1(long long k)
{
  long long x=1;
  long long n=9;
  while (true) {
    if (k<=x*n) break;
    else { k-=x*n; n*=10; x++; }
  }
  long long start=1;
  for (long long i=0; i<x-1; ++i) start*=10;
  long long m=k/x;
  start+=m;
  long long res;
  if (k%x==0) res=(start-1)%10;
  else {
    string s=*({stringstream ss; ss<<(start); static string r; ss>>r; &r;});
    res=s[k%x-1]-'0';
  }
  return res;
}

long long f2(long long k)
{
  // cout<<k<<endl;
  long long x=1;
  long long y=1;
  long long z=0;
  while (true) {
    y*=10LL;
    long long tmp=sqrt(y-1)-z;
    if (k<=x*tmp) break;
    else { k-=x*tmp; x++; }
    z+=tmp;
  }
  cout<<k<<endl;
  cout<<z<<" : "<<k<<" "<<x<<endl;
  long long start=z+1;
  long long m=k/x;
  start+=m;
  cout<<m<<" "<<start<<endl;
  cout<<k<<" "<<x<<endl;
  long long res;
  if (k%x==0) res=(start-1)*(start-1)%10;
  else {
    string s=*({stringstream ss; ss<<(start*start); static string r; ss>>r; &r;});
    res=s[k%x-1]-'0';
  }
  return res;
}

int LongNumber :: findDigit(int k)
{
  int a=f1(k);
  int b=f2(k);
  cout<<a<<" "<<b<<endl;

  long long  res=a+b;
  while (true) {
    k++;
    cout<<"***********"<<endl;
    int a=f1(k);
    int b=f2(k);
    cout<<"  ** "<<a<<" "<<b<<endl;
    if (a+b>9) { res++; break; }
    else if (a+b<9) break;
  }
  res%=10;
  cout<<INT_MAX<<endl;
  return res;
}
