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
  map<string, string> mm;
  string s;
  while (true) {
    getline(cin, s);
    if (s.empty()) break;
    string a, b;
    stringstream is(s);
    is>>a>>b;
    mm[b]=a;
  }
  while (getline(cin, s)) {
    if (((mm).find(s)!=(mm).end())) cout<<mm[s]<<endl;
    else cout<<"eh"<<endl;
  }
}
