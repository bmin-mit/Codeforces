//* 365494107	Mar/05/2026 23:01UTC+7	Minh4893IT	C - They Are Everywhere	C++17 (GCC 7-32)	Accepted	1703 ms	201100 KB

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

int n;
string s;

vector<map<char, int>> pref;
set<char> chars;

bool check(int l, int r)
{
    for (char c : chars)
        if (pref[r][c] - pref[l - 1][c] == 0)
            return false;
    return true;
}

void solve()
{
    cin >> n >> s;
    pref.resize(n + 1);

    for (int i = 0; i < n; i++)
    {
        pref[i + 1] = pref[i];
        pref[i + 1][s[i]]++;
    }

    chars = set<char>(s.begin(), s.end());

    int ans = n;
    for (int i = 1; i <= n; i++)
    {
        int low = 1;
        int high = i;
        int res = -INT_MAX;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (check(mid, i))
            {
                low = mid + 1;
                res = mid;
            }
            else
                high = mid - 1;
        }

        ans = min(ans, i - res + 1);
    }

    cout << ans;
}

signed main()
{
    FAST_IO;

    // MULTI
    solve();

    return 0;
}
