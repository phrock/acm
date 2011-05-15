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
////////////////////////////////////////////////////////////////////////////////

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

int main()
{
    int t;
    cin>>t;
    string s;
    for (int ti=0; ti<t; ++ti) {
        cin>>s;
        int n=(int)(s).size();
        string aux=s.substr(0, (n+1)/2);
        aux=addString(aux, "1");
        string res;
        if (n%2==0) {
            res=aux;
            if ((int)(aux).size()!=(n+1)/2) aux=aux.substr(0, (int)(aux).size()-1);
            reverse((aux).begin(), (aux).end());
            res+=aux; 
        } else {
            if ((int)(aux).size()==(n+1)/2) {
                res=aux;
                aux=aux.substr(0, (int)(aux).size()-1);
                reverse((aux).begin(), (aux).end());
                res+=aux;
            } else {
                aux=aux.substr(0, (int)(aux).size()-1);
                res=aux;
                reverse((aux).begin(), (aux).end());
                res+=aux;
            }                
        }
        cout<<res<<endl;
    }
}
