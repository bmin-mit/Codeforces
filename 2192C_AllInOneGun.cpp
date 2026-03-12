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

vector<int> arr;
int n, h, k;

bool check(int cnt)
{
    int currSum = 0;
    int mi = arr[0];
    int ma = 0;

    if (!cnt)
        return !h;
    for (int i = 0; i < n; i++)
        if (i < cnt)
        {
            currSum += arr[i];
            mi = min(mi, arr[i]);
        }
        else
            ma = max(ma, arr[i]);

    return currSum - mi + ma >= h || currSum >= h;
}

void solve()
{
    cin >> n >> h >> k;
    arr.resize(n);

    for (auto &elem : arr)
        cin >> elem;

    int sum = accumulate(arr.begin(), arr.end(), 0LL);
    int cycle = h / sum;
    int res = cycle * (n + k);

    h = h % sum;

    debug(h, cycle, res);

    int low = 0;
    int high = n;
    int choose = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (check(mid))
        {
            debug(mid);
            high = mid - 1, choose = mid;
        }
        else
            low = mid + 1;
    }

    cout << res + choose - IF(h, 0, k) << endl;
}

signed main()
{
    FAST_IO;

    MULTI
    solve();

    return 0;
}
