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
#include "/Users/Aphrodite/program/acm/lib/debug.cpp"
#endif

/****************************************************************************
 *                                                                          *
 *                To see the world in a grain of sand,                      *
 *                And a heaven in a wild flower;                            *
 *                Hold infinity in the palm of your hand,                   *
 *                And eternity in an hour.                                  *
 *                                                                          *
 ***************************************************************************/


int main()
{
    int n, k1, k2, p1, p2, p3;
    cin >> n >> k1 >> k2 >> p1 >> p2 >> p3;
    int orig_n = n;
    int res = 0, aux = 0;
    aux = n / p1;
    if (aux > 0) {
        if (aux > k1) {
            res += k1;
            n -= p1 * k1;
            aux = n / p2;
            if (aux > 0) {
                if (aux > k2) {
                    res += k2;
                    n -= p2 * k2;
                    aux = n / p3;
                    res += aux;
                } else {
                    res += aux;
                }
            }
        } else {
            res += aux;
        }
    }
    cout << res << endl;

    // int res2 = 0;
    // n = orig_n;
    // while (true) {
    //     aux = n / p1;
    //     if (aux > 0) {
    //         if (aux >= k1) {
    //             res2 += k1;
    //             n -= p1 * k1;
    //             aux = n / p2;
    //             if (aux > 0) {
    //                 if (aux >= k2) {
    //                     res2 += k2;
    //                     n -= p2 * k2;
    //                 } else {
    //                     res2 += aux;
    //                     break;
    //                 }
    //             } else {
    //                 break;
    //             }
    //         } else {
    //             res2 += aux;
    //             break;
    //         }
    //     } else {
    //         break;
    //     }
    // }
    // cout << max(orig_n / p1, max(res, res2)) << endl;
}
