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

#ifdef DEBUG
#include "/home/rock/program/topcoder/libs/debug.cpp"
#endif
////////////////////////////////////////////////////////////////////////////////

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second!=b.second) return a.second>b.second;
    else return a.first>b.first;
}

int main()
{
    int a, b;
    vector<pair<int, int> > v;
    while (cin>>a>>b) {
	if (a>b) continue;
	pair<int, int> x;
	x.first=a, x.second=b-a;
	v.push_back(x);
    }
    sort((v).begin(), (v).end(), cmp);
    int n=(int)(v).size();
    vector<vector<int> > dp(n, vector<int>(n));
    for (int i=0; i<n; ++i) dp[i][0]=v[i].second;
    vector<int> p(n);

    int res=0;
    for (int i=0; i<n; ++i)
	for (int j=0; j<i; ++j)
	    for (int k=0; k<=p[j]; ++k)
		if (v[i].first<=dp[j][k]) {
		    dp[i][k+1]=max(dp[i][k+1], min(v[i].second, dp[j][k]-v[i].first));
		    res=max(res, k+1);
		    p[i]=max(p[i], k+1);
		}
    cout<<res+1<<endl;
}
