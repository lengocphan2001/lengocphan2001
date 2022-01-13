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
    ll n, s, sum = 0;
    cin >> n >> s;
    vector<ll> a(n);
    Fi(0, n) {
        cin >> a[i];
        sum+=a[i];
    }
    if (sum > s)
        cout << 0;
    else{
        if (sum == s)
            cout << 1;
        else{

        }
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
