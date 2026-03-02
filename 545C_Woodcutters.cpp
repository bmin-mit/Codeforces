//* 365048965	Mar/02/2026 13:56UTC+7	Minh4893IT	C - Woodcutters	C++17 (GCC 7-32)	Accepted	93 ms	200 KB

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

pair<int, int> best(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return IF(a.second < b.second, a, b);
    return max(a, b);
}

pair<int, int> best(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    return best(a, best(b, c));
}

void solve()
{
    int n;
    cin >> n;

    vector<pair<int, int>> trees(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> trees[i].first >> trees[i].second;
    trees[0].first = -1'000'000'000;

    vector<int> stay(n + 1), left(n + 1), right(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        auto [x, h] = trees[i];
        auto [lastX, lastH] = trees[i - 1];

        int lEnd = x - h;
        int rEnd = x + h;
        int lastLEnd = lastX - lastH;
        int lastREnd = lastX + lastH;

        stay[i] = left[i] = right[i] = max(stay[i - 1], max(left[i - 1], right[i - 1]));

        if (lastX < lEnd)
            left[i] = left[i - 1] + 1;

        if (lastREnd < lEnd)
            left[i] = max(left[i], right[i - 1] + 1);
        if (i == n || trees[i + 1].first > rEnd)
            right[i] = max(max(left[i - 1] + 1, stay[i - 1] + 1), right[i - 1] + 1);
    }

    debug(stay);
    debug(left);
    debug(right);

    cout << max(stay[n], max(left[n], right[n]));
}

signed main()
{
    FAST_IO;

    // MULTI
    solve();

    return 0;
}
