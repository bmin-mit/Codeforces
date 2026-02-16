//* 363233316	Feb/16/2026 11:28UTC+7	Minh4893IT	B - Towers	C++17 (GCC 7-32)	Accepted	46 ms	0 KB

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
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i].first, arr[i].second = i;
    sort(arr.begin(), arr.end());

    int idx = -1;
    int curr = arr.back().first - arr.front().first;
    vector<pair<int, int>> result;
    for (int i = 0; i < k; ++i)
    {
        ++arr.front().first, --arr.back().first;
        result.push_back({arr.back().second + 1, arr.front().second + 1});

        sort(arr.begin(), arr.end());
        int diff = arr.back().first - arr.front().first;
        if (diff < curr)
        {
            curr = diff;
            idx = i;
        }
    }

    cout << curr << ' ' << idx + 1 << endl;
    for (int i = 0; i <= idx; ++i)
        cout << result[i].first << ' ' << result[i].second << endl;
}

signed main()
{
    FAST_IO;

    // MULTI
    solve();

    return 0;
}
