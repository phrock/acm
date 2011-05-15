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


int main()
{
    map<char, int> mm;
    mm['+']=1; mm['-']=2; mm['*']=3; mm['/']=4; mm['^']=5;
    int t;
    cin>>t;
    for (int ti=0; ti<t; ++ti) {
        string s;
        cin>>s;
        stack<char> st;
        for (int i=0; i<(int)(s).size(); ++i) {
            if (islower(s[i])) { cout<<s[i]; continue; }
            switch (s[i]) {
            case '(': st.push(s[i]); break;
            case ')':
                while (true) {
                    char c=st.top();
                    st.pop();
                    if (c=='(') break;
                    cout<<c;
                }
                break;
            default:
                if (!st.empty() && mm[s[i]]<mm[st.top()]) { cout<<st.top(); st.pop(); } 
                st.push(s[i]);
            }
        }
        while (!st.empty()) { cout<<st.top(); st.pop(); }
        cout<<endl;
    }
}
