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
    vector<int> dp(n+1, -1);
    dp[0]=INT_MAX;
    for (int i=0; i<(int)(v).size(); ++i)
	for (int j=0; j<=i; ++j)
	    if (dp[j]>=v[i].first)
		dp[j+1]=max(dp[j+1], min(v[i].second, dp[j]-v[i].first));
    int res=0;
    for (int i=0; i<(int)(dp).size(); ++i)
	if (dp[i]!=-1) res=i;
    cout<<res<<endl;
}
