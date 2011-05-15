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

class PointsOnAxis {
public:
    int a[1000001];
    vector<int> d;
    vector<int> res;
    vector<int> v;
    int n;
    vector <int> findPoints(vector <int> dis)
    {
	memset(a, 0, sizeof(a));
	n=(1+sqrt(1+8*dis.size()))/2;
	sort((dis).begin(), (dis).end());
	d=dis;
	v.push_back(0);
	for (int i = 0; i < d.size(); ++i) {
	    a[d[i]]++;
	}
	dfs(1);
	return res;
    }
    void dfs(int k)
    {
	// cout<<k<<endl;
	// cout<<"***"<<endl;
	// printv(v);
	if (k==n) {
	    vector<int> tmp=v;
	    sort((tmp).begin(), (tmp).end());
	    if (res.empty()) res=tmp;
	    else res=min(res, tmp);
	    return;
	}
	int j=d.size()-1;
	while (!a[d[j]]) j--;
	// for (int i = 0; i < v.size(); ++i) {
	    // cout<<j<<" &&&"<<endl;
	for (int i = 0; i < 2; ++i) {
	    int x=i?d[j]:(d[d.size()-1]-d[j]);
	    if (x<0 || x>d[d.size()-1]) continue;
	    bool ok=true;
	    for (int p = 0; p < v.size(); ++p) {
		int len=abs(v[p]-x);
		if (a[len]<=0) ok=false;
		a[len]--;
	    }
	    if (ok) { v.push_back(x); dfs(k+1); v.erase(--v.end()); }
	    for (int p = 0; p < v.size(); ++p) {
		int len=abs(v[p]-x);
		a[len]++;
		
	    }
	}
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
    // {
    //     int distancesARRAY[] = {5, 2, 1, 6, 2, 3, 3, 4, 5, 6, 3, 9, 1, 4, 1};
    //     vector <int> distances( distancesARRAY, distancesARRAY+ARRSIZE(distancesARRAY) );
    //     int retrunValueARRAY[] = { 0,  3,  4,  5,  6,  9 };
    //     vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
    //     PointsOnAxis theObject;
    //     eq(0, theObject.findPoints(distances),retrunValue);
    // }
    {
        int distancesARRAY[] = {20,100,120};
        vector <int> distances( distancesARRAY, distancesARRAY+ARRSIZE(distancesARRAY) );
        int retrunValueARRAY[] = { 0,  20,  120 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PointsOnAxis theObject;
        eq(1, theObject.findPoints(distances),retrunValue);
    }
    {
        int distancesARRAY[] = {1,2,3,4,5,7};
        vector <int> distances( distancesARRAY, distancesARRAY+ARRSIZE(distancesARRAY) );
        int retrunValueARRAY[] = { 0,  2,  3,  7 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PointsOnAxis theObject;
        eq(2, theObject.findPoints(distances),retrunValue);
    }
    {
        int distancesARRAY[] = {1,2,4};
        vector <int> distances( distancesARRAY, distancesARRAY+ARRSIZE(distancesARRAY) );
        PointsOnAxis theObject;
        eq(3, theObject.findPoints(distances),vector <int>());
    }
    {
        int distancesARRAY[] = {237601, 843904, 56786, 429289, 52254, 83576, 220417,
           606303, 180815, 191688, 185347, 154025, 17184, 787118,
           414615, 791650, 760328, 623487, 372503, 4532, 26790,
           163631, 377035, 345713, 208872, 31322, 168163, 136841};
        vector <int> distances( distancesARRAY, distancesARRAY+ARRSIZE(distancesARRAY) );
        int retrunValueARRAY[] = { 0,  52254,  56786,  83576,  220417,  237601,  429289,  843904 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PointsOnAxis theObject;
        eq(4, theObject.findPoints(distances),retrunValue);
    }
    {
        int distancesARRAY[] = {1, 1, 1, 1, 2, 2, 3, 4, 4, 5, 5, 5, 6, 6, 7};
        vector <int> distances( distancesARRAY, distancesARRAY+ARRSIZE(distancesARRAY) );
        int retrunValueARRAY[] = { 0,  1,  2,  5,  6,  7 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        PointsOnAxis theObject;
        eq(5, theObject.findPoints(distances),retrunValue);
    }
}
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE
