#include <vector>
#include <iostream>
#include <string>

using namespace std;

bool palindromic(string s)
{
    int n = s.size();

    for (int i=0; i<n/2; i++) {
	if (s[i] != s[n-1-i]) {
	    return false;
	}
    }

    return true;
}

bool bothPalindromic(int x)
{
    string decimal;
    string binary;

    int y = x;

    while (x != 0) {
	decimal += x%10;
	x /= 10;
    }

    while (y != 0) {
	binary += y%2;
	y /= 2;
    }

    if (palindromic(decimal) && palindromic(binary)) {
	return true;
    } else {
	return false;
    }
}

int main()
{
    int n = 1000000;

    long long sum = 0LL;

    for (int i=1; i<n; i+=2) {
	if (bothPalindromic(i) == true) {
	    sum += i;
	}
    }

    cout << sum << endl;
}
