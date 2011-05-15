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

struct node {
    vector< vector<int> > m;
    int x;
    int y;
};

class Gems {
public:
    int numMoves(vector <string> a)
    {
        int res=0;
	for (int i = 0; i < a.size(); ++i) {
	    for (int j = 0; j < a[i].size(); ++j) {
		if (i>0 && a[i][j]!=a[i-1][j]) {
		    vector<string> b=a;
		    swap(b[i][j], b[i-1][j]);
		    if (check(b, i, j) || check(b, i-1, j)) res++;
		}
		if (j>0 && a[i][j]!=a[i][j-1]) {
		    vector<string> b=a;
		    swap(b[i][j], b[i][j-1]);
		    if (check(b, i, j) || check(b, i, j-1)) res++;
		}
		// cout<<i<<" "<<j<<" "<<res<<endl;
	    }
	}
        return res;
    }
    bool check(const vector<string> &a, int x, int y)
    {
	int n = a.size();
	int m = a[0].size();
	char c=a[x][y];
	// cout<<x<<" "<<y<<endl;
	if (x>1 && a[x-2][y]==c && a[x-1][y]==c ||
	    y>1 && a[x][y-2]==c && a[x][y-1]==c ||
	    // x>0 && y>0 && a[x-1][y-1]==c && (a[x-1][y]==c || a[x][y-1]==c) ||
	    x<n-2 && a[x+1][y]==c && a[x+2][y]==c ||
	    y<m-2 && a[x][y+1]==c && a[x][y+2]==c ||
	    // x<n-1 && y<m-1 && a[x+1][y+1]==c && (a[x+1][y]==c || a[x][y+1]==c) ||
	    x>0 && x<n-1 && a[x-1][y]==c && a[x+1][y]==c ||
	    y>0 && y<m-1 && a[x][y-1]==c && a[x][y+1]==c )
	    // x>0 && y<m-1 && a[x-1][y+1]==c && (a[x-1][y]==c || a[x][y+1]==c) ||
	    // x<n-1 && y>0 && a[x+1][y-1]==c && (a[x+1][y]==c || a[x][y-1]==c))
	    return true;
	return false;
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
        string boardARRAY[] = {"ABC",
            "ABC",
            "BAD"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        Gems theObject;
        eq(0, theObject.numMoves(board),1);
    }
    {
        string boardARRAY[] = {"ABB",
            "BAA",
            "ABB"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        Gems theObject;
        eq(1, theObject.numMoves(board),3);
    }
    {
        string boardARRAY[] = {"ABA",
            "BAB",
            "ABA"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        Gems theObject;
        eq(2, theObject.numMoves(board),4);
    }
    {
        string boardARRAY[] = {"ABC",
            "DEF",
            "GHI"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        Gems theObject;
        eq(3, theObject.numMoves(board),0);
    }
    {
        string boardARRAY[] = {"SUMEEMEEPGPPG",
            "USPMIPSUSIISG",
            "UPSPGEGGPKEII",
            "KEMGISMKKIUIG",
            "MGSIIKMSISGKM",
            "SPGMSMIGMSMGM",
            "SSIIUKMPEPPUI",
            "UKUIUEMEEIGKE",
            "IPUPGUSEGSSUS",
            "EUPMKGGUKKEMI",
            "PEPSMUUEUSSIP",
            "SUMEEUSESUEKG",
            "EPSKUISGMSKGI",
            "IUGGUGGSIGUUP",
            "IUPIKKSGPPEEP",
            "KGEESGISPGGEM",
            "UEIUSSKPSSGPE",
            "KSUMKGEIMKPSE",
            "ESKEUEMMPPIGG",
            "UUIEUGGIGMEMK",
            "GPGMPPIUMEPMU",
            "IKIGGPIUEMIGS",
            "IPUSGUMKPKIPP",
            "UEEMUUEEGIPUS",
            "PPEKIKEMGGMSS",
            "EMKPMPUUMKEPU",
            "UKPGPKSUIEUPM",
            "PSUUMUKGIIPMS",
            "ESMGSKUEPGGEM",
            "SMEEIKGKGGPEG",
            "UEIEKPMESMEPP",
            "IPUIMGGMIPKMG",
            "ISSEKPKGKIUGU",
            "SSESKUGKISPUK"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        Gems theObject;
        eq(4, theObject.numMoves(board),83);
    }
}
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE
