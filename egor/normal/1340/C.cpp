/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Egor Kulikov
 */



#include <cstdio>
#include <cctype>
#include <string>
#include <cstring>


#include <vector>
#include <functional>

using namespace std;

#define all(v) (v).begin(), (v).end()

using ll = long long;
using ull = unsigned long long;
using li = __int128;
using uli = unsigned __int128;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

#ifdef LOCAL

void signalHandler(int) {
    throw "Abort detected";
}

#endif

void doReplace() {
}

template <typename T, typename U, typename...Vs>
void doReplace(T& t, const U& u, Vs&& ...vs) {
    t = u;
    doReplace(vs...);
}

template <typename T, typename...Us>
T minim(T& was, const T& cand, Us&& ...us) {
    if (was > cand) {
        was = cand;
        doReplace(us...);
    }
    return was;
}

template <typename T, typename...Us>
T maxim(T& was, const T& cand, Us&& ...us) {
    if (was < cand) {
        was = cand;
        doReplace(us...);
    }
    return was;
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


#include <algorithm>


class NumberIterator : iterator<forward_iterator_tag, int> {
public:
    int v;

    NumberIterator(int v) : v(v) {}

    operator int&() { return v; }

    int operator*() { return v; }
};

class range : pii {
public:
    range(int begin, int end) : pii(begin, max(begin, end)) {}

    range(int n) : pii(0, max(0, n)) {}

    NumberIterator begin() {
        return first;
    }

    NumberIterator end() {
        return second;
    }
};


template <typename T>
class arr {
    T* b;
    int n;

    void allocate(int sz) {
#ifdef LOCAL
        if (sz < 0) {
            throw "bad alloc";
        }
#endif
        n = sz;
        if (sz > 0) {
            b = (T*) (::operator new(sz * sizeof(T)));
        } else {
            b = nullptr;
        }
    }

public:
    arr(int n = 0) {
        allocate(n);
#ifdef LOCAL
        view();
#endif
    }

    arr(int n, const T& init) {
        allocate(n);
        for (int i : range(n)) {
            ::new((void*) (b + i)) T(init);
        }
#ifdef LOCAL
        view();
#endif
    }

    arr(initializer_list<T> l) : arr(l.size()) {
        if (n > 0) {
            memcpy(b, l.begin(), n * sizeof(T));
        }
    }

    arr(T* b, int n) : arr(b, b + n) {}

    arr(T* b, T* e) : b(b), n(e - b) {}

    int size() const {
        return n;
    }

    T* begin() {
        return b;
    }

    const T* begin() const {
        return b;
    }

    T* end() {
        return b + n;
    }

    const T* end() const {
        return b + n;
    }

    arr<T> clone() const {
        arr<T> res(n);
        copy(b, b + n, res.begin());
        return res;
    }

    T& operator[](int at) {
#ifdef LOCAL
        if (at < 0 || at >= n) {
            throw "Out of bounds";
        }
#endif
        return b[at];
    }

    const T& operator[](int at) const {
#ifdef LOCAL
        if (at < 0 || at >= n) {
            throw "Out of bounds";
        }
#endif
        return b[at];
    }

    bool operator==(const arr& other) const {
        if (n != other.n) {
            return false;
        }
        for (int i : range(n)) {
            if (b[i] != other.b[i]) {
                return false;
            }
        }
        return true;
    }

    vector<T> view() {
        return vector<T>(b, b + min(n, 50));
    }
};

typedef arr<int> arri;

void decreaseByOne() {}

template <typename T, class...Vs>
void decreaseByOne(arr<T>& array, Vs& ...vs) {
    int n = array.size();
    for (int i = 0; i < n; ++i) {
        array[i]--;
    }
    decreaseByOne(vs...);
}

template <typename T, typename U>
void decreaseByOne(arr<pair<T, U>>& v) {
    for (auto& p : v) {
        p.first--;
        p.second--;
    }
}


template <typename T>
class arr2d {
    T* b;
    int d1;
    int d2;
    int sz;

    void allocate(int n) {
#ifdef LOCAL
        if (n < 0) {
            throw "bad alloc";
        }
#endif
        if (n > 0) {
            b = (T*) (::operator new(n * sizeof(T)));
        } else {
            b = nullptr;
        }
    }

public:
    arr2d(int d1 = 0, int d2 = 0) : d1(d1), d2(d2), sz(d1 * d2) {
#ifdef LOCAL
        if (d1 < 0 || d2 < 0) {
            throw "bad alloc";
        }
#endif
        allocate(sz);
#ifdef LOCAL
        view();
#endif
    }

    arr2d(int d1, int d2, const T& init) : d1(d1), d2(d2), sz(d1 * d2) {
#ifdef LOCAL
        if (d1 < 0 || d2 < 0) {
            throw "bad alloc";
        }
#endif
        allocate(sz);
        for (int i : range(sz)) {
            ::new((void*) (b + i)) T(init);
        }
#ifdef LOCAL
        view();
#endif
    }

    arr2d(T* b, int d1, int d2) : b(b), d1(d1), d2(d2), sz(d1 * d2) {}

    int size() const {
        return sz;
    }

    int dim1() const {
        return d1;
    }

    int dim2() const {
        return d2;
    }

    T* begin() {
        return b;
    }

    T* end() {
        return b + sz;
    }

    T& operator()(int i1, int i2) {
#ifdef LOCAL
        if (i1 < 0 || i1 >= d1 || i2 < 0 || i2 >= d2) {
            throw "Out of bounds";
        }
#endif
        return b[i1 * d2 + i2];
    }

    const T& operator()(int i1, int i2) const {
#ifdef LOCAL
        if (i1 < 0 || i1 >= d1 || i2 < 0 || i2 >= d2) {
            throw "Out of bounds";
        }
#endif
        return b[i1 * d2 + i2];
    }

    arr<T> operator[](int at) {
#ifdef LOCAL
        if (at < 0 || at >= d1) {
            throw "Out of bounds";
        }
#endif
        return arr<T>(b + at * d2, d2);
    }

    vector<vector<T>> view() {
        vector<vector<T>> res(min(d1, 50));
        for (int i = 0; i < res.size(); ++i) {
            res[i] = (*this)[i].view();
        }
        return res;
    }

    arr2d<T> clone() {
        arr2d<T> res(d1, d2);
        copy(b, b + sz, res.b);
        return res;
    }
};


inline bool isWhitespace(int c) {
    return isspace(c) || c == EOF;
}

class Input {
private:
    bool exhausted = false;
    int bufSize = 4096;
    char* buf = new char[bufSize];
    int bufRead = 0;
    int bufAt = 0;

    inline int get() {
        if (exhausted) {
#ifdef LOCAL
            throw "Input exhausted";
#endif
            return EOF;
        }
        if (bufRead == bufAt) {
            bufRead = fread(buf, sizeof(char), bufSize, stdin);
            bufAt = 0;
        }
        if (bufRead == bufAt) {
            exhausted = true;
            return EOF;
        }
        return buf[bufAt++];
    }

    template <typename T>
    inline T readInteger() {
        int c = skipWhitespace();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = get();
        }
        T res = 0;
        do {
            if (!isdigit(c)) {
#ifdef LOCAL
                throw "Number format error";
#endif
                return sgn * res;
            }
            res *= 10;
            res += c - '0';
            c = get();
        } while (!isWhitespace(c));
        return res * sgn;
    }

    void initArrays(int) {}

    template <typename T, class...Vs>
    void initArrays(int n, arr<T>& array, Vs& ...vs) {
        array = arr<T>(n, T());
        initArrays(n, vs...);
    }

    template <typename T, class...Vs>
    void initArrays(int n, vector<T>&, Vs& ...vs) {
        initArrays(n, vs...);
    }

    void readImpl(int) {}

    template <typename T, class...Vs>
    void readImpl(int i, arr<T>& arr, Vs& ...vs) {
        arr[i] = readType<T>();
        readImpl(i, vs...);
    }

    template <typename T, class...Vs>
    void readImpl(int i, vector<T>& arr, Vs& ...vs) {
        arr.push_back(readType<T>());
        readImpl(i, vs...);
    }

public:
    inline int skipWhitespace() {
        int c;
        while (isWhitespace(c = get()) && c != EOF);
        if (c == EOF) {
            exhausted = true;
        }
        return c;
    }

    inline int readInt() {
        return readInteger<int>();
    }

    ll readLong() {
        return readInteger<ll>();
    }

    string readString() {
        int c = skipWhitespace();
        if (c == EOF) {
#ifdef LOCAL
            throw "Input exhausted";
#endif
            return "";
        }
        string res;
        do {
            res.push_back(c);
        } while (!isWhitespace(c = get()));
        return res;
    }

    arri readIntArray(int size) {
        return readArray<int>(size);
    }

    arr<ll> readLongArray(int size) {
        return readArray<ll>(size);
    }

    arr<double> readDoubleArray(int size) {
        return readArray<double>(size);
    }

    arr<string> readStringArray(int size) {
        return readArray<string>(size);
    }

    arr<char> readCharArray(int size) {
        return readArray<char>(size);
    }

    template <typename T>
    T readType() {
        throw "Operation not supported";
    }

    template <typename U, typename V>
    pair<U, V> readType() {
        U first = readType<U>();
        V second = readType<V>();
        return make_pair(first, second);
    }

    template <typename T>
    arr<T> readArray(int n) {
        arr<T> res(n, T());
        for (int i = 0; i < n; i++) {
            res[i] = readType<T>();
        }
        return res;
    }


    template <class...Vs>
    void readArrays(int n, Vs& ...vs) {
        initArrays(n, vs...);
        for (int i = 0; i < n; i++) {
            readImpl(i, vs...);
        }
    }

    template <typename U, typename V>
    arr<pair<U, V>> readArray(int n) {
        arr<pair<U, V>> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = readType<U, V>();
        }
        return res;
    }

    template <typename T>
    arr2d<T> readTable(int rows, int cols) {
        arr2d<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result(i, j) = readType<T>();
            }
        }
        return result;
    }

    arr2d<int> readIntTable(int rows, int cols) {
        return readTable<int>(rows, cols);
    }

    arr2d<char> readCharTable(int rows, int cols) {
        return readTable<char>(rows, cols);
    }

    string readLine() {
        int c = get();
        if (c == EOF) {
#ifdef LOCAL
            throw "Input exhausted";
#endif
            return "";
        }
        string res;
        do {
            res.push_back(c);
            c = get();
        } while (c != '\n' && c != '\r' && c != EOF);
        return res;
    }

    double readDouble() {
        int c = skipWhitespace();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = get();
        }
        double res = 0;
        do {
            if (tolower(c) == 'e') {
                return sgn * res * dPower(double(10), readInt());
            }
            if (!isdigit(c)) {
#ifdef LOCAL
                throw "Number format error";
#endif
                return sgn * res;
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
                    return sgn * (res + add * dPower(double(10), -length)) * dPower(double(10), readInt());
                }
                if (!isdigit(c)) {
#ifdef LOCAL
                    throw "Number format error";
#endif
                    res += add * dPower(10, -length);
                    return res * sgn;
                }
                add *= 10;
                add += c - '0';
                length++;
                c = get();
            } while (!isWhitespace(c));
            res += add * dPower(double(10), -length);
        }
        return res * sgn;
    }

    char readChar() {
        int c = skipWhitespace();
        if (c == EOF) {
#ifdef LOCAL
            throw "Input exhausted";
#endif
            return 0;
        }
        return c;
    }

    bool isExhausted() { return exhausted; }

    void setBufSize(int newBufSize) {
        if (newBufSize > bufSize) {
            char* newBuf = new char[newBufSize];
            memcpy(newBuf, buf, bufSize);
            buf = newBuf;
        }
        bufSize = newBufSize;
    }
};

