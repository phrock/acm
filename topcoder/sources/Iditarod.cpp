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

class Iditarod {
public:
  int avgMinutes(vector <string> times);

};

int Iditarod :: avgMinutes(vector <string> times)
{
  double total=0;
  for (int i=0; i<(times).size(); ++i) {
    times[i][2]=times[i][8]=' ';
    stringstream is(times[i]);
    int h, m, n;
    string s, d;
    is>>h>>m>>s>>d>>n;
    h%=12;
    if (s=="PM") h+=12;
    m+=h*60;
    m-=8*60;
    total+=m+(n-1)*24*60;
  }
  total/=times.size();
  int res=round(total);
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
        string timesARRAY[] = {"12:00 PM, DAY 1","12:01 PM, DAY 1"};
        vector <string> times( timesARRAY, timesARRAY+ARRSIZE(timesARRAY) );
        Iditarod theObject;
        eq(0, theObject.avgMinutes(times),241);
    }
    {
        string timesARRAY[] = {"12:00 AM, DAY 2"};
        vector <string> times( timesARRAY, timesARRAY+ARRSIZE(timesARRAY) );
        Iditarod theObject;
        eq(1, theObject.avgMinutes(times),960);
    }
    {
        string timesARRAY[] = {"02:00 PM, DAY 19","02:00 PM, DAY 20", "01:58 PM, DAY 20"};
        vector <string> times( timesARRAY, timesARRAY+ARRSIZE(timesARRAY) );
        Iditarod theObject;
        eq(2, theObject.avgMinutes(times),27239);
    }
}
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE
