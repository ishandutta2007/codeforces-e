#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
template<typename T>
ostream& operator+(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out<<x<<" ";
    }
    out<<"\n";
    return out;
}
template<typename T>
ostream& operator*(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out+x;
    }
    return out;
}
template<typename T>
istream& operator>>(istream& in, vector<T> &vec){
    for(auto &x : vec){
        in>>x;
    }
    return in;
}
template<typename T, typename U>
struct lazy_segment_tree{
    int n;
    int H;
    T base;
    vector<T> segtree;
    vector<U> lazytree;
    vector<bool> isempty;
    function<T(const T&, const T&)> join;
    function<T(int, const U&, const T&)> assign;
    function<U(const U&,const U&)> lazyassign;

    lazy_segment_tree(vector<T> &seq, 
    function<T(const T&, const T&)> join, 
    function<T(int, const U&, const T&)> assign,
    function<U(const U&,const U&)> lazyassign,
    T base) : join(join), assign(assign), lazyassign(lazyassign), base(base){
        n = seq.size();
        H = 32 - __builtin_clz(n);
        segtree.resize(2*n);
        lazytree.resize(n);
        isempty.resize(n,1);
        for(int i=0;i<n;i++){
            segtree[n+i]=seq[i];
        }
        for(int i=n-1;i>=1;i--){
            segtree[i]=join(segtree[(i<<1)], segtree[(i<<1)|1]);
        }
    }
    lazy_segment_tree(int n, 
    function<T(const T&, const T&)> join, 
    function<T(int, const U&, const T&)> assign,
    function<U(const U&,const U&)> lazyassign,
    T base) : join(join), assign(assign), lazyassign(lazyassign), base(base), n(n){
        H = 32 - __builtin_clz(n);
        segtree.resize(2*n, base);
        lazytree.resize(n);
        isempty.resize(n,1);
    }
    void calc(int pos, int h){
        segtree[pos]=join(segtree[(pos<<1)],segtree[(pos<<1)|1]);
        if(!isempty[pos]){
            segtree[pos]=assign(h,lazytree[pos],segtree[pos]);
        }
    }
    void apply(int pos, U value, int h){
        segtree[pos]=assign(h, value, segtree[pos]);
        if(pos<n){
            if(!isempty[pos]){
                lazytree[pos]=lazyassign(value, lazytree[pos]);
            }
            else{
                lazytree[pos] = value;
            }
            isempty[pos]=0;
        }
    }
    void updatenode(int pos){
        int h=0;
        pos+=n;
        while(pos>1){
            h++;
            pos>>=1;
            calc(pos, h);
        }
    }
    void push(int pos){
        int h=H;
        for(pos+=n;h;--h){
            int x=(pos>>h);
            if(!isempty[x]){
                apply((x<<1), lazytree[x], h-1);
                apply((x<<1)|1, lazytree[x], h-1);
                isempty[x]=1;
            }
        }
    }
    void updaterange(int l, int r, U value){
        push(l);
        push(r);
        int k=0;
        int l0=l, r0=r;
        for(l+=n, r+=n+1;l<r;l>>=1, r>>=1, k++){
            if(l&1){
                apply(l++, value, k);
            }
            if(r&1){
                apply(--r, value,k);
            }
        }
        updatenode(l0);
        updatenode(r0);
    }
    T query(int l, int r){
        push(l);
        push(r);
        T ansl=base;
        T ansr=base;
        for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
            if(l&1){
                ansl=join(ansl, segtree[l++]);
            }        
            if(r&1){
                ansr=join(segtree[--r], ansr);
            }
        }
        return join(ansl,ansr);
    }
};
void solve(){
    int n,q;
    cin >> n >> q;
    string s,f;
    cin>>f>>s;
    lazy_segment_tree<int,int> st(n, [&](int x,int y){
        return x+y;
    }, [&](int h,int x,int y){
        return x*(1<<h);
    }, [&](int x,int y){
        return x;
    }, 0);
    for(int i=0;i<n;i++) st.updaterange(i,i,s[i]-'0');
    bool ans = 1;
    vector<pair<int,int>> qry(q);
    for(auto &[l,r] : qry) cin>>l>>r;
    reverse(qry.begin(), qry.end());
    for(auto &[l,r] : qry){
        --l;--r;
        int cnt = st.query(l,r);
        //cout<<cnt<<" "<<l<<" "<<r<<"\n";
        if(2*cnt == r - l + 1){
            ans = 0;
            continue;
        }
        st.updaterange(l,r,(2*cnt > r-l+1));
    }
    for(int i=0;i<n;i++) ans &= (st.query(i,i) == (f[i] - '0'));
    cout<<(ans ? "YES\n" : "NO\n");
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}