template <>
double Input::readType() {
    return readDouble();
}

template <>
int Input::readType() {
    return readInt();
}

template <>
ll Input::readType() {
    return readLong();
}

template <>
char Input::readType() {
    return readChar();
}

template <>
string Input::readType() {
    return readString();
}

Input in;


#include <iostream>
#include <iomanip>


class Output {
private:
    ostream& out = cout;

    template <typename T>
    void printSingle(const T& value) {
        out << value;
    }

    template <typename T>
    void printSingle(const vector<T>& array) {
        size_t n = array.size();
        for (int i = 0; i < n; ++i) {
            out << array[i];
            if (i + 1 != n) {
                out << ' ';
            }
        }
    }

    template <typename T>
    void printSingle(const arr<T>& array) {
        size_t n = array.size();
        for (int i = 0; i < n; ++i) {
            out << array[i];
            if (i + 1 != n) {
                out << ' ';
            }
        }
    }

    template <typename T>
    void printSingle(const arr2d<T>& array) {
        size_t n = array.dim1();
        size_t m = array.dim2();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                out << array(i, j);
                if (j + 1 != m) {
                    out << ' ';
                }
            }
            if (i + 1 != n) {
                out << '\n';
            }
        }
    }

    template <typename T, typename U>
    void printSingle(const pair<T, U>& value) {
        out << value.first << ' ' << value.second;
    }

public:
    Output() {//ostream& out) : out(out) {
        out << fixed << setprecision(20);
    }

    void print() {}

    template <typename T, typename...Targs>
    void print(const T& first, const Targs... args) {
        printSingle(first);
        if (sizeof...(args) != 0) {
            out << ' ';
            print(args...);
        }
    }

    template <typename...Targs>
    void printLine(const Targs... args) {
        print(args...);
        out << '\n';
    }

    void flush() {
        out.flush();
    }

    void setPrecision(int digs) {
        out << fixed << setprecision(digs);
    }
};

Output out;


class IndexedHeap {
    arri heap;
    arri pos;
    int sz = 0;
    function<bool(int, int)> cmp;

    void swap(int i, int j) {
        std::swap(heap[i], heap[j]);
        std::swap(pos[heap[i]], pos[heap[j]]);
    }

public:
    IndexedHeap(int capacity = 0, const function<bool(int, int)> cmp = less<>()) : heap(arri(capacity)),
                                                                                   pos(arri(capacity, -1)), cmp(cmp) {}

    int* begin() {
        return heap.begin();
    }

    int* end() {
        return heap.begin() + sz;
    }

    const int* begin() const {
        return heap.begin();
    }

    const int* end() const {
        return heap.begin() + sz;
    }

    int size() const {
        return sz;
    }

