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

class Sets {
public:
    vector <int> operate(vector <int> A, vector <int> B, string operation)
    {
        vector <int> res;
	map<string, int> mm;
	mm["UNION"]=1;
	mm["INTERSECTION"]=2;
	mm["SYMMETRIC DIFFERENCE"]=3;
	int x=mm[operation];
	set<int> st;
	switch (x) {
	case 1:
	    st.insert((A).begin(), (A).end());
	    st.insert((B).begin(), (B).end());
	    for (__typeof((st).begin()) i = (st).begin(); i != (st).end(); ++i) {
		res.push_back(*i);
	    }
	    break;
	case 2:
	    for (int i = 0; i < A.size(); ++i) {
		if ((find((B).begin(), (B).end(), A[i]) != (B).end()))
		    res.push_back(A[i]);
	    }
	    sort((res).begin(), (res).end());
	    break;
	case 3:
	    for (int i = 0; i < A.size(); ++i) {
		if (!(find((B).begin(), (B).end(), A[i]) != (B).end()))
		    res.push_back(A[i]);
	    }
	    for (int i = 0; i < B.size(); ++i) {
		if (!(find((A).begin(), (A).end(), B[i]) != (A).end()))
		    res.push_back(B[i]);
	    }

	    sort((res).begin(), (res).end());
	    break;
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
        int AARRAY[] = {1,2,3,4};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {3,4,5,6};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int retrunValueARRAY[] = { 3,  4 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        Sets theObject;
        eq(0, theObject.operate(A, B, "INTERSECTION"),retrunValue);
    }
    {
        int AARRAY[] = {1,2,3,4};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {3,4,5,6};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int retrunValueARRAY[] = { 1,  2,  3,  4,  5,  6 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        Sets theObject;
        eq(1, theObject.operate(A, B, "UNION"),retrunValue);
    }
    {
        int AARRAY[] = {432,756,123};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {534,76,1209};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        Sets theObject;
        eq(2, theObject.operate(A, B, "INTERSECTION"),vector <int>());
    }
    {
        int AARRAY[] = {6,5,7,4};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {7,6,4,10};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int retrunValueARRAY[] = { 5,  10 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        Sets theObject;
        eq(3, theObject.operate(A, B, "SYMMETRIC DIFFERENCE"),retrunValue);
    }
    {
        int AARRAY[] = {342,654,897,312,76,23,78};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {21,43,87,98,23,756,897,234,645,876,123};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int retrunValueARRAY[] = { 21,  43,  76,  78,  87,  98,  123,  234,  312,  342,  645,  654,  756,  876 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        Sets theObject;
        eq(4, theObject.operate(A, B, "SYMMETRIC DIFFERENCE"),retrunValue);
    }
}
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE
