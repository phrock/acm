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
vector<string> split( const string& s, const string& delim =" " ) {
    vector<string> res;
    string t;
    for ( int i = 0 ; i != s.size() ; i++ ) {
        if ( delim.find( s[i] ) != string::npos ) {
            if ( !t.empty() ) {
                res.push_back( t );
                t = "";
            }
        } else {
            t += s[i];
        }
    }
    if ( !t.empty() ) {
        res.push_back(t);
    }
    return res;
}

class BaseMystery {
public:
    vector <int> getBase(string equation) {
        vector <int> res;
	for (int i = 0; i < equation.size(); ++i) {
	    if (equation[i]=='+' || equation[i]=='=') equation[i]=' ';
	}
	vector<string> a=split(equation);
	// printv(a);
	for (int i = 2; i <= 20; ++i) {
	    bool flag=true;
	    vector<int> tmp;
	    for (int j = 0; j < a.size(); ++j) {
		if (!flag) break;
		int x = 0;
		for (int k = 0; k < a[j].size(); ++k) {
		    int p=0;
		    if (a[j][k]<='9' && a[j][k]>='0') p=a[j][k]-'0';
		    else p=a[j][k]-'A'+10;
		    if (p>=i) { flag=false; break; }
		    x=x*i+p;
		}
		tmp.push_back(x);
	    }
	    // printv(tmp);
	    if (flag && tmp[0]+tmp[1]==tmp[2]) res.push_back(i);
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
    cerr << endl;
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
    cerr << endl;
}
static void eq( int n, string have, string need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    cerr << endl<<endl<<endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
    cerr << endl;
}

int main(int argc, char* argv[])
{
    {
        int retrunValueARRAY[] = { 3,  4,  5,  6,  7,  8,  9,  10,  11,  12,  13,  14,  15,  16,  17,  18,  19,  20 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        BaseMystery theObject;
        eq(0, theObject.getBase("1+1=2"),retrunValue);
    }
    {
        int retrunValueARRAY[] = { 2 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        BaseMystery theObject;
        eq(1, theObject.getBase("1+1=10"),retrunValue);
    }
    {
        BaseMystery theObject;
        eq(2, theObject.getBase("1+1=3"),vector <int>());
    }
    {
        int retrunValueARRAY[] = { 14 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        BaseMystery theObject;
        eq(3, theObject.getBase("ABCD+211=B000"),retrunValue);
    }
    {
        int retrunValueARRAY[] = { 15 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        BaseMystery theObject;
        eq(4, theObject.getBase("ABCD+322=B000"),retrunValue);
    }
    {
        int retrunValueARRAY[] = { 2,  3,  4,  5,  6,  7,  8,  9,  10,  11,  12,  13,  14,  15,  16,  17,  18,  19,  20 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        BaseMystery theObject;
        eq(5, theObject.getBase("1+0=1"),retrunValue);
    }
    {
        int retrunValueARRAY[] = { 20 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        BaseMystery theObject;
        eq(6, theObject.getBase("GHIJ+1111=HJ00"),retrunValue);
    }
    {
        int retrunValueARRAY[] = { 10,  11,  12,  13,  14,  15,  16,  17,  18,  19,  20 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        BaseMystery theObject;
        eq(7, theObject.getBase("1234+8765=9999"),retrunValue);
    }
}
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE
