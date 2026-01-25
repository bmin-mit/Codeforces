#include <bits/stdc++.h>
using namespace std;

#define int long long
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

    vector<int> a(n), b(n);
    for (auto &elem : a)
        cin >> elem;
    for (auto &elem : b)
        cin >> elem;

    sort(a.rbegin(), a.rend());

    int sum = 0;
    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += b[i];

        if (sum > n)
            break;

        int difficulty = a[sum - 1];
        int score = difficulty * (i + 1);
        res = max(res, score);
    }

    cout << res << endl;
}

signed main()
{
    FAST_IO;

    MULTI
    solve();

    return 0;
}
