#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool checkInnerOuter(const vector<int>& inner,
		     const vector<int>& outer,
		     int m, int l)
{
    vector<int> v(m+1, 0);
    for (int i=0; i<outer.size(); i++) {
	v[outer[i]] = 1;
    }

    for (int i=0; i<inner.size(); i++) {
	int x = inner[i] + inner[(i+1)%inner.size()];
	if (v[l-x] == 1) {
	    v[l-x] = 0;
	} else {
	    return false;
	}
    }

    return true;
}

vector< vector<int> > checkInnerCandidate(vector<int>& inner, int m, int l)
{
    vector<int> outer;
    
    for (int i=1; i<=m; i++) {
	if (find(inner.begin(), inner.end(), i) == inner.end()) {
	    outer.push_back(i);
	}
    }

    cout << "inner: ";
    for (int i=0; i<inner.size(); i++) {
	cout << inner[i] << " ";
    }
    cout << endl;

    cout << "outer: ";
    for (int i=0; i<outer.size(); i++) {
	cout << outer[i] << " ";
    }
    cout << endl;

    vector< vector<int> > result;

    if (checkInnerOuter(inner, outer, m, l) == true) {
	result.push_back(inner);
    }

    while (next_permutation(inner.begin(), inner.end()) == true) {
	if (checkInnerOuter(inner, outer, m, l) == true) {
	    result.push_back(inner);
	}
    }
	
    return result;
}

vector< vector< vector<int> > > buildRing(int n, int l)
{
    int m = 2*n;

    int a = m*(m+1)/2;

    int b = l*n - a;

    cout << a << " " << b << endl;

    vector< vector<int> > inner;
    for (int i1=1; i1<=m; i1++) {
	for (int i2=i1+1; i2<=m; i2++) {
	    for (int i3=i2+1; i3<=m; i3++) {
		for (int i4=i3+1; i4<=m; i4++) {
		    for (int i5=i4+1; i5<=m; i5++) {
			if (i1+i2+i3+i4+i5 == b) {
			    cout<<i1<<" "<<i2<<" "<<i3<<" "<<i4<<" "<<i5<<endl;
			    vector<int> innerCandidate(5);
			    innerCandidate[0] = i1;
			    innerCandidate[1] = i2;
			    innerCandidate[2] = i3;
			    innerCandidate[3] = i4;
			    innerCandidate[4] = i5;

			    vector< vector<int> > candidate =
				checkInnerCandidate(innerCandidate,m,l);
			    if (candidate.size() > 0) {
				for (int i=0; i<candidate.size(); i++) {
				    inner.push_back(candidate[i]);
				}
			    }
			}
		    }
		}
	    }
	}
    }
    
    vector< vector< vector<int> > > result;
    for (int i=0; i<inner.size(); i++) {
	vector< vector<int> > tmp;
	for (int j=0; j<inner[i].size(); j++) {
	    int x = inner[i][j];
	    int y = inner[i][(j+1)%inner[i].size()];
	    int z = l - x - y;

	    vector<int> v(3);
	    v[0] = z;
	    v[1] = x;
	    v[2] = y;

	    tmp.push_back(v);
	}
	result.push_back(tmp);
    }

    return result;
}

string buildDigitString(vector< vector<int> > v)
{
    int k = 0;
    for (int i=0; i<v.size(); i++) {
	if (v[i][0] < v[k][0]) {
	    k = i;
	}
    }

    string result;
    for (int i=k; i<k+v.size(); i++) {
	for (int j=0; j<v[i%v.size()].size(); j++) {
	    if (v[i%v.size()][j] < 10) {
		result += v[i%v.size()][j] + '0';
	    } else {
		result += "10";
	    }
	}
    }

    return result;
}

int main()
{
    int n = 5;
    int l = 16;

    vector< vector< vector<int> > > result = buildRing(n, l);

    for (int i=0; i<result.size(); i++) {
	cout << "**************" <<endl;
	string ts = buildDigitString(result[i]);
	cout << ts << endl;
	for (int j=0; j<result[i].size(); j++) {
	    for (int k=0; k<result[i][j].size(); k++) {
		cout << result[i][j][k] << " ";
	    }
	    cout << endl;
	}
	cout << "**************" <<endl<<endl;
    }

    string resultString;
    for (int i=0; i<result.size(); i++) {
	string ts = buildDigitString(result[i]);

	resultString = ts > resultString ? ts : resultString;
    }

    cout << resultString << endl;
}
