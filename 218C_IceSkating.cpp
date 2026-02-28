//* 364795073	Feb/28/2026 13:41UTC+7	Minh4893IT	C - Ice Skating	C++17 (GCC 7-32)	Accepted	92 ms	200 KB

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

int n;
array<bitset<1005>, 1005> mark;
vector<pair<int, int>> edges;
map<int, vector<int>> adjFirst, adjSecond;

void dfs(int ptIdx)
{
    int ptX = edges[ptIdx].first, ptY = edges[ptIdx].second;
    if (mark[ptX][ptY])
        return;
    mark[ptX][ptY] = true;

    for (int i : adjFirst[ptX])
        dfs(i);
    for (int i : adjSecond[ptY])
        dfs(i);
}

void solve()
{
    cin >> n;
    edges.resize(n);
    for (auto &[x, y] : edges)
        cin >> x >> y;

    for (int i = 1; i <= 1000; i++)
        for (int j = 0; j < n; ++j)
        {
            if (edges[j].first == i)
                adjFirst[i].push_back(j);
            if (edges[j].second == i)
                adjSecond[i].push_back(j);
        }

    int res = 0;
    for (int i = 0; i < n; ++i)
        if (!mark[edges[i].first][edges[i].second])
        {
            dfs(i);
            res++;
        }
    cout << res - 1 << endl;
}

signed main()
{
    FAST_IO;

    // MULTI
    solve();

    return 0;
}
