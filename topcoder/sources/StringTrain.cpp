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

class StringTrain {
public:
  string buildTrain(vector <string> cars);

};

string StringTrain :: buildTrain(vector <string> cars)
{
  string s=cars[0];
  for (int i=1; i<(cars).size(); ++i) {
    int k=min(cars[i].size()-1, s.size()-1);
    int len=0;
    for (len=k; len>=1; --len){
      if (s.substr(s.size()-len)==cars[i].substr(0, len)) break;
    }
    cout<<i<<" "<<len<<endl;
    if (len) s+=cars[i].substr(len);
  }
  cout<<s<<endl;
  set<char> st;
  string res;
  for (int i=(s).size()-1; i>=0; --i)
    if (!((st).find(s[i])!=(st).end())) res=s[i]+res, st.insert(s[i]);
  res=*({stringstream ss; ss<<(s.size()); static string r; ss>>r; &r;})+" "+res;
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
        string carsARRAY[] = {"ABCDE","CDFFF","CDE","CDEGG","GABC"};
        vector <string> cars( carsARRAY, carsARRAY+ARRSIZE(carsARRAY) );
        StringTrain theObject;
        eq(0, theObject.buildTrain(cars),"10 DEGABC");
    }
    {
        string carsARRAY[] = {"AAAAA","AAAAA","AAAAA"};
        vector <string> cars( carsARRAY, carsARRAY+ARRSIZE(carsARRAY) );
        StringTrain theObject;
        eq(1, theObject.buildTrain(cars),"7 A");
    }
    {
        string carsARRAY[] = {"CABABDABAB","CABAB","ABABDABAB","DABAB"};
        vector <string> cars( carsARRAY, carsARRAY+ARRSIZE(carsARRAY) );
        StringTrain theObject;
        eq(2, theObject.buildTrain(cars),"15 CDAB");
    }
    {
        string carsARRAY[] = {"ABABAB","ABABAB","ABABABAB","BZZZZZ"};
        vector <string> cars( carsARRAY, carsARRAY+ARRSIZE(carsARRAY) );
        StringTrain theObject;
        eq(3, theObject.buildTrain(cars),"15 ABZ");
    }
    {
        string carsARRAY[] = {"A","A","A","AA"};
        vector <string> cars( carsARRAY, carsARRAY+ARRSIZE(carsARRAY) );
        StringTrain theObject;
        eq(4, theObject.buildTrain(cars),"1 A");
    }
}
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE
