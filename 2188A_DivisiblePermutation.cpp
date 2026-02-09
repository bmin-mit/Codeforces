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

    vector<int> res(n + 1);
    res[n] = 1;

    int curr = 1;
    for (int i = n; i >= 1; i -= 2)
    {
        res[i] = curr;
        ++curr;
    }

    curr = n;
    for (int i = n - 1; i >= 1; i -= 2)
    {
        res[i] = curr;
        --curr;
    }

    for (int i = 1; i <= n; ++i)
        cout << res[i] << ' ';
    cout << endl;
}

signed main()
{
    FAST_IO;

    MULTI
    solve();

    return 0;
}
