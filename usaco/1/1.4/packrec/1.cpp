/*
  ID:   rock2to1
  LANG: C++
  PROG: packrec
*/
 
#include <algorithm>
#include <climits>
#include <cstdio>
using namespace std;
 
bool flag[10] = {};
int res[101], res_area = INT_MAX;
struct rectangle
{
	int x, y;
}a[4], rec;
 
void Record()
{
	if (rec.x*rec.y < res_area)
	{
		res_area = rec.x*rec.y;
		fill_n(res+1, 100, 0);
	}
	if (rec.x*rec.y == res_area)
		res[min(rec.x, rec.y)] = 1;
}
 
void Calc()
{
	//case 1
	rec.x = 0; rec.y = 0;
	for (int i = 0; i < 4; ++i)
	{
		rec.x += a[i].x;
		if (a[i].y > rec.y) rec.y = a[i].y;
	}
	Record();
	//case 2
	rec.x = 0; rec.y = 0;
	for (int i = 1; i < 4; ++i)
	{
		rec.x += a[i].x;
		if (a[i].y > rec.y) rec.y = a[i].y;
	}
	if (a[0].x > rec.x) rec.x = a[0].x;
	rec.y += a[0].y;
	Record();
	//case 3
	rec.x = max(a[0].x+a[1].x, a[2].x)+a[3].x;
	rec.y = max(max(a[0].y, a[1].y)+a[2].y, a[3].y);
	Record();
	//case 4, 5
	rec.x = a[0].x+max(a[1].x, a[2].x)+a[3].x;
	rec.y = max(max(a[0].y, a[1].y+a[2].y), a[3].y);
	Record();
	//case 6
	rec.x = a[0].x+a[1].x;
	rec.y = max(a[0].y+a[2].y, a[1].y+a[3].y);
	if (a[0].y < a[1].y)
		rec.x = max(rec.x, a[2].x+a[1].x);
	if (a[0].y+a[2].y > a[1].y)
		rec.x = max(rec.x, a[2].x+a[3].x);
	if (a[1].y < a[0].y)
		rec.x = max(rec.x, a[0].x+a[3].x);
	rec.x = max(rec.x, a[2].x);
	rec.x = max(rec.x, a[3].x);
	Record();
}
 
void Rotate(int k)
{
	if (k == 4) Calc();
	else
	{
		Rotate(k+1); swap(a[k].x, a[k].y);
		Rotate(k+1); swap(a[k].x, a[k].y);
	}
}
 
void Permutate(int k)
{
	if (k == 4) Rotate(0);
	else
	{
		for (int i = k; i < 4; ++i)
		{
			swap(a[k], a[i]);
			Permutate(k+1);
			swap(a[k], a[i]);
		}
	}
}
 
int main()
{
	freopen("packrec.in", "r", stdin);
	freopen("packrec.out", "w", stdout);
	for (int i = 0; i < 4; ++i)
		scanf("%d%d", &a[i].x, &a[i].y);
	Permutate(0);
	printf("%d\n", res_area);
	for (int i = 1; i <= 100; ++i)
        if (res[i])
            printf("%d %d\n", i, res_area/i);
}
