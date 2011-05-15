#include <iostream>
#include <string>

using namespace std;

string itoa(int n)
{
    string s;
    while (n != 0) {
	s = (char)(n%10+'0') + s;
	n /= 10;
    }

    return s;
}

int main()
{
    int n = 1000000;
    string s;

    for (int i=1; i<=n; i++) {
	s += itoa(i);
    }

    // cout << s << endl;
    // cout << s.size() << endl;
    // cout <<"*****************"<<endl;

    int product = 1;
    int d = 1;
    while (d <= n) {
	cout << s.at(d-1) - '0' << endl;
	product *= s.at(d-1) - '0';
	d *= 10;
    }
    cout << product << endl;
}
