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
    string s;
    cin >> n >> s;

    int res = 0;
    int curr = 0;
    bool flag = true;
    for (auto c : s)
    {
        if (c == '0')
            ++curr;
        else
        {
            ++res;
            res += (curr + flag) / 3;
            flag = false;
            curr = 0;
        }
    }

    cout << res + (curr + flag + 1) / 3 << endl;
}

signed main()
{
    FAST_IO;

    MULTI
    solve();

    return 0;
}
