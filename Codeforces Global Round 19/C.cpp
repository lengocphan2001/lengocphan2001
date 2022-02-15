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
    int n;
    cin >> n;
    vector<int> a(n);
    read(a);
    int tmp = 0;
    if (n == 3 && a[1] & 1){
    	cout << -1 << endl;
    	return;
    }
    for (int i = 1; i<n-1; i++){
    	if (a[i] <= 1){
    		tmp++;
    	}
    }
    if (tmp % 2 == 1){
    	cout << -1 << endl;
    	return;	
    }
	ll ans = 0;
	bool check = true;
	for (int i = 1; i<n - 1; i++){
		if (a[i] <= 1){
			
		}else check = true;
		ans += (a[i] + 1)/2;
	}
	if(!check){
		cout << -1 << endl;
		return;
	}
	cout << ans << endl;
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