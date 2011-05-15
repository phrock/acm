#include <cmath>
#include <iostream>
using namespace std;

bool squareNum(long long n)
{
    long long x = sqrt(n);

    if (x*x == n) {
	return true;
    } else {
	return false;
    }
}

long long getX(long long d)
{
    long long y = 1;
    while (true) {
	long long dy = d*y*y;
	// cout <<"/////////  "<<d<<endl;
	// cout << dy+1 << endl;
	if (squareNum(dy+1) == false) {
	    y++;
	    continue;
	} else {
	    return sqrt(dy+1);
	}
    }
}

long long minValue(int n)
{
    long long result = 0;
    long long x = 0;
    for (int i=1; i<=n; i++) {
	cout << i << endl;
	if (squareNum(i) == true) {
	    continue;
	}
	long long tmp = getX(i);
	if (tmp > x) {
	    x = tmp;
	    result = i;
	    cout << x << endl;
	}
    }
    return result;
}

int main()
{
    int n = 1000;

    cout << minValue(n) << endl;
}
