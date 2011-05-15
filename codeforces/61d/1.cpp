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

void dfs(int cur, const vector<vector<pair<int, int> > > &g, vector<int> &v, int sum, int &long_path)
{
    long_path=max(long_path, sum);
    for (int i=0; i<(int)(g[cur]).size(); ++i) {
	int next=g[cur][i].first;
	if (!v[next]) { v[next]=1; dfs(next, g, v, sum+g[cur][i].second, long_path); }
    }
}

int main()
{
    int n;
    cin>>n;
    long long res=0;
    vector<vector<pair<int, int> > > g(n);
    for (int i=0; i<n-1; ++i) {
	int a, b, w;
	cin>>a>>b>>w;
	res+=w*2;
	a--, b--;
	g[a].push_back(make_pair(b, w));
	g[b].push_back(make_pair(a, w));
    }
    vector<int> v(n);
    int long_path=0;
    v[0]=1;
    dfs(0, g, v, 0, long_path);
    res-=long_path;
    cout<<res<<endl;
}
