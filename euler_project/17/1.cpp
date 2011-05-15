#include <iostream>
using  namespace std;

int main()
{
    int sum = 0;
    int d1_9 = 3+3+5+4+4+3+5+5+4;
    sum += d1_9;

    int d10 = 3;
    sum += d10;

    int d11_19 = 6+6+8+8+7+7+9+8+8;
    sum += d11_19;

    int d20_90 = 6+6+5+5+5+7+6+6;
    sum += d20_90;

    int d21_99 = d1_9*8 + d20_90*9;
    sum += d21_99;

    int d20_99 = d20_90 + d21_99;
    int d1_99 = d1_9 + d10 + d11_19 + d20_99;

    int d100_900 = d1_9 + 7*9;
    sum += d100_900;

    int d101_999 = d1_99*9 + (d100_900+3*9)*99;
    sum += d101_999;

    int d1000 = 3 + 8;
    sum += d1000;

    cout << sum << endl;
}
