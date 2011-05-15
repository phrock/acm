/*
  ID:   rock2to1
  LANG: C++
  PROG: sort3
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

ifstream fin("sort3.in");
ofstream fout("sort3.out");
////////////////////////////////////////////////////////////////////////////////
int main()
{
  int n;
  fin>>n;
  vector<int> v(n);
  for (int i=0; i<n; ++i) fin>>v[i];
  int c1=0, c2=0, c3=0;
  for (int i=0; i<n; ++i) {
    if (v[i]==1) c1++;
    if (v[i]==2) c2++;
    if (v[i]==3) c3++;
  }

  int cnt=0;
  for (int i=0; i<c1; ++i) {
    if (v[i]==2) for (int j=c1; j<n; ++j) if (v[j]==1) { swap(v[i], v[j]); cnt++; break; }
    if (v[i]==3) for (int j=n-1; j>=0; --j) if (v[j]==1) { swap(v[i], v[j]); cnt++; break; }
  }
  for (int i=0; i<c2; ++i) {
    if (v[c1+i]==3) cnt++;
  }
  fout<<cnt<<endl;
}
