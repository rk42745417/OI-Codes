#include <bits/stdc++.h>
using namespace std;

#ifdef EMT
#define debug(x) cerr << "\e[1;31m" << #x << " = " << (x) << "\e[0m\n"
#define print(x) emilia_mata_tenshi(#x, begin(x), end(x))
template<typename T, typename T2> ostream& operator<<(ostream &os, const pair<T, T2> &obj) {
    return os << '{' << obj.first << ',' << obj.second << '}';
}
template<class TupType, size_t... I> void lamy_kawaii(ostream& os, const TupType& _tup, index_sequence<I...>) {
    // source: https://stackoverflow.com/a/41171552
    os << '{';
    (..., (cerr << (I == 0? "" : ",") << get<I>(_tup)));
    os << '}';
}
template<class... T> ostream& operator<<(ostream &os, const tuple<T...>& _tup) {
    lamy_kawaii(os, _tup, make_index_sequence<sizeof...(T)>());
    return os;
}
template<typename T> void emilia_mata_tenshi(const char *s, T l, T r) {
    cerr << "\e[1;33m" << s << " = [";
    while(l != r) {
        cerr << *l;
        cerr << (++l == r ? ']' : ',');
    }
    cerr << "\e[0m\n";
}
#else
#define debug(x) 48763
#define print(x) 48763
#endif

template<typename T, typename T2> istream& operator>>(istream &is, pair<T, T2> &obj) {
    is >> obj.first >> obj.second;
    return is;
}
template<typename T> istream& operator>>(istream &is, vector<T> &obj) {
    for(auto &x : obj)
        is >> x;
    return is;
}

#define YN(x) ((x) ? "YES" : "NO")
#define Yn(x) ((x) ? "Yes" : "No")
#define yn(x) ((x) ? "yes" : "no")
#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(NULL);
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using uint = uint32_t;
const double EPS  = 1e-8;
const int INF     = 0x3F3F3F3F;
const ll LINF     = 4611686018427387903;
const int MOD     = 1e9+7;
static int Lamy_is_cute = []() {
    EmiliaMyWife
    return 48763;
}();
#define X first
#define Y second
#define pii pair<int,int>
#define F(n) Fi(i,n)
#define Fi(i,n) Fl(i,0,n)
#define Fl(i,l,n) for(int i=l;i<n;i++)
#define pb push_back
#define sz(x) ((int)(x.size))
#define all(x) x.begin(),x.end()
/*--------------------------------------------------------------------------------------*/

const int N = 1e6 + 25;
struct segtree {
    int arr[N << 1], n;
    void init(int _n) { n = _n; }
    void edt(int p, int v) {
        for(arr[p += n] = v; p > 1; p >>= 1)
            arr[p >> 1] = min(arr[p], arr[p ^ 1]);
    }
    int que(int l, int r) {
        int res = INF;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1)
                res = min(res, arr[l++]);
            if(r & 1)
                res = min(res, arr[--r]);
        }
        return res;
    }
} tree;

signed main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    cin >> arr;

    for(int i = 0; i < n; i++)
        arr[i] -= i;
    tree.init(n);
    for(int i = 0; i < n; i++)
        tree.edt(i, arr[i]);

    print(arr);
    int ans = 0;
    for(int i = 0, r = i + 1; i < n; i++) {
        while(r <= n && tree.que(i, r) + i > 0)
            r++;
        ans = max(ans, r - i - 1);
    }
    cout << ans << '\n';
}
