///* 365543859	Mar/06/2026 10:34UTC+7	Minh4893IT	D - Mysterious Present	C++17 (GCC 7-32)	Accepted	93 ms	0 KB

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
    int n, w, h;
    cin >> n >> w >> h;

    vector<pair<pair<int, int>, int>> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i].first.first >> arr[i].first.second, arr[i].second = i;
    sort(arr.begin(), arr.end());

    vector<int> trace(n, -1);
    vector<int> dp(n);
    int maxLen = 0;
    int tracePos = -1;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i].first.first <= w || arr[i].first.second <= h)
            continue;

        dp[i] = 1;

        for (int j = 0; j < i; ++j)
            if (arr[j].first.first < arr[i].first.first && arr[j].first.second < arr[i].first.second)
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    trace[arr[i].second] = arr[j].second;
                }

        if (dp[i] > maxLen)
        {
            maxLen = dp[i];
            tracePos = arr[i].second;
        }
    }

    debug(dp);
    debug(trace);
    debug(tracePos);

    cout << maxLen << endl;

    if (!maxLen)
        return;

    vector<int> res;
    for (int pos = tracePos; pos != -1; pos = trace[pos])
        res.push_back(pos);
    reverse(res.begin(), res.end());
    for (auto &elem : res)
        cout << elem + 1 << ' ';
}

signed main()
{
    FAST_IO;

    // MULTI
    solve();

    return 0;
}
