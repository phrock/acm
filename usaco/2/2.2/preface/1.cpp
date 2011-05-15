/*
  ID:   rock2to1
  LANG: C++
  PROG: preface
*/

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

ifstream fin("preface.in");
ofstream fout("preface.out");
////////////////////////////////////////////////////////////////////////////////

map<int, string> mm;

string roman(int n)
{
  if (((mm).find(n)!=(mm).end())) return mm[n];
  string res;
  if (n>=1000) res="M"+roman(n-1000);
  else if (n>=900) res="CM"+roman(n-900);
  else if (n>=500) res="D"+roman(n-500);
  else if (n>=400) res="CD"+roman(n-400);
  else if (n>=100) res="C"+roman(n-100);
  else if (n>=90) res="XC"+roman(n-90);
  else if (n>=50) res="L"+roman(n-50);
  else if (n>=40) res="XL"+roman(n-40);
  else if (n>=10) res="X"+roman(n-10);
  else if (n>=9) res="IX"+roman(n-9);
  else if (n>=5) res="V"+roman(n-5);
  else if (n>=4) res="IV"+roman(n-4);
  else if (n>=1) res="I"+roman(n-1);
  mm[n]=res;
  return res;
}

int main()
{
  int n;
  fin>>n;
  map<char, int> res;
  for (int i=1; i<=n; ++i) {
    string s=roman(i);
    // cout<<s<<endl;
    for (int i=0; i<(int)(s).size(); ++i) res[s[i]]++;
  }
  string c="IVXLCDM";
  for (int i=0; i<(int)(c).size(); ++i) if (res[c[i]]) fout<<c[i]<<" "<<res[c[i]]<<endl;
}
