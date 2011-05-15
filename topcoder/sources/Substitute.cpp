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
template<class T> inline void printv(T A) { cout<<"{ "; for (__typeof((A).begin()) i = (A).begin(); i != (A).end(); ++i) { cout<<*i<<", "; } cout<<"}"<<endl; }

template<class T> inline void printv2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i = (A).begin(); i != (A).end(); ++i) { cout<<" { "; for (__typeof((*i).begin()) j = (*i).begin(); j != (*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl; } cout<<"}"<<endl; }

template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i = (A).begin(); i != (A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE

class Substitute {
public:
    int getValue(string key, string code)
    {
        int res=0;
	map<char, int> mm;
	for (int i = 0; i < key.size(); ++i) {
	    mm[key[i]]=(i+1)%10;
	}
	for (int i = 0; i < code.size(); ++i) {
	    if (((mm).find(code[i]) != (mm).end())) {
		res*=10;
		res+=mm[code[i]];
	    }
	}
        return res;
    }

};

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
        Substitute theObject;
        eq(0, theObject.getValue("TRADINGFEW", "LGXWEV"),709);
    }
    {
        Substitute theObject;
        eq(1, theObject.getValue("ABCDEFGHIJ", "XJ"),0);
    }
    {
        Substitute theObject;
        eq(2, theObject.getValue("CRYSTALBUM", "MMA"),6);
    }
}
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE
