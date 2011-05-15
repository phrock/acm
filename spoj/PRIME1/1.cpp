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

const int MAX=100000;
bitset<MAX> prime;
vector<int> v;

void create_prime()
{
    prime.reset();
    prime.flip();
    prime[0]=prime[1]=0;
    for (long long i=2; i<MAX; ++i) {
        if (prime[i]) {
            for (long long j=i*i; j<MAX; j+=i){
                prime[j]=0;
            }
        }
    }
}

bool check(int n)
{
    if (n<MAX) return prime[n];
    
    for (int i=0; i<(int)(v).size(); ++i) {
        int x=v[i];
        if (x*x>n) return true;
        if (n%x==0) return false;
    }
    return true;
}

int main()
{
    create_prime();
    for (int i=0; i<MAX; ++i)
        if (prime[i]) v.push_back(i);
    #ifdef DEBUG
    print(v);    
    #endif
    int t, n, m;
    cin>>t;
    for (int k=0; k<t; ++k) {
        if (k) cout<<endl;
        cin>>m>>n;
        for (int i=m; i<=n; ++i) 
            if (check(i)) printf("%d\n", i);
    }
}
