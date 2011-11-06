#include <cmath>
#include <iostream>

using namespace std;

bool f(int n, int k)
{
    int t = n;
    int sum = 0;
    while (n != 0) {
	sum += pow(n%10, k);
	n /= 10;
    }

    // if (t == 1634) {
    // 	cout <<"///////////"<< endl;
    // 	cout << sum << endl;
    // }

    if (sum == t) {
	return true;
    } else {
	return false;
    }
}

int main()
{
    int n = 10000000;
    int k = 5;
    int sum = 0;

    for (int i=2; i<=n; i++) {
	if (f(i, k)) {
	    sum += i;
	}
    }

    cout << sum << endl;
}
