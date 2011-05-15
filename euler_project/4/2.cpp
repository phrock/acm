#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(int n)
{
    string s;
    while (n > 0) {
	s += n%10;
	n /= 10;
    }

    int sz = s.size();
    for (int i=0; i<sz; i++) {
	if (s[i] != s[sz-1-i]) {
	    return false;
	}
    }

    return true;
}

int main()
{
    int max = 0;
    for (int i=10000; i<=999*999; i++) {
	if ((i > max) && isPalindrome(i)) {
	    max = i;
	}
    }
    cout << max << endl;
}
