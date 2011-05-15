/*
  ID:   rock2to1
  LANG: C++
  PROG: contact
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

ifstream fin("contact.in");
ofstream fout("contact.out");
////////////////////////////////////////////////////////////////////////////////

bool cmp(string a, string b)
{
  if ((int)(a).size()!=(int)(b).size()) return (int)(a).size()<(int)(b).size();
  else return a<b;
}

int main()
{
  int a, b, n;
  fin>>a>>b>>n;
  string s, aux;
  while (fin>>aux) s+=aux;
  map<string, int> mm;
  for (int i=0; i<(int)(s).size(); ++i)
    for (int j=a; j<=b; ++j)
      if (i+j<=(int)(s).size()) mm[s.substr(i, j)]++;
  map<int, vector<string> > res;
  for (__typeof((mm).begin()) i=(mm).begin(); i!=(mm).end(); ++i) res[i->second].push_back(i->first);
  for (__typeof((res).rbegin()) i=(res).rbegin(); i!=(res).rend(); ++i) {
    if (n-->0) {
      fout<<i->first<<endl;
      sort((i->second).begin(), (i->second).end(), cmp);
      for (int j=0; j<(int)(i->second).size(); ++j) {
	if (j%6) fout<<" "; else if (j) fout<<endl;
	fout<<i->second[j];
      }
      fout<<endl;
    }
  }
}
