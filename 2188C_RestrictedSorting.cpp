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

    vector<int> arr(n);
    for (auto &elem : arr)
        cin >> elem;

    if (is_sorted(arr.begin(), arr.end()))
    {
        cout << -1 << endl;
        return;
    }

    vector<int> clone(arr.begin(), arr.end());
    sort(clone.begin(), clone.end());

    int res = clone.back() - clone.front();
    for (int i = 0; i < n; ++i)
        if (clone[i] != arr[i])
        {
            int casei = max(arr[i] - clone.front(), clone.back() - arr[i]);
            res = min(casei, res);
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
