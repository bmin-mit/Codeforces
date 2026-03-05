//* 365498172	Mar/05/2026 23:38UTC+7	Minh4893IT	C - Dijkstra?	C++17 (GCC 7-32)	Accepted	140 ms	8400 KB

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
    int n, m;
    cin >> n >> m;

    map<int, vector<pair<int, int>>> adj;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, INT64_MAX);
    vector<int> trace(n + 1, -1);
    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty())
    {
        auto [cDist, u] = pq.top();
        pq.pop();

        if (cDist > dist[u])
            continue;

        for (auto [v, w] : adj[u])
            if (cDist + w < dist[v])
            {
                dist[v] = cDist + w;
                pq.push({dist[v], v});
                trace[v] = u;
            }
    }

    vector<int> res = {n};
    int curr = n;
    while (curr != 1)
    {
        if (trace[curr] == -1)
        {
            cout << -1;
            return;
        }

        res.push_back(trace[curr]);
        curr = trace[curr];
    }

    reverse(res.begin(), res.end());

    for (auto &elem : res)
        cout << elem << ' ';
}

signed main()
{
    FAST_IO;

    // MULTI
    solve();

    return 0;
}
