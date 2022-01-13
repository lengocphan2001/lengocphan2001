#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define Fi(a,n) for(int i = a; i < n; i++)
#define Fd(n,a) for(int i = n; i >= a; i--)
#define all(a) a.begin(), a.end()
#define pb push_back

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), b;
    map<ll, int> cur;
    Fi(0, n)
    {
        cin >> a[i];
        cur[a[i]] = i;
    }
    int ans = 1;
    b = a;
    sort(all(b));
    for (int i = 0; i<n-1; i++)
    {
        if (cur[b[i+1]] - cur[b[i]] != 1)
            ans++;

    }
    if (ans <= k)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}
