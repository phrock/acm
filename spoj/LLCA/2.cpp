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
#include "/home/rock/program/topcoder/libs/debug.cpp"
#endif

/*******************************************************************************
 *                                                                             *
 *                  To see the world in a grain of sand,                       *
 *                  And a heaven in a wild flower;                             *
 *                  Hold infinity in the palm of your hand,                    *
 *                  And eternity in an hour.                                   *
 *                                                                             *
 ******************************************************************************/


int main()
{
    string s;
    int T;
    while (true) {
        getline(cin, s);
        if (s.empty()) cout << endl;
        else {
            T = *({stringstream ss; ss << (s); static int _; ss >> _; &_;});
            break;
        }
    }
    for (int ti = 0; ti < T; ++ti) {
        int k, a, b;
        getline(cin, s);
        if (s.empty()) cout << endl, --ti;
        else {
            stringstream is(s);
            is >> k >> a >> b;
        }
        int aux = max(a, b);
        vector<long long> v;
        long long x = 1, width = 1;
        v.push_back(x);
        while (x < aux) {
            x += width;
            v.push_back(x);
            width *= k;
        }
        #ifdef DEBUG
        print(v);        
        #endif
        int ia = 0, ib = 0;
        for (ia = (int)(v).size() - 1; ia >= 0; --ia)
            if (a >= v[ia]) break;
        for (ib = (int)(v).size() - 1; ib >= 0; --ib)
            if (b >= v[ib]) break;
        vector<int> va, vb;
        while (a != 1) {
            va.push_back(a);
            a = (a - v[ia]) / k + v[ia - 1];
            --ia;
        }
        va.push_back(1);
        while (b != 1) {
            vb.push_back(b);
            b = (b - v[ib]) / k + v[ib - 1];
            --ib;
        }
        vb.push_back(1);
        #ifdef DEBUG
        print(va);
        print(vb);
        #endif
        vector<int> res((int)(va).size());
        set_intersection((va).rbegin(), (va).rend(), (vb).rbegin(), (vb).rend(), res.begin());
        cout << *max_element((res).begin(), (res).end()) << endl;
    }
}
