#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int count(int p)
{
    p /= 2;
    cout << p << endl;
    int result = 0;
    for (int i=1; i<sqrt(p); i++) {
	if (p%i == 0) {
	    int j = p/i - i;
	    // if (j >= i) {
	    // 	continue;
	    // }

	    // if ((abs(i*i-j*j) + 2*i*j + i*i+j*j) != 2*p) {
	    // 	continue;
	    // }
		
	    if ((abs(i*i-j*j) + 2*i*j) > (i*i+j*j)) {
		result++;
		cout << i << "@@ "<< j << endl;
		cout << abs(i*i-j*j) << " " << 2*i*j << "  " << i*i+j*j<< endl;
	    }
	}
    }

    return result;
}

int main()
{
    int p = 1000;

    int max = 0;

    int mp = 0;

    for (int i=2; i<=p; i+=2) {
	cout << "*******************" << i << endl;
	int tmp = count(i);
	if (tmp > max) {
	    max = tmp;
	    mp = i;
	}
    }

    cout << mp << endl;
    cout << max << endl;
}
    
