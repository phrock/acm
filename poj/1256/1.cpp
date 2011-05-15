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

bool cmp(char a, char b)
{
  char at=toupper(a);
  char bt=toupper(b);
  if (at!=bt) return at<bt;
  return a<b;
}

int main()
{
  int n;
  cin>>n;
  string s;
  for (int i=0; i<n; ++i) {
    cin>>s;
    sort((s).begin(), (s).end(), cmp);
    do {
      cout<<s<<endl;
    } while (next_permutation((s).begin(), (s).end(), cmp));
  }
}
