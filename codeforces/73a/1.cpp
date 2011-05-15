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
    vector<long long> v(3);
    long long k;
    cin>>v[0]>>v[1]>>v[2]>>k;
    sort((v).begin(), (v).end());
    if (accumulate((v).begin(), (v).end(), 0)-3<=k) { cout<<v[0]*v[1]*v[2]<<endl; return 0; }
    long long p1=min(k/3, v[0]-1);
    long long p2=min((k-p1)/2, v[1]-1);
    long long p3=k-p1-p2;
    cout<<(p1+1)*(p2+1)*(p3+1)<<endl;
}
