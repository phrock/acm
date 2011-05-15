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
    sort((a).begin(), (a).end());
    bool ok=true;
    for (int i=0; i<(int)(a).size(); ++i)
      if (a[i].second>d) ok=false;
    if (!ok) { cout<<"Case "<<k<<": "<<-1<<endl; continue; }
    vector<int> v(n);
    int res=0;
    for (int i=0; i<(int)(a).size(); ++i) {
      if (v[i]) continue;
      double x=sqrt(d*d-a[i].second*a[i].second)+a[i].first;
      v[i]=1;
      res++;
      for (int j=i+1; j<(int)(a).size(); ++j)
	if (!v[j] && sqrt((a[j].first-x)*(a[j].first-x)+a[j].second*a[j].second)<=d) v[j]=1;
    }
    cout<<"Case "<<k<<": "<<res<<endl;
  }
}
