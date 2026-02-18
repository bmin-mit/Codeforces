//* 363535471	Feb/18/2026 23:33UTC+7	Minh4893IT	B - Tanya and Postcard	C++17 (GCC 7-32)	Accepted	62 ms	0 KB

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

char swapcase(char c)
{
    if (islower(c))
        return toupper(c);
    return tolower(c);
}

void solve()
{
    string s, t;
    cin >> s >> t;

    map<char, int> cntA, cntB;
    for (auto c : s)
        cntA[c]++;
    for (auto c : t)
        cntB[c]++;

    int res1 = 0, res2 = 0;
    for (char c = 'a'; c <= 'z'; ++c)
    {
        if (cntA[c] && cntB[c])
        {
            int res = min(cntA[c], cntB[c]);

            res1 += res;
            cntA[c] -= res;
            cntB[c] -= res;
        }
    }

    for (char c = 'A'; c <= 'Z'; ++c)
    {
        if (cntA[c] && cntB[c])
        {
            int res = min(cntA[c], cntB[c]);

            res1 += res;
            cntA[c] -= res;
            cntB[c] -= res;
        }
    }

    for (char c = 'a'; c <= 'z'; ++c)
    {
        char d = swapcase(c);
        if (cntA[c] && cntB[d])
        {
            int res = min(cntA[c], cntB[d]);

            res2 += res;
            cntA[c] -= res;
            cntB[d] -= res;
        }
    }

    for (char c = 'A'; c <= 'Z'; ++c)
    {
        char d = swapcase(c);
        if (cntA[c] && cntB[d])
        {
            int res = min(cntA[c], cntB[d]);

            res2 += res;
            cntA[c] -= res;
            cntB[d] -= res;
        }
    }

    cout << res1 << ' ' << res2;
}

signed main()
{
    FAST_IO;

    // MULTI
    solve();

    return 0;
}
