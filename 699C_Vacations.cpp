//* 364899836	Mar/01/2026 08:50UTC+7	Minh4893IT	C - Vacations	C++17 (GCC 7-32)	Accepted	46 ms	100 KB

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

void solve()
{
    int n;
    cin >> n;

    array<array<int, 105>, 2> dp;
    dp[0].fill(0), dp[1].fill(0);
    for (int i = 1; i <= n; ++i)
    {
        int acti;
        cin >> acti;

        bool contest = acti & 1;
        bool gym = acti & 2;

        debug(i, contest, gym);

        dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + contest);
        dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + gym);

        if (i < 2)
            continue;

        dp[0][i] = max(dp[0][i], dp[0][i - 2] + contest);
        dp[1][i] = max(dp[1][i], dp[1][i - 2] + gym);
    }

    debug(dp[0]);
    debug(dp[1]);

    cout << n - max(dp[0][n], dp[1][n]);
}

signed main()
{
    FAST_IO;

    // MULTI
    solve();

    return 0;
}
