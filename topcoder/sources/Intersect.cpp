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

class Intersect {
public:
    int area(vector <int> x, vector <int> y)
    {
	int n=x.size();
	for (int i = 0; i < n; i+=2) {
	    if (x[i]>x[i+1]) swap(x[i], x[i+1]);
	}
	for (int i = 0; i < n; i+=2) {
	    if (y[i]>y[i+1]) swap(y[i], y[i+1]);
	}
        int res=0;
	for (int i = -10000; i < 10000; ++i) {
	    for (int j = -10000; j < 10000; ++j) {
		bool ok=true;
		for (int k = 0; k < n; ++k, ++k) {
		    if (i<x[k] || i>=x[k+1] || j<y[k] || j>=y[k+1]) {
			ok=false; break;
		    }
		}
		if (ok) res++;
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
        int xARRAY[] = {0,2,3,-4};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {17,1000,18,6};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        Intersect theObject;
        eq(0, theObject.area(x, y),2);
    }
    {
        int xARRAY[] = {10000,-10000};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {-10000,10000};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        Intersect theObject;
        eq(1, theObject.area(x, y),400000000);
    }
    {
        int xARRAY[] = {3,8,6,12,10,15};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {7,17,7,17,7,17};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        Intersect theObject;
        eq(2, theObject.area(x, y),0);
    }
    {
        int xARRAY[] = {0,0,0,0,0,0,0,0};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {5,5,5,5,5,5,5,5};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        Intersect theObject;
        eq(3, theObject.area(x, y),0);
    }
    {
        int xARRAY[] = {2,100,5,32,1000,-20,47,12};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {29,-1000,-800,-200,-900,300,-600,-650};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        Intersect theObject;
        eq(4, theObject.area(x, y),1000);
    }
    {
        int xARRAY[] = {1,7,12,3,16,8,3,12}	;
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {-90,-60,-70,3,-60,-90,-80,-100};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        Intersect theObject;
        eq(5, theObject.area(x, y),0);
    }
}
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE
