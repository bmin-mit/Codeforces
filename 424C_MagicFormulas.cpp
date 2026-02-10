#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

#define IF(cond, t, f) (cond ? t : f)
#define OFILE(finp, fout) freopen(finp, "r", stdin), freopen(fout, "w", stdout)
#define FAST_IO ios_base::sync_with_stdio(false), (void)cin.tie()
#define MULTI \
    int t;    \
    cin >> t; \
    while (t--)

template <class T, class V>
ostream &operator<<(ostream &o, pair<T, V> p)
{
    return o << "(" << p.first << ", " << p.second << ")";
}

#define P(T, O, C)                          \
    template <class U>                      \
    ostream &operator<<(ostream &o, T<U> v) \
    {                                       \
        o << O;                             \
        int f = 0;                          \
        for (auto &i : v)                   \
            o << (f++ ? ", " : "") << i;    \
        return o << C;                      \
    }

#define Q(T, O, C)                             \
    template <class K, class V>                \
    ostream &operator<<(ostream &o, T<K, V> v) \
    {                                          \
        o << O;                                \
        int f = 0;                             \
        for (auto &i : v)                      \
            o << (f++ ? ", " : "") << i;       \
        return o << C;                         \
    }

P(vector, '[', ']')
P(set, '{', '}')
Q(map, '{', '}')

template <class T, size_t N>
ostream &operator<<(ostream &o, array<T, N> v)
{
    o << "[";
    int f = 0;
    for (auto &i : v)
        o << (f++ ? ", " : "") << i;
    return o << "]";
}

void dbg(const char *s) { cerr << endl; }

template <class T, class... A>
void dbg(const char *s, T v, A... a)
{
    const char *c = s;
    int b = 0;
    while (*c && (*c != ',' || b))
        b += bool(strchr("({[", *c)), b -= bool(strchr(")}]", *c)), c++;
    cerr.write(s, c - s) << " = " << v << (sizeof...(a) ? " |" : "");
    if (sizeof...(a))
        dbg(c + 1, a...);
    else
        cerr << endl;
}

#ifdef LOCAL
#define debug(...) dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 42
#endif

int n;
array<signed, 1000005> xorRange;

int xorRangeMod(int mod)
{
    int len = n - mod + 1;
    int res = xorRange[len % mod];
    if (len % (mod * 2) >= mod)
        res ^= xorRange[mod];
    debug(mod, res);
    return res;
}

void solve()
{
    cin >> n;

    vector<int> arr(n);
    for (auto &elem : arr)
        cin >> elem;

    xorRange[0] = 0;
    for (int i = 1; i < xorRange.size(); ++i)
        xorRange[i] = xorRange[i - 1] ^ (i - 1);

    int leftTria = 0;
    for (int i = n - 1; i >= 0; i -= 2)
        leftTria ^= i;

    debug(leftTria);

    int rightTria = 0;
    for (int i = 2; i <= n; ++i)
        rightTria ^= xorRangeMod(i);

    debug(rightTria);

    int res = 0;
    for (auto &elem : arr)
        res ^= elem;
    cout << (res ^ leftTria ^ rightTria);
}

signed main()
{
    FAST_IO;

    // MULTI
    solve();

    return 0;
}
