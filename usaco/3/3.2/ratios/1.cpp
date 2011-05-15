/*
  ID:   rock2to1
  LANG: C++
  PROG: ratios
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

ifstream fin("ratios.in");
ofstream fout("ratios.out");
streambuf *cin_buf=cin.rdbuf();
streambuf *cout_buf=cout.rdbuf();
////////////////////////////////////////////////////////////////////////////////
int check(int a[], int b[], int n)
{
  int res=0;
  for (int i=0; i<n; ++i) {
    if (!a[i] && !b[i]) continue;
    if (a[i]>b[i]) return 0;
    if (!a[i] && b[i]) return 0;
    if (b[i]%a[i]) return 0;
    int k=b[i]/a[i];
    if (res==0) res=k;
    else if (res!=k) return 0;
  }
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

  int a[3], b[3];
  int p[3][3];
  for (int i=0; i<3; ++i) cin>>a[i];
  for (int i=0; i<3; ++i) for (int j=0; j<3; ++j) cin>>p[i][j];
  int m=INT_MAX, r1=0, r2=0, r3=0, c;
  for (int k1=0; k1<100; ++k1)
    for (int k2=0; k2<100; ++k2)
      for (int k3=0; k3<100; ++k3) {
	b[0]=k1*p[0][0]+k2*p[1][0]+k3*p[2][0];
	b[1]=k1*p[0][1]+k2*p[1][1]+k3*p[2][1];
    	b[2]=k1*p[0][2]+k2*p[1][2]+k3*p[2][2];
	// cout<<k1<<" "<<k2<<" "<<k3<<" ";
	// print(a, 3); print(b, 3);
	int tmp;
	if ((tmp=check(a, b, 3))!=0) {
	  int aux=k1+k2+k3;
	  if (aux<m) { m=aux, r1=k1, r2=k2, r3=k3; c=tmp; }
	}
      }
  if (m==INT_MAX) cout<<"NONE"<<endl;
  else cout<<r1<<" "<<r2<<" "<<r3<<" "<<c<<endl;
}
