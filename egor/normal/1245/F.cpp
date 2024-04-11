/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Egor Kulikov
 */

#include <iostream>
#include <fstream>

#include <bits/stdc++.h>
//
// Created by kulikov on 10/17/2019.
//

#ifndef JHELPER_EXAMPLE_PROJECT_INPUT_H
#define JHELPER_EXAMPLE_PROJECT_INPUT_H

//
// Created by egor on 30.10.2019.
//

#ifndef JHELPER_EXAMPLE_PROJECT_GENERAL_H
#define JHELPER_EXAMPLE_PROJECT_GENERAL_H



using namespace std;

typedef long long longint;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int MAX_INT = 2147483647;

const double PI = atan(1) * 4;

const int DX_KNIGHT[] = {2, 1, -1, -2, -2, -1, 1, 2};
const int DY_KNIGHT[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isValidCell(int x, int y, int rows, int cols) {
    return x >= 0 && y >= 0 && x < rows && y < cols;
}

void decreaseByOne() {
}

template <typename T, class...Vargs>
void decreaseByOne(vector<T>& arr, Vargs...arrs) {
    for (int& i : arr) {
        i--;
    }
    decreaseByOne(arrs...);
}

#endif //JHELPER_EXAMPLE_PROJECT_GENERAL_H


class Input {
public:
    enum ErrorType {
        OK,
        END_OF_FILE,
        UNEXPECTED_SYMBOL,
        INVALID_CALL
    };

private:
    istream& in;
    bool exhausted = false;
    ErrorType error = OK;
    int get();
    template<typename T> T readInteger();
    int skipWhitespace();

public:
    Input(istream& in);
    int readInt();
    longint readLong();
    string readString();
    vector<int> readIntArray(int size);
    template<typename T> T readType();
    template<typename T> vector<T> readArray(int size);
    template<typename T1, typename T2> tuple<vector<T1>, vector<T2> > readArrays(int size);
    template<typename T1, typename T2, typename T3> tuple<vector<T1>, vector<T2>, vector<T3> > readArrays(int size);
    template<typename T1, typename T2, typename T3, typename T4>
        tuple<vector<T1>, vector<T2>, vector<T3>, vector<T4> > readArrays(int size);
    template<typename T1, typename T2, typename T3, typename T4, typename T5>
        tuple<vector<T1>, vector<T2>, vector<T3>, vector<T4>, vector<T5> > readArrays(int size);
    template<typename T> vector<vector<T> > readTable(int rows, int cols);
};

inline bool isWhitespace(int c) {
    return isspace(c) || c == EOF;
}

int Input::skipWhitespace() {
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

Input::Input(std::istream &in) : in(in) {
}

inline int Input::get() {
    int result = in.get();
    if (result == EOF) {
        exhausted = true;
    }
    return result;
}

template<typename T>
T Input::readType() {
    error = INVALID_CALL;
    return nullptr;
}

template<typename T>
T Input::readInteger() {
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

template<>
int Input::readType() {
    return readInteger<int>();
}

template<>
longint Input::readType() {
    return readInteger<longint>();
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

inline longint Input::readLong() {
    return readType<longint>();
}

template<typename T>
vector<T> Input::readArray(int size) {
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

vector<int> Input::readIntArray(int size) {
    return readArray<int>(size);
}

template<typename T1, typename T2>
tuple<vector<T1>, vector<T2> > Input::readArrays(int size) {
    vector<T1> v1;
    vector<T2> v2;
    v1.reserve(size);
    v2.reserve(size);
    for (int i = 0; i < size; ++i) {
        v1.push_back(readType<T1>());
        v2.push_back(readType<T2>());
    }
    return make_tuple(v1, v2);
}

string Input::readString() {
    return readType<string>();
}

template<typename T>
vector<vector<T>> Input::readTable(int rows, int cols) {
    vector<vector<T> > result;
    result.reserve(rows);
    for (int i = 0; i < rows; ++i) {
        result.push_back(readArray<T>(cols));
    }
    return result;
}

template<typename T1, typename T2, typename T3>
tuple<vector<T1>, vector<T2>, vector<T3> > Input::readArrays(int size) {
    vector<T1> v1;
    vector<T2> v2;
    vector<T3> v3;
    v1.reserve(size);
    v2.reserve(size);
    v3.reserve(size);
    for (int i = 0; i < size; ++i) {
        v1.push_back(readType<T1>());
        v2.push_back(readType<T2>());
        v3.push_back(readType<T3>());
    }
    return make_tuple(v1, v2, v3);
}

template<typename T1, typename T2, typename T3, typename T4>
tuple<vector<T1>, vector<T2>, vector<T3>, vector<T4> > Input::readArrays(int size) {
    vector<T1> v1;
    vector<T2> v2;
    vector<T3> v3;
    vector<T4> v4;
    v1.reserve(size);
    v2.reserve(size);
    v3.reserve(size);
    v4.reserve(size);
    for (int i = 0; i < size; ++i) {
        v1.push_back(readType<T1>());
        v2.push_back(readType<T2>());
        v3.push_back(readType<T3>());
        v4.push_back(readType<T4>());
    }
    return make_tuple(v1, v2, v3, v4);
}

template<typename T1, typename T2, typename T3, typename T4, typename T5>
tuple<vector<T1>, vector<T2>, vector<T3>, vector<T4>, vector<T5> > Input::readArrays(int size) {
    vector<T1> v1;
    vector<T2> v2;
    vector<T3> v3;
    vector<T4> v4;
    vector<T5> v5;
    v1.reserve(size);
    v2.reserve(size);
    v3.reserve(size);
    v4.reserve(size);
    v5.reserve(size);
    for (int i = 0; i < size; ++i) {
        v1.push_back(readType<T1>());
        v2.push_back(readType<T2>());
        v3.push_back(readType<T3>());
        v4.push_back(readType<T4>());
        v5.push_back(readType<T5>());
    }
    return make_tuple(v1, v2, v3, v4, v5);
}

#endif //JHELPER_EXAMPLE_PROJECT_INPUT_H

//
// Created by egor on 31.10.2019.
//

#ifndef JHELPER_EXAMPLE_PROJECT_OUTPUT_H
#define JHELPER_EXAMPLE_PROJECT_OUTPUT_H



class Output {
private:
    ostream& out;
    template<typename T> void printSingle(T value);

public:
    Output(ostream& out);
    void print();
    template<typename T, typename...Targs>void print(T first, Targs... args);
    template<typename T> void print(const vector<T>& array);
    template<typename...Targs>void printLine(Targs... args);
    template<typename T> void printLine(const vector<T>& array);
    void flush();
};

Output::Output(ostream &out) : out(out) {
    out << setprecision(12);
}

void Output::print() {
}

template<typename T, typename... Targs>
void Output::print(T first, Targs... args) {
    printSingle(first);
    if (sizeof...(args) != 0) {
        out << ' ';
        print(args...);
    }
}

template<typename T>
void Output::printSingle(T value) {
    out << value;
}

template<typename T>
void Output::print(const vector<T> &array) {
    unsigned int size = array.size();
    for (int i = 0; i < size; ++i) {
        out << array[i];
        if (i + 1 != size) {
            out << ' ';
        }
    }
}

template<typename... Targs>
void Output::printLine(Targs... args) {
    print(args...);
    out << '\n';
}

template<typename T>
void Output::printLine(const vector<T> &array) {
    print(array);
    out << '\n';
}

void Output::flush() {
    out.flush();
}

#endif //JHELPER_EXAMPLE_PROJECT_OUTPUT_H

//
// Created by egor on 31.10.2019.
//

#ifndef JHELPER_EXAMPLE_PROJECT_ALGO_H
#define JHELPER_EXAMPLE_PROJECT_ALGO_H



template <typename T>
inline void sort(vector<T>& v) {
    sort(v.begin(), v.end());
}

template <typename T, class C>
inline void sort(vector<T>& v, C c) {
    sort(v.begin(), v.end(), c);
}

template <typename T>
inline void unique(vector<T>& v) {
    v.resize(unique(v.begin(), v.end()) - v.begin());
}

template <typename T>
inline T accumulate(const vector<T>& v) {
    return accumulate(v.begin(), v.end(), T(0));
}

vi createOrder(int n) {
    vi order(n);
    for (int i = 0; i < n; i++) {
        order[i] = i;
    }
    return order;
}

template <typename T>
inline void reverse(vector<T>& v) {
    reverse(v.begin(), v.end());
}

template <typename T>
inline T min_element(const vector<T>& v) {
    return *min_element(v.begin(), v.end());
}

template <typename T>
inline T max_element(const vector<T>& v) {
    return *max_element(v.begin(), v.end());
}

template <typename T>
inline vector<vector<T> > makeArray(int a, int b) {
    return vector<vector<T> >(a, vector<T>(b));
}

template <typename T>
inline vector<vector<vector<T> > > makeArray(int a, int b, int c) {
    return vector<vector<vector<T> > >(a, makeArray<T>(b, c));
}

template <typename T>
inline vector<vector<T> > makeArray(int a, int b, T init) {
    return vector<vector<T> >(a, vector<T>(b, init));
}

template <typename T>
inline vector<vector<vector<T> > > makeArray(int a, int b, int c, T init) {
    return vector<vector<vector<T> > >(a, makeArray<T>(b, c, init));
}

#endif //JHELPER_EXAMPLE_PROJECT_ALGO_H


using namespace std;

bool okFlags(int flags, int l,  int r, int at, int bit) {
    if ((flags & 1) == 0 && (l >> at & 1) == 1 && bit == 0) {
        return false;
    }
    if ((flags & 2) == 0 && (r >> at & 1) == 0 && bit == 1) {
        return false;
    }
    return true;
}

int updateFlags(int flags, int l,  int r, int at, int bit) {
    if ((r >> at & 1) == 1 && bit == 0) {
        flags |= 2;
    }
    if ((l >> at & 1) == 0 && bit == 1) {
        flags |= 1;
    }
    return flags;
}

longint go(int at, int aFlags, int bFlags, vector<vector<vector<longint> > >& res, int l, int r) {
    if (at == -1) {
        return 1;
    }
    if (res[at][aFlags][bFlags] != -1) {
        return res[at][aFlags][bFlags];
    }
    longint& answer = res[at][aFlags][bFlags];
    answer = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; i + j < 2; j++) {
            if (okFlags(aFlags, l, r, at, i) && okFlags(bFlags, l, r, at, j)) {
                answer += go(at - 1, updateFlags(aFlags, l, r, at, i), updateFlags(bFlags, l, r, at, j), res, l, r);
            }
        }
    }
    return answer;
}

class TaskF {
public:
	void solve(std::istream& inp, std::ostream& outp) {
        Input in(inp);
        Output out(outp);

        int l = in.readInt();
        int r = in.readInt();

        auto res = makeArray<longint>(30, 4, 4, -1);
        out.printLine(go(29, 0, 0, res, l, r));
	}
};


int main() {
    std::ios::sync_with_stdio(false);
	TaskF solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	int n;
in >> n;
for(int i = 0; i < n; ++i) {
	solver.solve(in, out);
}

	return 0;
}