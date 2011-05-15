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

class HanoiGoodAndBad {
public:
  int moves(int N, int Dave);
  void dfs1(set<int>& a,  set<int> &b,  set<int> &c, int n)
  {
    // cout<<a<<b<<c<<" "<<p1<<" "<<dd<<endl;
    // printv(a);
    // printv(b);
    // printv(c);
    if (n>0 &&!f1) {
      dfs1(a, c, b, n-1);
      p1++;
      int tt=*a.begin();
      a.erase(a.begin());
      b.insert(tt);
      // cout<<"** "<<p1<<" "<<dd<<endl;
      if (p1==dd) { cout<<"ha"<<endl;x=a; y=b; z=c; f1=true; return; }
      if (f1) return;
      dfs1(c, b, a, n-1);
    }
  }
  void dfs2(set<int>& a, set<int> &b, set<int> &c, int n)
  {
    if (n>0&&!f2) {
      dfs2(a, b, c, n-1);
      int tt=*a.begin();
      a.erase(a.begin());
      c.insert(tt);
      p2++;
      if (a==x && b==y && c==z) { if(!f2) res=p2;f2=true; return; }
      if (f2)return;
      dfs2(b, a, c, n-1);
      int tt2=*c.begin();
      c.erase(c.begin());
      b.insert(tt2);
      p2++;
      if (a==x && b==y && c==z) { if(!f2)res=p2;f2=true; return; }
      if (f2)return;
      dfs2(a, b, c, n-1);
    }
  }
  int p1,p2;
  set<int> x,y,z;
  bool f1, f2;
  int dd;
  int res;
};

int HanoiGoodAndBad :: moves(int N, int Dave)
{
  set<int> st1, st2, st3;
  for (int i=1; i<=N; ++i) st1.insert(i);
  dd=Dave;
  p2=0;
  p1=0;
  f1=f2=false;
  // cout<<"kk"<<endl;
  dfs1(st1, st2, st3, N);
  // cout<<x<<" "<<y<<" "<<z<<endl;
  // cout<<"ff"<<endl;
  set<int> s1, s2, s3;
  for (int i=1; i<=N; ++i) s1.insert(i);
  dfs2(s1, s2, s3, N);
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
        HanoiGoodAndBad theObject;
        eq(0, theObject.moves(3, 1),2);
    }
    {
        HanoiGoodAndBad theObject;
        eq(1, theObject.moves(4, 15),80);
    }
    {
        HanoiGoodAndBad theObject;
        eq(2, theObject.moves(9, 265),16418);
    }
}
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE
