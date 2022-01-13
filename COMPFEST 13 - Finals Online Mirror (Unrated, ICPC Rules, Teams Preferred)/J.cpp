#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define Fi(a,n) for(int i = a; i < n; i++)
#define Fd(n,a) for(int i = n; i >= a; i--)
#define all(a) a.begin(), a.end()
#define pb push_back
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
const ll mod = 1e9 + 7;
vector<int> prime(10e5+1, 1);
void prime(){
	for (int i = 2; i*i<=10e5+1; i++){
		if (prime[i] == 1){
			for (int j = i*i;j<=10e5+1; j+=i)
				prime[j] = i;
		}
	}
}	
void solve()
{
	int n;
	ll ans = 0;
	cin >> n;
	vector<int> a(n+1);
	Fi(1, n+1) cin >> a[i];
	for (int i = 1; i<n; i++){
		for (int j = i + 1; j<=n; j++){
			ll cur = (__gcd(a[i], a[j]) * __gcd(i, j));
			cout << cur << endl;
			ans+=cur;
		}
	}
	cout << ans;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	solve();
}