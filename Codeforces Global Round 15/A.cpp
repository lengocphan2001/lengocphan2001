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
    int n, a, b;
    cin >> n >> a >> b;
    int cur = n / 2;
    if (a > b)
    {
        if (n - a == cur - 1 && b == a - 1)
        {
            for (int i = n; i >= 1; i--)
                cout << i << " ";
            cout << endl;
        }
        else
            cout << -1 << endl;
    }else{
        if ()
    }
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