    bool empty() const {
        return sz == 0;
    }

    void siftUp(int index) {
#ifdef LOCAL
        if (index < 0 || index >= sz) {
            throw "Out of bounds";
        }
#endif
        int val = heap[index];
        while (index) {
            int parent = (index - 1) >> 1;
            int parVal = heap[parent];
            if (!cmp(val, parVal)) {
                heap[index] = val;
                pos[val] = index;
                return;
            }
            heap[index] = parVal;
            pos[parVal] = index;
            index = parent;
        }
        heap[0] = val;
        pos[val] = 0;
    }

    void siftDown(int index) {
#ifdef LOCAL
        if (index < 0 || index >= sz) {
            throw "Out of bounds";
        }
#endif
        while (true) {
            int child = (index << 1) + 1;
            if (child >= sz) {
                return;
            }
            if (child + 1 < sz && cmp(heap[child + 1], heap[child])) {
                child++;
            }
            if (!cmp(heap[child], heap[index])) {
                return;
            }
            swap(index, child);
            index = child;
        }
    }

    int operator[](int index) const {
#ifdef LOCAL
        if (index < 0 || index >= sz) {
            throw "Out of bounds";
        }
#endif
        return heap[index];
    }

    void push(int element) {
#ifdef LOCAL
        if (element < 0 || element >= pos.size() || pos[element] != -1) {
            throw "Out of bounds";
        }
#endif
        heap[sz] = element;
        pos[element] = sz;
        siftUp(sz++);
    }

