#include <iostream>
using namespace std;
int func(int a, int b)
{
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
        int a, b;
        cin >> a >> b;
        cout << func(a, b) << endl;
    }
}
