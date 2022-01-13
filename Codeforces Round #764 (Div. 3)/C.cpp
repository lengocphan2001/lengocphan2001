
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
    vector<int> b = a;
    sort(all(b));
    if (b[0] == b[n-1]){
        cout << n - 1 << endl;
        return;
    }
    vector<vector<int>> cur(150100);
    for (int i = 0; i<n; i++){
        cur[a[i]].pb(i);
    }
    int ans = -1;
    for (int i = 0; i<n; i++){
        if (sz(cur[a[i]]) > 1){
            for (int k = 0; k<sz(cur[a[i]]) - 1; k++){
                int tmp = n - (cur[a[i]][k+1] - cur[a[i]][k]);
                ans = max(ans, tmp);
            }
            cur[a[i]].clear();
        }
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}