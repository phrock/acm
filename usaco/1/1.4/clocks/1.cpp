/*
  ID:   rock2to1
  LANG: C++
  PROG: clocks
*/

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

////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }
template<class T> inline void print(T A[], int n) { cout<<"{ "; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", ";} cout<<" }"<<endl; }
template<class T> inline void print2(T A[], int n, int m) { cout<<"{"<<endl; for (int i=0; i<n; ++i) {cout<<" { "; for (int j=0; j<m; ++j) { cout<<A[i][j]; if (j+1<m) cout<<", ";} cout<<" } "<<endl; } cout<<"}"<<endl; }

void rotate_helper(vector< vector<int> >& vv, int x, int y)
{
	vv[x][y] += 3;
	vv[x][y] %= 12;
	if (vv[x][y] == 0) vv[x][y] = 12;
}

vector< vector<int> > rotate(const vector< vector<int> >& vv, int n)
{
	vector< vector<int> > ret = vv;
	switch (n) {
	case 1: rotate_helper(ret, 0, 0);
		rotate_helper(ret, 0, 1);
		rotate_helper(ret, 1, 0);
		rotate_helper(ret, 1, 1);
		break;
	case 2: rotate_helper(ret, 0, 0);
		rotate_helper(ret, 0, 1);
		rotate_helper(ret, 0, 2);
		break;
	case 3: rotate_helper(ret, 0, 1);
		rotate_helper(ret, 0, 2);
		rotate_helper(ret, 1, 1 );
		rotate_helper(ret, 1, 2);
		break;
	case 4: rotate_helper(ret, 0, 0);
		rotate_helper(ret, 1, 0);
		rotate_helper(ret, 2, 0);
		break;
	case 5: rotate_helper(ret, 0, 1);
		rotate_helper(ret, 1, 0);
		rotate_helper(ret, 1, 1);
		rotate_helper(ret, 1, 2);
		rotate_helper(ret, 2, 1);
		break;
	case 6: rotate_helper(ret, 0, 2);
		rotate_helper(ret, 2, 1);
		rotate_helper(ret, 2, 2);
		break;
	case 7: rotate_helper(ret, 1, 0);
		rotate_helper(ret, 1, 1);
		rotate_helper(ret, 2, 0);
		rotate_helper(ret, 2, 1);
		break;
	case 8: rotate_helper(ret, 2, 0);
		rotate_helper(ret, 2, 1);
		rotate_helper(ret, 2, 2);
		break;
	case 9: rotate_helper(ret, 1, 1);
		rotate_helper(ret, 1, 2);
		rotate_helper(ret, 2, 1);
		rotate_helper(ret, 2, 2);
		break;
	}
	return ret;
}

int main()
{
  ifstream fin("clocks.in.test");
  ofstream fout("clocks.out");

  vector< vector<int> > start(3, vector<int>(3));
  for (int i=0; i<3; ++i)
    for (int j=0; j<3; ++j)
      fin>>start[i][j];
  vector< vector<int> > dest=start;
  for (int i=0; i<(int)(dest).size(); ++i)
    for (int j=0; j<(int)(dest[i]).size(); ++j)
      dest[i][j]=12;
  queue<vector< vector<int> > > q;
  q.push(start);
  map<vector< vector<int> >, pair<vector< vector<int> >, int> > mm;
  mm[start]=make_pair(start, -1);
  while (!q.empty()) {
    vector< vector<int> > x=q.front();
    print2(x);
    q.pop();
    if (x==dest) {
      vector<int> path;
      while (x!=start) { path.push_back(mm[x].second); x=mm[x].first; }
      reverse((path).begin(), (path).end());
      for (int i=0; i<(int)(path).size(); ++i) {
	if (i) fout<<" ";
	fout<<path[i];
      }
      fout<<endl;
    }
    for (int i=1; i<=9; ++i) {
      vector< vector<int> > aux=rotate(x, i);
      if (((mm).find(aux)!=(mm).end())) continue;
      q.push(aux);
      mm[aux]=make_pair(x, i);
    }
  }

  return 0;
}
