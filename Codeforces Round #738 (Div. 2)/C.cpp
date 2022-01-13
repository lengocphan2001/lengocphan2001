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
    int n, ans = 0, l = 0;
    cin >> n;
    vector<int> a(n+1);
    Fi(1, n+1) {
        cin >> a[i];
        if (a[i] == 1) {
            ans++;
        }
        else l = max(l, i);
    }
    if (ans == n){
        cout << -1 << endl;
    }else{
        for (int i = 1; i<=l; i++)
            cout << i << " ";
        cout << n + 1 << " ";
        for (int j = l + 1; j<n+1; j++)
            cout << j << " ";
        cout << endl;
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}
