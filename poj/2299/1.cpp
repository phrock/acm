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

ifstream fin("in");
////////////////////////////////////////////////////////////////////////////////

const int M=1000000;
int a[M];
int b[M];
int n;

long long mergeSort(int a[], int p, int q)
{
  if (q-p<=1) return 0;
  int d=(p+q)/2;
  long long k1=mergeSort(a, p, d);
  long long k2=mergeSort(a, d, q);
  long long k3=0;
  int i1=p, i2=d, j=0;
  while (i1<d || i2<q) {
    if (i1<d && i2<q) {
      if (a[i1]<=a[i2]) b[j++]=a[i1++], k3+=i2-d;
      else b[j++]=a[i2++];
    } else if (i1<d) while (i1<d) b[j++]=a[i1++], k3+=q-d;
    else while (i2<q) b[j++]=a[i2++];
  }
  memcpy(a+p, b, j*sizeof(int));
  return k1+k2+k3;
}

int main()
{
#ifdef DEBUG
  cin.rdbuf(fin.rdbuf());  
#endif

  while (cin>>n && n) {
    for (int i=0; i<n; ++i) cin>>a[i];
    cout<<mergeSort(a, 0, n)<<endl;;
  }
}
