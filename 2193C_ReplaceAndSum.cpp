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
    int n, q;
    cin >> n >> q;

    vector<int> a(n), b(n);
    for (auto &elem : a)
        cin >> elem;
    for (auto &elem : b)
        cin >> elem;

    a.back() = max(a.back(), b.back());
    for (int i = n - 2; i >= 0; --i)
        a[i] = max(a[i], max(a[i + 1], b[i]));

    vector<int> pref(n + 1);
    for (int i = 1; i <= n; ++i)
        pref[i] = a[i - 1] + pref[i - 1];

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << pref[r] - pref[l - 1] << ' ';
    }

    cout << endl;
}

signed main()
{
    FAST_IO;

    MULTI
    solve();

    return 0;
}
