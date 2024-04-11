/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Egor Kulikov
 */




#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const double PI = atan(1) * 4;

template <typename T>
T minim(T& was, T cand) {
    return was = min(was, cand);
}

template <typename T>
T maxim(T& was, T cand) {
    return was = max(was, cand);
}

template <typename T, typename U>
void decreaseByOne(vector<pair<T, U> >& v) {
    for (auto& p : v) {
        p.first--;
        p.second--;
    }
}

void decreaseByOne() {}

template <typename T, class...Vs>
void decreaseByOne(vector<T>& arr, Vs&...vs) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        arr[i]--;
    }
    decreaseByOne(vs...);
}





template <typename D>
D dPower(D base, ll exponent) {
    if (exponent < 0) {
        return dPower(1 / base, -exponent);
    }
    if (exponent == 0) {
        return 1;
    }
    if ((exponent & 1) == 1) {
        return dPower(base, exponent - 1) * base;
    } else {
        D res = dPower(base, exponent >> 1);
        return res * res;
    }
}


inline bool isWhitespace(int c) {
    return isspace(c) || c == EOF;
}

class Input {
private:
    istream &in;
    bool exhausted = false;

    inline int get() {
        if (exhausted) {
            throw "Input exhausted";
        }
        int c = in.get();
        if (c == EOF) {
            exhausted = true;
        }
        return c;
    }

    template<typename T>
    T readInteger() {
        skipWhitespace();
        int c = get();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = get();
        }
        T res = 0;
        do {
            if (!isdigit(c)) {
                throw "Number format error";
            }
            res *= 10;
            res += c - '0';
            c = get();
        } while (!isWhitespace(c));
        return res * sgn;
    }

    void initArrays(int n) {}

    template <typename T, class...Vs>
    void initArrays(int n, vector<T>& arr, Vs&...vs) {
        arr.resize(n);
        initArrays(n, vs...);
    }

    void readImpl(int i) {}

    template <typename T, class...Vs>
    void readImpl(int i, vector<T>& arr, Vs&...vs) {
        arr[i] = readType<T>();
        readImpl(i, vs...);
    }

public:
    Input(istream &in) : in(in) {};

    inline void skipWhitespace() {
        int c;
        while (isWhitespace(c = in.peek()) && c != EOF) {
            in.get();
        }
        if (c == EOF) {
            exhausted = true;
        }
    }

    int readInt() {
        return readInteger<int>();
    }

    ll readLong() {
        return readInteger<long>();
    }

    string readString() {
        skipWhitespace();
        int c = get();
        if (c == EOF) {
            throw "Input exhausted";
        }
        vector<char> res;
        do {
            res.push_back(c);
        } while (!isWhitespace(c = get()));
        return string(all(res));
    }

    vector<int> readIntArray(int size) {
        return readArray<int>(size);
    }

    template<typename T>
    T readType() {
        throw "Operation not supported";
    }

    template<typename U, typename V>
    pair<U, V> readType() {
        U first = readType<U>();
        V second = readType<V>();
        return make_pair(first, second);
    }

    template<typename T>
    vector<T> readArray(int n) {
        vector<T> res;
        res.reserve(n);
        for (int i = 0; i < n; i++) {
            res.push_back(readType<T>());
        }
        return res;
    }



    template <class...Vs>
    void readArrays(int n, Vs&...vs) {
        initArrays(n, vs...);
        for (int i = 0; i < n; i++) {
            readImpl(i, vs...);
        }
    }

    template<typename U, typename V>
    vector<pair<U, V> > readArray(int n) {
        vector<pair<U, V> > res;
        res.reserve(n);
        for (int i = 0; i < n; i++) {
            res.push_back(readType<U, V>());
        }
        return res;
    }

    template<typename T>
    vector<vector<T> > readTable(int rows, int cols) {
        vector<vector<T> > result;
        result.reserve(rows);
        for (int i = 0; i < rows; ++i) {
            result.push_back(readArray<T>(cols));
        }
        return result;
    }

    string readLine() {
        skipWhitespace();
        int c = get();
        if (c == EOF) {
            throw "Input exhausted";
        }
        int length = 0;
        vector<char> res;
        do {
            res.push_back(c);
            if (!isWhitespace(c)) {
                length = res.size();
            }
            c = get();
        } while (c != '\n' && c != '\r' && c != EOF);
        return string(res.begin(), res.begin() + length);
    }

    double readDouble() {
        skipWhitespace();
        int c = get();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = get();
        }
        double res = 0;
        do {
            if (tolower(c) == 'e') {
                return sgn * res * dPower(10, readInt());
            }
            if (!isdigit(c)) {
                throw "Number format error";
            }
            res *= 10;
            res += c - '0';
            c = get();
        } while (!isWhitespace(c) && c != '.');
        if (c == '.') {
            double add = 0;
            int length = 0;
            c = get();
            do {
                if (tolower(c) == 'e') {
                    return sgn * (res + add * dPower(10, -length)) * dPower(10, readInt());
                }
                if (!isdigit(c)) {
                    throw "Number format error";
                }
                add *= 10;
                add += c - '0';
                length++;
                c = get();
            } while (!isWhitespace(c));
            res += add * dPower(10, -length);
        }
        return res * sgn;
    }

    char readChar() {
        skipWhitespace();
        int c = get();
        if (c == EOF) {
            throw "Input exhausted";
        }
        return c;
    }

    bool isExhausted() { return exhausted; }
};

