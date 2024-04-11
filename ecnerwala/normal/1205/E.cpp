#include<bits/stdc++.h>
using namespace std;

template <int MOD_> struct modnum {
	static constexpr int MOD = MOD_;
	static_assert(MOD_ > 0, "MOD must be positive");

private:
	using ll = long long;

	int v;

	static int minv(int a, int m) {
		a %= m;
		assert(a);
		return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
	}

public:

	modnum() : v(0) {}
	modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
	explicit operator int() const { return v; }
	friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
	friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }

	friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
	friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

	modnum inv() const {
		modnum res;
		res.v = minv(v, MOD);
		return res;
	}
	modnum neg() const {
		modnum res;
		res.v = v ? MOD-v : 0;
		return res;
	}

	modnum operator- () const {
		return neg();
	}
	modnum operator+ () const {
		return modnum(*this);
	}

	modnum& operator ++ () {
		v ++;
		if (v == MOD) v = 0;
		return *this;
	}
	modnum& operator -- () {
		if (v == 0) v = MOD;
		v --;
		return *this;
	}
	modnum& operator += (const modnum& o) {
		v += o.v;
		if (v >= MOD) v -= MOD;
		return *this;
	}
	modnum& operator -= (const modnum& o) {
		v -= o.v;
		if (v < 0) v += MOD;
		return *this;
	}
	modnum& operator *= (const modnum& o) {
		v = int(ll(v) * ll(o.v) % MOD);
		return *this;
	}
	modnum& operator /= (const modnum& o) {
		return *this *= o.inv();
	}

	friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
	friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
	friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
	friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
	friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
	friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

template <typename T> T pow(T a, long long b) {
	assert(b >= 0);
	T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r;
}

using num = modnum<int(1e9)+7>;

const int MAXN = 1.1e5;
int N;
num K;

num phi[MAXN];

num phiSum[MAXN];

num kCoeff[MAXN * 2];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> K;

	for (int i = 0; i <= N; i++) {
		phi[i] = i;
	}

	for (int p = 2; p <= N; p++) {
		if (phi[p] != p) continue;
		for (int j = p; j <= N; j += p) {
			phi[j] -= phi[j] / p;
		}
	}

	phiSum[0] = 0;
	for (int i = 1; i <= N; i++) {
		phiSum[i] = phiSum[i-1] + phi[i];
	}

	// >= N
	for (int i = 0; i <= N-2; i++) {
		kCoeff[i] += N - 1 - i;
	}

	for (int g = 1; g <= N-1; g++) {
		// a + b = ceiling N / g
		int v = (N + g - 1) / g;
		if (v > 1) {
			kCoeff[v * g - N] -= phi[v];
			kCoeff[g] += phi[v];
		}

		//cerr << g << ' ' << (N-1) / g << ' ' << phiSum[(N-1) / g] << '\n';
		// a + b <= N-1
		kCoeff[g] += phiSum[(N-1) / g] - 1;
	}

	num ans = 0;
	num pK = 1;
	for (int i = 0; i <= N - 1; i++, pK *= K) {
		//cerr << i << ' ' << kCoeff[i] << '\n';
		ans += kCoeff[i] * pK;
	}
	ans /= pow(K, N);
	cout << ans << '\n';

	return 0;
}