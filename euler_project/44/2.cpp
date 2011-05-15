#include <iostream>
#include <vector>

using namespace std;

int fac3(int n)
{
    int result = 1;
    for (int i=0; i<n; i++) {
	result *= 3;
    }
    return result;
}

bool check(int n, int& a, int& b)
{
    int x = n*(3*n-1)/2;

    x *= 2;
     cout << x << endl;
    int t = n;
    int f = 0;
    while ((f=(3*t+1)) < x) {
	//	cout << "ffffff: "<< f << endl;
	// if ((x%(f-1) == 0) && ((x/(f-1)-1)%3 == 0) && ((a=(x/(f-1)-1)/3) > n)) {
	//     b = a + t;
	//     // cout << m << endl;
	//     return true;
	// }

	if (x%f == 0) {
	    int z = x/f + 1;
	    cout << "z;; " << z<<endl;
	    b = 0;
	    while (z%3 == 0) {
		b++;
		z /= 3;
	    }

	    if (z == 1) {
		a = t;
		b += a;
		return true;
	    }
	}
	t++;
    }
    return false;
}

int main()
{
    int n = 1;
    int a = 1;
    int b = 1;
    int t1 = 1;
    int t2 = 1;
       while (true) {
       	// if (n > 100) break;
       	cout << n-1 << " a: " << a << " b: " << b<< endl;
         	if (check(n, a, b) && check(a, t1, t2) && (b == t1)) {
        	    cout << a << endl;
         	    cout << n*(3*n-1)/2;
         	    break;
         	}
         	n++;
       }

    cout <<check(4,a, b) << endl;
    cout << a <<" " << b<<endl;
}
	
