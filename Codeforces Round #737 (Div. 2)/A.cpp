#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define Fi(a,n) for(int i = a; i < n; i++)
#define Fd(n,a) for(int i = n; i >= a; i--)
#define all(a) a.begin(), a.end()
#define pb push_back

void solve(){
    ll n, ans = 0, ans1 = 0;
    cin >> n;
    vector<ll> a(n);
    Fi(0, n) cin >> a[i];
    sort(all(a));
    for (int i = 0; i<n-1; i++)
        ans+=a[i];
    double cur = ans/(double)(n-1);
    cur += a[n-1];
    for (int i = 1; i<n; i++)
        ans1+=a[i];
    double cur1 = ans1/(double)(n-1);
    cur1 += a[0];
    cout <<setprecision(9) << fixed << max(cur, cur1) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}
