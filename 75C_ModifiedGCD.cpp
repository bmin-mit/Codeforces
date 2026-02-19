//* 363569307	Feb/19/2026 10:53UTC+7	Minh4893IT	C - Modified GCD	C++17 (GCC 7-32)	Accepted	92 ms	100 KB

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

int a, b;
map<int, int> primeFact;
vector<int> divs;

void gen(map<int, int>::iterator it, int curr = 1)
{
    if (it == primeFact.end())
    {
        divs.push_back(curr);
        return;
    }

    int p = (*it).first;
    int e = (*it).second;
    advance(it, 1);

    for (int i = 0; i <= e; ++i)
    {
        gen(it, curr);
        curr *= p;
    }
}

void solve()
{
    cin >> a >> b;

    int g = gcd(a, b);
    for (int i = 2; i < g; ++i)
    {
        while (g % i == 0)
            primeFact[i]++, g /= i;
    }

    if (g != 1)
        primeFact[g]++;

    debug(primeFact);

    gen(primeFact.begin());
    sort(divs.begin(), divs.end());

    debug(divs);

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;

        int low = 0, high = divs.size() - 1;
        int res = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (divs[mid] >= l && divs[mid] <= r)
            {
                res = divs[mid];
                low = mid + 1;
            }
            else if (divs[mid] < l)
                low = mid + 1;
            else
                high = mid - 1;
        }

        cout << res << endl;
    }
}

signed main()
{
    FAST_IO;

    // MULTI
    solve();

    return 0;
}
