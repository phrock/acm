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
    int x=0, y=0, z=0;
    for (int i=0; i<n; ++i) {
	int a, b, c;
	cin>>a>>b>>c;
	x+=a, y+=b, c+=z;
    }
    if (!x && !y && !z) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
