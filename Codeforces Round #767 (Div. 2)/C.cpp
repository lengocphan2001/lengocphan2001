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
    int n, q, x, y, x1, y1;
    cin >> n >> q;
    vector<string> a(n);
    read(a);
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = (a[0][0] == '*'? 1: 0);
    for (int i = 1; i < n; i++)
        dp[0][i] = dp[0][i-1] + (a[0][i] == '*'? 1: 0);
    for (int i = 1; i < n; i++)
        dp[i][0] = dp[i-1][0] + (a[i][0] == '*'? 1: 0);
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
                        - dp[i - 1][j - 1] + (a[i][j] == '*'? 1: 0);
    }
    for (int i = 0; i < q; i++) {
        cin >> x >> y >> x1 >> y1;
        x--;
        y--;
        x1--;
        y1--;
        int res = dp[x1][y1];
        if (x > 0)
            res = res - dp[x-1][y1];
        if (y > 0)
            res = res - dp[x1][y-1];
        if (x > 0 && y > 0)
            res = res + dp[x-1][y-1];
        cout << res << endl;
    }
    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}