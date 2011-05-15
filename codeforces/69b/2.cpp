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
    for (int i=0; i<m; ++i)
	for (int j=l[i]; j<=r[i]; ++j)
	    if (t[i]<p[j]) p[j]=t[i], res[j]=i;
    int sum=0;
    for (int i=1; i<=n; ++i)
	if (p[i]!=INT_MAX) sum+=c[res[i]];
    cout<<sum<<endl;
}
