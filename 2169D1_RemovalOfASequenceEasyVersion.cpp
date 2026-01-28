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

int pos(int x, int y, int val)
{
    int curr = val;
    while (x--)
        curr -= curr / y;
    return curr;
}

void solve()
{
    int x, y, k;
    cin >> x >> y >> k;

    int low = 1;
    int high = 1e12;
    int res = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int p = pos(x, y, mid);
        if (p >= k)
        {
            high = mid - 1;
            res = mid;
        }
        else
        {
            low = mid + 1;
        }
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
