#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int DY4[]{1, 0, -1, 0}, DX4[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1};
constexpr int DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U>
inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U>
inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

template <typename Abelian>
struct FenwickTree {
  explicit FenwickTree(const int n, const Abelian ID = 0)
      : n(n), ID(ID), data(n, ID) {}

  void add(int idx, const Abelian val) {
    for (; idx < n; idx |= idx + 1) {
      data[idx] += val;
    }
  }

  Abelian sum(int idx) const {
    Abelian res = ID;
    for (--idx; idx >= 0; idx = (idx & (idx + 1)) - 1) {
      res += data[idx];
    }
    return res;
  }

  Abelian sum(const int left, const int right) const {
    return left < right ? sum(right) - sum(left) : ID;
  }

  Abelian operator[](const int idx) const { return sum(idx, idx + 1); }

  int lower_bound(Abelian val) const {
    if (val <= ID) return 0;
    int res = 0, exponent = 1;
    while (exponent <= n) exponent <<= 1;
    for (int mask = exponent >> 1; mask > 0; mask >>= 1) {
      const int idx = res + mask - 1;
      if (idx < n && data[idx] < val) {
        val -= data[idx];
        res += mask;
      }
    }
    return res;
  }

 private:
  const int n;
  const Abelian ID;
  std::vector<Abelian> data;
};

template <typename T>
struct LazySegmentTree {
  using Monoid = typename T::Monoid;
  using OperatorMonoid = typename T::OperatorMonoid;

  explicit LazySegmentTree(const int n)
      : LazySegmentTree(std::vector<Monoid>(n, T::m_id())) {}

  explicit LazySegmentTree(const std::vector<Monoid>& a)
      : n(a.size()), height(0) {
    while ((1 << height) < n) ++height;
    p2 = 1 << height;
    lazy.assign(p2, T::o_id());
    data.assign(p2 << 1, T::m_id());
    std::copy(a.begin(), a.end(), data.begin() + p2);
    for (int i = p2 - 1; i > 0; --i) {
      data[i] = T::m_merge(data[i << 1], data[(i << 1) + 1]);
    }
  }

  void set(int idx, const Monoid val) {
    idx += p2;
    for (int i = height; i > 0; --i) {
      propagate(idx >> i);
    }
    data[idx] = val;
    for (int i = 1; i <= height; ++i) {
      const int current_idx = idx >> i;
      data[current_idx] =
          T::m_merge(data[current_idx << 1], data[(current_idx << 1) + 1]);
    }
  }

  void apply(int idx, const OperatorMonoid val) {
    idx += p2;
    for (int i = height; i > 0; --i) {
      propagate(idx >> i);
    }
    data[idx] = T::apply(data[idx], val);
    for (int i = 1; i <= height; ++i) {
      const int current_idx = idx >> i;
      data[current_idx] =
          T::m_merge(data[current_idx << 1], data[(current_idx << 1) + 1]);
    }
  }

  void apply(int left, int right, const OperatorMonoid val) {
    if (right <= left) return;
    left += p2;
    right += p2;
    const int ctz_left = __builtin_ctz(left);
    for (int i = height; i > ctz_left; --i) {
      propagate(left >> i);
    }
    const int ctz_right = __builtin_ctz(right);
    for (int i = height; i > ctz_right; --i) {
      propagate(right >> i);
    }
    for (int l = left, r = right; l < r; l >>= 1, r >>= 1) {
      if (l & 1) apply_sub(l++, val);
      if (r & 1) apply_sub(--r, val);
    }
    for (int i = left >> (ctz_left + 1); i > 0; i >>= 1) {
      data[i] = T::m_merge(data[i << 1], data[(i << 1) + 1]);
    }
    for (int i = right >> (ctz_right + 1); i > 0; i >>= 1) {
      data[i] = T::m_merge(data[i << 1], data[(i << 1) + 1]);
    }
  }

