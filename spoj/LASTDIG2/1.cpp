#include <climits>
#include <iostream>
using namespace std;
int func(int a, long long b)
{
    // if (!a && !b) return 0;
    if (!b) return 1;
    if (b % 2) return a * func(a, b - 1) % 10;
    else {
        int aux = func(a, b / 2);
        return aux * aux % 10;
    }
}

int main()
{
    int T;
    cin >> T;
    for (int ti = 0; ti < T; ++ti) {
        string a;
        long long b;
        cin >> a >> b;
        if (a == "0" && !b) {
            cout << 0 << endl;
            continue;
        }
        cout << func(a[(int)(a).size() - 1] - '0', b) << endl;
    }
}
