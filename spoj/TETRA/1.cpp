#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#ifdef DEBUG
#include "/home/Aphrodite/program/acm/topcoder/libs/debug.cpp"
#endif

/*******************************************************************************
 *                                                                             *
 *                  To see the world in a grain of sand,                       *
 *                  And a heaven in a wild flower;                             *
 *                  Hold infinity in the palm of your hand,                    *
 *                  And eternity in an hour.                                   *
 *                                                                             *
 ******************************************************************************/

double angle(double a, double b, double c)
{
    return acos((a * a + b * b - c * c) / (2 * a * b));
}

double volume(const vector<double> &edge)
{
    double g1 = angle(edge[0], edge[1], edge[3]);
    double g2 = angle(edge[1], edge[2], edge[5]);
    double g3 = angle(edge[0], edge[2], edge[4]);
    double g4 = (g1 + g2 + g3) / 2;
    double res = sqrt(sin(g4) * sin(g4 - g1) * sin(g4 - g2) * sin(g4 - g3)) * edge[0] * edge[1] * edge[2] / 3;

    return res;
}

double heron(double a, double b, double c)
{
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double area(const vector<double> & edge)
{
    return heron(edge[0], edge[1], edge[3]) + heron(edge[1], edge[2], edge[5]) + heron(edge[0], edge[2], edge[4]) + heron(edge[3], edge[4], edge[5]);
}

double apothem(const vector<double> &edge)
{
    return 3 * volume(edge) / area(edge);
}

int main()
{
    cout << setiosflags(ios::fixed) << setprecision(4);
    int T;
    cin >> T;
    for (int ti = 0; ti < T; ++ti) {
        vector<double> edge(6);
        for (int i = 0; i < 6; ++i)
            cin >> edge[i];
        cout << apothem(edge) << endl;
    }
}
