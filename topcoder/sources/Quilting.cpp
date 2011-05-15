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

int p[]={-1, 0, 1, 0};
int q[]={0, -1, 0, 1};
int p2[]={-1, 0, 1, 0, -1, -1, 1, 1};
int q2[]={0, -1, 0, 1, -1, 1, -1, 1};
vector< vector<int> > c;
int len;
int wid;
int used[100];
struct node {
    int color;
    int x, y;
    bool operator <(const node &a) const
    {
	int t1=0, t2=0;

	for (int i = 0; i < 4; ++i) {
	    if (x+p2[i]>=0 && x+p2[i]<len && y+q2[i]>=0 && y+q2[i]<wid &&
		c[x+p2[i]][y+q2[i]]==color)
		t1++;
	    if (a.x+p2[i]>=0 && a.x+p2[i]<len && a.y+q2[i]>=0 && a.y+q2[i]<wid &&
		c[a.x+p2[i]][a.y+q2[i]]==a.color)
		t2++;
	}
	cout<<color<<" "<<a.color<<endl;
	cout<<t1<<" "<<t2<<"--------"<<endl;
	if (t1 != t2) return t1<t2;
	if (used[color] != used[a.color]) return used[color]<used[a.color];
	return color<a.color;
    }
};
	

class Quilting {
public:
    string lastPatch(int length, int width, vector <string> colorList)
    {
	memset(used, 0, sizeof(used));
	len=length;
	wid=width;
        string res;
	int x=length/2, y=width/2;
	int m=colorList.size();
	vector<vector<int> > a(length, vector<int> (width, -1));
	c=a;
	vector< pair<int, int> > v;
	v.push_back(make_pair(x, y));
	int z=length*width-1;
	int k=0;
	cout<<"haha "<<x<<y<<endl;
	printp(v);
	while (z>0) {
	    k++;
	    for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < k; ++j) {
		    x=x+p[i]; y=y+q[i];
		    cout<<x<<" "<<y<<" "<<k<<endl;
		    v.push_back(make_pair(x, y));
		    // printp(v);
		    z--;
		    if (!z) break;
		}
		if (i==1) k++;
		if (!z) break;
	    }
	}
	cout<<"haha"<<endl;
	printp(v);
	int tt;
	for (int i = 0; i < len*wid; ++i) {
	    vector<node> h;
	    for (int j = 0; j < m; ++j) {
		node o;
		o.x=v[i].first; o.y=v[i].second;
		o.color=j;
		h.push_back(o);
	    }
	    for (int z = 0; z < 10; ++z) {
		cout<<used[z]<<" ";
	    }
	    cout<<endl;
	    cout<<h[0].color<<" ."<<v[i].first<<" "<<v[i].second<<endl;
	    sort((h).begin(), (h).end());
	    tt=h[0].color;
	    cout<<tt<<" "<<colorList[tt]<<endl;
	    used[tt]++;
	    c[v[i].first][v[i].second]=tt;
	}
	res=colorList[tt];
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
        string colorListARRAY[] = {"RED","BLUE","TAN"};
        vector <string> colorList( colorListARRAY, colorListARRAY+ARRSIZE(colorListARRAY) );
        Quilting theObject;
        eq(0, theObject.lastPatch(3, 2, colorList),"TAN");
    }
    {
        string colorListARRAY[] = {"E","D","C","B","A"};
        vector <string> colorList( colorListARRAY, colorListARRAY+ARRSIZE(colorListARRAY) );
        Quilting theObject;
        eq(1, theObject.lastPatch(4, 3, colorList),"E");
    }
    {
        string colorListARRAY[] = {"A","B","C","D"};
        vector <string> colorList( colorListARRAY, colorListARRAY+ARRSIZE(colorListARRAY) );
        Quilting theObject;
        eq(2, theObject.lastPatch(3, 3, colorList),"C");
    }
    {
        string colorListARRAY[] = {"RED","BLUE","YELLOW"};
        vector <string> colorList( colorListARRAY, colorListARRAY+ARRSIZE(colorListARRAY) );
        Quilting theObject;
        eq(3, theObject.lastPatch(1, 1, colorList),"RED");
    }
    {
        string colorListARRAY[] = {"X","Y","Z"};
        vector <string> colorList( colorListARRAY, colorListARRAY+ARRSIZE(colorListARRAY) );
        Quilting theObject;
        eq(4, theObject.lastPatch(10, 10, colorList),"Z");
    }
}
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE
