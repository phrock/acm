#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    while (b != 0) {
	int r = a%b;
	a = b;
	b = r;
    }

    return a;
}

bool equal(int a, int b, int x, int y)
{
    int m = gcd(a, b);
    int n = gcd(x, y);

    if ((a/m == x/n) && (b/m == y/n)) {
	return true;
    } else {
	return false;
    }
}

bool canSimplify(int a, int b)
{
    int x = 0;
    int y = 0;

    x = a%10;
    y = b%10;
    if ((a/10 == b/10) && (equal(a, b, x, y) == true)) {
	return true;
    }

    x = a%10;
    y = b/10;
    if ((a/10 == b%10) && (equal(a, b, x, y) == true)) {
	return true;
    }
    
    x = a/10;
    y = b%10;
    if ((a%10 == b/10) && (equal(a, b, x, y) == true)) {
	return true;
    }

    x = a/10;
    y = b/10;
    if ((a%10 == b%10) && (equal(a, b, x, y) == true)) {
	return true;
    }

    return false;
}

int main()
{
    vector< vector<int> > result;

    for (int i=11; i<=99; i++) {
	for (int j=i+1; j<=99; j++) {
	    if ((i%10 == 0) || (j%10 == 0)) {
		continue;
	    }

	    vector<int> v(2);
	    v[0] = i;
	    v[1] = j;

	    if (canSimplify(i, j) == true) {
		result.push_back(v);
	    }
	}
    }

    for (int i=0; i<result.size(); i++) {
	for (int j=0; j<result[i].size(); j++) {
	    cout << result[i][j] << " ";
	}
	cout << endl;
    }
    cout << "**************"<< endl;

    int numerator = 1;
    int denominator = 1;
    for (int i=0; i<result.size(); i++) {
	numerator *= result[i][0];
    }
    for (int i=0; i<result.size(); i++) {
	denominator *= result[i][1];
    }

    cout << denominator / gcd(numerator, denominator) << endl;
}
