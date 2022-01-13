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
    int n;
    cin >> n;
    vector<int64_t> a(n);
    Fi(0, n) cin >> a[i];
    int64_t ans = *min_element(all(a));
    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++)
            ans = min(ans, a[i]&a[j]);
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}
