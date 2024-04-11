/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Egor Kulikov
 */

#include <iostream>
#include <fstream>

#ifndef CPP_INPUT_H
#define CPP_INPUT_H

#ifndef CPP_GENERAL_H
#define CPP_GENERAL_H

#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const double PI = atan(1) * 4;

const int DX_KNIGHT[] = {2, 1, -1, -2, -2, -1, 1, 2};
const int DY_KNIGHT[] = {1, 2, 2, 1, -1, -2, -2, -1};
const int DX4[] = {1, 0, -1, 0};
const int DY4[] = {0, 1, 0, -1};
const int DX8[] = {1, 1, 1, 0, -1, -1, -1, 0};
const int DY8[] = {-1, 0, 1, 1, 1, 0, -1, -1};

template<typename T>
T minim(T &was, T cand) {
    return was = min(was, cand);
}

template<typename T>
T maxim(T &was, T cand) {
    return was = max(was, cand);
}

bool isValidCell(int r, int c, int n, int m) {
    return r >= 0 && c >= 0 && r < n && c < m;
}

template<typename T, typename U>
void decreaseByOne(vector<pair<T, U> > &v) {
    for (auto &p : v) {
        p.first--;
        p.second--;
    }
}

void decreaseByOne() {}

template<typename T, class...Vs>
void decreaseByOne(vector<T> &arr, Vs &...vs) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        arr[i]--;
    }
    decreaseByOne(vs...);
}

inline bool isSubset(int set, int subSet) {
    return (set & subSet) == subSet;
}

#endif


inline bool isWhitespace(int c) {
    return isspace(c) || c == EOF;
}

class Input {
public:
    enum ErrorType {
        OK,
        END_OF_FILE,
        UNEXPECTED_SYMBOL,
        INVALID_CALL
    };

private:
    istream &in;
    bool exhausted = false;
    ErrorType error = OK;

    inline int get() {
        int result = in.get();
        if (result == EOF) {
            exhausted = true;
        }
        return result;
    }

    template<typename T>
    T readInteger() {
        error = OK;
        int c = skipWhitespace();
        if (error != OK) {
            return 0;
        }
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = get();
        }
        T res = 0;
        do {
            if (!isdigit(c)) {
                error = UNEXPECTED_SYMBOL;
                return 0;
            }
            res *= 10;
            res += c - '0';
            c = get();
        } while (!isWhitespace(c));
        return res * sgn;
    }

    inline int skipWhitespace() {
        int c;
        do {
            c = get();
            if (exhausted) {
                error = END_OF_FILE;
                return c;
            }
        } while (isWhitespace(c));
        return c;
    }

    void initArrays(int n) {}

    template<typename T, class...Vs>
    void initArrays(int n, vector<T> &arr, Vs &...vs) {
        arr.resize(n);
        initArrays(n, vs...);
    }

    void readImpl(int i) {}

    template<typename T, class...Vs>
    void readImpl(int i, vector<T> &arr, Vs &...vs) {
        arr[i] = readType<T>();
        readImpl(i, vs...);
    }

public:
    Input(istream &in) : in(in) {};

    int readInt();

    ll readLong();

    string readString();

    vector<int> readIntArray(int size) {
        return readArray<int>(size);
    }

    template<typename T>
    T readType() {
        error = INVALID_CALL;
        return nullptr;
    }

    template<typename U, typename V>
    pair<U, V> readType() {
        U first = readType<U>();
        V second = readType<V>();
        return make_pair(first, second);
    }

    template<typename T>
    vector<T> readArray(int size) {
        vector<T> res;
        res.reserve(size);
        for (int i = 0; i < size; i++) {
            res.push_back(readType<T>());
            if (error != OK) {
                res.clear();
                return res;
            }
        }
        return res;
    }


    template<class...Vs>
    void readArrays(int n, Vs &...vs) {
        initArrays(n, vs...);
        for (int i = 0; i < n; i++) {
            readImpl(i, vs...);
        }
    }

    template<typename U, typename V>
    vector<pair<U, V> > readArray(int size) {
        vector<pair<U, V> > res;
        res.reserve(size);
        for (int i = 0; i < size; i++) {
            res.push_back(readType<U, V>());
            if (error != OK) {
                res.clear();
                return res;
            }
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
        error = OK;
        int c = skipWhitespace();
        if (error != OK) {
            return "";
        }
        int length = 0;
        vector<char> res;
        do {
            if (error != OK) {
                return "";
            }
            res.push_back(c);
            if (!isWhitespace(c)) {
                length = res.size();
            }
            c = get();
        } while (c != '\n' && c != '\r' && c != EOF);
        return string(res.begin(), res.begin() + length);
    }

    double readDouble();

    bool isExhausted() { return exhausted; }
};

