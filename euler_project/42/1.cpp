#include <cmath>
#include <bitset>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

bool isTriangleWord(string s)
{
    int n = 0;
    for (int i=0; i<s.size(); i++) {
	n += s[i]-'A'+1;
    }

    n *= 2;
    for (int i=1; i<sqrt(n); i++) {
	if ((n%i == 0) && (n/i == i+1)){
	    return true;
	}
    }

    return false;
}

int main()
{
    vector<string> v;

    char c;
    string s;
    while (cin >> c) {
	if (c == ',') {
	    v.push_back(s);
	    s.clear();
	    continue;
	}
	if (c>='A' && c<='Z') {
	    s += c;
	}
    }

    int result = 0;
    for (int i=0; i<v.size(); i++) {
	if (isTriangleWord(v[i]) == true) {
	    result++;
	}
    }

    cout << result << endl;
}
	
