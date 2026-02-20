//* 363697009	Feb/20/2026 20:01UTC+7	Minh4893IT	C - Maze	C++17 (GCC 7-32)	Accepted	46 ms	19900 KB

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

int n, m, k, cellCnt = 0;
vector<string> board;

array<bitset<505>, 505> mark;

void dfs(int i, int j)
{
    if (i >= n || i < 0 || j >= m || j < 0 || board[i][j] != '.' || mark[i][j])
        return;

    mark[i][j] = true;

    if (cellCnt-- <= k)
        board[i][j] = 'X';

    dfs(i - 1, j);
    dfs(i + 1, j);
    dfs(i, j - 1);
    dfs(i, j + 1);
}

void solve()
{
    cin >> n >> m >> k;
    board.resize(n);

    for (auto &elem : board)
    {
        cin >> elem;
        for (auto &c : elem)
            cellCnt += c == '.';
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (board[i][j] == '.')
            {
                dfs(i, j);

                for (auto &row : board)
                    cout << row << endl;
                return;
            }

    for (auto &row : board)
        cout << row << endl;
}

signed main()
{
    FAST_IO;

    // MULTI
    solve();

    return 0;
}
