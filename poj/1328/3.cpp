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


double a[1005][2];
struct node { double x1; double x2; };
node b[1005];

bool cmp(const node &a, const node &b)
{
  return a.x1<b.x1;
}

int main()
{
  int n;
  double d;
  int k=0;
  while (cin>>n>>d) {
    if (!n) break;
    k++;
    for (int i=0; i<n; ++i) cin>>a[i][0]>>a[i][1];
    bool ok=true;
    for (int i=0; i<n; ++i)
      if (a[i][1]>d) ok=false;
    if (!ok) { cout<<"Case "<<k<<": "<<-1<<endl; continue; }
    for (int i=0; i<2; ++i) {
      b[i].x1=a[i][0]-sqrt(d*d-a[i][1]*a[i][1]);
      b[i].x2=a[i][0]+sqrt(d*d-a[i][1]*a[i][1]);
    }
    #ifdef DEBUG
    printp(b);
    #endif
    sort(b, b+n, cmp);
    int res=0;
    double x=INT_MIN;
    for (int i=0; i<n; ++i) {
      if (b[i].x1<=x) x=min(x, b[i].x2);
      else res++, x=b[i].x2;
    }
    cout<<"Case "<<k<<": "<<res<<endl;
  }
}
