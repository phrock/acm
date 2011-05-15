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
  int n;
  cin>>n;
  string s;
  map<string, int> mm;
  for (int i=0; i<n; ++i) {
    cin>>s;
    if (((mm).find(s)!=(mm).end())) {
      mm[s]++;
      cout<<s+*({stringstream ss; ss<<(mm[s]); static string _; ss>>_; &_;})<<endl;
    } else {
      mm[s]=0;
      cout<<"OK"<<endl;
    }
  }
}
