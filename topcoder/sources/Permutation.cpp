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
// BEGIN CUT HERE
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void printv(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void printv2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE


class Permutation {
public:
  string best(int n);
};

string Permutation :: best(int n)
{
  int m=-1;
  for (int i=1; i<20000; ++i) {
    int sum=0;
    int tmp=0;
    int k=i;
    for (int j=2; j<=i; ++j) {
      tmp=0;
      while (k%j==0) tmp+=j, k/=j;
    }
    sum+=tmp;
    if (sum<=n) m=i;
  }
  cout<<m<<endl;
  vector<int> v;
  int tmp=0;
  for (int i=2; i<=m; ++i) {
    tmp=0;
    while (m%i==0) tmp+=i, m/=i;
    if (tmp) v.push_back(tmp);
  }
  int sum=0;
  for (int i=0; i<(v).size(); ++i) sum+=v[i];
  for (int i=0; i<n-sum; ++i) v.push_back(1);
  sort((v).begin(), (v).end());
  string res;
  string t;
  for (int i=0; i<26; ++i) t+='A'+i;
  for (int i=0; i<26; ++i) t+='a'+i;
  // cout<<t<<endl;
  for (int i=0; i<(v).size(); ++i) {
    res+=t[v[i]-1];
  }
  return res;
}

// BEGIN CUT HERE
////////////////////////////////////////////////////////////////////////////////
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

template<typename T> void print( T a ) {
  cout << a;
}
static void print( long long a ) {
  cout << a << "L";
}
static void print( string a ) {
  cout << '"' << a << '"';
}
template<typename T> void print( vector<T> a ) {
  cout << "{";
  for ( int i = 0 ; i != a.size() ; i++ ) {
    if ( i != 0 ) cout << ", ";
    print( a[i] );
  }
  cout << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
  if ( have == need ) {
    cout << "Case " << n << " passed." << endl;
  } else {
    cout << "Case " << n << " failed: expected ";
    print( need );
    cout << " received ";
    print( have );
    cout << "." << endl;
  }
  cout << endl;
}
template<typename T> void eq( int n, vector<T> have, vector<T> need ) {
  if( have.size() != need.size() ) {
    cout << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
    print( have );
    print( need );
    return;
  }
  for( int i= 0; i < have.size(); i++ ) {
    if( have[i] != need[i] ) {
      cout << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
      print( have );
      print( need );
      return;
    }
  }
  cout << "Case " << n << " passed." << endl;
  cout << endl;
}
static void eq( int n, string have, string need ) {
  if ( have == need ) {
    cout << "Case " << n << " passed." << endl;
  } else {
    cout << "Case " << n << " failed: expected ";
    print( need );
    cout << " received ";
    print( have );
    cout << "." << endl;
  }
  cout << endl;
}

int main(int argc, char* argv[])
{
  {
    Permutation theObject;
        eq(0, theObject.best(6),"ACBEFD");
  }
  {
        Permutation theObject;
        eq(1, theObject.best(7),"BCAEFGD");
  }
    {
        Permutation theObject;
        eq(2, theObject.best(29),"BCDEAGHIJKLFNOPQRSTMVWXYZabcU");
    }
    {
        Permutation theObject;
        eq(3, theObject.best(1),"A");
    }
    {
        Permutation theObject;
        eq(4, theObject.best(8),"BCAEFGHD");
    }
    {
        Permutation theObject;
        eq(5, theObject.best(3),"BCAEFGHD");
    }
}
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE
