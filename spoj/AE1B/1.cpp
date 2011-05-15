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
    int n, k, s;
    cin>>n>>k>>s;
    vector<int> v(n);
    for (int i=0; i<n; ++i) cin>>v[i];
    sort((v).begin(), (v).end(), greater<int>());
    int cnt=0, aux=0;
    for (int i=0; i<(int)(v).size(); ++i) {
        if (aux>=k*s) break;
        else aux+=v[i], cnt++;
    }
    cout<<cnt<<endl;
}
