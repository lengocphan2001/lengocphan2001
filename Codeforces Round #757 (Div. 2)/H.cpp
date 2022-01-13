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
const ll mod = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].ss;
    for (int i = 0; i < n; i++)
        cin >> a[i].ff;
    sort(all(a));
    int i = 0, j = n - 1, ans = 1, times = 0;
    while (i < j)
    {
        if (a[i].ss + a[j].ss <= a[j].ff)
        {
            a[j].ss += a[i].ss;
            times += a[i].ss;
            a[i].ss = 0;
            i++;
        }
        else
        {
            times += a[j].ff - a[j].ss;
            a[i].ss -= (a[j].ff - a[j].ss);
            a[j].ss = a[j].ff;
            ans++;
            j--;
        }
    }
    cout << ans << " " << times;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}