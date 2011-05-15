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

class StampPads {
public:
    int bestCombo(vector <string> pads, vector <string> wishlist)
    {
	vector<int> a(pads.size());
	for (int i = 0; i < pads.size(); ++i) {
	    vector<string> v=split(pads[i]);
	    for (int j = 0; j < wishlist.size(); ++j) {
		if ((find((v).begin(), (v).end(), wishlist[j]) != (v).end()))
		    a[i]|=(1<<j);
	    }
	}

        int res=INT_MAX;
	int n=pads.size();
	for (int i = 0; i < (1<<n); ++i) {
	    int color=0;
	    if (__builtin_popcount(i)>=res) continue;
	    for (int j = 0; j < n; ++j) {
		if (i & (1<<j)) {
		    color|=a[j];
		}
	    }
	    if (color == (1<<wishlist.size())-1)
		res=min(res, __builtin_popcount(i));
	}
	if (res==INT_MAX) res=-1;
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
        string padsARRAY[] = {"yellow red purple blue cyan",
            "red green orange magenta yellow",
            "brown black orange yellow tan"};
        vector <string> pads( padsARRAY, padsARRAY+ARRSIZE(padsARRAY) );
        string wishlistARRAY[] = {"orange", "yellow", "red", "blue", "magenta", "tan"};
        vector <string> wishlist( wishlistARRAY, wishlistARRAY+ARRSIZE(wishlistARRAY) );
        StampPads theObject;
        eq(0, theObject.bestCombo(pads, wishlist),3);
    }
    {
        string padsARRAY[] = {"yellow red purple blue cyan",
            "red green orange magenta yellow",
            "brown black orange yellow tan"};
        vector <string> pads( padsARRAY, padsARRAY+ARRSIZE(padsARRAY) );
        string wishlistARRAY[] = {"orange", "yellow", "red", "blue", "tan"};
        vector <string> wishlist( wishlistARRAY, wishlistARRAY+ARRSIZE(wishlistARRAY) );
        StampPads theObject;
        eq(1, theObject.bestCombo(pads, wishlist),2);
    }
    {
        string padsARRAY[] = {"yellow black blue green red",
            "yellow brown cyan magenta tan",
            "black grey fire maroon silver",
            "blue white neon tangerine rust",
            "green orange soot turquoise mint",
            "red cream opal chrome sky"};
        vector <string> pads( padsARRAY, padsARRAY+ARRSIZE(padsARRAY) );
        string wishlistARRAY[] = {"yellow", "black", "blue", "green", "red",
            "brown", "grey", "white", "orange", "cream"};
        vector <string> wishlist( wishlistARRAY, wishlistARRAY+ARRSIZE(wishlistARRAY) );
        StampPads theObject;
        eq(2, theObject.bestCombo(pads, wishlist),5);
    }
    {
        string padsARRAY[] = {"red green orange magenta yellow"};
        vector <string> pads( padsARRAY, padsARRAY+ARRSIZE(padsARRAY) );
        string wishlistARRAY[] = {"silver"};
        vector <string> wishlist( wishlistARRAY, wishlistARRAY+ARRSIZE(wishlistARRAY) );
        StampPads theObject;
        eq(3, theObject.bestCombo(pads, wishlist),-1);
    }
    {
        string padsARRAY[] = {"a i y d o", "t s k g e", "j u w i k", "u k l s j", "q s a c y",
            "q m d x a", "m s l h r", "s x q l n", "u r j s k", "e w v d p",
            "o l a b q", "f z g a m", "o g k b a", "c h g k t", "z v s n x",
            "z n b w c", "h p o u k", "t z o x m", "a w i v z", "u t v m y"};
        vector <string> pads( padsARRAY, padsARRAY+ARRSIZE(padsARRAY) );
        string wishlistARRAY[] = {"x", "b", "u", "c", "h", "j", "t", "v", "d", "g",
            "k", "w", "y", "z", "a", "i", "m", "l", "n", "e"};
        vector <string> wishlist( wishlistARRAY, wishlistARRAY+ARRSIZE(wishlistARRAY) );
        StampPads theObject;
        eq(4, theObject.bestCombo(pads, wishlist),6);
    }
    {
        string padsARRAY[] ={"m k n c q", "t b c o j", "l v u d y", "x l i q o", "u o m g z", "k n s e l", "w y x t u", "r e d n y", "a u x o b", "y q h c e", "p v l g i", "t j o u i", "b q e a i", "v a o g s", "p o i j l", "b o k c t", "w z n e q", "r p a v x", "l t q j g", "r n k m o"};
        vector <string> pads( padsARRAY, padsARRAY+ARRSIZE(padsARRAY) );
        string wishlistARRAY[] = {"a", "d", "f", "g", "b", "h", "j", "t", "c", "i", "e", "s"};
        vector <string> wishlist( wishlistARRAY, wishlistARRAY+ARRSIZE(wishlistARRAY) );
        StampPads theObject;
        eq(4, theObject.bestCombo(pads, wishlist),6);
    }
    {
        string padsARRAY[] ={"m k n c q", "t b c o j", "l v u d y", "x l i q o", "u o m g z", "k n s e l", "w y x t u", "r e d n y", "a u x o b", "y q h c e", "p v l g i", "t j o u i", "b q e a i", "v a o g s", "p o i j l", "b o k c t", "w z n e q", "r p a v x", "l t q j g", "r n k m o"};
        vector <string> pads( padsARRAY, padsARRAY+ARRSIZE(padsARRAY) );
        string wishlistARRAY[] = {"a", "d", "f", "g", "b", "h", "j", "t", "c", "i", "e", "s"};
        vector <string> wishlist( wishlistARRAY, wishlistARRAY+ARRSIZE(wishlistARRAY) );
        StampPads theObject;
        eq(4, theObject.bestCombo(pads, wishlist),6);
    }

}
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE
