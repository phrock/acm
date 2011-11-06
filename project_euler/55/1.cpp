#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string addString(string a, string b)
{
    string result;

    int ai = a.length() - 1;
    int bi = b.length() - 1;

    int carry = 0;
    while ((ai >= 0) || (bi >= 0)) {
	int x = 0;
	int y = 0;
	int z = 0;

	if (ai >= 0) {
	    x = a[ai] - '0';
	}
	if (bi >= 0) {
	    y = b[bi] - '0';
	}
	z = x + y + carry;

	carry = z / 10;
	int m = z % 10;

	result = (char)(m+'0') + result;

	if (ai >= 0) ai--;
	if (bi >= 0) bi--;
    }

    if (carry > 0) {
	result = (char)(carry+'0') + result;
    }

    return result;
}

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

string intToString(int x)
{
    string s;
    while (x != 0) {
	s += x%10 + '0';
	x /=10;
    }

    return s;
}

bool isLychrel(int n)
{
    string s = intToString(n);

    int m = 50;
    for (int i=0; i<m; i++) {
	// cout << s << endl;
	string t = s;
	reverse(t.begin(), t.end());
	s = addString(s, t);
	if (palindromic(s) == true) {
	    return false;
	}
    }

    return true;
}

int main()
{
    int n = 10000;
    int count = 0;
    for (int i=0; i<n; i++) {
	// cout << i << endl;
	if (isLychrel(i) == true) {
	    count++;
	}
    }

    cout << count << endl;

    // cout << isLychrel(359) << endl;
}
