//* 390395124	Sep/12/2026 16:46UTC+7	Minh4893IT	1788A - One and Two	C++23 (GCC 14-64, msys2)	Accepted	46 ms	0 KB

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

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
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i] += IF(i, arr[i - 1], 0) - 1;
    }

    if (arr.back() % 2)
    {
        println("-1");
        return;
    }

    auto it = lower_bound(arr.begin(), arr.end(), arr.back() / 2);
    println("{}", it - arr.begin() + 1);
}

signed main()
{
    FAST_IO;

    MULTI
    solve();

    return 0;
}
