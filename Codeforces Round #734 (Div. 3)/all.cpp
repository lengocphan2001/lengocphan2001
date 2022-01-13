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
    ll x, y, n;
    cin >> x >> y >> n;
    if (n % x == y){
        cout << n << endl;
    }else{
        ll cur = n/x;
        if (cur*x + y <= n)
            cout << cur*x + y << endl;
        else
            cout << (cur-1)*x + y << endl;
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
