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
template<class T> inline void printv(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void printv2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE

class SMBus {
public:
  int transmitTime(vector <string> messages, vector <int> times);

};

int SMBus :: transmitTime(vector <string> messages, vector <int> times)
{
  int res=0;
  int n=messages.size();
  // sort((messages).begin(), (messages).end());
  vector<int> v(n);
  vector<int> t(n);
  while (true) {
    bool ok=true;
    for (int i=0; i<(v).size(); ++i)
      if (v[i]<messages[i].size()) {ok=false; break;}
    if (ok) break;
    int a=INT_MAX;
    int b=0;
    for (int i=0; i<(v).size(); ++i)
      if (v[i]<messages[i].size() && !t[i])
	a=min(a, messages[i][v[i]]-'0'), b=max(b, times[i]);
    for (int i=0; i<(v).size(); ++i)
      if (!t[i] && v[i]<messages[i].size()) {
	if (messages[i][v[i]]-'0'==a) v[i]++;
	else t[i]=1, v[i]=0;
      }
    for (int i=0; i<n; ++i)
      if (t[i]) {
	int ok=true;
	for (int j=0; j<n; ++j) if (v[j]>0 && v[j]<messages[j].size()) {ok=false; break;}
	if (ok) t[i]=0;
      }
    
    // cout<<b<<endl;
    // printv(v);
    res+=b;
  }
  return res;
    
}

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
        string messagesARRAY[] = {"123","124","134"};
        vector <string> messages( messagesARRAY, messagesARRAY+ARRSIZE(messagesARRAY) );
        int timesARRAY[] = {1,2,3};
        vector <int> times( timesARRAY, timesARRAY+ARRSIZE(timesARRAY) );
        SMBus theObject;
        eq(0, theObject.transmitTime(messages, times),25);
    }
    {
        string messagesARRAY[] = {"012", "1234", "1233", "1223", "1123"};
        vector <string> messages( messagesARRAY, messagesARRAY+ARRSIZE(messagesARRAY) );
        int timesARRAY[] = {4,1,5,2,9};
        vector <int> times( timesARRAY, timesARRAY+ARRSIZE(timesARRAY) );
        SMBus theObject;
        eq(1, theObject.transmitTime(messages, times),94);
    }
    {
        string messagesARRAY[] = {"0002019289019101039663222896280025447",
            "00201873554718989597528841094293294387326",
            "010699029378761", "0110118", "011143279122561420",
            "001046384966198", "00200570375817801109530240012",
            "0003163277589822", "01100240744590150136673219652442108",
            "012033596872642679096489479354", "0121059494098",
            "00001002303019117948961792176", "00216399923558", "02014",
            "00224999120803846121427603894967637446889670369",
            "01101009414735635151893037596051740080475886",
            "0000101211809647472761605153430927981533514",
            "176845042961739039392207791589",
            "02000047506929386333221966659552927385017901842706",
            "021001117450487502127241076595509511",
            "021010776262723557108100899515",
            "0210114830738951774606917781619656",
            "0211798433083855430", "00000005842153604632996228135814",
            "0001000766929248550736138555144997170272757787",
            "0001010247593342056062432721557",
            "01100004828618452515832113396660046634951",
            "0132559984733529872911444204991646138116334788",
            "0224149857349431864906523152249992",
            "00001142929552573133212195441932219",
            "0011090498947092002457447355036811372647896489218",
            "000001275414757476198997466", "00010014",
            "00111025861963467834393486017602553072649743",
            "000102085", "00120882661783539",
            "01100018938145727291185020",
            "01100191373790478446634214244459341793", "0001129060",
            "001111287431066271555393813846448",
            "011010160778408696098486370196313", "0002125146381515395"};
        vector <string> messages( messagesARRAY, messagesARRAY+ARRSIZE(messagesARRAY) );
        int timesARRAY[] = {42, 86, 47, 86, 32, 95, 2, 98, 17, 58, 31, 32, 85, 77,
            87, 61, 1, 20, 15, 80, 20, 95, 55, 87, 52, 14, 55, 68,
            2, 66, 67, 3, 28, 97, 100, 67, 65, 20, 28, 77, 93, 64};
        vector <int> times( timesARRAY, timesARRAY+ARRSIZE(timesARRAY) );
        SMBus theObject;
        eq(2, theObject.transmitTime(messages, times),71048);
    }
}
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE
