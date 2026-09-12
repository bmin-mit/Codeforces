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
    int emp, proj, month;
    cin >> emp >> proj >> month;

    int res = 0;
    while (proj / emp > 1 && month > 0)
    {
        int gap = proj / emp - 1;
        int curr = proj % emp;
        int take = min(curr / gap + 1, month);

        month -= take;
        proj += take;
        emp += take;

        int u1 = curr - (take - 1) * gap;
        int u2 = curr;
        int sum = take * (u1 + u2) / 2;
        res += sum;
    }

    cout << res + month * (proj % emp) << endl;
}

signed main()
{
    FAST_IO;

    MULTI
    solve();

    return 0;
}
