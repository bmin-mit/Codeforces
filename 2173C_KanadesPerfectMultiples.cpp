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
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (auto &elem : arr)
        cin >> elem;
    set<int> values(arr.begin(), arr.end());
    set<int> appear(arr.begin(), arr.end());

    sort(arr.begin(), arr.end());

    vector<int> result;
    for (auto elem : arr)
    {
        if (values.find(elem) == values.end())
            continue;

        result.push_back(elem);
        int curr = elem;

        while (curr <= k)
        {
            if (appear.find(curr) == appear.end())
            {
                cout << -1 << endl;
                return;
            }

            values.erase(curr);
            curr += elem;
        }
    }

    cout << result.size() << endl;
    for (auto &elem : result)
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
