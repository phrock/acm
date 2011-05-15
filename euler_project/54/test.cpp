#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<string> v;
    v.push_back("12");
    v.push_back("34");
    v.push_back("56");
    v.push_back("78");
    v.push_back("90");

    vector<string> v1(v.begin()+1, v.begin()+3);
    vector<string> v2(v.begin()+3, v.end());

    for (int i=0; i<v2.size(); i++) {
	cout << v2[i] << endl;
    }

    int a = 3;
    switch (a) {
    case 3:
	cout << "haha"<<endl;
    case 2:
	cout << "haha"<<endl;

    case 1:
	cout << "haha"<<endl;

    }
}
