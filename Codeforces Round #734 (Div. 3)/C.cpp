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
    int n, k, c = 0;
    cin >> n >> k;
    vector<int> a(n), cur(n+1, 0), ans(n, 0);
    vector<pair<int, int>> tmp(n);
    Fi(0, n)
    {
        cin >> a[i];
        cur[a[i]]++;
        tmp[i] = {a[i], i};
    }
    for (int i = 0; i<n; i++){
        c+=min(cur[a[i]], k);
        cur[a[i]] = 0;
    }
    c/=k;
    sort(all(tmp));
    int dem = 1, cur1 = 1;
    for (int i = 0; i<n; i++){
        if(cur[tmp[i].ff] <= k){
            if(dem > k){
                cur1++;
                dem = 1;
            }
            if (cur1 <= c){
                ans[tmp[i].ss] = dem;
                dem++;
            }
        }else{
            cur[tmp[i].ff]--;
        }
    }
    for (int i = 0; i<n; i++)
        cout << ans[i] << ' ';
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}
