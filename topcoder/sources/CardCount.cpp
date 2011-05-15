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

class CardCount {
public:
  vector <string> dealHands(int numPlayers, string deck);

};

vector <string> CardCount :: dealHands(int numPlayers, string deck)
{
  int n=deck.size()/numPlayers;
  vector<string> res(numPlayers);
  for (int i=0; i<n; ++i)
    for (int j=0; j<(res).size(); ++j) res[j].push_back(deck[numPlayers*i+j]);
  
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
        string retrunValueARRAY[] = { "000",  "111",  "222",  "333",  "444",  "555" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        CardCount theObject;
        eq(0, theObject.dealHands(6, "012345012345012345"),retrunValue);
    }
    {
        string retrunValueARRAY[] = { "123",  "123",  "123",  "123" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        CardCount theObject;
        eq(1, theObject.dealHands(4, "111122223333"),retrunValue);
    }
    {
        string retrunValueARRAY[] = { "012345012345012345" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        CardCount theObject;
        eq(2, theObject.dealHands(1, "012345012345012345"),retrunValue);
    }
    {
        string retrunValueARRAY[] = { "",  "",  "",  "",  "",  "" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        CardCount theObject;
        eq(3, theObject.dealHands(6, "01234"),retrunValue);
    }
    {
        string retrunValueARRAY[] = { "",  "" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        CardCount theObject;
        eq(4, theObject.dealHands(2, ""),retrunValue);
    }
}
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE
