#include <bits/stdc++.h>
using namespace std;

// #define int long long
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
    int n, m, h;
    cin >> n >> m >> h;

    vector<int> arr(n);
    for (auto &elem : arr)
        cin >> elem;
    queue<pair<int, int>> actions;

    while (m--)
    {
        int b, c;
        cin >> b >> c;

        arr[b - 1] += c;
        actions.push({b - 1, c});
        if (arr[b - 1] > h)
            while (actions.size())
            {
                arr[actions.front().first] -= actions.front().second;
                actions.pop();
            }
    }

    for (auto &elem : arr)
        cout << elem << ' ';
    cout << endl;
}

signed main()
{
    FAST_IO;

    MULTI
    solve();

    return 0;
}
