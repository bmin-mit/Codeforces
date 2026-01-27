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
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> robots(n), spikes(m);
    for (auto &elem : robots)
        cin >> elem;
    for (auto &elem : spikes)
        cin >> elem;

    sort(robots.begin(), robots.end());
    sort(spikes.begin(), spikes.end());

    map<int, vector<int>> dist;
    int spikeUpper = 0;
    for (auto robot : robots)
    {
        while (spikeUpper < m && spikes[spikeUpper] < robot)
            ++spikeUpper;

        if (spikeUpper && spikes[spikeUpper - 1] < robot)
        {
            int lower = spikes[spikeUpper - 1];
            dist[lower - robot].push_back(robot);
        }

        if (spikeUpper < m)
        {
            int upper = spikes[spikeUpper];
            if (upper > robot)
                dist[upper - robot].push_back(robot);
        }
    }

    int delta = 0;
    set<int> remainingRobots(robots.begin(), robots.end());

    while (k--)
    {
        char direction;
        cin >> direction;

        delta += IF(direction == 'R', 1, -1);

        for (auto &dr : dist[delta])
            remainingRobots.erase(dr);
        dist[delta] = {};

        cout << remainingRobots.size() << ' ';
    }

    cout << endl;
}

signed main()
{
    FAST_IO;

    MULTI
    solve();

    return 0;
}
