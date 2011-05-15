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

int main()
{
    create_prime();

    int n, m;
    cin>>n>>m;

    int k;
    for (int i=n+1; i<MAX; ++i)
        if (prime[i]) { k=i; break; }
    cout<<(m==k?"YES":"NO")<<endl;
}
