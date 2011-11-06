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
    for (int i=100; i<1000; i++) {
	for (int j=100; j<1000; j++) {
	    if ((i*j > max) && isPalindrome(i*j)) {
		max = i*j;
	    }
	}
    }
    cout << max << endl;
}
