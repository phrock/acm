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

int main()
{
  int n;
  double d;
  int k=0;
  while (cin>>n>>d) {
    if (!n) break;
    k++;
    vector<pair<double, double> > a(n);
    for (int i=0; i<n; ++i) cin>>a[i].first>>a[i].second;
    bool ok=true;
    for (int i=0; i<(int)(a).size(); ++i)
      if (a[i].second>d) ok=false;
    if (!ok) { cout<<"Case "<<k<<": "<<-1<<endl; continue; }
    vector<pair<double, double> > b;
    for (int i=0; i<(int)(a).size(); ++i) {
      double x1=a[i].first-sqrt(d*d-a[i].second*a[i].second);
      double x2=a[i].first+sqrt(d*d-a[i].second*a[i].second);
      b.push_back(make_pair(x1, x2));
    }
    #ifdef DEBUG
    printp(b);
    #endif
    sort((b).begin(), (b).end());
    vector<int> v(n);
    int res=0;
    double x=INT_MIN;
    for (int i=0; i<(int)(b).size(); ++i) {
      if (b[i].first<=x) x=min(x, b[i].second);
      else res++, x=b[i].second;
    }
    
    cout<<"Case "<<k<<": "<<res<<endl;
  }
}
