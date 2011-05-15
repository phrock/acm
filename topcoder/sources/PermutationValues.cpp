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

class PermutatifonValues {
public:
  vector <int> getValues(vector <int> lows, vector <int> highs, string lexPos, vector <string> retInts);

};

vector <int> PermutationValues :: getValues(vector <int> lows, vector <int> highs, string lexPos, vector <string> retInts)
{
  
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
        int lowsARRAY[] = {1};
        vector <int> lows( lowsARRAY, lowsARRAY+ARRSIZE(lowsARRAY) );
        int highsARRAY[] = {4};
        vector <int> highs( highsARRAY, highsARRAY+ARRSIZE(highsARRAY) );
        string retIntsARRAY[] = {"0","1","2","3"};
        vector <string> retInts( retIntsARRAY, retIntsARRAY+ARRSIZE(retIntsARRAY) );
        int retrunValueARRAY[] = { 1,  2,  3,  4 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PermutationValues theObject;
        eq(0, theObject.getValues(lows, highs, "0", retInts),retrunValue);
    }
    {
        int lowsARRAY[] = {1};
        vector <int> lows( lowsARRAY, lowsARRAY+ARRSIZE(lowsARRAY) );
        int highsARRAY[] = {3};
        vector <int> highs( highsARRAY, highsARRAY+ARRSIZE(highsARRAY) );
        string retIntsARRAY[] = {"0","1","2"};
        vector <string> retInts( retIntsARRAY, retIntsARRAY+ARRSIZE(retIntsARRAY) );
        int retrunValueARRAY[] = { 3,  2,  1 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PermutationValues theObject;
        eq(1, theObject.getValues(lows, highs, "5", retInts),retrunValue);
    }
    {
        int lowsARRAY[] = {1,16};
        vector <int> lows( lowsARRAY, lowsARRAY+ARRSIZE(lowsARRAY) );
        int highsARRAY[] = {5,20};
        vector <int> highs( highsARRAY, highsARRAY+ARRSIZE(highsARRAY) );
        string retIntsARRAY[] = {"0","1","2","3","4","5","6","7","8","9","1","2","3"};
        vector <string> retInts( retIntsARRAY, retIntsARRAY+ARRSIZE(retIntsARRAY) );
        int retrunValueARRAY[] = { 3,  18,  19,  4,  20,  2,  16,  17,  1,  5,  18,  19,  4 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PermutationValues theObject;
        eq(2, theObject.getValues(lows, highs, "1000000", retInts),retrunValue);
    }
    {
        int lowsARRAY[] = {1};
        vector <int> lows( lowsARRAY, lowsARRAY+ARRSIZE(lowsARRAY) );
        int highsARRAY[] = {5};
        vector <int> highs( highsARRAY, highsARRAY+ARRSIZE(highsARRAY) );
        string retIntsARRAY[] = {"0","1","2","3","4"};
        vector <string> retInts( retIntsARRAY, retIntsARRAY+ARRSIZE(retIntsARRAY) );
        int retrunValueARRAY[] = { 2,  4,  5,  3,  1 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PermutationValues theObject;
        eq(3, theObject.getValues(lows, highs, "100000000000001", retInts),retrunValue);
    }
    {
        int lowsARRAY[] = {-1000000000,500000};
        vector <int> lows( lowsARRAY, lowsARRAY+ARRSIZE(lowsARRAY) );
        int highsARRAY[] = {0,2000000000};
        vector <int> highs( highsARRAY, highsARRAY+ARRSIZE(highsARRAY) );
        string retIntsARRAY[] = {"2999500000","1234123","123344","9293939","2999500001","2999499950"};
        vector <string> retInts( retIntsARRAY, retIntsARRAY+ARRSIZE(retIntsARRAY) );
        int retrunValueARRAY[] = { 1999999987,  -998765877,  -999876656,  -990706061,  1999999982,  1999999949 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PermutationValues theObject;
        eq(4, theObject.getValues(lows, highs, "99999999999999999", retInts),retrunValue);
    }
    {
        int lowsARRAY[] = {9};
        vector <int> lows( lowsARRAY, lowsARRAY+ARRSIZE(lowsARRAY) );
        int highsARRAY[] = {9};
        vector <int> highs( highsARRAY, highsARRAY+ARRSIZE(highsARRAY) );
        string retIntsARRAY[] = {"0"};
        vector <string> retInts( retIntsARRAY, retIntsARRAY+ARRSIZE(retIntsARRAY) );
        int retrunValueARRAY[] = { 9 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PermutationValues theObject;
        eq(5, theObject.getValues(lows, highs, "999999", retInts),retrunValue);
    }
    {
        int lowsARRAY[] = {0,-100,101};
        vector <int> lows( lowsARRAY, lowsARRAY+ARRSIZE(lowsARRAY) );
        int highsARRAY[] = {99,-11,100000000};
        vector <int> highs( highsARRAY, highsARRAY+ARRSIZE(highsARRAY) );
        string retIntsARRAY[] = {"4","100000087","7"};
        vector <string> retInts( retIntsARRAY, retIntsARRAY+ARRSIZE(retIntsARRAY) );
        int retrunValueARRAY[] = { -96,  99999993,  -93 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PermutationValues theObject;
        eq(6, theObject.getValues(lows, highs, "100000000000009", retInts),retrunValue);
    }
}
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE
