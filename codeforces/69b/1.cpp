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

const int M=105;
int l[M], r[M], t[M], c[M], res[M], p[M];

int main()
{
    int n, m;
    cin>>n>>m;
    for (int i=0; i<m; ++i) {
	cin>>l[i]>>r[i]>>t[i]>>c[i];
    }
    for (int i=1; i<=n; ++i) p[i]=INT_MAX;
    int time=0;
    for (int i=0; i<m; ++i) time=max(time, t[i]*(r[i]-l[i]));
    for (int i=0; i<time; ++i)
	for (int j=0; j<m; ++j) {
	    int k=i/t[j]+l[j];
	    cout<<i<<" "<<j<<endl;
	    if (k<=r[j] && t[j]<p[k]) { p[k]=t[j], res[k]=j;
		cout<<i<<" "<<j<<" "<<p[j]<<" "<<res[k]<<" "<<k<<" "<<p[k]<<endl; }
	}
    int sum=0;
    for (int i=1; i<=n; ++i) sum+=c[res[i]];
    cout<<sum<<endl;
    #ifdef DEBUG
    print(res, 10);    
    #endif
}
