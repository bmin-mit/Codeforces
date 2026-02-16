//* 363229840	Feb/16/2026 10:20UTC+7	Minh4893IT	C - Greg and Array	C++17 (GCC 7-32)	Accepted	187 ms	1700 KB

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
ostream &operator<<(ostream &o, pair<T, V> p);

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

template <class T, class V>
ostream &operator<<(ostream &o, pair<T, V> p)
{
    return o << "(" << p.first << ", " << p.second << ")";
}

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

int n, m, k;

struct Update
{
    int l, r, d, count;
};

vector<int> arr, arrDiff, updDiff;
vector<Update> updates;

void solve()
{
    cin >> n >> m >> k;
    arr.resize(n + 1), arrDiff.resize(n + 2), updDiff.resize(m + 2), updates.resize(m + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arrDiff[i] = arr[i] - arr[i - 1];
    }
    for (int i = 1; i <= m; i++)
        cin >> updates[i].l >> updates[i].r >> updates[i].d;

    while (k--)
    {
        int x, y;
        cin >> x >> y;

        updDiff[x]++;
        updDiff[y + 1]--;
    }

    int updCount = 0;
    for (int i = 1; i <= m; ++i)
    {
        updCount += updDiff[i];
        int updVal = updCount * updates[i].d;

        int l = updates[i].l, r = updates[i].r;
        arrDiff[l] += updVal;
        arrDiff[r + 1] -= updVal;
    }

    debug(arr, arrDiff, updDiff);

    int sum = 0;
    for (int i = 1; i <= n; ++i)
        cout << (sum += arrDiff[i]) << ' ';
}

signed main()
{
    FAST_IO;

    // MULTI
    solve();

    return 0;
}
