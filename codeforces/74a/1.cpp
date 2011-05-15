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
    string s;
    int p, q, a, b, c, d, e;
    int n;
    cin>>n;
    vector<pair<int, string> > v;
    for (int i=0; i<n; ++i) {
        cin>>s>>p>>q>>a>>b>>c>>d>>e;
        pair<int, string> tmp;
        tmp.second=s;
        tmp.first=100*p-50*q+a+b+c+d+e;
        v.push_back(tmp);
    }
    sort((v).begin(), (v).end());
    #ifdef DEBUG
    printp(v);    
    #endif
    cout<<v.back().second<<endl;
}
