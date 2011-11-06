#include <iostream>
using namespace std;
int rectangles(int _y, int _x)
{
	int y, x, cnt = 0;
 
	for(y = 1; y <= _y; y++)
	{
		for(x = 1; x <= _x; x++)
			cnt += (x*y);
	}
 
	return cnt;
}
 
int main()
{
	for(int x = 1; x < 300; x++)
	{
		for(int y = x; y < 300; y++)
		{
			int t = rectangles(y, x);
 
			if(t > 1999000 && t < 2001000)
			{
				cout << x << " " << y << " " << t << endl;
			}
		}
	}
 
	return 0;
}
