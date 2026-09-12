//* 390393790	Sep/12/2026 16:31UTC+7	Minh4893IT	1791C - Prepend and Append	C++23 (GCC 14-64, msys2)	Accepted	46 ms	0 KB

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
    string s;
    cin >> n >> s;

    int res = n;
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - 1 - i])
        {
            res -= 2;
        }
        else
        {
            break;
        }
    }

    println("{}", res);
}

signed main()
{
    FAST_IO;

    MULTI
    solve();

    return 0;
}
