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

class LumberjackHack
{ 
public: 
  int timeToShore(vector <string> riverMap);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".+.",
 "||."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, timeToShore(Arg0)); }
	void test_case_1() { string Arr0[] = {"..+",
 "||."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, timeToShore(Arg0)); }
	void test_case_2() { string Arr0[] = {"....|||",
 "....|..",
 "...||..",
 "||.+...",
 "...|...",
 "...||||"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(2, Arg1, timeToShore(Arg0)); }
	void test_case_3() { string Arr0[] = {"||.|....",
 "........",
 ".|.+|..|",
 "...|....",
 "|..|.|.|"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(3, Arg1, timeToShore(Arg0)); }
	void test_case_4() { string Arr0[] = {".........|.|.|.|.|..||...||.|..|.||...|.|.|||...||",
 ".||.||...||..|||.....|.||||...|.|.|.|.|..|...|.|||",
 "||.|.|..||.||....|.....|.||.|||||.|.|.||.|||||.|..",
 "|.....|.|.||||.||..|.|..|..|.|||||.....||.|.||....",
 "..|..||...||.|.......|||+||.||||....||||.....|..||",
 "...||..||||.|......||..|.|||||.|.|||||.||..|||...|",
 "|||...|..|..|.|||.||.|..|...||.|||..|..||.|.||....",
 "|..|||||||||.||.....|..|.|.|||||...||...|.|.|||||.",
 ".|..||...|||............|.|..|||.||.|||.||..||.|||",
 ".|.|||...||..|..|...||.||..|..|||||.|.|...||..||.|",
 "||||.|||.|..||||..|..||...|..||.|.||||...|...|.|..",
 ".||..||...|.....|||.|||||..||......|.||.||.|..||..",
 "|.|||....|||||.|..|..|.|||..|.||.||.|.|.|.|..||...",
 ".||.||||||...||||||..||....|..||.|||..||...|.|||||",
 ".||||.|....|...|.||..||..|||.|||||....|...||.|.||.",
 ".|...|..||....||...|.||||.....||||.||.|||||||..|||",
 ".||||...|...|..||...|...|...|.|..|.|.|..|..|||.||.",
 ".|.|||..||||||||........|||||||||.|.|........|||||",
 ".....|...||.||...|||...||||..|||...||....||..||.||",
 "||...||..||.||...||...||||..|.|..|...|||..||..|||.",
 "|..||||.||..|...|....||||||...|||.|.|||||..|||...|",
 ".....|||..||.|||.....||..||||...|||||.||.|.||..|||",
 "|..|.||..|..||..||..|...|..|.||..||||..|...||..|..",
 "||.|..|.|||||...|...|.|..|||||...|.......|.||.||||",
 ".|.....|.|||||.....|||...|..|||||...|.||..||.|||.|",
 ".|...||....|||...|||.||.|.|......|........|.||||||",
 "..|.|.|.|||||..|||..|.........|...|.|.|...||.....|",
 ".|.|.|.|..|.|||||||||||.|.|||....|||||...|.||||.|.",
 "|.|||....|.||||..||......|..|||||.....||.|..||..|.",
 "||.||.|||.|......|..|.|...|..||.|||..||.....|.|..|",
 ".||||..|.|.||||.|||.||.||.....|....|....||...|..||",
 ".....|||...||.||.||....|.||..||....|....|||||.|..|",
 "|.|.|||||...|.||..|..|..|.|..|.|........||..|.|.||",
 "....|..|.|..|.||||||....||||.|.||||||.|.|.|.......",
 "||||....|..|...||..||||||||...|.|||||.|.|||.|...||",
 "|...|.|..|..|..|....|..||..|||....||..||..|..|..|.",
 "|||||....|.||.|..|.||..|||..|.|.|..||.|...|.|..||.",
 "..|.|||.|.||..|...|||.|..|||..||...||...||||.....|",
 "..||||.|.|.....|||..||||..|.||||..|..|||.....||.||",
 "|..|||||....|........|.||||.||..||||.|....|||||||.",
 ".|...||.|.||..|.|....|.||..|.|....|.|.||.||.||.|..",
 ".|..|..|.||||.||||....|||.....|.|...|.|...|...||..",
 "|..|||..|.||.|||..||.....|.|..|.|.|...|.....|.....",
 "||..||.|...|.||...|..|..||.|||.||.|.||...|....|||.",
 ".|....|.|||.|..|||..|.....|.||.||...|...||.......|",
 ".||..|||.|.|....|||...|..|.||.||.|.|...|||||.|.|.|",
 "|.|.||.||.|.|.||.|||.||....||.|||||.||.|.|||......",
 "|...|||...|.||||....|.||.||.|.........|..||.|..||.",
 ".|.....|.|.|....||.||...|||.|..||...||.|||.||.|.|.",
 "||.||.|||.|||..||......|......||..||||.|..||.||||."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 63; verify_case(4, Arg1, timeToShore(Arg0)); }
	void test_case_5() { string Arr0[] = {".+."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(5, Arg1, timeToShore(Arg0)); }
	void test_case_6() { string Arr0[] = {"..+.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(6, Arg1, timeToShore(Arg0)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }
template<class T> inline void print(T A[], int n) { cout<<"{ "; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", ";} cout<<" }"<<endl; }
template<class T> inline void print2(T A[], int n, int m) { cout<<"{"<<endl; for (int i=0; i<n; ++i) {cout<<" { "; for (int j=0; j<m; ++j) { cout<<A[i][j]; if (j+1<m) cout<<", ";} cout<<" } "<<endl; } cout<<"}"<<endl; }

int main()
{
  LumberjackHack ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

struct node {
  int x, y, time, water;
};

int LumberjackHack :: timeToShore(vector <string> riverMap)
{
  int n=(int)(riverMap).size(), m=(int)(riverMap[0]).size();
  vector<vector<pair<int, int> > > dist(n, vector<pair<int, int> >(m));
  for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) dist[i][j].first=dist[i][j].second=INT_MAX;
  int startx, starty;
  for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) if (riverMap[i][j]=='+') startx=i, starty=j;
  queue<node> q;
  node start;
  start.x=startx; start.y=starty; start.time=0; start.water=0;
  q.push(start);
  dist[startx][starty].first=0;
  int res=INT_MAX;
  while (!q.empty()) {
    node top=q.front();
    int x=top.x, y=top.y, time=top.time, water=top.water;
     cout<<x<<" "<<y<<" "<<time<<" "<<water<<endl;
    q.pop();
    if (!y || y==m-1) { res=min(res, time); continue; }
    node next;
    for (int p=-1; p<=1; p+=2) {
      if ((x+p>=n)|| x+p<0) continue;
      if (riverMap[x+p][y]=='|') {
	if (!water) {
	  if (time+1<dist[x+p][y].first) {
	    dist[x+p][y].first=time+1;
	    next.x=x+p; next.y=y; next.time=time+1; next.water=0;
	    q.push(next);
	  }
	} else {
	  if (time+1<dist[x+p][y].second) {
	    dist[x+p][y].second=time+1;
	    next.x=x+p; next.y=y; next.time=time+1; next.water=1;
	    q.push(next);
	  }
	}
      } else if (riverMap[x+p][y]=='.') {
	if (!water) {
	  if (time+3<dist[x+p][y].second) {
	    dist[x+p][y].second=time+3;
	    next.x=x+p; next.y=y; next.time=time+3; next.water=1;
	    q.push(next);
	  }
	}
      }
    }
    for (int p=-1; p<=1; p+=2)  {
      if ((y+p>=m)|| y+p<0) continue;
      if (riverMap[x][y+p]=='|') {
	if (!water) {
	  if (time+2<dist[x][y+p].first) {
	    dist[x][y+p].first=time+2;
	    next.x=x; next.y=y+p; next.time=time+2; next.water=0;
	    q.push(next);
	  }
	} else {
	  if (time+2<dist[x][y+p].second) {
	    dist[x][y+p].second=time+2;
	    next.x=x; next.y=y+p; next.time=time+2; next.water=1;
	    q.push(next);
	  }
	}
      } else if (riverMap[x][y+p]=='.') {
	if (!water) {
	  if (time+3<dist[x][y+p].second) {
	    dist[x][y+p].second=time+3;
	    next.x=x; next.y=y+p; next.time=time+3; next.water=1;
	    q.push(next);
	  }
	}
      }
    }
  }
  if (res==INT_MAX) res=-1;
  return res;
}
