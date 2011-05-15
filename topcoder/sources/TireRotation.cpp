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
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
template<class T> inline void printv(T A) { cout<<"{ "; for (__typeof((A).begin()) i = (A).begin(); i != (A).end(); ++i) { cout<<*i<<", "; } cout<<"}"<<endl; }


class TireRotation {
public:
    int getCycle(string initial, string current) {
        int res;
	vector<string> v(4);
	v[0]=initial;
	for (int i = 1; i < v.size(); ++i) {
	    string t = v[i-1];
	    swap(t[0], t[2]);
	    swap(t[0], t[3]);
	    swap(t[1], t[3]);
	    v[i] = t;
	}
	printv(v);
	res = -1;
	for (int i = 0; i < v.size(); ++i) {
	    if (current == v[i]) { res = i+1; break; }
	}
        return res;
    }

};

// BEGIN CUT HERE
////////////////////////////////////////////////////////////////////////////////
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))



template<typename T> void print( T a ) {
    cerr << a;
}
static void print( long long a ) {
    cerr << a << "L";
}
static void print( string a ) {
    cerr << '"' << a << '"';
}
template<typename T> void print( vector<T> a ) {
    cerr << "{";
    for ( int i = 0 ; i != a.size() ; i++ ) {
        if ( i != 0 ) cerr << ", ";
        print( a[i] );
    }
    cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}
template<typename T> void eq( int n, vector<T> have, vector<T> need ) {
    if( have.size() != need.size() ) {
        cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
        print( have );
        print( need );
        return;
    }
    for( int i= 0; i < have.size(); i++ ) {
        if( have[i] != need[i] ) {
            cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
            print( have );
            print( need );
            return;
        }
    }
    cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {

    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}

int main(int argc, char* argv[])
{
    {
        TireRotation theObject;
        eq(0, theObject.getCycle("ABCD", "ABCD"),1);
    }
    {
        TireRotation theObject;
        eq(1, theObject.getCycle("ABCD", "DCAB"),2);
    }
    {
        TireRotation theObject;
        eq(2, theObject.getCycle("ABCD", "CDBA"),4);
    }
    {
        TireRotation theObject;
        eq(3, theObject.getCycle("ABCD", "ABDC"),-1);
    }
    {
        TireRotation theObject;
        eq(4, theObject.getCycle("ZAXN", "XNAZ"),4);
    }
}
// END CUT HERE
