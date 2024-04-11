#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

// const int mod = 1e9 + 7;
const int mod = 998244353;

const int64 infll = (1LL << 62) - 1;
const int inf = (1 << 30) - 1;

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  }
} iosetup;


template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 > &p) {
  os << p.first << " " << p.second;
  return os;
}

template< typename T1, typename T2 >
istream &operator>>(istream &is, pair< T1, T2 > &p) {
  is >> p.first >> p.second;
  return is;
}

template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
  for(int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
  for(T &in: v) is >> in;
  return is;
}

template< typename T1, typename T2 >
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

template< typename T1, typename T2 >
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

template< typename T = int64 >
vector< T > make_v(size_t a) {
  return vector< T >(a);
}

template< typename T, typename... Ts >
auto make_v(size_t a, Ts... ts) {
  return vector< decltype(make_v< T >(ts...)) >(a, make_v< T >(ts...));
}

template< typename T, typename V >
typename enable_if< is_class< T >::value == 0 >::type fill_v(T &t, const V &v) {
  t = v;
}

template< typename T, typename V >
typename enable_if< is_class< T >::value != 0 >::type fill_v(T &t, const V &v) {
  for(auto &e: t) fill_v(e, v);
}

template< typename F >
struct FixPoint : F {
  FixPoint(F &&f) : F(forward< F >(f)) {}

  template< typename... Args >
  decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, forward< Args >(args)...);
  }
};

template< typename F >
inline decltype(auto) MFP(F &&f) {
  return FixPoint< F >{forward< F >(f)};
}

template< int mod >
struct ModInt {
  int x;

  ModInt() : x(0) {}

  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

  ModInt &operator+=(const ModInt &p) {
    if((x += p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator-=(const ModInt &p) {
    if((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator*=(const ModInt &p) {
    x = (int) (1LL * x * p.x % mod);
    return *this;
  }

  ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }

  ModInt operator-() const { return ModInt(-x); }

  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

  bool operator==(const ModInt &p) const { return x == p.x; }

  bool operator!=(const ModInt &p) const { return x != p.x; }

  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }

  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ModInt &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt< mod >(t);
    return (is);
  }

  static int get_mod() { return mod; }
};

using modint = ModInt< mod >;


int main() {
  int N, M, K;
  cin >> N >> M >> K;

  vector< map< int, int > > mp(N);
  auto X_mat = make_v< int >(N, 2);
  auto Y_mat = make_v< int >(M, 2);
  int X_dame = 0, X_two = N;
  int Y_dame = 0, Y_two = M;
  int V[2] = {};
  vector< modint > mul2(1010101);
  mul2[0] = 1;
  for(int i = 1; i < mul2.size(); i++) mul2[i] = mul2[i - 1] * 2;

  while(K--) {
    int x, y, t;
    cin >> x >> y >> t;
    --x, --y;
    int f = (x + y) & 1;

    if(mp[x].count(y)) {
      int v = mp[x][y];
      if((X_mat[x][0]>0) + (X_mat[x][1]>0) == 2) {
        --X_dame;
      } else if((X_mat[x][0]>0) + (X_mat[x][1]>0) == 0) {
        --X_two;
      }
      if((Y_mat[y][0]>0) + (Y_mat[y][1]>0) == 2) {
        --Y_dame;
      } else if((Y_mat[y][0]>0) + (Y_mat[y][1]>0) == 0) {
        --Y_two;
      }
      --X_mat[x][f ^ v];
      --Y_mat[y][f ^ v];
      --V[f ^ v];
      if((X_mat[x][0]>0) + (X_mat[x][1]>0) == 2) {
        ++X_dame;
      } else if((X_mat[x][0]>0) + (X_mat[x][1]>0) == 0) {
        ++X_two;
      }
      if((Y_mat[y][0]>0) + (Y_mat[y][1]>0) == 2) {
        ++Y_dame;
      } else if((Y_mat[y][0]>0) + (Y_mat[y][1]>0) == 0) {
        ++Y_two;
      }
      mp[x].erase(y);
    }



    if(t >= 0) {
      int v = t;
      if((X_mat[x][0]>0) + (X_mat[x][1]>0) == 2) {
        --X_dame;
      } else if((X_mat[x][0]>0) + (X_mat[x][1]>0) == 0) {
        --X_two;
      }
      if((Y_mat[y][0]>0) + (Y_mat[y][1]>0) == 2) {
        --Y_dame;
      } else if((Y_mat[y][0]>0) + (Y_mat[y][1]>0) == 0) {
        --Y_two;
      }
      X_mat[x][f ^ v]++;
      Y_mat[y][f ^ v]++;
      ++V[f ^ v];
      if((X_mat[x][0]>0) + (X_mat[x][1]>0) == 2) {
        ++X_dame;
      } else if((X_mat[x][0]>0) + (X_mat[x][1]>0) == 0) {
        ++X_two;
      }
      if((Y_mat[y][0]>0) + (Y_mat[y][1]>0) == 2) {
        ++Y_dame;
      } else if((Y_mat[y][0]>0) + (Y_mat[y][1]>0) == 0) {
        ++Y_two;
      }
      mp[x][y] = t;
    }
    modint ret = 0;
    if(X_dame == 0) {
      ret += mul2[X_two];
    }
    if(Y_dame == 0) {
      ret += mul2[Y_two];
    }
    if((V[0] > 0) + (V[1] > 0) == 0) {
      ret -= 2;
    } else if((V[0] > 0) + (V[1] > 0) == 1) {
      ret -= 1;
    }
    cout << ret << "\n";
  }
}