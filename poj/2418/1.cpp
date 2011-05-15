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
  string s;
  map<string, int> mm;
  int sum=0;
  while (getline(cin, s)) { sum++; mm[s]++; }
  cout<<setiosflags(ios::fixed)<<setprecision(4);
  for (__typeof((mm).begin()) i=(mm).begin(); i!=(mm).end(); ++i)
    cout<<i->first<<" "<<100.0*i->second/sum<<endl;
}
