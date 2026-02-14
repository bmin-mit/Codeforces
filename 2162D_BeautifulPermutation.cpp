//* 362885207	Feb/14/2026 16:43UTC+7	Minh4893IT	D - Beautiful Permutation	C++17 (GCC 7-32)	Accepted	203 ms	0 KB

#include <bits/stdc++.h>
using namespace std;

#define int long long
// #define endl "\n"

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

int query(int type, int l, int r)
{
    cout << type << " " << l << " " << r << endl;
    int sum;
    cin >> sum;
    return sum;
}

int lenRange(int l, int r)
{
    return query(2, l, r) - query(1, l, r);
}

void solve()
{
    int n;
    cin >> n;

    int len = query(2, 1, n) - (n * (n + 1)) / 2;

    debug(len);

    int low = 1, high = n;
    int start = 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int currLen = lenRange(mid, n);
        if (currLen < len)
        {
            high = mid - 1;
        }
        else
        {
            start = mid;
            low = mid + 1;
        }
    }

    cout << "! " << start << " " << start + len - 1 << endl;
}

signed main()
{
    FAST_IO;

    MULTI
    solve();

    return 0;
}
