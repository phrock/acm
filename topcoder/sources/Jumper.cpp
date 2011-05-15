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

class Jumper {
public:
    int minTime(vector <string> patterns, vector <int> speeds, string rows)
    {
        int res;
	
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
        string patternsARRAY[] = {"###..", "..###"};
        vector <string> patterns( patternsARRAY, patternsARRAY+ARRSIZE(patternsARRAY) );
        int speedsARRAY[] = {1,1};
        vector <int> speeds( speedsARRAY, speedsARRAY+ARRSIZE(speedsARRAY) );
        Jumper theObject;
        eq(0, theObject.minTime(patterns, speeds, "01"),5);
    }
    {
        string patternsARRAY[] = {"###..", "..###"};
        vector <string> patterns( patternsARRAY, patternsARRAY+ARRSIZE(patternsARRAY) );
        int speedsARRAY[] = {5,5};
        vector <int> speeds( speedsARRAY, speedsARRAY+ARRSIZE(speedsARRAY) );
        Jumper theObject;
        eq(1, theObject.minTime(patterns, speeds, "01"),5);
    }
    {
        string patternsARRAY[] = {"....#", "....#"};
        vector <string> patterns( patternsARRAY, patternsARRAY+ARRSIZE(patternsARRAY) );
        int speedsARRAY[] = {4,5};
        vector <int> speeds( speedsARRAY, speedsARRAY+ARRSIZE(speedsARRAY) );
        Jumper theObject;
        eq(2, theObject.minTime(patterns, speeds, "0111"),9);
    }
    {
        string patternsARRAY[] = {"#....", "#...."};
        vector <string> patterns( patternsARRAY, patternsARRAY+ARRSIZE(patternsARRAY) );
        int speedsARRAY[] = {-4,-5};
        vector <int> speeds( speedsARRAY, speedsARRAY+ARRSIZE(speedsARRAY) );
        Jumper theObject;
        eq(3, theObject.minTime(patterns, speeds, "0111"),24);
    }
    {
        string patternsARRAY[] = {"#####","#####"};
        vector <string> patterns( patternsARRAY, patternsARRAY+ARRSIZE(patternsARRAY) );
        int speedsARRAY[] = {10,10};
        vector <int> speeds( speedsARRAY, speedsARRAY+ARRSIZE(speedsARRAY) );
        Jumper theObject;
        eq(4, theObject.minTime(patterns, speeds, "01"),-1);
    }
    {
        string patternsARRAY[] = {"#####","#####","....."};
        vector <string> patterns( patternsARRAY, patternsARRAY+ARRSIZE(patternsARRAY) );
        int speedsARRAY[] = {1,-1,1};
        vector <int> speeds( speedsARRAY, speedsARRAY+ARRSIZE(speedsARRAY) );
        Jumper theObject;
        eq(5, theObject.minTime(patterns, speeds, "01010101010101010102"),-1);
    }
    {
        string patternsARRAY[] = {"#....", "#....", "#...."};
        vector <string> patterns( patternsARRAY, patternsARRAY+ARRSIZE(patternsARRAY) );
        int speedsARRAY[] = {5,-5,6};
        vector <int> speeds( speedsARRAY, speedsARRAY+ARRSIZE(speedsARRAY) );
        Jumper theObject;
        eq(6, theObject.minTime(patterns, speeds, "2012"),12);
    }
}
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE
