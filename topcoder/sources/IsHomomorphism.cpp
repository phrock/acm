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

class IsHomomorphism {
public:
  vector <string> numBad(vector <string> source, vector <string> target, vector <int> mapping);

};

vector <string> IsHomomorphism :: numBad(vector <string> source, vector <string> target, vector <int> mapping)
{
  int n=source.size();
  vector< pair<int, int> > aux;
  for (int i=0; i<n; ++i)
    for (int j=0; j<n; ++j) {
      int x=mapping[source[i][j]-'0'];
      int y=target[mapping[i]][mapping[j]]-'0';
      // cout<<i<<" "<<j<<"   "<<x<<" "<<y<<endl;

      if (x!=y) aux.push_back(make_pair(i, j));
    }
  sort((aux).begin(), (aux).end());
  vector<string> res;
  for (int i=0; i<(aux).size(); ++i)
    res.push_back("("+*({stringstream ss; ss<<(aux[i].first); static string r; ss>>r; &r;})+","+*({stringstream ss; ss<<(aux[i].second); static string r; ss>>r; &r;})+")");
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
        string sourceARRAY[] = {"0000",
            "0123",
            "0202",
            "0321"};
        vector <string> source( sourceARRAY, sourceARRAY+ARRSIZE(sourceARRAY) );
        string targetARRAY[] = {"0000",
            "0123",
            "0202",
            "0321"};
        vector <string> target( targetARRAY, targetARRAY+ARRSIZE(targetARRAY) );
        int mappingARRAY[] = {0,1,2,3};
        vector <int> mapping( mappingARRAY, mappingARRAY+ARRSIZE(mappingARRAY) );
        IsHomomorphism theObject;
        eq(0, theObject.numBad(source, target, mapping),vector <string>());
    }
    {
        string sourceARRAY[] = {"0123456",
            "1234560",
            "2345601",
            "3456012",
            "4560123",
            "5601234",
            "6012345"};
        vector <string> source( sourceARRAY, sourceARRAY+ARRSIZE(sourceARRAY) );
        string targetARRAY[] = {"0123456",
            "1234560",
            "2345601",
            "3456012",
            "4560123",
            "5601234",
            "6012345"};
        vector <string> target( targetARRAY, targetARRAY+ARRSIZE(targetARRAY) );
        int mappingARRAY[] = {1,3,2,1,2,1,1};
        vector <int> mapping( mappingARRAY, mappingARRAY+ARRSIZE(mappingARRAY) );
        string retrunValueARRAY[] = { "(0,0)",  "(0,1)",  "(0,2)",  "(0,3)",  "(0,4)",  "(0,5)",  "(0,6)",  "(1,0)",  "(1,1)",  "(1,2)",  "(1,3)",  "(1,4)",  "(1,5)",  "(1,6)",  "(2,0)",  "(2,1)",  "(2,2)",  "(2,3)",  "(2,4)",  "(2,5)",  "(3,0)",  "(3,1)",  "(3,2)",  "(3,3)",  "(3,4)",  "(3,5)",  "(4,0)",  "(4,1)",  "(4,2)",  "(4,3)",  "(4,4)",  "(4,5)",  "(4,6)",  "(5,0)",  "(5,1)",  "(5,2)",  "(5,3)",  "(5,4)",  "(5,5)",  "(6,0)",  "(6,1)",  "(6,4)",  "(6,6)" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        IsHomomorphism theObject;
        eq(1, theObject.numBad(source, target, mapping),retrunValue);
    }
    {
        string sourceARRAY[] = {"012",
            "120",
            "210"};
        vector <string> source( sourceARRAY, sourceARRAY+ARRSIZE(sourceARRAY) );
        string targetARRAY[] = {"012",
            "120",
            "110"};
        vector <string> target( targetARRAY, targetARRAY+ARRSIZE(targetARRAY) );
        int mappingARRAY[] = {0,1,2};
        vector <int> mapping( mappingARRAY, mappingARRAY+ARRSIZE(mappingARRAY) );
        string retrunValueARRAY[] = { "(2,0)" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        IsHomomorphism theObject;
        eq(2, theObject.numBad(source, target, mapping),retrunValue);
    }
    {
        string sourceARRAY[] = {"012",
            "120",
            "210"};
        vector <string> source( sourceARRAY, sourceARRAY+ARRSIZE(sourceARRAY) );
        string targetARRAY[] = {"012",
            "120",
            "210"};
        vector <string> target( targetARRAY, targetARRAY+ARRSIZE(targetARRAY) );
        int mappingARRAY[] = {1,2,0};
        vector <int> mapping( mappingARRAY, mappingARRAY+ARRSIZE(mappingARRAY) );
        string retrunValueARRAY[] = { "(0,0)",  "(0,1)",  "(0,2)",  "(1,0)",  "(1,2)",  "(2,0)",  "(2,2)" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        IsHomomorphism theObject;
        eq(3, theObject.numBad(source, target, mapping),retrunValue);
    }
    {
        string sourceARRAY[] = {"01","10"};
        vector <string> source( sourceARRAY, sourceARRAY+ARRSIZE(sourceARRAY) );
        string targetARRAY[] = {"10","01"};
        vector <string> target( targetARRAY, targetARRAY+ARRSIZE(targetARRAY) );
        int mappingARRAY[] = {1,0};
        vector <int> mapping( mappingARRAY, mappingARRAY+ARRSIZE(mappingARRAY) );
        IsHomomorphism theObject;
        eq(4, theObject.numBad(source, target, mapping),vector <string>());
    }
}
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE
