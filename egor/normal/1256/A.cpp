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
const int DX4[] = {1, 0, -1, 0};
const int DY4[] = {0, 1, 0, -1};

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
    template<typename T, typename U> pair<T, U> readType();
    template<typename T> vector<T> readArray(int size);
    template<typename T1, typename T2> tuple<vector<T1>, vector<T2> > readArrays(int size);
    template<typename T1, typename T2, typename T3> tuple<vector<T1>, vector<T2>, vector<T3> > readArrays(int size);
    template<typename T1, typename T2, typename T3, typename T4>
        tuple<vector<T1>, vector<T2>, vector<T3>, vector<T4> > readArrays(int size);
    template<typename T1, typename T2, typename T3, typename T4, typename T5>
        tuple<vector<T1>, vector<T2>, vector<T3>, vector<T4>, vector<T5> > readArrays(int size);
    template<typename T> vector<vector<T> > readTable(int rows, int cols);

    string readLine();
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

string Input::readLine() {
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
    template<typename T> void printSingle(const T& value);
    template<typename T> void printSingle(const vector<T>& value);
    template<typename T, typename U> void printSingle(const pair<T, U>& value);

public:
    Output(ostream& out);
    void print();
    template<typename T, typename...Targs>void print(const T& first, const Targs... args);
    template<typename...Targs>void printLine(const Targs... args);
    void flush();
};

Output::Output(ostream &out) : out(out) {
    out << setprecision(12);
}

void Output::print() {
}

template<typename T, typename... Targs>
void Output::print(const T& first, const Targs... args) {
    printSingle(first);
    if (sizeof...(args) != 0) {
        out << ' ';
        print(args...);
    }
}

template<typename T>
void Output::printSingle(const T& value) {
    out << value;
}

template<typename... Targs>
void Output::printLine(const Targs... args) {
    print(args...);
    out << '\n';
}

void Output::flush() {
    out.flush();
}

template<typename T>
void Output::printSingle(const vector<T>& array) {
    unsigned int size = array.size();
    for (int i = 0; i < size; ++i) {
        out << array[i];
        if (i + 1 != size) {
            out << ' ';
        }
    }
}

template<typename T, typename U>
void Output::printSingle(const pair<T, U>& value) {
    out << value.first << ' ' << value.second;
}

#endif //JHELPER_EXAMPLE_PROJECT_OUTPUT_H


using namespace std;

class TaskA {
public:
	void solve(std::istream& inp, std::ostream& outp) {
        Input in(inp);
        Output out(outp);

        int a = in.readInt();
        int b = in.readInt();
        int n = in.readInt();
        int s = in.readInt();

        if (longint(a) * n + b >= s && s % n <= b) {
            out.printLine("YES");
        } else {
            out.printLine("NO");
        }
	}
};


int main() {
    std::ios::sync_with_stdio(false);
	TaskA solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	int n;
in >> n;
for(int i = 0; i < n; ++i) {
	solver.solve(in, out);
}

	return 0;
}