template<>
double Input::readType() {
    error = OK;
    int c = skipWhitespace();
    if (error != OK) {
        return 0;
    }
    int sgn = 1;
    if (c == '-') {
        sgn = -1;
        c = get();
    }
    double res = 0;
    do {
        if (!isdigit(c)) {
            error = UNEXPECTED_SYMBOL;
            return 0;
        }
        res *= 10;
        res += c - '0';
        c = get();
    } while (!isWhitespace(c) && c != '.');
    if (c == '.') {
        vi digits;
        c = get();
        do {
            if (!isdigit(c)) {
                error = UNEXPECTED_SYMBOL;
                return 0;
            }
            digits.push_back(c - '0');
            c = get();
        } while (!isWhitespace(c));
        double add = 0;
        for (int i = int(digits.size()) - 1; i >= 0; i--) {
            add += digits[i];
            add /= 10;
        }
        res += add;
    }
    return res * sgn;
}

template<>
int Input::readType() {
    return readInteger<int>();
}

template<>
ll Input::readType() {
    return readInteger<ll>();
}

template<>
char Input::readType() {
    error = OK;
    int c = skipWhitespace();
    if (error != OK) {
        return 0;
    }
    return c;
}

template<>
string Input::readType() {
    error = OK;
    int c = skipWhitespace();
    if (error != OK) {
        return "";
    }
    vector<char> res;
    do {
        if (error != OK) {
            return "";
        }
        res.push_back(c);
    } while (!isWhitespace(c = get()));
    return string(res.begin(), res.end());
}

inline int Input::readInt() {
    return readType<int>();
}

inline ll Input::readLong() {
    return readType<ll>();
}

string Input::readString() {
    return readType<string>();
}

double Input::readDouble() {
    return readType<double>();
}

#endif

#ifndef CPP_OUTPUT_H
#define CPP_OUTPUT_H


class Output {
private:
    ostream &out;

    template<typename T>
    void printSingle(const T &value);

    template<typename T>
    void printSingle(const vector<T> &value);

    template<typename T, typename U>
    void printSingle(const pair<T, U> &value);

public:
    Output(ostream &out);

    void print();

    template<typename T, typename...Targs>
    void print(const T &first, const Targs... args);

    template<typename...Targs>
    void printLine(const Targs... args);

    void flush() {
        out.flush();
    }
};

Output::Output(ostream &out) : out(out) {
    out << setprecision(12);
}

void Output::print() {
}

template<typename T, typename... Targs>
void Output::print(const T &first, const Targs... args) {
    printSingle(first);
    if (sizeof...(args) != 0) {
        out << ' ';
        print(args...);
    }
}

template<typename T>
void Output::printSingle(const T &value) {
    out << value;
}

template<typename... Targs>
void Output::printLine(const Targs... args) {
    print(args...);
    out << '\n';
}

template<typename T>
void Output::printSingle(const vector<T> &array) {
    unsigned int size = array.size();
    for (int i = 0; i < size; ++i) {
        out << array[i];
        if (i + 1 != size) {
            out << ' ';
        }
    }
}

template<typename T, typename U>
void Output::printSingle(const pair<T, U> &value) {
    out << value.first << ' ' << value.second;
}

#endif


//#pragma comment(linker, "/STACK:200000000")

class TaskB {
public:
    void solve(istream &inp, ostream &outp) {
        Input in(inp);
        Output out(outp);

        int a = in.readInt();
        int b = in.readInt();

        if ((a + b) % 3 == 0 && a <= 2 * b && b <= 2 * a) {
            out.printLine("YES");
        } else {
            out.printLine("NO");
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    TaskB solver;
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    int n;
    in >> n;
    for (int i = 0; i < n; ++i) {
        solver.solve(in, out);
    }

    return 0;
}