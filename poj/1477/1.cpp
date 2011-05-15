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


int main()
{
  for (int i=1; ; ++i) {
    int n;
    cin>>n;
    if (!n) break;
    cout<<"Set #"<<i<<endl;
    vector<int> v(n);
    int sum=0;
    for (int j=0; j<(int)(v).size(); ++j) cin>>v[j], sum+=v[j];
    sum/=n;
    int res=0;
    for (int j=0; j<(int)(v).size(); ++j) if (v[j]>sum) res+=v[j]-sum;
    cout<<"The minimum number of moves is "<<res<<"."<<endl<<endl;
  }
}
