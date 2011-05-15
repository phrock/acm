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

class TennisRallies {
public:
  int howMany(int numLength, vector <string> forbidden, int allowed);
  int res;
  vector<string>  v;
  int n;
  string s;
  int allo;
  void go(int cur)
  {
    // cout<<cur<<endl;
    // cout<<s<<endl;
    if (cur>=allo) return;
    if (s.size()==n) { res++; return;}
    for (int i=0; i<2; ++i) {
      char c=i?'c':'d';
      s+=c;
      int cnt=0;
      for (int i=0; i<(v).size(); ++i)
	if (s.size()>=v[i].size() && v[i]==s.substr(s.size()-v[i].size()))
	  cnt++;
      go(cur+cnt);
      s.erase(--s.end());
    }
  }
};

int TennisRallies :: howMany(int numLength, vector <string> forbidden, int allowed)
{
  res=0;
  allo=allowed;
  n=numLength;
  v=forbidden;
  go(0);
  return res;
}

// int TennisRallies :: howMany(int numLength, vector <string> forbidden, int allowed)
// {
//   int res=0;
//   for (int i=0; i<(1<<numLength); ++i) {
//     string s;
//     for (int j=0; j<numLength; ++j)
//       if (i & (1<<j)) s+='c';
//       else s+='d';
//     int cnt=0;
//     for (int j=0; j<(forbidden).size(); ++j)
//       for (int k=0; k<(s).size(); ++k)
// 	if (s.size()-k>=forbidden[j].size() && forbidden[j]==s.substr(k, forbidden[j].size())) { cnt++; if (cnt>=allowed) goto out; }
//   out:
//     if (cnt<allowed) res++;
//   }
//   return res;
// }

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
        string forbiddenARRAY[] = {"cc","dd"};
        vector <string> forbidden( forbiddenARRAY, forbiddenARRAY+ARRSIZE(forbiddenARRAY) );
        TennisRallies theObject;
        eq(0, theObject.howMany(3, forbidden, 1),2);
    }
    {
        string forbiddenARRAY[] = {"c"};
        vector <string> forbidden( forbiddenARRAY, forbiddenARRAY+ARRSIZE(forbiddenARRAY) );
        TennisRallies theObject;
        eq(1, theObject.howMany(10, forbidden, 1),1);
    }
    {
        string forbiddenARRAY[] = {"c"};
        vector <string> forbidden( forbiddenARRAY, forbiddenARRAY+ARRSIZE(forbiddenARRAY) );
        TennisRallies theObject;
        eq(2, theObject.howMany(10, forbidden, 2),11);
    }
    {
        string forbiddenARRAY[] = {"c","d"};
        vector <string> forbidden( forbiddenARRAY, forbiddenARRAY+ARRSIZE(forbiddenARRAY) );
        TennisRallies theObject;
        eq(3, theObject.howMany(18, forbidden, 1),0);
    }
    {
        TennisRallies theObject;
        eq(4, theObject.howMany(18, vector <string>(), 1),262144);
    }
    {
        string forbiddenARRAY[] = {"c","cc","ccc","cccc","ccccc","cccccc","ccccccc",
            "cccccccc","ccccccccc","cccccccccc"};
        vector <string> forbidden( forbiddenARRAY, forbiddenARRAY+ARRSIZE(forbiddenARRAY) );
        TennisRallies theObject;
        eq(5, theObject.howMany(18, forbidden, 100),262122);
    }
}
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE
