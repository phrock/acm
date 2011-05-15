/*
  ID:   rock2to1
  LANG: C++
  PROG: heritage
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

ifstream fin("heritage.in");
ofstream fout("heritage.out");
streambuf *cin_buf=cin.rdbuf();
streambuf *cout_buf=cout.rdbuf();
////////////////////////////////////////////////////////////////////////////////

string func(string in, string pre)
{
  // cout<<in<<" *** "<<pre<<endl;
  string res;
  if (in.empty()) return res;
  char root=pre[0];
  int k=in.find(root);
  int k2=(int)(in).size()-k-1;
  res=func(in.substr(0, k), pre.substr(1, k))+func(in.substr(k+1), pre.substr(k+1, k2))+root;
  return res;
}

int main()
{
  cin.rdbuf(fin.rdbuf());
  cout.rdbuf(fout.rdbuf());
  #ifdef DEBUG
  cin.rdbuf(cin_buf);
  cout.rdbuf(cout_buf);
  #endif
  //////////////////////////////////////////////////////////////////////////////

  string in, pre, res;
  cin>>in>>pre;
  res=func(in, pre);
  cout<<res<<endl;
}
