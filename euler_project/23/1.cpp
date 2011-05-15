#include <iostream>
#include <vector>

using namespace std;

int sumOfDivisors(int n)
{
    int sum = 0;
    for (int i=1; i<n; i++) {
	if (n%i == 0) {
	    sum += i;
	}
    }

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
	if (sumOfDivisors(i) > i) {
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

    
