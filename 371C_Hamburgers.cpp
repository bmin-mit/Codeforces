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

int calcCost(int amount, array<int, 3> &require, array<int, 3> remaining, array<int, 3> prices)
{
    int totalCost = 0;
    for (int i = 0; i < 3; ++i)
    {
        int requireAmount = max(require[i] * amount - remaining[i], 0ll);
        totalCost += requireAmount * prices[i];
    }
    return totalCost;
}

void solve()
{
    string s;
    cin >> s;

    array<int, 3> require, remaining, prices;
    fill(require.begin(), require.end(), 0);

    for (auto c : s)
        switch (c)
        {
        case 'B':
            ++require[0];
            break;
        case 'S':
            ++require[1];
            break;
        default:
            ++require[2];
        }

    for (auto &elem : remaining)
        cin >> elem;
    for (auto &elem : prices)
        cin >> elem;

    int budget;
    cin >> budget;

    int low = 0;
    int high = 1e12 + 100;
    int res = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int cost = calcCost(mid, require, remaining, prices);
        if (cost <= budget)
        {
            res = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    cout << res << endl;
}

signed main()
{
    FAST_IO;

    // MULTI
    solve();

    return 0;
}
