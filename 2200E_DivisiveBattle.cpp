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

int factorize(int n)
{
    if (n == 1)
        return n;

    int last = -1;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            if (last != -1)
                return -1;

            last = i;
            while (n % i == 0)
                n /= i;
        }

    if (n > 1)
        if (last != -1)
            return -1;
        else
            return n;
    return last;
}

void solve()
{
    int n;
    cin >> n;

    vector<int>
        arr(n);
    for (auto &elem : arr)
        cin >> elem;

    if (is_sorted(arr.begin(), arr.end()))
    {
        cout << "Bob" << endl;
        return;
    }

    for (auto &elem : arr)
        elem = factorize(elem);
    debug(arr);

    for (auto &elem : arr)
        if (elem == -1)
        {
            cout << "Alice" << endl;
            return;
        }

    if (is_sorted(arr.begin(), arr.end()))
    {
        cout << "Bob" << endl;
        return;
    }

    cout << "Alice" << endl;
}

signed main()
{
    FAST_IO;

    MULTI
    solve();

    return 0;
}
