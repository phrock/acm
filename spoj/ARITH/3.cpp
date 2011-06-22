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

string addString(string a, string b)
{
    string result;
    int ai = a.length() - 1;
    int bi = b.length() - 1;
    int carry = 0;
    while ((ai >= 0) || (bi >= 0)) {
	int x = 0;
	int y = 0;
	int z = 0;
	if (ai >= 0) x = a[ai] - '0';
	if (bi >= 0) y = b[bi] - '0';
	z = x + y + carry;
	carry = z / 10;
	int m = z % 10;
	result = (char)(m+'0') + result;
	if (ai >= 0) ai--;
	if (bi >= 0) bi--;
    }
    if (carry > 0) result = (char)(carry+'0') + result;

    return result;
}

string subString(string a, string b)
{
    bool negitive = false;
    if ((int)(a).size() < (int)(b).size()) {
        negitive = true;
    } else if ((int)(a).size() == (int)(b).size()) {
        for (int i = 0; i < (int)(a).size(); ++i)
            if (a[i] > b[i]) break;
            else if (a[i] < b[i]) {
                negitive = true;
                break;
            }
    }
    if (negitive) swap(a, b);

    int tmp = (int)(a).size() - (int)(b).size();
    for (int i = 0; i < tmp; ++i)
        b = "0" + b;
    int carry = 0;
    string res;
    for (int i = (int)(a).size() - 1; i >= 0; --i)
        if (carry) {
            if (a[i] > b[i]) {
                res = char('0' + a[i] - b[i] - 1) + res;
                carry = 0;
            } else {
                res = char('0' + a[i] - b[i] - 1 + 10) + res;
                carry = 1;
            }
        } else {
            if (a[i] >= b[i]) {
                res = char('0' + a[i] - b[i]) + res;
                carry = 0;
            } else {
                res = char('0' + a[i] - b[i] + 10) + res;
                carry = 1;
            }
        }
    while (!res.empty()) {
        if (res[0] == '0') res = res.substr(1);
        else break;
    }
    if (res.empty()) res = "0";
    if (negitive) res = "-" + res;
    return res;
}

string productString(string a, int n)
{
    int carry = 0;
    string res;
    for (int i = (int)(a).size() - 1; i >= 0; --i) {
        int aux = (a[i] - '0') * n + carry;
        res = char(aux % 10 + '0') + res;
        carry = aux / 10;
    }
    if (carry)
        res = *({stringstream ss; ss << (carry); static string _; ss >> _; &_;}) + res;
    while (!res.empty()) {
        if (res[0] == '0') res = res.substr(1);
        else break;
    }
    if (res.empty()) res = "0";
    return res;
}

template<class T> vector<T> split(const string& s, const string& delim = " ") {
    vector<string> aux;
    string t;
    for (int i = 0; i != (int)(s).size(); ++i)
        if (delim.find(s[i]) != string::npos) { if (!t.empty()) { aux.push_back(t); t = ""; } }
        else t += s[i];
    if (!t.empty()) aux.push_back(t);
    vector<T> res;
    for (int i = 0; i < (int)(aux).size(); ++i)
        res.push_back(*({stringstream ss; ss << (aux[i]); static T _; ss >> _; &_;}));
    return res;
}

void add(string a, string b)
{
    string res = addString(a, b);
    int dash_length = max((int)(b).size() + 1, (int)(res).size());
    string dash;
    for (int i = 0; i < dash_length; ++i)
        dash += "-";
    int space = dash_length - (int)(a).size();
    for (int i = 0; i < space; ++i)
        a = " " + a;
    cout << a << endl;

    b = "+" + b;
    space = dash_length - (int)(b).size();
    for (int i = 0; i < space; ++i)
        b = " " + b;
    cout << b << endl;

    cout << dash << endl;

    space = dash_length - (int)(res).size();
    for (int i = 0; i < space; ++i)
        res = " " + res;
    cout << res << endl;
    cout << endl;
}

