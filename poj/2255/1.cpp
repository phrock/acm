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


string go(string a, string b)
{
  if ((int)(a).size()<=1) return a;
  char root=a[0];
  int p=b.find(root);
  string x1=a.substr(1, p);
  string y1=a.substr(1+p);
  string x2=b.substr(0, p);
  string y2=b.substr(1+p);
  return go(x1, x2)+go(y1, y2)+root;
}

int main()
{
  string a, b;
  while (cin>>a) {
    cin>>b;
    cout<<go(a, b)<<endl;
  }
}
