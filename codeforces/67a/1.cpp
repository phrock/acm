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
    string s;
    cin>>n>>s;
    vector<int> v(n, 1);
    while (true) {
	bool ok=true;
	for (int i=1; i<n; ++i) {
	    if (s[i-1]=='=' && v[i-1]!=v[i]) {
		if (v[i-1]<v[i]) v[i-1]=v[i];
		else v[i]=v[i-1];
		ok=false;
	    } else if (s[i-1]=='R' && v[i-1]>=v[i]) {
		v[i]=v[i-1]+1;
		ok=false;
	    } else if (s[i-1]=='L' && v[i-1]<=v[i]) {
		v[i-1]=v[i]+1;
		ok=false;
	    }
	}
	if (ok) break;
    }
    for (int i=0; i<n; ++i) cout<<v[i]<<" ";
    cout<<endl;
}
