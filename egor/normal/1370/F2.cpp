/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Egor Kulikov
 */





#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using ll = long long;
using ull = unsigned long long;
using li = __int128;
using uli = unsigned __int128;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

void doReplace() {
}

template <typename T, typename U, typename...Vs>
void doReplace(T& t, const U& u, Vs&&...vs) {
    t = u;
    doReplace(vs...);
}

template <typename T, typename...Us>
T minim(T& was, const T& cand, Us&&...us) {
    if (was > cand) {
        was = cand;
        doReplace(us...);
    }
    return was;
}

template <typename T, typename...Us>
T maxim(T& was, const T& cand, Us&&...us) {
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








class NumberIterator : iterator<forward_iterator_tag, int> {
public:
    int v;

    NumberIterator(int v) : v(v) {}

    operator int &() { return v; }

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
            b = (T*)(::operator new(sz * sizeof(T)));
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
            ::new((void*)(b + i)) T(init);
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

    bool operator ==(const arr& other) const {
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
void decreaseByOne(arr<T>& array, Vs&...vs) {
    int n = array.size();
    for (int i : range(n)) {
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
            b = (T*)(::operator new(n * sizeof(T)));
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
            ::new((void*)(b + i)) T(init);
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

    T& operator[](const pii& p) {
        return operator()(p.first, p.second);
    }

    const T& operator[](const pii& p) const {
        return operator()(p.first, p.second);
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
        for (int i : range(res.size())) {
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

public:
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

    inline int peek() {
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
        return buf[bufAt];
    }

private:
    template<typename T>
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
    void initArrays(int n, arr<T>& array, Vs&...vs) {
        array = arr<T>(n, T());
        initArrays(n, vs...);
    }

    template <typename T, class...Vs>
    void initArrays(int n, vector<T>&, Vs&...vs) {
        initArrays(n, vs...);
    }

    void readImpl(int) {}

    template <typename T, class...Vs>
    void readImpl(int i, arr<T>& arr, Vs&...vs) {
        arr[i] = readType<T>();
        readImpl(i, vs...);
    }

    template <typename T, class...Vs>
    void readImpl(int i, vector<T>& arr, Vs&...vs) {
        arr.push_back(readType<T>());
        readImpl(i, vs...);
    }

public:
    inline int skipWhitespace() {
        int c;
        while (isWhitespace(c = get()) && c != EOF);
        return c;
    }

    inline int peekNext() {
        while (isWhitespace(peek()) && peek() != EOF) {
            get();
        }
        return peek();
    }

    inline int readInt() {
        return readInteger<int>();
    }

    inline ll readLong() {
        return readInteger<ll>();
    }

    inline unsigned readUnsigned() {
        return readInteger<unsigned>();
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
    arr<T> readArray(int n) {
        arr<T> res(n, T());
        for (int i : range(n)) {
            res[i] = readType<T>();
        }
        return res;
    }



    template <class...Vs>
    void readArrays(int n, Vs&...vs) {
        initArrays(n, vs...);
        for (int i : range(n)) {
            readImpl(i, vs...);
        }
    }

    template<typename U, typename V>
    arr<pair<U, V> > readArray(int n) {
        arr<pair<U, V> > res(n);
        for (int i : range(n)) {
            res[i] = readType<U, V>();
        }
        return res;
    }

    template<typename T>
    arr2d<T> readTable(int rows, int cols) {
        arr2d<T> result(rows, cols);
        for (int i : range(rows)) {
            for (int j : range(cols)) {
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

    inline double readDouble() {
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

    inline char readChar() {
        int c = skipWhitespace();
        if (c == EOF) {
#ifdef LOCAL
            throw "Input exhausted";
#endif
            return 0;
        }
        return c;
    }

    inline bool isExhausted() { return exhausted; }

    inline void setBufSize(int newBufSize) {
        if (newBufSize > bufSize) {
            char* newBuf = new char[newBufSize];
            memcpy(newBuf, buf, bufSize);
            buf = newBuf;
        }
        bufSize = newBufSize;
    }
};

template<>
inline double Input::readType() {
    return readDouble();
}

template<>
inline int Input::readType() {
    return readInt();
}

template<>
inline ll Input::readType() {
    return readLong();
}

template<>
inline unsigned Input::readType() {
    return readUnsigned();
}

template<>
inline char Input::readType() {
    return readChar();
}

template<>
inline string Input::readType() {
    return readString();
}

Input in;







class Output {
private:
    ostream* out;

    template<typename T>
    inline void printSingle(const T& value) {
        *out << value;
    }

    template<typename T>
    void printSingle(const vector<T>& array) {
        size_t n = array.size();
        for (int i : range(n)) {
            *out << array[i];
            if (i + 1 != n) {
                *out << ' ';
            }
        }
    }

    template<typename T>
    void printSingle(const arr<T>& array) {
        int n = array.size();
        for (int i : range(n)) {
            *out << array[i];
            if (i + 1 != n) {
                *out << ' ';
            }
        }
    }

    template<typename T>
    void printSingle(const arr2d<T>& array) {
        size_t n = array.dim1();
        size_t m = array.dim2();
        for (int i : range(n)) {
            for (int j : range(m)) {
                *out << array(i, j);
                if (j + 1 != m) {
                    *out << ' ';
                }
            }
            if (i + 1 != n) {
                *out << '\n';
            }
        }
    }

    template<typename T, typename U>
    inline void printSingle(const pair<T, U>& value) {
        *out << value.first << ' ' << value.second;
    }

public:
    bool autoflush;

    Output(ostream& out, bool autoflush) : out(&out), autoflush(autoflush) {
        setPrecision(20);
    }

    void setOut(ostream& nOut) {
        out = &nOut;
        setPrecision(20);
    }

    inline void print() {}

    template<typename T, typename...Targs>
    inline void print(const T& first, const Targs... args) {
        printSingle(first);
        if (sizeof...(args) != 0) {
            *out << ' ';
            print(args...);
        }
        if (autoflush) {
            flush();
        }
    }

    template<typename...Targs>
    inline void printLine(const Targs... args) {
        print(args...);
        *out << '\n';
        if (autoflush) {
            flush();
        }
    }

    inline void flush() {
        out->flush();
    }

    inline void setPrecision(int digs) {
        *out << fixed << setprecision(digs);
    }
};

Output out(cout, false);
Output err(cerr, true);






template <class Edge>
class Graph {
public:
    int vertexCount;
    int edgeCount = 0;
private:
    vector<vector<Edge>> edges;

public:
    Graph(int vertexCount) : vertexCount(vertexCount), edges(vertexCount, vector<Edge>()) {}

    template <typename...Ts>
    int addEdge(int from, int to, Ts... args) {
#ifdef LOCAL
        if (from < 0 || to < 0 || from >= vertexCount || to >= vertexCount) {
            throw "Out of bounds";
        }
#endif
        edges[from].emplace_back(to, edgeCount, args...);
        int directId = edges[from].size() - 1;
        if (Edge::reversable) {
            edges[to].push_back(edges[from][directId].reverseEdge(from));
            int revId = edges[to].size() - 1;
            edges[from][directId].setReverseId(revId);
            edges[to][revId].setReverseId(directId);
        }
        edgeCount++;
        return directId;
    }

    vector<Edge>& operator [](int at) {
        return edges[at];
    }

    void addVertices(int count) {
        vertexCount += count;
        edges.resize(vertexCount);
    }

    void clear() {
        edgeCount = 0;
        for (int i : range(vertexCount)) {
            edges[i].clear();
        }
    }
};









class BaseEdge {
public:
    const static bool reversable = false;
    int to;
    int id;

    BaseEdge(int to, int id) : to(to), id(id) {
    }

    BaseEdge reverseEdge(int) {
        throw "Unsupported operation exception";
    }

    void setReverseId(int) {
        throw "Unsupported operation exception";
    }
};




class BiEdge : public BaseEdge {
public:
    const static bool reversable = true;
    int rev;

    BiEdge(int to, int id) : BaseEdge(to, id) {
    }

    void setReverseId(int revId) {
        rev = revId;
    }

    BiEdge reverseEdge(int from) {
        return BiEdge(from, id);
    }

    BiEdge& reverseEdge(Graph<BiEdge>& graph) {
        return graph[to][rev];
    }
};









template<typename Value, typename Delta>
class SegmentTree {
    const int size;
public:
    Value defaultValue;
private:
    const Delta defaultDelta;
    function<Value(Value, Value)> joinValue;
    function<Delta(Delta, Delta)> joinDelta;
    function<Value(Value, Delta, int, int)> accumulate;
    arr<Value> value;
    arr<Delta> delta;

    void init(int root, int left, int right) {
        if (left + 1 == right) {
            value[root] = defaultValue;
        } else {
            int mid = (left + right) >> 1;
            init(2 * root + 1, left, mid);
            init(2 * root + 2, mid, right);
            value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
        }
    }

    void apply(int root, Delta dlt, int left, int right) {
        value[root] = accumulate(value[root], dlt, left, right);
        delta[root] = joinDelta(delta[root], dlt);
    }

    void pushDown(int root, int left, int mid, int right) {
        apply(2 * root + 1, delta[root], left, mid);
        apply(2 * root + 2, delta[root], mid, right);
        delta[root] = defaultDelta;
    }

    void update(int root, int left, int right, int from, int to, Delta dlt) {
        if (left >= from && right <= to) {
            apply(root, dlt, left, right);
            return;
        }
        if (right <= from || left >= to) {
            return;
        }
        int mid = (left + right) >> 1;
        pushDown(root, left, mid, right);
        update(2 * root + 1, left, mid, from, to, dlt);
        update(2 * root + 2, mid, right, from, to, dlt);
        value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
    }

    Value query(int root, int left, int right, int from, int to) {
        if (left >= from && right <= to) {
            return value[root];
        }
        if (right <= from || left >= to) {
            return defaultValue;
        }
        int mid = (left + right) >> 1;
        pushDown(root, left, mid, right);
        return joinValue(query(2 * root + 1, left, mid, from, to), query(2 * root + 2, mid, right, from, to));
    }

public:
    SegmentTree(int size, function<Value(Value, Value)> joinValue,
                function<Delta(Delta, Delta)> joinDelta,
                function<Value(Value, Delta, int, int)> accumulate,
                Value defaultValue = 0, Delta defaultDelta = 0 ) :
                size(size), joinValue(joinValue), joinDelta(joinDelta), accumulate(accumulate),
                defaultValue(defaultValue), defaultDelta(defaultDelta) {
        int vertexSize = size * 4;
        value = arr<Value>(vertexSize);
        delta = arr<Delta>(vertexSize, defaultDelta);
        if (size > 0) {
            init(0, 0, size);
        }
    }

    void update(int from, int to, Delta delta) {
        update(0, 0, size, max(0, from), to, delta);
    }

    Value query(int from, int to) {
        return query(0, 0, size, max(0, from), to);
    }
};






const int DX_KNIGHT[] = {2, 1, -1, -2, -2, -1, 1, 2};
const int DY_KNIGHT[] = {1, 2, 2, 1, -1, -2, -2, -1};
const int DX4[] = {1, 0, -1, 0};
const int DY4[] = {0, 1, 0, -1};
const int DX8[] = {1, 1, 1, 0, -1, -1, -1, 0};
const int DY8[] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool isValidCell(int r, int c, int n, int m) {
    return r >= 0 && c >= 0 && r < n && c < m;
}






inline bool isSubset(unsigned set, unsigned subSet) {
    return (set & subSet) == subSet;
}

inline int bitCount(unsigned x) {
    return __builtin_popcount(x);
}

inline int bitCount(ull x) {
    return __builtin_popcountll(x);
}

inline int bitCount(uli x) {
    return __builtin_popcountll(x) + __builtin_popcountll(x >> 64);
}

inline int highestOneBit(unsigned x) {
    return 1 << (31 - __builtin_clz(x | 1));
}

inline int binaryDigits(unsigned x) {
    return 32 - __builtin_clz(x | 1);
}

inline ull setBit(ull mask, int bit) {
#ifdef LOCAL
    if (bit < 0 || bit >= 64) {
        throw "Bad index";
    }
#endif
    mask |= ull(1) << bit;
    return mask;
}

inline unsigned setBit(unsigned mask, int bit) {
#ifdef LOCAL
    if (bit < 0 || bit >= 32) {
        throw "Bad index";
    }
#endif
    mask |= unsigned(1) << bit;
    return mask;
}

inline uli setBit(uli mask, int bit) {
#ifdef LOCAL
    if (bit < 0 || bit >= 128) {
        throw "Bad index";
    }
#endif
    mask |= uli(1) << bit;
    return mask;
}

inline ull unsetBit(ull mask, int bit) {
#ifdef LOCAL
    if (bit < 0 || bit >= 64) {
        throw "Bad index";
    }
#endif
    mask &= ~(ull(1) << bit);
    return mask;
}

inline unsigned unsetBit(unsigned mask, int bit) {
#ifdef LOCAL
    if (bit < 0 || bit >= 32) {
        throw "Bad index";
    }
#endif
    mask &= ~(unsigned(1) << bit);
    return mask;
}

inline uli unsetBit(uli mask, int bit) {
#ifdef LOCAL
    if (bit < 0 || bit >= 128) {
        throw "Bad index";
    }
#endif
    mask &= ~(uli(1) << bit);
    return mask;
}

inline bool isSet(ull mask, int bit) {
#ifdef LOCAL
    if (bit < 0 || bit >= 64) {
        throw "Bad index";
    }
#endif
    return mask >> bit & 1;
}

inline bool isSet(unsigned mask, int bit) {
#ifdef LOCAL
    if (bit < 0 || bit >= 32) {
        throw "Bad index";
    }
#endif
    return mask >> bit & 1;
}

inline bool isSet(uli mask, int bit) {
#ifdef LOCAL
    if (bit < 0 || bit >= 128) {
        throw "Bad index";
    }
#endif
    return mask >> bit & 1;
}

inline unsigned allBits(int n) {
#ifdef LOCAL
    if (n < 0 || n >= 32) {
        throw "Bad index";
    }
#endif
    return (1u << n) - 1;
}

inline ull allBitsLL(int n) {
#ifdef LOCAL
    if (n < 0 || n >= 64) {
        throw "Bad index";
    }
#endif
    return (1ull << n) - 1;
}

inline uli allBits128(int n) {
#ifdef LOCAL
    if (n < 0 || n >= 128) {
        throw "Bad index";
    }
#endif
    return (uli(1) << n) - 1;
}


class LCA {
private:
    arri order;
    arri position;
    arr2d<int> lcaArr;

    int getMin(int a, int b) const {
        if (level[a] < level[b]) {
            return a;
        }
        return b;
    }

public:
    arri level;
    arri parent;

    template <class Edge>
    LCA(Graph<Edge>& graph, int root = 0) {
        int vertexCount = graph.vertexCount;
        order = arri(2 * vertexCount - 1);
        position = arri(vertexCount, -1);
        level = arri(vertexCount);
        level[root] = 0;
        arri index(vertexCount, 0);
        parent = arri(vertexCount);
        arri& last = parent;
        arri stack(vertexCount);
        stack[0] = root;
        int size = 1;
        int j = 0;
        last[root] = -1;
        while (size > 0) {
            int vertex = stack[--size];
            if (position[vertex] == -1) {
                position[vertex] = j;
            }
            order[j++] = vertex;
            if (last[vertex] != -1) {
                level[vertex] = level[last[vertex]] + 1;
            }
            while (index[vertex] < graph[vertex].size() && last[vertex] == graph[vertex][index[vertex]].to) {
                index[vertex]++;
            }
            if (index[vertex] < graph[vertex].size()) {
                stack[size++] = vertex;
                int to = graph[vertex][index[vertex]].to;
                stack[size++] = graph[vertex][index[vertex]].to;
                last[to] = vertex;
                index[vertex]++;
            }
        }
        lcaArr = arr2d<int>(binaryDigits(2 * vertexCount - 1), 2 * vertexCount - 1);
        for (int i : range(2 * vertexCount - 1)) {
            lcaArr(0, i) = order[i];
        }
        for (int i : range(1, lcaArr.dim1())) {
            for (int j : range(2 * vertexCount - 1)) {
                if (j + (1 << (i - 1)) < 2 * vertexCount - 1) {
                    lcaArr(i, j) = getMin(lcaArr(i - 1, j), lcaArr(i - 1, j + (1 << (i - 1))));
                } else {
                    lcaArr(i, j) = lcaArr(i - 1, j);
                }
            }
        }
    }

    int lca(int first, int second) const {
        int from = min(position[first], position[second]);
        int to = max(position[first], position[second]);
        int lv = binaryDigits(to - from) - 1;
        return getMin(lcaArr(lv, from), lcaArr(lv, to + 1 - (1 << lv)));
    }

    int pathLength(int first, int second) const {
        return level[first] + level[second] - 2 * level[lca(first, second)];
    }
};


class F1ZagadanaParaVershinProstayaVersiya {
public:
    void solve() {
        in.setBufSize(1);
        out.autoflush = true;

        int t = in.readInt();
        for (int z : range(t)) {
            int n = in.readInt();
            arri u, v;
            in.readArrays(n - 1, u, v);
            decreaseByOne(u, v);

            Graph<BiEdge> graph(n);
            for (int i : range(n - 1)) {
                graph.addEdge(u[i], v[i]);
            }
            vi f;
            for (int i : range(1, n + 1)) {
                f.push_back(i);
            }
            out.printLine("?", n, f);
            int root = in.readInt() - 1;
            if (root == -2) {
                while (true);
            }
            int dist = in.readInt();
            LCA lca(graph, root);
            int x = root;
            int y = root;
            while (lca.pathLength(x, y) != dist) {
                int xy = lca.pathLength(x, y);
                int rem = dist - xy;
                int cd = (rem + 1) / 2;
                vi req;
                for (int i : range(n)) {
                    if (lca.pathLength(x, i) == cd && lca.pathLength(y, i) == cd + xy ||
                        lca.pathLength(y, i) == cd && lca.pathLength(x, i) == cd + xy) {
                        req.push_back(i + 1);
                    }
                }
                out.printLine("?", req.size(), req);
                int vert = in.readInt() - 1;
                if (vert == -2) {
                    while (true);
                }
                if (dist != in.readInt()) {
                    throw "Jopa";
                }
                if (lca.pathLength(x, vert) == cd) {
                    x = vert;
                } else {
                    y = vert;
                }
            }
            out.printLine("!", x + 1, y + 1);
            if (in.readString() == "Incorrect") {
                return;
            }
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
#ifdef LOCAL_RELEASE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto time = clock();
#endif
    F1ZagadanaParaVershinProstayaVersiya solver;


    solver.solve();
    fflush(stdout);
#ifdef LOCAL_RELEASE
    cerr << double(clock() - time) / CLOCKS_PER_SEC << endl;
#endif
    return 0;
}