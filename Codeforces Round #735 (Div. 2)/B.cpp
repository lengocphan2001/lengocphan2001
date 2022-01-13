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
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n+1);
    Fi(1, n+1) {
        cin >> a[i].ff;
        a[i].ss = i + 1;
    }
    sort(all(a));

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


