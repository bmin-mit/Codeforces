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
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &elem : arr)
        cin >> elem;

    sort(arr.begin(), arr.end());

    int segmentSize = 1;
    int maxSegmentSize = 1;
    for (int i = 1; i < n; ++i)
    {
        if (arr[i] == arr[i - 1])
            continue;

        if (arr[i] != arr[i - 1] + 1)
        {
            segmentSize = 1;
            continue;
        }

        segmentSize += 1;
        maxSegmentSize = max(maxSegmentSize, segmentSize);
    }

    cout << maxSegmentSize << endl;
}

signed main()
{
    FAST_IO;

    MULTI
    solve();

    return 0;
}
