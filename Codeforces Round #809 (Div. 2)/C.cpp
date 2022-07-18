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
const string path = "123456789ABCDEF";
const string h[16] = {"0000", "0001", "0010", "0011", 
"0100", "0101", "0110", "0111", 
"1000", "1001", "1010", "1011", 
"1100", "1101", "1110", "1111"};
const ll mod = 1e9 + 7;
const ll module = 998244353;
bool can(vector<ll> &a, int n, ll mid){
	vector<bool> check(n, false);
	int t = 0;
	for (int i = 1; i<n - 1; i++){
		if (a[i] > a[i - 1] && a[i] > a[i + 1]){
			check[i] = true;
			check[i - 1] = true;
			check[i + 1] = true;
			t++;
		}
	}
	for (int i = 1; i<n; i++){
		if (!check[i] && !check[i - 1] && !check[i + 1]){
			mid -= max(a[i-1], a[i+1]) - a[i] + 1;
		}
	}
	return mid >= 0;
}
void solve()
{
	int n;
	cin >> n;
	vector<ll> a(n);
	read(a);
	ll l = 0, r = 1e9, ans = mod;
	while(l <= r){
		ll mid = (l + r)/2;
		if (can(a, n, mid)){
			r = mid - 1;
			ans = min(ans, mid);
		}else l = mid + 1;
	}
	cout << "Ans: " << ans << endl;
}	
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin); //file input.txt is opened in reading mode i.e "r"
		freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
	#endif
	int t;
	cin >> t;
	while(t--)
    	solve();
}