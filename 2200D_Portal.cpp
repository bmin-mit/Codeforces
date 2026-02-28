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
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int left = x, right = y - 1;

    vector<int> first(arr.begin(), arr.begin() + left), mid(arr.begin() + left, arr.begin() + right + 1), last(arr.begin() + right + 1, arr.end());

    auto minMid = min_element(mid.begin(), mid.end());

    int firstShift = 0;
    while (firstShift < left && first[firstShift] < *minMid)
        firstShift++;

    int lastShift = 0;
    while (lastShift < last.size() && last[lastShift] < *minMid)
        lastShift++;

    vector<int> res1, res2;
    for (int i = 0; i < firstShift; i++)
        res1.push_back(first[i]);
    for (int i = 0; i < mid.size(); ++i)
        res1.push_back(mid[(i + (minMid - mid.begin())) % mid.size()]);
    for (int i = firstShift; i < first.size(); i++)
        res1.push_back(first[i]);
    for (int i = 0; i < last.size(); i++)
        res1.push_back(last[i]);

    for (int i = 0; i < first.size(); ++i)
        res2.push_back(first[i]);
    for (int i = 0; i < lastShift; i++)
        res2.push_back(last[i]);
    for (int i = 0; i < mid.size(); ++i)
        res2.push_back(mid[(i + (minMid - mid.begin())) % mid.size()]);
    for (int i = lastShift; i < last.size(); i++)
        res2.push_back(last[i]);

    debug(res1, res2);

    vector<int> res = min(res1, res2);
    for (auto &elem : res)
        cout << elem << " ";
    cout << endl;
}

signed main()
{
    FAST_IO;

    MULTI
    solve();

    return 0;
}
