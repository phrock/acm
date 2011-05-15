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

vector<pair<double, double> > a(1005);
vector<pair<double, double> > b(1005);

int main()
{
  int n;
  double d;
  int k=0;
  while (true) {
    scanf("%d%lf", &n, &d);
    if (!n) break;
    k++;
    for (int i=0; i<n; ++i) scanf("%lf%lf", &a[i].first, &a[i].second);
    bool ok=true;
    for (int i=0; i<n; ++i) {
      if (a[i].second>d) { ok=false; break; }
      b[i].first=a[i].first-sqrt(d*d-a[i].second*a[i].second);
      b[i].second=a[i].first+sqrt(d*d-a[i].second*a[i].second);
    }
    if (!ok) { cout<<"Case "<<k<<": "<<-1<<endl; continue; }

    #ifdef DEBUG
    printp(b);
    #endif
    sort((b).begin(), b.begin()+n);
    int res=0;
    double x=INT_MIN;
    for (int i=0; i<n; ++i) {
      if (b[i].first<=x) x=min(x, b[i].second);
      else res++, x=b[i].second;
    }
    
    cout<<"Case "<<k<<": "<<res<<endl;
  }
}