    int at(int element) const {
#ifdef LOCAL
        if (element < 0 || element >= pos.size()) {
            throw "Out of bounds";
        }
#endif
        return pos[element];
    }

    int top() const {
#ifdef LOCAL
        if (sz == 0) {
            throw "Out of bounds";
        }
#endif
        return heap[0];
    }

    int pop() {
#ifdef LOCAL
        if (sz == 0) {
            throw "Out of bounds";
        }
#endif
        int res = heap[0];
        pos[res] = -1;
        if (sz == 1) {
            sz = 0;
            return res;
        }
        heap[0] = heap[--sz];
        pos[heap[0]] = 0;
        siftDown(0);
        return res;
    }

    bool erase(int element) {
#ifdef LOCAL
        if (element < 0 || element >= pos.size()) {
            throw "Out of bounds";
        }
#endif
        int index = pos[element];
        if (index == -1) {
            return false;
        }
        pos[element] = -1;
        if (index == sz - 1) {
            sz--;
            return true;
        }
        heap[index] = heap[--sz];
        pos[heap[index]] = index;
        siftDown(index);
        siftUp(index);
        return true;
    }

    void clear() {
        sz = 0;
        fill(all(pos), -1);
    }
};


#include <queue>


template <typename T>
class que : public queue<T> {
    using parent = queue<T>;
public:
    que() : parent() {}

    que(const que<T>& q) : parent(q) {}

    que(que<T>&& q) noexcept: parent(move(q)) {}

    T pop() {
#ifdef LOCAL
        if (parent::empty()) {
            throw "Pop on empty queue";
        }
#endif
        T res = parent::front();
        parent::pop();
        return res;
    }

    que<T>& operator=(que<T>&& __x) noexcept {
        parent::operator=(__x);
        return *this;
    }

    que<T>& operator=(const que<T>& __x) {
        parent::operator=(__x);
        return *this;
    }
};

using qi = que<int>;


class TaskC {
public:
    void solve() {
        int n = in.readInt();
        int m = in.readInt();
        auto d = in.readIntArray(m);
        int g = in.readInt();
        int r = in.readInt();

        sort(all(d));
        arr2d<int> at(m, g + 1, numeric_limits<int>::max());
        at(0, 0) = 0;
        que<int> heap;
        que<int> next;
        heap.push(0);
        auto tryAddCur = [&](int pos, int cat, int val) {
            if (at(pos, cat) > val) {
                at(pos, cat) = val;
                heap.push(pos * (g + 1) + cat);
            }
        };
        auto tryAddNext = [&](int pos, int cat, int val) {
            if (at(pos, cat) > val) {
                at(pos, cat) = val;
                next.push(pos * (g + 1) + cat);
            }
        };
        int answer = numeric_limits<int>::max();
        while (!heap.empty() || !next.empty()) {
            if (heap.empty()) {
                if (answer != numeric_limits<int>::max()) {
                    break;
                }
                heap.swap(next);
            }
            int top = heap.pop();
            int pos = top / (g + 1);
            int cat = top % (g + 1);
            if (pos == m - 1) {
                minim(answer, at(pos, cat));
                continue;
            }
            if (cat == g) {
                tryAddNext(pos, 0, at(pos, cat) + r);
            } else {
                if (cat + d[pos + 1] - d[pos] <= g) {
                    tryAddCur(pos + 1, cat + d[pos + 1] - d[pos], at(pos, cat) + d[pos + 1] - d[pos]);
                }
                if (pos && cat + d[pos] - d[pos - 1] <= g) {
                    tryAddCur(pos - 1, cat + d[pos] - d[pos - 1], at(pos, cat) + d[pos] - d[pos - 1]);
                }
            }
        }
        out.printLine(answer == numeric_limits<int>::max() ? -1 : answer);
    }
};


int main() {
#ifdef LOCAL
    signal(SIGABRT, &signalHandler);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    TaskC solver;


    solver.solve();
    fflush(stdout);
    return 0;
}