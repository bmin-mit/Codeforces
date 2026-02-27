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

#define INF 100003

bitset<1000005> markVal;
bool cmp(vector<int> &a, vector<int> &b)
{
    int aptr = 0, bptr = 0;
    map<int, bool> markC;
    while (aptr < a.size() && bptr < b.size())
    {
        if (markVal[a[aptr]] || markC[a[aptr]])
        {
            aptr++;
            continue;
        }

        if (markVal[b[bptr]] || markC[b[bptr]])
        {
            bptr++;
            continue;
        }

        if (a[aptr] == b[bptr])
        {
            markC[a[aptr]] = true;
            markC[b[bptr]] = true;
            aptr++;
            bptr++;
        }
        else
            return a[aptr] < b[bptr];
    }

    return aptr == a.size();
}

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> a(n);
    vector<int> ptr(n);

    markVal.reset();

    for (auto &row : a)
    {
        int l;
        cin >> l;

        vector<int> inp(l);

        for (auto &i : inp)
            cin >> i;

        reverse(inp.begin(), inp.end());
        row = inp;
    }

    bitset<3005> markRow;
    vector<int> res;
    for (int i = 0; i < n; ++i)
    {
        int row = 0;

        for (int i = 0; i < n; ++i)
            if (!markRow[i])
            {
                row = i;
                break;
            }

        debug(row);

        for (int j = 1; j < n; ++j)
        {
            if (!markRow[j] && cmp(a[j], a[row]))
                row = j;
        }

        debug(row, a[row]);

        markRow[row] = true;
        for (auto &elem : a[row])
            if (!markVal[elem])
                res.push_back(elem), markVal[elem] = true;
    }

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
