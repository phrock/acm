#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> rankPoker(const vector<string>& v)
{
    vector<int> rank(10, 0);
    int n = v.size();
    vector<int> value(15, 0);
    for (int i=0; i<n; i++) {
	switch (v[i][0]) {
	case '2': value[2]++; break;
	case '3': value[3]++; break;
	case '4': value[4]++; break;
	case '5': value[5]++; break;
	case '6': value[6]++; break;
	case '7': value[7]++; break;
	case '8': value[8]++; break;
	case '9': value[9]++; break;
	case 'T': value[10]++; break;
	case 'J': value[11]++; break;
	case 'Q': value[12]++; break;
	case 'K': value[13]++; break;
	case 'A': value[14]++; break;
	}
    }

    // rank[0]: High Card: Highest value card.
    int highCard = 0;
    for (int i=value.size()-1; i>=0; i--) {
	if (value[i] != 0) {
	    highCard = i;
	    break;
	}
    }
    rank[0] = highCard;

    // rank[1]: One Pair: Two cards of the same value.
    int pairCount = 0;
    int pairResult = 0;
    for (int i=value.size()-1; i>=0; i--) {
	if (value[i] == 2) {
	    pairCount++;
	    pairResult = pairResult*100 + i;
	}
    }
    if (pairCount == 1) {
	rank[1] = pairResult;
    }

    // rank[2]: Two Pairs: Two different pairs.
    if (pairCount == 2) {
	rank[2] = pairResult;
    }
    
    // rank[3]: Three of a Kind: Three cards of the same value.
    for (int i=0; i<value.size(); i++) {
	if (value[i] == 3) {
	    rank[3] = i;
	    break;
	}
    }

    // rank[4]: Straight: All cards are consecutive values.
    int valueStart = 0;
    while ((valueStart < 15) && (value[valueStart] != 1)) {
	valueStart++;
    }
    if ((valueStart <= 10) && (value[valueStart+1] == 1) &&
	(value[valueStart+2] == 1) && (value[valueStart+3] == 1) &&
	(value[valueStart+4] == 1)) {
	rank[4] = valueStart;
    }

    // rank[5]: Flush: All cards of the same suit.
    bool isFlush = true;
    for (int i=1; i<n; i++) {
	if (v[i][1] != v[i-1][1]) {
	    isFlush = false;
	    break;
	}
    }
    if (isFlush == true) {
	rank[5] = 1;
    } else {
	rank[5] = 0;
    }

    // rank[6]: Full House: Three of a kind and a pair.
    // do NOT need more code, just test rank[1] and rank[3].
    if ((rank[1] > 0) && (rank[3] > 0)) {
     	rank[6] = 1;
    }

    // rank[7]: Four of a Kind: Four cards of the same value.
    for (int i=0; i<value.size(); i++) {
	if (value[i] == 4) {
	    rank[7] = i;
	    break;
	}
    }

    // rank[8]: Straight Flush: All cards are consecutive values of same suit.
    // do NOT need more code, just test rank[4] and rank[5].
    if ((rank[4] > 0) && (rank[5] > 0)) {
	rank[8] = 1;
    }

    // rank[9]: Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.
    // do NOT need more code, just test rank[4] and rank[5].
    if ((rank[4] == 10) && (rank[5] == 1)) {
	rank[9] = 1;
    }

    return rank;
}

int cmpRank(const vector<int>& rank1, const vector<int>& rank2)
{
    int n = rank1.size();

    for (int i=n-1; i>=0; i--) {
	if (rank1[i] > rank2[i]) {
	    return 1;
	} else if (rank1[i] < rank2[i]) {
	    return 2;
	}
    }
    return 0;
}

int whoWin(const vector<string>& v)
{
    vector<string> p1(v.begin(), v.begin()+5);
    vector<string> p2(v.begin()+5, v.end());

    vector<int> rank1 = rankPoker(p1);
    vector<int> rank2 = rankPoker(p2);

    int result = cmpRank(rank1, rank2);

    return result;
}

int main()
{
    vector< vector<string> > v;
    vector<string> vs(10);

    string s;
    while (cin >> s) {
	for (int i=0; i<10; i++) {
	    vs[i] = s;
	    if (i != 9) {
		cin >> s;
	    }
	}
	v.push_back(vs);
    }

    // for (int i=0; i<v.size(); i++) {
    // 	for (int j=0; j<v[i].size(); j++) {
    // 	    cout << v[i][j] << " ";
    // 	}
    // 	cout << endl;
    // }

    int count = 0;
    for (int i=0; i<v.size(); i++) {
	if (whoWin(v[i]) == 1) {
	    count++;
	}
    }

    cout << count << endl;
}
