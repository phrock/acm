#include <cmath>
#include <iostream>

using namespace std;

bool isTriangle(long long n)
{
    n *= 8;
    n++;
    
    long long m = sqrt(n);
    if ((m*m == n) && ((m-1)%2 == 0)) {
	return true;
    } else {
	return false;
    }
}

bool isPentagonal(long long n)
{
    n *= 24;
    n++;

    long long m = sqrt(n);
    if ((m*m == n) && ((m+1)%6 == 0)) {
	return true;
    } else {
	return false;
    }
}

int main()
{
    long long h = 143 + 1;
    // long long h = 2;

    long long hn = h*(2*h-1);
    while (!isTriangle(hn) || !isPentagonal(hn)) {
	cout << hn << endl;
 	h++;
 	hn = h*(2*h-1);
    }

    cout << hn << endl;

    // test
    // cout << isTriangle(1) << endl;
    // cout << isTriangle(3) << endl;
    // cout << isTriangle(6) << endl;
    // cout << isTriangle(10) << endl;
    // cout << isTriangle(11) << endl;

    // cout << isPentagonal(1) << endl;
    // cout << isPentagonal(5) << endl;
    // cout << isPentagonal(12) << endl;
    // cout << isPentagonal(22) << endl;
    // cout << isPentagonal(23) << endl;
}
