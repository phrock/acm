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

int a, b, n;
int llx[1001], lly[1001], urx[1001], ury[1001], color[1001];
int cut(int lx, int ly, int rx, int ry, int b)
{
  if (lx==rx||ly==ry) return 0;
  if (b>n) return (rx-lx)*(ry-ly);
  if (lx>=urx[b]||ly>=ury[b]||rx<=llx[b]||ry<=lly[b])
      return cut(lx,ly,rx,ry,b+1);
  int x[4], y[4];
  x[0]=lx; y[0]=ly; x[3]=rx; y[3]=ry;
  x[1]=max(lx,llx[b]); y[1]=max(ly,lly[b]);
  x[2]=min(rx,urx[b]); y[2]=min(ry,ury[b]);
  int res=0;
  for (int i=0; i<3; ++i)
      for (int j=0; j<3; ++j)
          if (i!=1||j!=1) res+=cut(x[i], y[j], x[i+1], y[j+1], b+1);
  return res;
}
 
int main() {
  fin >> a >> b >> n;
  llx[0]=0; lly[0]=0; urx[0]=a; ury[0]=b; color[0]=1;
  for (int i=1; i<=n; ++i)
      fin >> llx[i] >> lly[i] >> urx[i] >> ury[i] >> color[i];
  int count[2501];
  memset(count, 0, sizeof(count));
  for (int id=n; id>=0; --id)
      count[color[id]]+=cut(llx[id],lly[id],urx[id],ury[id],id+1);
  for (int i=1; i<=2500; ++i)
      if (count[i]>0) fout << i << " " << count[i] << endl;
}

