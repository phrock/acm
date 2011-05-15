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
  int T, n;
  cin>>T;
  for (int k=0; k<T; ++k) {
    vector< pair<int, int> > a;
    cin>>n;
    for (int n1=0; n1<n; ++n1) {
      int s, t;
      cin>>s>>t;
      s++;
      t++;
      s/=2; t/=2;
      a.push_back(make_pair(min(s, t), max(s, t)));
    }
    sort((a).begin(), (a).end());
    int res=0;
    for (int i=0; i<(int)(a).size(); ++i) {
      int aux=1;
      for (int j=0; j<i; ++j)
	if (a[i].first<=a[j].second) aux++;
      res=max(res, aux);
    }
    cout<<res*10<<endl;
  }
}
