/*
  ID:   rock2to1
  LANG: C++
  PROG: rect1
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

ifstream fin("rect1.in");
ofstream fout("rect1.out");
////////////////////////////////////////////////////////////////////////////////

struct node {
  int llx, lly, urx, ury, color;
};

int main()
{
  int a, b, n;
  fin>>a>>b>>n;
  vector<node> v(n);
  for (int i=0; i<n; ++i) fin>>v[i].llx>>v[i].lly>>v[i].urx>>v[i].ury>>v[i].color;
  reverse((v).begin(), (v).end());
  map<int, int> mm;
  for (int i=0; i<a; ++i)
    for (int j=0; j<b; ++j) {
      int x=1;
      for (int k=0; k<(int)(v).size(); ++k) 
	if (i>=v[k].llx && j>=v[k].lly && i<v[k].urx && j<v[k].ury) { x=v[k].color; break; }
      mm[x]++;
    }
  for (__typeof((mm).begin()) i=(mm).begin(); i!=(mm).end(); ++i) fout<<i->first<<" "<<i->second<<endl;
}
