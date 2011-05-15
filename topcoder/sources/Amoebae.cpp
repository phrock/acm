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

class Amoebae
{ 
public: 
  int cultureX(vector <string> known, vector <string> candidate);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"...XXXXXXX.......",
 "....X.X.X........",
 "...XXXXXX........",
 "...............XX",
 "......X.....XX..X",
 ".XXXXX........X.X",
 ".X.XXX.......XXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"X.X..........XXXX",
 "XXX...XX......X.X",
 "X.X...XX........X",
 "XXX...XX.......XX",
 "X.X....X.X.......",
 "XXX...XX.X.......",
 "X.......X........"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(0, Arg2, cultureX(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"...XXXXXXX.......",
 "....X.X.X........",
 "...XXXXXX........",
 "...............XX",
 "......X.....XX..X",
 ".XXXXX........X.X",
 ".X.XXX.......XXXX"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"X.X..........XXXX",
 "XXX...XX......X.X",
 "X.X...XX........X",
 "......XX.......XX",
 "X.X....X.X.......",
 "XXX...XX.X.......",
 "X.......X........"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(1, Arg2, cultureX(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"......................",
 "....XXX...............",
 "..X...X......XX.XX....",
 "..XX.........XX.XX....",
 "...XX.................",
 "..........X...X..XXXX.",
 "..XXX.....XX.XX.XX..XX",
 "..X........X.X..X....X",
 ".....XX....XXX..X....X",
 ".....XX.....X...XX..XX",
 "............X....XXXX."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"....X......XX.XX.XX...",
 "....XXX....XX.XX.XX...",
 ".........XX...........",
 ".........XX...........",
 "......................",
 "..X....XXXX....X......",
 "..X...XX..XX...X......",
 ".XXX..X....X..XXX.....",
 ".X.X..X....X..X.X.....",
 "XX.XX.XX..XX.XX.XX....",
 "X...X..XXXX..X...X...."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(2, Arg2, cultureX(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {".XXXX.X...X...XXXX..", 
"X..XXXXXXX.X.....XX.", 
".X.X.XX....X..XXX..X", 
"..XXX.X.X....X......", 
".XXXXX...X.....XXXX.", 
"..X.XXX..XX....XXX.X", 
".......XXX..X.X...XX", 
"XX....X.....X...X.X.", 
".....X.....XX..XXX.X", 
"X...XX.X.X..X....X.X", 
".X........X.........", 
".X..X.........X.....", 
"..X.X..X..........XX", 
"........X.X...X.XX..", 
"....X.......X.X..X.X", 
"....XX..X..X.X.X...X", 
"X.....X.........X.X.", 
"X.X...X.............", 
"..XXX.X...X..X..XX..", 
"X.......XX...X......"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".X.....X.X......XX.X", 
"X.X.X..X..XX........", 
"X..XXX......X....XX.", 
"XXXXX.............X.", 
"XX.XXX...X.XX.XX..X.", 
".XX.XX..XX.....X....", 
"XXXX.X.X........XXX.", 
".X....X..X..X.......", 
".X.X..X......X.X...X", 
".X..XXX..X.........X", 
"X....X....X..X....X.", 
".XX.....X......X....", 
"......XXXX....X.....", 
"...X...........X..XX", 
"X.X...X....X.XX.....", 
"X.X.XX..X......X....", 
"X.X.XX.XX....X..X.X.", 
"XX..XX..XX...XX...X.", 
".X..X.XX....X...X...", 
"..X..XX.XX..X.XX...."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(3, Arg2, cultureX(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {".....XXX...X.....XX.....XX.XX..XX..", 
"..X.XX.XX.X....XXX....X......X.....", 
".....XX...X....X.X....X.X.X........", 
"X.....X.......XXX.X....X..XX.X.....", 
".X.X....X.X........X..........XX...", 
"........XX........X.....X..X.X.....", 
".X..X...X...XX.X..X.....X..........", 
"..............X......X...X....X..X.", 
"XX..X.....XX..X...X...X.X..X....X..", 
".X....XX..X...............X.X.XXXX.", 
"...XXXXX.....X...X....X.XX..XXX..X.", 
".........X..XX....X.X......XXXX....", 
"..XXXX.X..XXX.X...........X..X.XX..", 
"X...X...........X..X.X..X.XX..X.X..", 
"..X....X.....X..X.X....X..X.X..XXXX", 
"X..XXX..X..XX.XX.X..X...X...X..X.XX", 
"....X....X.X...X..X..X..XXX...XXXX.", 
".X..XX.XX.....X..XX..............XX", 
"X..........X..X......XXXX.....X..X.", 
".X.XXX...X..X..XX.X.X.X.X..X.......", 
"X....X.........X....XXXX..X....X..X", 
"..X.XX...X......X.X.......XX....X..", 
"X.XXXX....X.XXX..XX..XXXX.X.XX.....", 
"XXX.X........X.X..X..X....X..X.....", 
"......X..X..XX..X.....XX........X..", 
"...X.....XX..X..X..X.X......XX..X.X", 
"..X..X.......XX......X......X...XX.", 
"..X.XX......XX.X..X.....X...X.X..X.", 
".X.X.XX.XXX.X..X.X.................", 
".......X.XX..X..X..X.....X.X..XX..X", 
"X...XX.......X...X...X.X....X......", 
"X.......X.X......X.X.X......X.....X", 
"....X.X.X.X....XXX..XX.....XX.X..X.", 
"...X..X.X.XX......X.....XX.XXXX....", 
"..X......X...X.X...X...X.X.XXXX...X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..XX......X..XX.X....X..X.XX..X....", 
"...X.X.X.......X..X....X...........", 
".XXX.X.XXX.....X.X.X..XX.XX.X.XX.XX", 
"X...X......X.X........X...X.X.....X", 
"X.....X....X...XX....X.X........XX.", 
"..XXX...XXX............X.XX..XX..XX", 
"....X.X..X..X.X...X.X....X.XX...X..", 
".XX..X........XX..X......XX..X....X", 
"...X......X...X..X...XX...XXX..X.X.", 
"..XX...X..X...X...X.XX.....X.....X.", 
".XX.X........X..X..X......XX.X.XX..", 
".X.X..XX..X.XX......X....X.........", 
"X..X.X..X........X.....X..X..XX...X", 
"X.X.........X.XXX..XX..X.........X.", 
".........X......XX.....X.....X..X.X", 
"X..X.X.XXX.X.....X...X...X...X..X.X", 
"X......X..X.XX.X......X....XX.....X", 
"X.X...................X...X..X..XX.", 
".........X........X..XX..X......X.X", 
".X....X.X.X.......X..XX..XX.XXX...X", 
".................XXX...XX...X..X...", 
"..X...X...XX.....X.....X..XX....XX.", 
".......XXX.XX....X...XX..XXX.X....X", 
"........X...XXXX..X..........X.....", 
"..........XX.X.XX.X.........XX....X", 
"...X.....X.X.................X....X", 
"...XX.X.....X.....XXXX...X...X.X...", 
".............X.....X..X..X.X.X..X..", 
"...............X....X....X..X.X.X.X", 
".XX..XX........X.....X.XX....X....X", 
"...X....X..X...XXX..X........X.....", 
"X.XXX.XX..X......XX.X......X.X.X...", 
".XX.X....X..X..X.X.................", 
"....XXX.X.X......XX.....XX...X.XX..", 
"......X....XX..X.....X...XX.X.....X"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 64; verify_case(4, Arg2, cultureX(Arg0, Arg1)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }

int main()
{
  Amoebae ___test; 
  ___test.run_test(0); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

int t1[]={-1, 1, 0, 0};
int t2[]={0, 0, -1, 1};

vector<string> bfs(const vector<string> &a, vector< vector<int> > &v, int i, int j)
{
  int p, q, l, r;
  p=q=i;
  l=r=j;
  queue<pair<int, int> > que;
  que.push(make_pair(i, j));
  v[i][j]=1;
  while (!que.empty()) {
    pair<int, int> x=que.front();
    que.pop();
    p=min(p, x.first); q=max(q, x.first);
    l=min(l, x.second); r=max(r, x.second);
    for (int i=0; i<4; ++i) {
      int g1=x.first+t1[i], g2=x.second+t2[i];
      if (g1>=0 && g1<(int)(a).size() && g2>=0 && g2<(int)(a[0]).size() &&
	  !v[g1][g2] && a[g1][g2]=='X')
	{ v[g1][g2]=1; que.push(make_pair(g1, g2)); }
    }
  }
  vector<string> res;
  for (int i=p; i<=q; ++i) {
    string s;
    for (int j=l; j<=r; ++j)
      s+=a[i][j];
    res.push_back(s);
  }
  return res;
}

vector<vector<string> > findCultureX(const vector<string> &a)
{
  vector<vector<string> > res;
  vector< vector<int> > v((int)(a).size(), vector<int> ((int)(a[0]).size()));
  for (int i=0; i<(int)(a).size(); ++i)
    for (int j=0; j<(int)(a[i]).size(); ++j)
      if (a[i][j]=='X' && !v[i][j]) {
	vector<string> x=bfs(a, v, i, j);
	res.push_back(x);
      }
  return res;
}

void rotate(vector<string> &a)
{
  vector<string> aux;
  for (int i=0; i<(int)(a[0]).size(); ++i) {
    string s;
    for (int j=(int)(a).size()-1; j>=0; --j) s+=a[j][i];
    aux.push_back(s);
  }
  a=aux;
}

void reflect1(vector<string> &a)
{
  vector<string> aux;
  for (int i=(int)(a).size()-1; i>=0; --i) aux.push_back(a[i]);
  a=aux;
}

void reflect2(vector<string> &a)
{
  for (int i=0; i<(int)(a).size(); ++i) {
    int j=0, k=(int)(a[0]).size()-1;
    while (j<k) swap(a[i][j], a[i][k]), j++, k--;
  }
}

bool identical(const vector<string> a, const vector<string> b)
{
  for (int i=0; i<4; ++i)
    for (int j=0; j<2; ++j)
      for (int k=0; k<2; ++k) {
	vector<string> aux=b;
	for (int p=0; p<i; ++p) rotate(aux);
	if (j) reflect1(aux);
	if (k) reflect2(aux);
	cout<<i<<" "<<j<<" "<<k<<" "<<"*********"<<endl;
	print(a); print(aux);
	cout<<(a==aux)<<endl;
	if (a==aux) return true;
      }
  return false;
}

int Amoebae :: cultureX(vector <string> known, vector <string> candidate)
{
  vector<vector<string> > a=findCultureX(known);
  vector<vector<string> > b=findCultureX(candidate);
  #ifdef DEBUG
  print2(a); print2(b);  
  #endif
  int res=0;
  for (int i=0; i<(int)(a).size(); ++i) {
    bool ok=true;
    for (int j=0; j<(int)(b).size(); ++j) {
          #ifdef DEBUG
      print(a[i]); print(b[j]); cout<<identical(a[i], b[j])<<"//////////"<<endl;    
    #endif
      if (identical(a[i], b[j])) { ok=false; break; }
    }
    if (ok) res++;
  }
  for (int i=0; i<(int)(b).size(); ++i) {
    bool ok=true;
    for (int j=0; j<(int)(a).size(); ++j)
      if (identical(b[i], a[j])) { ok=false; break; }
    if (ok) res++;
  }
  return res;
}
