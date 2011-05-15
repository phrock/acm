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


int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i=0; i<n; ++i) cin>>v[i];
    int res=0;
    for (int i=0; i<n; ++i) {
	int cnt=1;
	for (int j=i+1; j<n; ++j)
	    if (v[j]<=v[j-1]) cnt++;
	    else break;
	#ifdef DEBUG
	if (cnt>res) cout<<i<<" "<<v[i]<<" "<<cnt<<endl;	
	#endif
	for (int j=i-1; j>=0; --j)
	    if (v[j]<=v[j+1]) cnt++;
	    else break;
	#ifdef DEBUG
	if (cnt>res) cout<<i<<" "<<v[i]<<" "<<cnt<<endl;	
	#endif
	res=max(res, cnt);
    }
    cout<<res<<endl;
}
