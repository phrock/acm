#include <iostream>

using namespace std;

int fibEvenSum(int n)
{
    int x = 1;
    int y = 1;

    int result = 0;

    while (x <= n) {
	if (x%2 == 0) {
	    result += x;
	}
	int tmp = x;
	x += y;
	y = tmp;
    }

    return result;
}

int main()
{
    cout << fibEvenSum(89) << endl;
    cout << fibEvenSum(4000000) << endl;
}
