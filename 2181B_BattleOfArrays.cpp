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

void playTurn(priority_queue<int> &a, priority_queue<int> &b)
{
    if (a.top() < b.top())
    {
        int oppoVal = b.top();
        b.pop();
        b.push(oppoVal - a.top());
    }
    else
        b.pop();
}

void solve()
{
    int n, m;
    cin >> n >> m;

    priority_queue<int> a, b;
    for (int i = 0; i < n; ++i)
    {
        int v;
        cin >> v;
        a.push(v);
    }

    for (int i = 0; i < m; ++i)
    {
        int v;
        cin >> v;
        b.push(v);
    }

    bool turn = true;
    while (a.size() && b.size())
    {
        if (turn)
            playTurn(a, b);
        else
            playTurn(b, a);

        turn = !turn;
    }

    cout << IF(a.size(), "Alice", "Bob") << endl;
}

signed main()
{
    FAST_IO;

    MULTI
    solve();

    return 0;
}
