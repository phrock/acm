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

// bool cmp(const pair<int, int> &a, const pair<int, int> &b)
// {
//     if (a.second!=b.second) return a.second>b.second;
//     else return a.first>b.first;
// }

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

    // sort((v).begin(), (v).end());
    int m=INT_MAX;
    int n=(int)(v).size();
    vector<int> p(n);
    int res=0;
    while (true) {
	int idx=0;
	int aux=-1;
	for (int i=0; i<n; ++i)
	    if (!p[i]) {
		int tmp=min(v[i].second, m-v[i].first);
		if (tmp>=0 && tmp>=aux) aux=tmp, idx=i;
	    }
	if (aux==-1)break;
	p[idx]=1;
	m=aux;
	res++;
    }
    cout<<res<<endl;
}
