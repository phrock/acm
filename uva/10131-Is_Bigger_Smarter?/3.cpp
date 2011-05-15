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

struct node {
    int num, weight, iq;
};

bool cmp(const node &a, const node &b)
{
    return a.weight<b.weight;
}

int main()
{
    vector<node> v;
    node x;
    int cnt=1;
    while (cin>>x.weight>>x.iq) {
	x.num=cnt++;
	v.push_back(x);
    }
    int n=(int)(v).size();
    sort((v).begin(), (v).end(), cmp);
    int res=0, idx=0;
    vector<int> dp(n), bt(n, -1);
    for (int i=0; i<n; ++i) {
	for (int j=0; j<i; ++j)
	    if (v[j].weight<v[i].weight && v[j].iq>v[i].iq && dp[j]>dp[i])
		dp[i]=dp[j], bt[i]=j;
	dp[i]++;
	if (dp[i]>res) res=dp[i], idx=i;
    }
    vector<int> path;
    while (idx!=-1) path.push_back(v[idx].num), idx=bt[idx];
    reverse((path).begin(), (path).end());
    cout<<res<<endl;
    for (int i=0; i<(int)(path).size(); ++i) cout<<path[i]<<endl;
}
