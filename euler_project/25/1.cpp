//#include <gmp>
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

long long firstTerm(int n)
{
    long long result = 2;

    string a = "1";
    string b = "1";
    string tmp;

    while (true) {
	if (a.size() >= n) {
	    break;
	}

	tmp = a;
	a = addString(a, b);
	b = tmp;

	result++;
	// cout << result << " *** " << a << endl;
    }

    return result;
}

int main()
{
    int n = 1000;
    cout << firstTerm(n) << endl;
}
