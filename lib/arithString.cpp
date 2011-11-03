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
