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

template<class T> inline void printv2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE

class PaperFold {
public:
  int numFolds(vector <int> paper, vector <int> box);

};

int PaperFold :: numFolds(vector <int> paper, vector <int> box)
{
  int res=-1;
  vector<double> start;
  if (paper[0]>paper[1]) swap(paper[0], paper[1]);
  if (box[0]>box[1]) swap(box[0], box[1]);
  start.push_back(paper[0]); start.push_back(paper[1]); start.push_back(0);
  queue<vector<double> >q;
  q.push(start);
  while (!q.empty()) {
    vector<double> x=q.front();
    q.pop();
    if (x[2]>8) continue;
    if (x[0]<=box[0] && x[1]<=box[1]) {res=x[2]; break;}
    double a=x[0]/2;
    vector<double> next(3);
    next[0]=a; next[1]=x[1]; next[2]=x[2]+1;
    q.push(next);
    double b=x[1]/2;
    next[0]=min(b, x[0]); next[1]=max(b, x[0]); next[2]=x[2]+1;
    q.push(next);
  }
  return res;
}

// BEGIN CUT HERE
////////////////////////////////////////////////////////////////////////////////
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

// template<typename T> void print( T a ) {
//   cout << a;
// }
static void print( long long a ) {
  cout << a << "L";
}
// static void print( string a ) {
//   cout << '"' << a << '"';
// }
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
// static void eq( int n, string have, string need ) {
//   if ( have == need ) {
//     cout << "Case " << n << " passed." << endl;
//   } else {
//     cout << "Case " << n << " failed: expected ";
//     print( need );
//     cout << " received ";
//     print( have );
//     cout << "." << endl;
//   }
//   cout << endl;
// }

int main(int argc, char* argv[])
{
      {
        int paperARRAY[] = {8, 11};
        vector <int> paper( paperARRAY, paperARRAY+ARRSIZE(paperARRAY) );
        int boxARRAY[] = {6, 10};
        vector <int> box( boxARRAY, boxARRAY+ARRSIZE(boxARRAY) );
        PaperFold theObject;
        eq(0, theObject.numFolds(paper, box),1);
    }
    {
        int paperARRAY[] = {11, 17};
        vector <int> paper( paperARRAY, paperARRAY+ARRSIZE(paperARRAY) );
        int boxARRAY[] = {6, 4};
        vector <int> box( boxARRAY, boxARRAY+ARRSIZE(boxARRAY) );
        PaperFold theObject;
        eq(1, theObject.numFolds(paper, box),4);
    }
    {
        int paperARRAY[] = {11, 17};
        vector <int> paper( paperARRAY, paperARRAY+ARRSIZE(paperARRAY) );
        int boxARRAY[] = {5, 4};
        vector <int> box( boxARRAY, boxARRAY+ARRSIZE(boxARRAY) );
        PaperFold theObject;
        eq(2, theObject.numFolds(paper, box),4);
    }
    {
        int paperARRAY[] = {1000,1000};
        vector <int> paper( paperARRAY, paperARRAY+ARRSIZE(paperARRAY) );
        int boxARRAY[] = {62,63};
        vector <int> box( boxARRAY, boxARRAY+ARRSIZE(boxARRAY) );
        PaperFold theObject;
        eq(3, theObject.numFolds(paper, box),-1);
    }
    {
        int paperARRAY[] = {100,30};
        vector <int> paper( paperARRAY, paperARRAY+ARRSIZE(paperARRAY) );
        int boxARRAY[] = {60,110};
        vector <int> box( boxARRAY, boxARRAY+ARRSIZE(boxARRAY) );
        PaperFold theObject;
        eq(4, theObject.numFolds(paper, box),0);
    }
    {
        int paperARRAY[] = {1895, 6416};
        vector <int> paper( paperARRAY, paperARRAY+ARRSIZE(paperARRAY) );
        int boxARRAY[] = {401, 1000};
        vector <int> box( boxARRAY, boxARRAY+ARRSIZE(boxARRAY) );
        PaperFold theObject;
        eq(5, theObject.numFolds(paper, box),5);
    }
}
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE
