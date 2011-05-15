/*
  ID:   rock2to1
  LANG: C++
  PROG: fracdec
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

ifstream fin("fracdec.in");
ofstream fout("fracdec.out");
////////////////////////////////////////////////////////////////////////////////

int main()
{
  int n,d,k[100001],dat[100001],len=0;
  fin>>n>>d;
  fout<<n/d<<".";
  if (n>=d) len=int(log(n/d)/log(10)+2.00001);
  else len=2;
 
  n%=d;
  memset(k,0,sizeof(k));
  int tmp=d/__gcd(n,d);
  while (tmp%2==0) tmp/=2;
  while (tmp%5==0) tmp/=5;
 
  if (tmp==1)
    {
      for (;;)
	{
	  n*=10;
	  fout<<n/d;
	  n%=d;
	  if (n==0) break;
	}
      fout<<endl;
      return 0;
    }
 
 
  for (int i=1;;i++)
    {
      if (k[n]!=0)
        {
	  for (int j=1;j<=k[n]-1;j++)
	    {
	      fout<<dat[j];
	      len++;
	      if (len%76==0) fout<<endl;
	    }
	  fout<<"(";
	  len++;
	  if (len%76==0) fout<<endl;
	  for (int j=k[n];j<=i-1;j++)
	    {
	      fout<<dat[j];
	      len++;
	      if (len%76==0) fout<<endl;
	    }
	  fout<<")"<<endl;
	  return 0;
        }
      k[n]=i;
      n*=10;
      dat[i]=n/d;
      n%=d;
    }
  return 0;

}
