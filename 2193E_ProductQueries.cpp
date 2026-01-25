#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define ss stringstream
#define endl "\n"
#define LLMAX INT64_MAX
#define IF(cond, t, f) (cond ? t : f)
#define OFILE(finp, fout) freopen(finp, "r", stdin), freopen(fout, "w", stdout)
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL)
#define MULTI \
    int t;    \
    cin >> t; \
    while (t--)

void solve()
{
    int n;
    cin >> n;

    vector<int> count(n + 1, INT_MAX);
    for (int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        count[t] = 1;
    }

    vector<int> values;
    for (int i = 2; i <= n; ++i)
        if (count[i] != INT_MAX)
            values.push_back(i);

    for (int i = 1; i <= n; ++i)
    {
        if (count[i] != INT_MAX)
            continue;

        for (auto &v : values)
        {
            if (v * v > i)
                break;
            if (i % v == 0 && count[i / v] != INT_MAX)
                count[i] = min(count[i], count[i / v] + 1);
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << IF(count[i] != INT_MAX, count[i], -1) << ' ';
    cout << endl;
}

signed main()
{
    FAST_IO;

    MULTI
    solve();

    return 0;
}
