//* 365694866	Mar/07/2026 15:23UTC+7	Minh4893IT	C - Text Editor	C++17 (GCC 7-32)	Accepted	186 ms	100 KB

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define endl "\n"

#define IF(cond, t, f) (cond ? t : f)

#ifdef LOCAL
#define OFILE(...) 42
#else
#define OFILE(finp, fout) freopen(finp, "r", stdin), freopen(fout, "w", stdout)
#endif

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

    vector<int> arr(n);
    for (auto &elem : arr)
        cin >> elem;

    int xs, ys, xe, ye;
    cin >> xs >> ys >> xe >> ye;

    --xs, --xe;
    queue<pair<int, int>> q;
    q.push({xs, ys});
    array<bitset<100005>, 105> visited;
    visited[xs][ys] = true;

    int depth = 0;
    while (!q.empty())
    {
        int layerSize = q.size();
        while (layerSize--)
        {
            auto [x, y] = q.front();
            q.pop();
            if (x == xe && y == ye)
            {
                cout << depth << endl;
                return;
            }

            if (x < n - 1 && !visited[x + 1][min(y, arr[x + 1] + 1)])
            {
                q.push({x + 1, min(y, arr[x + 1] + 1)});
                visited[x + 1][min(y, arr[x + 1] + 1)] = true;
            }
            if (x > 0 && !visited[x - 1][min(y, arr[x - 1] + 1)])
            {
                q.push({x - 1, min(y, arr[x - 1] + 1)});
                visited[x - 1][min(y, arr[x - 1] + 1)] = true;
            }
            if (y > 1 && !visited[x][y - 1])
            {
                q.push({x, y - 1});
                visited[x][y - 1] = true;
            }
            if (y < arr[x] && !visited[x][y + 1])
            {
                q.push({x, y + 1});
                visited[x][y + 1] = true;
            }
        }

        depth++;
    }
}

signed main()
{
    FAST_IO;
    OFILE("input.txt", "output.txt");

    // MULTI
    solve();

    return 0;
}
