#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maxSum(const vector< vector<int> >& triangle)
{
    int result = 0;

    vector< vector<int> > sum;
    vector<int> row_sum(1);
    row_sum[0] = triangle[0][0];
    sum.push_back(row_sum);
	
    for (int i=1; i<triangle.size(); i++) {
	vector<int> row_sum(i+1);
	row_sum[0] = sum[i-1][0] + triangle[i][0];
	for (int j=1; j<i; j++) {
	    row_sum[j] = triangle[i][j] + max(sum[i-1][j-1], sum[i-1][j]);
	}
	row_sum[i] = sum[i-1][i-1] + triangle[i][i];

	sum.push_back(row_sum);
    }

      // for (int i=0; i<sum.size(); i++) {
      // 	for (int j=0; j<sum[i].size(); j++) {
      // 	    cout << sum[i][j] << " ";
      // 	}
      // 	cout << endl;
      // }

    int m = sum.size() - 1;
    for (int i=0; i<sum[m].size(); i++) {
	result = sum[m][i] > result ? sum[m][i] : result;
    }

    return result;
}

int main()
{
    vector< vector<int> > triangle;

    int row = 1;
    int num = 0;
    while (cin >> num) {
	vector<int> v(row);
	v[0] = num;
	for (int i=1; i<row; i++) {
	    cin >> v[i];
	}

	triangle.push_back(v);

	row++;
    }

    // for (int i=0; i<triangle.size(); i++) {
    // 	for (int j=0; j<triangle[i].size(); j++) {
    // 	    cout << triangle[i][j] << " ";
    // 	}
    // 	cout << endl;
    // }

    cout << maxSum(triangle) << endl;
}
