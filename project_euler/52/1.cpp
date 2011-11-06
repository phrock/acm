#include <cstring>
#include <iostream>

using namespace std;

bool sameDigits(int a[], int b[], int n)
{
    for (int i=0; i<n; i++) {
	if (a[i] != b[i]) {
	    return false;
	}
    }

    return true;
}

void fillArray(int x, int a[])
{
    while (x != 0) {
	a[x%10]++;
	x /= 10;
    }
}

bool testDigits(int x)
{
    int xd[10];
    int yd[10];
    memset(xd, 0, sizeof(xd));
    memset(yd, 0, sizeof(yd));

    fillArray(x, xd);
    
    for (int i=2; i<=6; i++) {
	memset(yd, 0, sizeof(yd));
	fillArray(x*i, yd);

	if (sameDigits(xd, yd, 10) == false) {
	    return false;
	}
    }

    return true;
}

int main()
{
    int x = 1;
    while (testDigits(x) == false) {
	x++;
    }

    cout << x << endl;
}
