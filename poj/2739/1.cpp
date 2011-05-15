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

////////////////////////////////////////////////////////////////////////////////


bool isPrime(int x)
{
  for (int i=2; i*i<=x; ++i)
    if (x%i==0) return false;
  return true;
}

int main()
{
  const int M=10005;
  vector<int> res(M);
  vector<int> prime;
  for (int i=2; i<=M; ++i)
    if (isPrime(i)) prime.push_back(i);
  for (int i=0; i<(int)(prime).size(); ++i) {
    int sum=0;
    for (int j=i; j<(int)(prime).size(); ++j) {
      sum+=prime[j];
      if (sum<M) res[sum]++;
    }
  }
  int n;
  while (cin>>n) {
    if (!n) break;
    cout<<res[n]<<endl;
  }
}
