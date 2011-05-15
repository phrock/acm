#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s = "123";

    string t;
    cout << s << endl;
    reverse_copy(s.begin(), s.end(),t.begin());
    cout << s << endl;
    cout << t << endl;
}
