#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    while (b != 0) {
	int r = a%b;
	a = b;
	b = r;
    }

    return a;
}

int main()
{
    cout << gcd(81,9) << endl;
}