  Monoid get(int left, int right) {
    if (right <= left) return T::m_id();
    left += p2;
    right += p2;
    const int ctz_left = __builtin_ctz(left);
    for (int i = height; i > ctz_left; --i) {
      propagate(left >> i);
    }
    const int ctz_right = __builtin_ctz(right);
    for (int i = height; i > ctz_right; --i) {
      propagate(right >> i);
    }
    Monoid res_l = T::m_id(), res_r = T::m_id();
    for (; left < right; left >>= 1, right >>= 1) {
      if (left & 1) res_l = T::m_merge(res_l, data[left++]);
      if (right & 1) res_r = T::m_merge(data[--right], res_r);
    }
    return T::m_merge(res_l, res_r);
  }

  Monoid operator[](const int idx) {
    const int node = idx + p2;
    for (int i = height; i > 0; --i) {
      propagate(node >> i);
    }
    return data[node];
  }

  template <typename G>
  int find_right(int left, const G g) {
    if (left >= n) return n;
    left += p2;
    for (int i = height; i > 0; --i) {
      propagate(left >> i);
    }
    Monoid val = T::m_id();
    do {
      while (!(left & 1)) left >>= 1;
      Monoid nxt = T::m_merge(val, data[left]);
      if (!g(nxt)) {
        while (left < p2) {
          propagate(left);
          left <<= 1;
          nxt = T::m_merge(val, data[left]);
          if (g(nxt)) {
            val = nxt;
            ++left;
          }
        }
        return left - p2;
      }
      val = nxt;
      ++left;
    } while (__builtin_popcount(left) > 1);
    return n;
  }

  template <typename G>
  int find_left(int right, const G g) {
    if (right <= 0) return -1;
    right += p2;
    for (int i = height; i > 0; --i) {
      propagate((right - 1) >> i);
    }
    Monoid val = T::m_id();
    do {
      --right;
      while (right > 1 && (right & 1)) right >>= 1;
      Monoid nxt = T::m_merge(data[right], val);
      if (!g(nxt)) {
        while (right < p2) {
          propagate(right);
          right = (right << 1) + 1;
          nxt = T::m_merge(data[right], val);
          if (g(nxt)) {
            val = nxt;
            --right;
          }
        }
        return right - p2;
      }
      val = nxt;
    } while (__builtin_popcount(right) > 1);
    return -1;
  }

 private:
  const int n;
  int p2, height;
  std::vector<Monoid> data;
  std::vector<OperatorMonoid> lazy;

  void apply_sub(const int idx, const OperatorMonoid& val) {
    data[idx] = T::apply(data[idx], val);
    if (idx < p2) lazy[idx] = T::o_merge(lazy[idx], val);
  }

  void propagate(const int idx) {
    // assert(1 <= idx && idx < p2);
    apply_sub(idx << 1, lazy[idx]);
    apply_sub((idx << 1) + 1, lazy[idx]);
    lazy[idx] = T::o_id();
  }
};

