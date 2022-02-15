#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define Fi(a, n) for (int i = a; i < n; i++)
#define Fd(n, a) for (int i = n; i >= a; i--)
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#define pb push_back
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define read(a) for (int i = 0; i<sz(a); i++) cin >> a[i]
const ll mod = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    read(a);
    vector<pair<int, int>> cur(n);
    for (int i = 0; i < n; i++)
    {
        cur[i].ff = a[i];
        cur[i].ss = i;
    }
    sort(all(cur));
    vector<bool> visit(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (visit[i] || cur[i].ss == i)
            continue;
        int res = 0;
        int j = i;
        while (!visit[j])
        {
            visit[j] = 1;
            j = cur[j].ss;
            res++;
        }
        if (res > 0)
        {
            ans += (res - 1);
        }
    }
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}