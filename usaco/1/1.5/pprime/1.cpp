/*
  ID:   rock2to1
  LANG: C++
  PROG: pprime
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

ifstream fin("pprime.in");
ofstream fout("pprime.out");
////////////////////////////////////////////////////////////////////////////////

bool isPal(int x)
{
  string s=*({stringstream ss; ss<<(x); static string _; ss>>_; &_;});
  string s2=s;
  reverse((s).begin(), (s).end());
  return s==s2;
}

bool isPrime(int x)
{
  for (int i=2; i*i<=x; ++i)
    if (x%i==0) return false;
  return true;
}

int main()
{
  int a, b;
  fin>>a>>b;
  for (int i7=0; i7<=0; ++i7) // because if a palindrome has even length, it could be divided by 11;
    for (int i6=0; i6<10; ++i6)
      for (int i5=0; i5<10; ++i5)
	for (int i4=0; i4<10; ++i4)
	  for (int i3=0; i3<10; ++i3) {
	    if (i7 && i6 && i5 && i4!=i3) continue;
	    for (int i2=0; i2<10; ++i2) {
	      if (i7 && i6 && i5!=i2) continue;
	      if (!i7 && i6 && i5 && i4!=i2) continue;
	      if (!i7 && !i6 && i5 && i4 && i3!=i2) continue;
	      for (int i1=0; i1<10; ++i1) {
		if (i7 && i6!=i1) continue;
		if (!i7 && i6 && i5!=i1) continue;
		if (!i7 && !i6 && i5 && i4!=i1) continue;
		if (!i7 && !i6 && !i5 && i4 && i3!=i1) continue;
		if (!i7 && !i6 && !i5 && !i4 && i3 && i2!=i1) continue;
		for (int i0=0; i0<10; ++i0) {
		  if (i7 && i7!=i0) continue;
		  if (!i7 && i6 && i6!=i0) continue;
		  if (!i7 && !i6 && i5 && i5!=i0) continue;
		  if (!i7 && !i6 && !i5 && i4 && i4!=i0) continue;
		  if (!i7 && !i6 && !i5 && !i4 && i3 && i3!=i0) continue;
		  if (!i7 && !i6 && !i5 && !i4 && !i3 && i2 && i2!=i0) continue;
		  if (!i7 && !i6 && !i5 && !i4 && !i3 && !i2 && i1 && i1!=i0) continue;
		  int x=i7*1e7+i6*1e6+i5*1e5+i4*1e4+i3*1e3+i2*1e2+i1*1e1+i0;
		  if (x>=a && x<=b && isPal(x) && isPrime(x)) fout<<x<<endl; 
		}
	      }
	    }
	  }
}
