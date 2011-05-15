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

template<class T> vector<T> split(const string& s, const string& delim =" ") {
  vector<string> aux;
  string t;
  for (int i=0; i!=(int)(s).size(); i++)
    if (delim.find(s[i])!=string::npos) { if (!t.empty()) { aux.push_back(t); t=""; } }
    else t+=s[i];
  if (!t.empty()) aux.push_back(t);
  vector<T> res;
  for (int i=0; i<(int)(aux).size(); ++i)
    res.push_back(*({stringstream ss; ss<<(aux[i]); static T _; ss>>_; &_;}));
  return res;
}

bool isRXCY(string s)
{
  for (int i=0; i<(int)(s).size(); ++i)
    if (isdigit(s[i])) s[i]=' ';
  vector<string> v=split<string>(s);
  return (int)(v).size()==2;
}

string func1(string s)
{
  for (int i=0; i<(int)(s).size(); ++i)
    if (!isdigit(s[i])) s[i]=' ';
  vector<string> v=split<string>(s);
  int x=*({stringstream ss; ss<<(v[1]); static int _; ss>>_; &_;});
  string res;
  while (x) {
    int y=(x-1)%26;
    x=(x-1)/26;
    res=(char)('A'+y)+res;
  }
  res+=v[0];
  return res;
}

string func2(string s)
{
  string r, c;
  for (int i=0; i<(int)(s).size(); ++i)
    if (isdigit(s[i])) r+=s[i];
    else c+=s[i];
  int x=0, k=1;
  for (int i=(int)(c).size()-1; i>=0; --i) x+=(c[i]-'A'+1)*k, k*=26;
  string res="R"+r+"C"+*({stringstream ss; ss<<(x); static string _; ss>>_; &_;});
  return res;
}

int main()
{
  int n;
  cin>>n;
  for (int i=0; i<n; ++i) {
    string s;
    cin>>s;
    if (isRXCY(s)) cout<<func1(s)<<endl;
    else cout<<func2(s)<<endl;
  }
}