template<>
double Input::readType() {
    return readDouble();
}

template<>
int Input::readType() {
    return readInt();
}

template<>
ll Input::readType() {
    return readLong();
}

template<>
char Input::readType() {
    return readChar();
}

template<>
string Input::readType() {
    return readString();
}





class Output {
private:
    ostream& out;

    template<typename T> void printSingle(const T& value) {
        out << value;
    }

    template<typename T> void printSingle(const vector<T>& array) {
        size_t n = array.size();
        for (int i = 0; i < n; ++i) {
            out << array[i];
            if (i + 1 != n) {
                out << ' ';
            }
        }
    }
    template<typename T, typename U> void printSingle(const pair<T, U>& value) {
        out << value.first << ' ' << value.second;
    }

public:
    Output(ostream& out) : out(out) {
        out << fixed << setprecision(12);
    }

    void print() {}

    template<typename T, typename...Targs>
    void print(const T& first, const Targs... args) {
        printSingle(first);
        if (sizeof...(args) != 0) {
            out << ' ';
            print(args...);
        }
    }

    template<typename...Targs>
    void printLine(const Targs... args) {
        print(args...);
        out << '\n';
    }

    void flush() {
        out.flush();
    }
};





class NumberIterator : iterator<forward_iterator_tag, int> {
public:
    int v;

    NumberIterator(int v) : v(v) {}

    operator int &() { return v; }

    int operator*() { return v; }
};

class Range : pii {
public:
    Range(int begin, int end) : pii(begin, max(begin, end)) {}

    Range(int n) : pii(0, max(0, n)) {}

    NumberIterator begin() {
        return first;
    }

    NumberIterator end() {
        return second;
    }
};





const int MOD7 = 1000000007;
const int MOD9 = 1000000009;
const int MODF = 998244353;

int mod = MOD7;

class ModuloInt {
public:
    ll n;
    ModuloInt() : n(0) {}
    ModuloInt(ll n) {
        n %= mod;
        if (n < 0) {
            n += mod;
        }
        this->n = n;
    }
    ModuloInt(const ModuloInt& n) = default;
    ModuloInt& operator +=(const ModuloInt& other);
    ModuloInt& operator -=(const ModuloInt& other);
    ModuloInt& operator *=(const ModuloInt& other);
    ModuloInt operator -();
    friend ostream&operator <<(ostream& out, const ModuloInt& val);
};

ModuloInt &ModuloInt::operator+=(const ModuloInt& other) {
    n += other.n;
    if (n >= mod) {
        n -= mod;
    }
    return *this;
}

ModuloInt &ModuloInt::operator-=(const ModuloInt& other) {
    n -= other.n;
    if (n < 0) {
        n += mod;
    }
    return *this;
}

ModuloInt &ModuloInt::operator*=(const ModuloInt& other) {
    n *= other.n;
    n %= mod;
    return *this;
}

ModuloInt operator +(const ModuloInt& a, const ModuloInt& b) {
    return ModuloInt(a) += b;
}

ModuloInt operator -(const ModuloInt& a, const ModuloInt& b) {
    return ModuloInt(a) -= b;
}

ModuloInt operator *(const ModuloInt& a, const ModuloInt& b) {
    return ModuloInt(a) *= b;
}

