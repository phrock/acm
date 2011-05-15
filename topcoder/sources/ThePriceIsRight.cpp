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

class ThePriceIsRight {
public:
    vector <int> howManyReveals(vector <int> prices)
    {
        vector <int> res;
	int n=prices.size();
	vector<pair<int, int> > a(n);
	int m=0;
	for (int i = 0; i < n; ++i) {
	    int k=0;
	    int p=1;
	    for (int j = 0; j < i; ++j) {
		if (prices[j]<=prices[i]) {
		    if (k<a[j].first) {
			k=a[j].first;
			p=a[j].second;
		    } else if (k==a[j].first) {
			p+=a[j].second;
		    }
		}
	    }
	    a[i].first=k+1;
	    a[i].second=p;
	    m=max(m, a[i].first);
	}
	res.push_back(m);
	int cnt=0;
	for (int i = 0; i < a.size(); ++i) {
	    if (a[i].first==m) cnt+=a[i].second;
	}
	res.push_back(cnt);
	 // cout<<m<<endl;
	 // printp(a);
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
        int pricesARRAY[] = {30,10,20,40,50};
        vector <int> prices( pricesARRAY, pricesARRAY+ARRSIZE(pricesARRAY) );
        int retrunValueARRAY[] = { 4,  1 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        ThePriceIsRight theObject;
        eq(0, theObject.howManyReveals(prices),retrunValue);
    }
    {
        int pricesARRAY[] = {39,88,67,5,69,87,82,64,58,61};
        vector <int> prices( pricesARRAY, pricesARRAY+ARRSIZE(pricesARRAY) );
        int retrunValueARRAY[] = { 4,  2 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        ThePriceIsRight theObject;
        eq(1, theObject.howManyReveals(prices),retrunValue);
    }
    {
        int pricesARRAY[] = {1,2,3,4,5,6,7,8,9,10};
        vector <int> prices( pricesARRAY, pricesARRAY+ARRSIZE(pricesARRAY) );
        int retrunValueARRAY[] = { 10,  1 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        ThePriceIsRight theObject;
        eq(2, theObject.howManyReveals(prices),retrunValue);
    }
    {
        int pricesARRAY[] = {10,9,8,7,6,5,4,3,2,1};
        vector <int> prices( pricesARRAY, pricesARRAY+ARRSIZE(pricesARRAY) );
        int retrunValueARRAY[] = { 1,  10 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        ThePriceIsRight theObject;
        eq(3, theObject.howManyReveals(prices),retrunValue);
    }
    {
        int pricesARRAY[] = {29,31,73,70,14,5,6,34,53,30,15,86};
        vector <int> prices( pricesARRAY, pricesARRAY+ARRSIZE(pricesARRAY) );
        int retrunValueARRAY[] = { 5,  2 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        ThePriceIsRight theObject;
        eq(4, theObject.howManyReveals(prices),retrunValue);
    }
    {
        int pricesARRAY[] = {100,99,1,2,3};
        vector <int> prices( pricesARRAY, pricesARRAY+ARRSIZE(pricesARRAY) );
        int retrunValueARRAY[] = { 3,  1 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        ThePriceIsRight theObject;
        eq(5, theObject.howManyReveals(prices),retrunValue);
    }
    {
        int pricesARRAY[] = {10,20,11,12};
        vector <int> prices( pricesARRAY, pricesARRAY+ARRSIZE(pricesARRAY) );
        int retrunValueARRAY[] = { 3,  1 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        ThePriceIsRight theObject;
        eq(6, theObject.howManyReveals(prices),retrunValue);
    }
}
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE
