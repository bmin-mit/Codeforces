#include <bits/stdc++.h>
using namespace std;

// #define int long long
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

void solve()
{
    int n, m;
    cin >> n >> m;

    int ones = 0;
    vector<vector<int>> table(n, vector<int>(m));
    for (auto &row : table)
        for (auto &cell : row)
        {
            cin >> cell;
            ones += cell;
        }

    int target = ones / 2;

    int top_pad = 0;
    int left_pad = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = m - 1; j >= 0; --j)
        {
            target -= table[i][j];
            if (!target)
            {
                left_pad = j;
                break;
            }
        }

        if (!target)
        {
            top_pad = i;
            break;
        }
    }

    cout << (long long)ones / 2 * (ones - ones / 2) << endl;

    for (int i = 0; i < top_pad; ++i)
        cout << 'D';

    for (int i = 0; i < left_pad; ++i)
        cout << 'R';

    cout << 'D';

    for (int i = left_pad; i < m; ++i)
        cout << 'R';
    for (int i = top_pad + 1; i < n; ++i)
        cout << 'D';

    cout << endl;
}

signed main()
{
    FAST_IO;

    MULTI
    solve();

    return 0;
}
