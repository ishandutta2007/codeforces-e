/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */

// Actual solution is at the bottom





#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define val const auto&

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

    arr(T* b, int n) : arr(b, b + n) {}
    arr(T* b, T* e) : b(b), n(e - b) {}

    arr(initializer_list<T> l) : arr(l.size()) {
        if (n > 0) {
            memcpy(b, l.begin(), n * sizeof(T));
        }
    }

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
        return vector<T>(b, b + n);
    }

    arr<T> subArray(int from, int to) const {
        return arr<T>(b + from, b + to);
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
    explicit arr2d(int d1 = 0, int d2 = 0) : d1(d1), d2(d2), sz(d1 * d2) {
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
            return EOF;
        }
        if (bufRead == bufAt) {
            bufRead = fread(buf, sizeof(char), bufSize, stdin);
            bufAt = 0;
        }
        if (bufRead == bufAt) {
            exhausted = true;
            getchar();
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
        } else if (c == '+') {
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
        array = arr<T>(n);
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
        while (c != '\n' && c != '\r' && c != EOF) {
            res.push_back(c);
            c = get();
        }
        if (c == '\r' && peek() == '\n') {
            get();
        }
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

#ifdef LOCAL
#define debug(x) err.printLine(#x, '=', x);
#else
#define debug(x)
#endif












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





template<typename T>
class que : public queue<T> {
    using parent = queue<T>;
public:
    que() : parent() {}
    que(const que<T>& q) : parent(q) {}
    que(que<T>&& q) noexcept : parent(move(q)) {}

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

    que<T>& operator =(que<T>&& __x) noexcept {
        parent::operator=(__x);
        return *this;
    }

    que<T>& operator =(const que<T>& __x) {
        parent::operator=(__x);
        return *this;
    }
};

using qi = que<int>;


class ENizhniiUroven {
public:
    void solve() {
        int n = in.readInt();
        int m = in.readInt();
        auto a = in.readIntArray(n - 1);
        auto b = in.readIntArray(n - 1);
        arri u, v;
        in.readArrays(m, u, v);
        decreaseByOne(u, v);

        Graph<BiEdge> graph(n);
        for (int i : range(m)) {
            graph.addEdge(u[i], v[i]);
        }

        int left = *min_element(all(a)) + 1;
        int right = *max_element(all(a)) + 1;

        arr<ll> power(n, -1);
        arri parent(n, -1);
        arr<bool> reached(n, false);
        while (left < right) {
            int mid = (left + right) / 2;

            fill(all(reached), false);
            reached[0] = true;

            ll cpower = mid;
            while (true) {
                fill(all(power), -1);
                fill(all(parent), -1);
                que<int> q;
                bool found = false;
                for (int i : range(n)) {
                    if (reached[i]) {
                        for (auto& e : graph[i]) {
                            if (!reached[e.to] && a[e.to - 1] < cpower) {
                                if (parent[e.to] != -1) {
                                    cpower += b[e.to - 1];
                                    reached[e.to] = true;
                                    found = true;
                                    break;
                                }
                                parent[e.to] = i;
                                power[e.to] = cpower + b[e.to - 1];
                                q.push(e.to);
                            }
                        }
                    }
                    if (found) {
                        break;
                    }
                }
                if (found) {
                    continue;
                }
                while (!q.empty()) {
                    int cur = q.pop();
                    for (auto& e : graph[cur]) {
                        if (e.to == parent[cur]) {
                            continue;
                        }
                        if (reached[e.to] || parent[e.to] != -1) {
                            int v = cur;
                            while (!reached[v]) {
                                reached[v] = true;
                                cpower += b[v - 1];
                                v = parent[v];
                            }
                            v = e.to;
                            while (!reached[v]) {
                                reached[v] = true;
                                cpower += b[v - 1];
                                v = parent[v];
                            }
                            found = true;
                            break;
                        }
                        if (a[e.to - 1] < power[cur]) {
                            power[e.to] = power[cur] + b[e.to - 1];
                            parent[e.to] = cur;
                            q.push(e.to);
                        }
                    }
                    if (found) {
                        break;
                    }

                }
                if (!found) {
                    break;
                }
            }
            if (count(all(reached), true) == n) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        out.printLine(left);
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
    ENizhniiUroven solver;


    int n;
scanf("%d", &n);
for(int i = 0; i < n; ++i) {
	solver.solve();
}

    fflush(stdout);
#ifdef LOCAL_RELEASE
    cerr << setprecision(3) << double(clock() - time) / CLOCKS_PER_SEC << endl;
#endif
    return 0;
}