ostream& operator <<(ostream& out, const ModuloInt& val) {
    return out << val.n;
}

ModuloInt ModuloInt::operator-() {
    if (n == 0) {
        return 0;
    }
    return ModuloInt(mod - n);
}






template <typename T>
T gcd(T a, T b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        a = a % b;
        swap(a, b);
    }
    return a;
}

template <typename T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}

template <typename T>
T power(const T& a, ll b) {
    if (b == 0) {
        return 1;
    }
    if ((b & 1) == 0) {
        T res = power(a, b >> 1);
        return res * res;
    } else {
        return power(a, b - 1) * a;
    }
}

template <typename T>
vector<T> generateFactorial(int length) {
    vector<T> result(length);
    if (length > 0) {
        result[0] = 1;
    }
    for (int i = 1; i < length; i++) {
        result[i] = result[i - 1] * i;
    }
    return result;
}

template <typename T>
vector<T> generateReverse(int length) {
    vector<T> result(length);
    if (length > 1) {
        result[1] = 1;
    }
    for (int i = 2; i < length; i++) {
        result[i] = -(mod / i) * result[mod % i];
    }
    return result;
}

template <typename T>
vector<T> generatePowers(T base, int length) {
    vector<T> result(length);
    if (length > 0) {
        result[0] = 1;
    }
    for (int i = 1; i < length; i++) {
        result[i] = result[i - 1] * base;
    }
    return result;
}

template <typename T>
vector<T> generateReverseFactorial(int length) {
    auto result = generateReverse<T>(length);
    if (length > 0) {
        result[0] = 1;
    }
    for (int i = 1; i < length; i++) {
        result[i] *= result[i - 1];
    }
    return result;
}

template <typename T>
class Combinations {
private:
    vector<T> fact;
    vector<T> revFactorial;

public:
    Combinations(int length) {
        fact = generateFactorial<T>(length);
        revFactorial = generateReverseFactorial<T>(length);
    }

public:
    T c(int n, int k) {
        if (k < 0 || k > n) {
            return 0;
        }
        return fact[n] * revFactorial[k] * revFactorial[n - k];
    }

    T factorial(int n) {
        return fact[n];
    }

    T reverseFactorial(int n) {
        return revFactorial[n];
    }
};


//#pragma comment(linker, "/STACK:200000000")

class TaskC {
public:
	void solve(istream& inp, ostream& outp) {
        Input in(inp);
        Output out(outp);

        mod = MODF;
        int n = in.readInt();
        int q = in.readInt();
        auto pp = in.readIntArray(n);

        vector<ModuloInt> p;
        p.reserve(n);
        auto reverse = [](ModuloInt n) -> ModuloInt {
            return power(n, mod - 2);
        };
        ModuloInt rev = reverse(100);
        for (int i : Range(n)) {
            p.push_back(rev * pp[i]);
        }
        vector<ModuloInt> alpha(1);
        vector<ModuloInt> beta(1);
        vector<ModuloInt> gamma(1, 1);
        vector<ModuloInt> gammaRev(1, 1);
        for (int i : Range(0, n)) {
            gamma.push_back(gamma[i] * p[i]);
            gammaRev.push_back(reverse(gamma[i + 1]));
            beta.push_back(beta[i] + gamma[i] * (1 - p[i]));
            alpha.push_back(alpha[i] + gamma[i] * (1 - p[i]) * (i + 1));
        }
        auto value = [&](int from, int to) -> ModuloInt {
            return (alpha[to] - alpha[from] - from * (beta[to] - beta[from])) * gammaRev[to] + to - from;
        };
        ModuloInt answer = value(0, n);
        set<int> enabled;
        enabled.insert(0);
        enabled.insert(n);
        for (int i : Range(q)) {
            int u = in.readInt() - 1;
            if (enabled.count(u)) {
                auto at = enabled.find(u);
                at--;
                int left = *at;
                at++;
                at++;
                int right = *at;
                answer -= value(left, u);
                answer -= value(u, right);
                answer += value(left, right);
                enabled.erase(u);
            } else {
                auto at = enabled.lower_bound(u);
                int right = *at;
                at--;
                int left = *at;
                answer += value(left, u);
                answer += value(u, right);
                answer -= value(left, right);
                enabled.insert(u);
            }
            out.printLine(answer);
        }
	}
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	TaskC solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}