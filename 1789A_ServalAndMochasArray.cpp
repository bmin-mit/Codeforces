//* 390394281	Sep/12/2026 16:37UTC+7	Minh4893IT	1789A - Serval and Mocha's Array	C++23 (GCC 14-64, msys2)	Accepted	171 ms	0 KB

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
        cin >> arr[i];

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
        {
            if (gcd(arr[i], arr[j]) <= 2)
            {
                println("Yes");
                return;
            }
        }

    println("No");
}

signed main()
{
    FAST_IO;

    MULTI
    solve();

    return 0;
}
