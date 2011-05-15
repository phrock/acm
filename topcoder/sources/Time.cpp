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

class Time {
public:
    string whatTime(int seconds) {
        string res;
	res += *({ ostringstream oss; oss << (seconds/3600); istringstream iss(oss.str()); static string _cast_ret; iss >> _cast_ret; &_cast_ret; })+":"+*({ ostringstream oss; oss << (seconds/60%60); istringstream iss(oss.str()); static string _cast_ret; iss >> _cast_ret; &_cast_ret; })+":"+*({ ostringstream oss; oss << (seconds%60); istringstream iss(oss.str()); static string _cast_ret; iss >> _cast_ret; &_cast_ret; });
        return res;
    }

};

// BEGIN CUT HERE
////////////////////////////////////////////////////////////////////////////////
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i = (A).begin(); i != (A).end(); ++i) { cout<<" { "; for (__typeof((*i).begin()) j = (*i).begin(); j != (*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl; } cout<<"}"<<endl; }

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

int main( int argc, char* argv[] )
{
    {
        Time theObject;
        eq(0, theObject.whatTime(0),"0:0:0");
    }
    {
        Time theObject;
        eq(1, theObject.whatTime(3661),"1:1:1");
    }
    {
        Time theObject;
        eq(2, theObject.whatTime(5436),"1:30:36");
    }
    {
        Time theObject;
        eq(3, theObject.whatTime(86399),"23:59:59");
    }
}
// END CUT HERE
