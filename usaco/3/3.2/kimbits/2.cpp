/*
  ID:   rock2to1
  LANG: C++
  PROG: kimbits
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

ifstream fin("kimbits.in");
ofstream fout("kimbits.out");
streambuf *cin_buf=cin.rdbuf();
streambuf *cout_buf=cout.rdbuf();
  // if (cin_buf==NULL || cout_buf==NULL) { cout<<"iostream error!"<<endl; return 0; }

////////////////////////////////////////////////////////////////////////////////

const int M=32;
long long ncr[M][M];

void dfs(int N, int L, unsigned I, string &res)
{
  //cout<<N<<" "<<L<<" "<<I<<" "<<ncr[N-1][L]<<" "<<res<<endl;
  if (!N) return;
  if (ncr[N-1][L]<I) res+='1', dfs(N-1, L-1, I-ncr[N-1][L], res);
  else res+='0', dfs(N-1, L, I, res);
}

int main()
{
  cin.rdbuf(fin.rdbuf());
  cout.rdbuf(fout.rdbuf());
  #ifdef DEBUG
  cin.rdbuf(cin_buf);
  cout.rdbuf(cout_buf);
  #endif

  for (int i=0; i<M; ++i) ncr[0][i]=ncr[i][0]=1;
  for (int i=1; i<M; ++i) for (int j=1; j<M; ++j) ncr[i][j]=ncr[i-1][j]+ncr[i-1][j-1];

  unsigned int N, L, I;
  cin>>N>>L>>I;
  string res;
  dfs(N, L, I, res);

  cout<<res<<endl;
}
