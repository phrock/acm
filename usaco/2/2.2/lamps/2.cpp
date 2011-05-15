/*
  ID:   rock2to1
  LANG: C++
  PROG: lamps
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

ifstream fin("lamps.in");
ofstream fout("lamps.out");
////////////////////////////////////////////////////////////////////////////////
vector<bool> lamp, on, off;
int n, c;
int button[4];
set<string> res;

void fun()
{
  for (button[0]=0; button[0]<2; ++button[0])
    for (button[1]=0; button[1]<2; ++button[1])
      for (button[2]=0; button[2]<2; ++button[2])
	for (button[3]=0; button[3]<3; ++button[3]) {
	  fill((lamp).begin(), (lamp).end(), true);
	  if (button[0]) fill((lamp).begin(), (lamp).end(), false); 
	  if (button[1]) for (int i=1; i<=n; i+=2) lamp[i]=!lamp[i]; 
	  if (button[2]) for (int i=2; i<=n; i+=2) lamp[i]=!lamp[i]; 
	  if (button[3]) for (int i=1; i<=n; i+=3) lamp[i]=!lamp[i];
	  bool ok=true;
	  for (int i=1; i<=n; ++i) if (on[i] && !lamp[i]) { ok=false; break; }
	  for (int i=1; i<=n; ++i) if (off[i] && lamp[i]) { ok=false; break; }
	  int cnt=accumulate(button, button+4, 0);
	  if (!(c>=cnt && (c-cnt)%2==0)) ok=false;
	  if (ok) {
	    string s;
	    for (int i=1; i<=n; ++i) s+=lamp[i]?"1":"0";
	    res.insert(s);
	  }
	}
}

int main()
{ 
  fin>>n>>c;
  int aux;
  lamp.resize(n+1); on.resize(n+1); off.resize(n+1);
  while (fin>>aux) { if (aux==-1) break; on[aux]=true; }
  while (fin>>aux) { if (aux==-1) break; off[aux]=true; }
  fun();
  if (!res.empty()) for (__typeof((res).begin()) i=(res).begin(); i!=(res).end(); ++i) fout<<*i<<endl;
  else fout<<"IMPOSSIBLE"<<endl;
}