namespace monoid {

template <typename T>
struct RangeMinimumAndUpdateQuery {
  using Monoid = T;
  using OperatorMonoid = T;
  static constexpr Monoid m_id() { return std::numeric_limits<Monoid>::max(); }
  static constexpr OperatorMonoid o_id() {
    return std::numeric_limits<OperatorMonoid>::max();
  }
  static Monoid m_merge(const Monoid& a, const Monoid& b) {
    return std::min(a, b);
  }
  static OperatorMonoid o_merge(const OperatorMonoid& a,
                                const OperatorMonoid& b) {
    return b == o_id() ? a : b;
  }
  static Monoid apply(const Monoid& a, const OperatorMonoid& b) {
    return b == o_id() ? a : b;
  }
};

template <typename T>
struct RangeMaximumAndUpdateQuery {
  using Monoid = T;
  using OperatorMonoid = T;
  static constexpr Monoid m_id() {
    return std::numeric_limits<Monoid>::lowest();
  }
  static constexpr OperatorMonoid o_id() {
    return std::numeric_limits<OperatorMonoid>::lowest();
  }
  static Monoid m_merge(const Monoid& a, const Monoid& b) {
    return std::max(a, b);
  }
  static OperatorMonoid o_merge(const OperatorMonoid& a,
                                const OperatorMonoid& b) {
    return b == o_id() ? a : b;
  }
  static Monoid apply(const Monoid& a, const OperatorMonoid& b) {
    return b == o_id()? a : b;
  }
};

template <typename T, T Inf>
struct RangeMinimumAndAddQuery {
  using Monoid = T;
  using OperatorMonoid = T;
  static constexpr Monoid m_id() { return Inf; }
  static constexpr OperatorMonoid o_id() { return 0; }
  static Monoid m_merge(const Monoid& a, const Monoid& b) {
    return std::min(a, b);
  }
  static OperatorMonoid o_merge(const OperatorMonoid& a,
                                const OperatorMonoid& b) {
    return a + b;
  }
  static Monoid apply(const Monoid& a, const OperatorMonoid& b) {
    return a + b;
  }
};

template <typename T, T Inf>
struct RangeMaximumAndAddQuery {
  using Monoid = T;
  using OperatorMonoid = T;
  static constexpr Monoid m_id() { return -Inf; }
  static constexpr OperatorMonoid o_id() { return 0; }
  static Monoid m_merge(const Monoid& a, const Monoid& b) {
    return std::max(a, b);
  }
  static OperatorMonoid o_merge(const OperatorMonoid& a,
                                const OperatorMonoid& b) {
    return a + b;
  }
  static Monoid apply(const Monoid& a, const OperatorMonoid& b) {
    return a + b;
  }
};

template <typename T>
struct RangeSumAndUpdateQuery {
  using Monoid = struct { T sum; int len; };
  using OperatorMonoid = T;
  static std::vector<Monoid> init(const int n) {
    return std::vector<Monoid>(n, Monoid{0, 1});
  }
  static constexpr Monoid m_id() { return {0, 0}; }
  static constexpr OperatorMonoid o_id() {
    return std::numeric_limits<OperatorMonoid>::max();
  }
  static Monoid m_merge(const Monoid& a, const Monoid& b) {
    return Monoid{a.sum + b.sum, a.len + b.len};
  }
  static OperatorMonoid o_merge(const OperatorMonoid& a,
                                const OperatorMonoid& b) {
    return b == o_id() ? a : b;
  }
  static Monoid apply(const Monoid& a, const OperatorMonoid& b) {
    return Monoid{b == o_id() ? a.sum : b * a.len, a.len};
  }
};

template <typename T>
struct RangeSumAndAddQuery {
  using Monoid = struct { T sum; int len; };
  using OperatorMonoid = T;
  static std::vector<Monoid> init(const int n) {
    return std::vector<Monoid>(n, Monoid{0, 1});
  }
  static constexpr Monoid m_id() { return {0, 0}; }
  static constexpr OperatorMonoid o_id() { return 0; }
  static Monoid m_merge(const Monoid& a, const Monoid& b) {
    return Monoid{a.sum + b.sum, a.len + b.len};
  }
  static OperatorMonoid o_merge(const OperatorMonoid& a,
                                const OperatorMonoid& b) {
    return a + b;
  }
  static Monoid apply(const Monoid& a, const OperatorMonoid& b) {
    return Monoid{a.sum + b * a.len, a.len};
  }
};

}  // namespace monoid

int main() {
  constexpr int A = 200000;
  int q, d; cin >> q >> d;
  FenwickTree<int> is_not_empty(A);
  LazySegmentTree<monoid::RangeSumAndAddQuery<ll>> seg(A);
  const auto calc = [&](const int a) -> ll {
    ll ans = 0;
    const int l = is_not_empty.sum(max(a - d, 0), a);
    ans += l * (l - 1LL) / 2;
    const int r = is_not_empty.sum(a + 1, min(a + d + 1, A));
    ans += r * (r - 1LL) / 2;
    ans -= (l + 1LL) * l / 2;
    ans += seg.get(max(a - d, 0), a).sum;
    return ans;
  };
  ll ans = 0;
  while (q--) {
    int a; cin >> a; --a;
    if (is_not_empty[a]) {
      ans -= calc(a);
      is_not_empty.add(a, -1);
      seg.apply(max(a - d, 0), a, -1);
      seg.set(a, monoid::RangeSumAndAddQuery<ll>::m_id());
    } else {
      is_not_empty.add(a, 1);
      seg.apply(max(a - d, 0), a, 1);
      seg.set(a, monoid::RangeSumAndAddQuery<ll>::Monoid{is_not_empty.sum(a + 1, min(a + d + 1, A)), 1});
      ans += calc(a);
    }
    cout << ans << '\n';
  }
  return 0;
}