void sub(string a, string b)
{
    string res = subString(a, b);
    int dash_length = max((int)(b).size() + 1, (int)(res).size());
    string dash;
    for (int i = 0; i < dash_length; ++i)
        dash += "-";
    int space = dash_length - (int)(a).size();
    for (int i = 0; i < space; ++i)
        a = " " + a;
    cout << a << endl;

    b = "-" + b;
    space = dash_length - (int)(b).size();
    for (int i = 0; i < space; ++i)
        b = " " + b;
    cout << b << endl;

    cout << dash << endl;

    space = dash_length - (int)(res).size();
    for (int i = 0; i < space; ++i)
        res = " " + res;
    cout << res << endl;
    cout << endl;
}

void product(string a, string b)
{
    map<int, string> mp;
    vector<string> v((int)(b).size());
    for (int i = (int)(b).size() - 1; i >= 0; --i) {
        string aux = string("") + b[i];
        if (a == "0" || aux == "0") {
            v[(int)(b).size() - i - 1] = "0";
        } else {
            if (((mp).find(b[i] - '0') != (mp).end()))
                v[(int)(b).size() - i - 1] = mp[b[i] - '0'];
            else {
                v[(int)(b).size() - i - 1] = productString(a, b[i] - '0');
                mp[b[i] - '0'] = v[(int)(b).size() - i - 1];
            }
        }
    }
    #ifdef DEBUG
    print(v);    
    #endif
    string res = "0";
    for (int i = 0; i < (int)(v).size(); ++i) {
        string tmp = v[i];
        for (int j = 0; j < i; ++j)
            tmp += "0";
        res = addString(res, tmp);
    }

    int max_dash_length = max((int)(b).size() + 1, (int)(res).size());

    int space = max_dash_length - (int)(a).size();
    for (int i = 0; i < space; ++i)
        a = " " + a;
    cout << a << endl;

    string ob = b;
    b = "*" + b;
    space = max_dash_length - (int)(b).size();
    for (int i = 0; i < space; ++i)
        b = " " + b;
    cout << b << endl;

    string dash;
    int dash_length = max((int)(ob).size() + 1, (int)(v[0]).size());
    for (int i = 0; i < dash_length; ++i)
        dash += "-";
    space = max_dash_length - (int)(dash).size();
    for (int i = 0; i < space; ++i)
        dash = " " + dash;
    cout << dash << endl;

    space = max_dash_length - (int)(v[0]).size();
    for (int i = 0; i < space; ++i)
        v[0] = " " + v[0];
    cout << v[0] << endl;
    if ((int)(v).size() == 1) { cout << endl; return; }
    
    for (int i = 1; i < (int)(v).size(); ++i) {
        // for (int j = 0; j < i; ++j)
        //     v[i] += " ";
        space = max_dash_length - (int)(v[i]).size() - i;
        for (int j = 0; j < space; ++j)
            v[i] = " " + v[i];
        cout << v[i] << endl;
    }

    dash = "";
    dash_length = max((int)(v.back().size()), (int)(res).size());
    for (int i = 0; i < dash_length; ++i)
        dash += "-";
    space = max_dash_length - (int)(dash).size();
    for (int i = 0; i < space; ++i)
        dash = " " + dash;
    cout << dash << endl;

    space = max_dash_length - (int)(res).size();
    for (int i = 0; i < space; ++i)
        res = " " + res;
    cout << res << endl;
    cout << endl;
}

int main()
{
    int T;
    cin >> T;
    for (int ti = 0; ti < T; ++ti) {
        string s;
        cin >> s;
        if ((find((s).begin(), (s).end(), '+') != (s).end())) {
            vector<string> v = split<string>(s, "+");
            add(v[0], v[1]);
        } else if ((find((s).begin(), (s).end(), '-') != (s).end())) {
            vector<string> v = split<string>(s, "-");
            sub(v[0], v[1]);
        } else {
            vector<string> v = split<string>(s, "*");
            product(v[0], v[1]);
        }
    }
}
