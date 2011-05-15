/*
  ID:   rock2to1
  LANG: C++
  PROG: msquare
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

ifstream fin("msquare.in");
ofstream fout("msquare.out");
streambuf *cin_buf=cin.rdbuf();
streambuf *cout_buf=cout.rdbuf();
////////////////////////////////////////////////////////////////////////////////

vector<int> turn1(const vector<int> &a)
{
  vector<int> res=a;
  swap(res[0], res[7]); swap(res[1], res[6]); swap(res[2], res[5]); swap(res[3], res[4]);
  return res;
}

vector<int> turn2(const vector<int> &a)
{
  vector<int> res=a;
  swap(res[0], res[3]); swap(res[1], res[2]); swap(res[1], res[3]); swap(res[4], res[7]); swap(res[5], res[6]); swap(res[4], res[6]);
  return res;
}

vector<int> turn3(const vector<int> &a)
{
  vector<int> res=a;
  int aux=res[1];
  res[1]=res[6]; res[6]=res[5]; res[5]=res[2]; res[2]=aux;
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

  vector<int> a;
  for (int i=1; i<=8; ++i) a.push_back(i);
  vector<int> b(8);
  for (int i=0; i<8; ++i) cin>>b[i];
  queue<vector<int> > q;
  q.push(a);
  map<vector<int>, pair<vector<int>, char> > back;
  back[a]=make_pair(vector<int>(), 0);
  string res;
  bool ok=false;
  while (!q.empty()) {
    vector<int> x=q.front();
    q.pop();
    if (x==b) {
      ok=true;
      while (x!=a) res+=back[x].second, x=back[x].first;
      reverse((res).begin(), (res).end());
      break;
    }
    vector<int> next=turn1(x);
    if (!((back).find(next)!=(back).end())) back[next]=make_pair(x, 'A'), q.push(next);
    next=turn2(x);
    if (!((back).find(next)!=(back).end())) back[next]=make_pair(x, 'B'), q.push(next);
    next=turn3(x);
    if (!((back).find(next)!=(back).end())) back[next]=make_pair(x, 'C'), q.push(next);
  }
  if (ok) {
    cout<<(int)(res).size()<<endl;
    for (int i=0; i<(int)(res).size(); ++i) {
      if (i && i%60==0) cout<<endl;
      cout<<res[i];
    }
    cout<<endl;
  }
}
