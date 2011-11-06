#include <iostream>
#include <vector>

using namespace std;

int factorial(int n)
{
    int a = 1;
    for (int i=0; i<n; i++) {
	a *= i+1;
    }

    return a;
}

int f(int n, const vector<int>& v)
{
    int r = 0;
    while (n != 0) {
	r += v[n%10];
	n /= 10;
    }

    return r;
}

int main()
{
    vector<int> v(10);
    for (int i=0; i<v.size(); i++) {
	v[i] = factorial(i);
    }

    int sum = 0;
    for (int i=3; i<20000000; i++) {
	if (f(i, v) == i) {
	    sum += i;
	}
    }

    cout << sum << endl;
}
