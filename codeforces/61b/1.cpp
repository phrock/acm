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
    vector<string> v(3);
    for (int i=0; i<3; ++i) {
	string s;
	cin>>s;
	for (int j=0; j<(int)(s).size(); ++j)
	    if (isalpha(s[j])) v[i]+=tolower(s[j]);
    }
    set<string> st;
    sort((v).begin(), (v).end());
    do {
	string s;
	for (int i=0; i<3; ++i) s+=v[i];
	st.insert(s);
    } while (next_permutation((v).begin(), (v).end()));
    int n;
    cin>>n;
    for (int i=0; i<n; ++i) {
	string s, t;
	cin>>s;
	for (int j=0; j<(int)(s).size(); ++j)
	    if (isalpha(s[j])) t+=tolower(s[j]);
	if (((st).find(t)!=(st).end())) cout<<"ACC"<<endl;
	else cout<<"WA"<<endl;
    }
}
