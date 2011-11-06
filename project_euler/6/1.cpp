#include <iostream>
#include <algorithm>

using namespace std;

long long diff(long long n)
{
    long long a = 0LL;
    long long b = 0LL;

    for (long long i=1; i<=n; i++) {
	a += i*i;
	b += i;
    }

    b *= b;

    return abs(a-b);
}

int main()
{
    int test = 10;
    cout << diff(test) << endl;

    int x = 100;
    cout << diff(x) << endl;
}
