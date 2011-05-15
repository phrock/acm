#include <iostream>
#include <vector>

using namespace std;

int sumOfDivisors(int n)
{
    int sum = 1;
    for (int i=2; i*i<=n; i++) {
	int p = 1;
	while (n%i == 0) {
	    p = p*i + 1;
	    n /= i;
	}
	sum *= p;

    }

    if (n > 1) {
	sum *= n + 1;
    }

    // cout << sum << endl;
    return sum;
}

bool noTwo(int n, const vector<int>& a)
{
    for (int i=1; i<n; i++) {
	if ((a[i] == 1) && (a[n-i] == 1)) {
	    return false;
	}
    }
    return true;
}

int main()
{
    int n = 28124;
    vector<int> a(n, 0);

    for (int i=1; i<n; i++) {
	if (sumOfDivisors(i)-i > i) {
	    a[i] = 1;
	     // cout <<"*** "<<i<<endl;
	}
    }
    cout << "haha"<< endl;
    int sum = 0;
    for (int i=1; i<n; i++) {
	if (noTwo(i, a) == true) {
	    sum += i;
	    // cout << i << endl;
	}
    }

    cout << sum << endl;
}

    
