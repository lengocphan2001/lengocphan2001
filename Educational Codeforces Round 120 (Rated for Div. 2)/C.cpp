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
const ll mod = 100;
void solve()
{
    int n, t = 0;
    cin >> n;
    vector<int> a(n);
   	for (int i = 0; i<n; i++) {
   		cin >> a[i];
   		t = max(t, a[i]);
   	}
    vector<int> prime(t + 10, 1);
    prime[1] = 0;
    prime[0] = 0;
    for (int i = 2; i*i<=t; i++){
    	if (prime[i] == 1){
    		for (int j = i * i; j<=t; j+=i) prime[j] = 0;
     	}
    }
    int ans = 0;
    for (int i = 0; i<n; i++) if (prime[a[i]] == 1) ans++;
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
