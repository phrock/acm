#include <iostream>

using namespace std;

int d35(int n)
{
    int sum = 0;
    for (int i=1; i<n; i++) {
	if ((i%3 == 0) || (i%5) == 0) {
	    sum += i;
	}
    }
    return sum;
}

int main()
{
    cout << d35(10) << endl;
    cout << d35(1000) << endl;
}
