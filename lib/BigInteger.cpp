const int MAX_LENGTH = 1024;

class BigInteger
{
public:
    BigInteger();
    BigInteger(int x, int _base = 10);
    BigInteger(const string &s, int _base = 10);
    BigInteger(const BigInteger & object);

    BigInteger& operator=(const BigInteger &object);
    BigInteger& operator=(int x);
    BigInteger& operator=(const string &s);

    bool operator==(const BigInteger &object) const;
    bool operator<(const BigInteger &object) const;
    bool operator>(const BigInteger &object) const;

    int digit[MAX_LENGTH];
    int base;
    int highBit;
};

BigInteger :: BigInteger(): base(0), highBit(0) {
    memset(digit, 0, sizeof(digit));
}

BigInteger :: BigInteger(int x, int _base): base(_base), highBit(0) {
    memset(digit, 0, sizeof(digit));
    while (x > 0) {
        digit[highBit++] = x % base;
        x /= base;
    }
}

BigInteger :: BigInteger(const string &s, int _base): base(_base), highBit(0) {
    memset(digit, 0, sizeof(digit));
    int idx = 0, len = (int)(s).size();
    while (idx < len && s[idx] =='0')
        ++idx;
    for (int i = len - 1; i >= idx; --i)
        digit[highBit++] = s[i] - '0';
}

BigInteger :: BigInteger(const BigInteger &object)
{
    memcpy(digit, object.digit, sizeof(digit));
    base = object.base;
    highBit = object.highBit;
}

BigInteger& BigInteger :: operator=(const BigInteger &object)
{
    memcpy(digit, object.digit, sizeof(digit));
    base = object.base;
    highBit = object.highBit;
    return *this;
}

BigInteger& BigInteger :: operator=(int x)
{
    memset(digit, 0, sizeof(digit));
    base = 10;
    while (x > 0) {
        digit[highBit++] = x % base;
        x /= base;
    }
    return *this;
}

BigInteger& BigInteger :: operator=(const string &s)
{
    memset(digit, 0, sizeof(digit));
    base = 10;
    int idx = 0, len = (int)(s).size();
    while (idx < len && s[idx] =='0')
        ++idx;
    for (int i = len - 1; i >= idx; --i)
        digit[highBit++] = s[i] - '0';
    return *this;
}

bool BigInteger :: operator==(const BigInteger &object) const
{
    if (highBit != object.highBit)
        return false;
    return memcmp(digit, object.digit, sizeof(digit)) == 0;
}

bool BigInteger :: operator<(const BigInteger &object) const
{
    if (highBit != object.highBit)
        return highBit < object.highBit;
    for (int i = highBit - 1; i >= 0; --i)
        if (digit[i] != object.digit[i])
            return digit[i] < object.digit[i];
    return false;
}

bool BigInteger :: operator>(const BigInteger &object) const
{
    if (highBit != object.highBit)
        return highBit > object.highBit;
    for (int i = highBit - 1; i >= 0; --i)
        if (digit[i] != object.digit[i])
            return digit[i] > object.digit[i];
    return false;
}

BigInteger operator+(const BigInteger &object1, const BigInteger &object2)
{
    BigInteger res;
    res.base = object1.base;
    res.highBit = max(object1.highBit, object2.highBit);
    int carry = 0;
    for (int i = 0; i < res.highBit; ++i) {
        int aux = object1.digit[i] + object2.digit[i] + carry;
        res.digit[i] = aux % res.base;
        carry = aux / res.base;
    }
    if (carry > 0)
        res.digit[res.highBit++] = carry;
    return res;
}

ostream& operator <<(ostream& os, const BigInteger &object)
{
    if (!object.highBit) {
        os << 0;
    } else {
        for (int i = object.highBit - 1; i >= 0; --i)
            os << object.digit[i];
    }
    return os;
}

istream& operator >>(istream& is, BigInteger &object)
{
    string s;
    is >> s;
    object = BigInteger(s);
    return is;
}
