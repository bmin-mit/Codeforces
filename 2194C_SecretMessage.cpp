#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define endl "\n"

#define IF(cond, t, f) (cond ? t : f)
#define OFILE(finp, fout) freopen(finp, "r", stdin), freopen(fout, "w", stdout)
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL)
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
    int n, k;
    cin >> n >> k;

    vector<string> strs(k);
    for (auto &elem : strs)
        cin >> elem;

    vector<int> divs;
    for (int i = 1; i * i <= n; ++i)
        if (n % i == 0)
        {
            divs.push_back(i);
            if (i != n / i)
                divs.push_back(n / i);
        }

    sort(divs.begin(), divs.end());

    int loop_count = 0;
    for (auto d : divs)
    {
        string res;

        for (int start = 0; start < d; ++start)
        {
            map<char, int> count;
            for (int curr = start; curr < n; curr += d)
            {
                set<char> mark;
                for (auto &s : strs)
                    mark.insert(s[curr]);

                for (auto marked : mark)
                    ++count[marked];
            }

            bool found = false;
            for (auto [chr, freq] : count)
                if (freq == n / d)
                {
                    res.push_back(chr);
                    found = true;
                    break;
                }

            if (!found)
                break;
        }

        if (d == res.size())
        {
            for (int i = 0; i < n / d; ++i)
                cout << res;
            cout << endl;
            return;
        }
    }
}

signed main()
{
    FAST_IO;

    MULTI
    solve();

    return 0;
}
