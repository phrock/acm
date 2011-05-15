#include <iostream>
using namespace std;

int circleSum(int n)
{
    int m = n;
    int p = m * m;
    int q = p;
    for (int i=0; i<3; i++) {
	cout << p << "**///////"<<n<<endl;
	p += q - m + 1;
	q = q - m + 1;
    }
    cout << p << "*******"<<n<<endl;
    return p;
}

int main()
{
    int sum = 1;
    // int n = 5;
    int n = 1001;
    
    for (int i=3; i<=n; i+=2) {
	sum += circleSum(i);
    }

    cout << sum << endl;
}
