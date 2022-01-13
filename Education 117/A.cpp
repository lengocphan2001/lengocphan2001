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
    ll k, x;
    cin >> k >> x;
    ll cur = (k * (k + 1)/2) + (k * (k - 1)/2);
    if (cur <= x){
    	cout << 2 * k - 1 << endl;
    }else{
    	ll i = 1, j = k;
    	ll ans = k;
    	while (i <= j){
    		ll mid = (i + j)/2;
    		if (mid * (mid + 1)/2 < x){
    			i = mid + 1;
    		}else{
    			ans = mid;
    			j = mid - 1;
    		}
    	}	
 	   	if (ans == k){
 	   		k--;
 	   		ll temp = (ans * (ans + 1)/2);
 	   		ll add = 1;
 	   		cur = k * (k + 1)/2;
 	   		i = 1, j = k;
 	   		while(i <= j){
 	   			ll mid = (i + j)/2;
 	   			if (temp + (cur - mid * (mid + 1)/2) < x){
 	   				j = mid - 1;
 	   			}else {
 	   				add = mid;
 	   				i = mid + 1;
 	   			}
 	   		}
 	   		cout << ans + (k - add) << endl;
 	   	}else cout << ans << endl;
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