#include <set>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    set<int> s;
    set<int> s2;

    set<int> s3(9);
    set_union(s.begin(), s.end(), s2.begin(), s2.end(), s3.begin());
}
