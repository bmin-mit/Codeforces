//* 390395669	Sep/12/2026 16:52UTC+7	Minh4893IT	1777A - Everybody Likes Good Arrays!	C++23 (GCC 14-64, msys2)	Accepted	31 ms	100 KB

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

    int res = 0;
    int last = 0;
    cin >> last;
    while (--n)
    {
        int x;
        cin >> x;

        res += x % 2 == last % 2;
        last = x;
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
