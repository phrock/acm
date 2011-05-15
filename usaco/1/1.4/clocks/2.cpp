/*
  ID:   rock2to1
  LANG: C++
  PROG: clocks
*/
#include <algorithm>
#include <climits>
#include <cstdio>
#include <numeric>
using namespace std;
 
#define LOOP(x) for (s[x] = 0; s[x] < 4; ++s[x])
 
int main()
{
	int a[9], b[9], cnt, min_cnt = INT_MAX, res[10], s[10];
	freopen("clocks.in", "r", stdin);
	freopen("clocks.out", "w", stdout);
	for (int i = 0; i < 9; ++i)
		scanf("%d", &a[i]), a[i] = a[i]/3%4;
	LOOP(1) LOOP(2) LOOP(3)
	LOOP(4)	LOOP(5)	LOOP(6)
	LOOP(7)	LOOP(8)	LOOP(9)
	{
		b[0] = (a[0]+s[1]+s[2]+s[4])%4;
		b[1] = (a[1]+s[1]+s[2]+s[3]+s[5])%4;
		b[2] = (a[2]+s[2]+s[3]+s[6])%4;
		b[3] = (a[3]+s[1]+s[4]+s[5]+s[7])%4;
		b[4] = (a[4]+s[1]+s[3]+s[5]+s[7]+s[9])%4;
		b[5] = (a[5]+s[3]+s[5]+s[6]+s[9])%4;
		b[6] = (a[6]+s[4]+s[7]+s[8])%4;
		b[7] = (a[7]+s[5]+s[7]+s[8]+s[9])%4;
		b[8] = (a[8]+s[6]+s[8]+s[9])%4;
		if (accumulate(b, b+9, 0)) continue;
		cnt = accumulate(s+1, s+10, 0);
		if (cnt < min_cnt)
		{
			min_cnt = cnt;
			copy(s+1, s+10, res+1);
		}
	}
	for (int i = 1; i < 10; ++i)
		while (res[i]--)
			printf("%d%c", i, --cnt ? ' ' : '\n');
}
