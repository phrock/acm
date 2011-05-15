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


int a[100010];

int main()
{
    int n, k;
    cin>>n>>k;
    for (int i=0; i<n; ++i) cin>>a[i];
    map<int, int> mm;
    set<int> st;
    for (int i=0; i<k; ++i) {
	int x=a[i];
	mm[x]++;
	if (mm[x]==1) st.insert(-x);
	else st.erase(-x);
    }
    if (st.empty()) cout<<"Nothing"<<endl;
    else cout<<-*st.begin()<<endl;
    #ifdef DEBUG
    print(st);    
    #endif
    for (int i=1; i<n-k+1; ++i) {
	int x=a[i-1];
	mm[x]--;
	if (mm[x]==1) st.insert(-x);
	else st.erase(-x);
	x=a[i+k-1];
	mm[x]++;
	if (mm[x]==1) st.insert(-x);
	else st.erase(-x);
	if (st.empty()) cout<<"Nothing"<<endl;
	else cout<<-*st.begin()<<endl;
    #ifdef DEBUG
    print(st);    
    #endif
    }
}
