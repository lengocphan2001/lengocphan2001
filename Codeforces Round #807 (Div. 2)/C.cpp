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
const string h[16] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
const ll mod = 1e9 + 7;
const ll module = 998244353;
void solve()
{
	int n, c, q;
	cin >> n >> c >> q;
	string s;
	cin >> s;
	vector<pair<int, int>> a(c);
	vector<pair<ll, int>> temp;
	int current = 0;
	for (int i = 0; i<c; i++){
		cin >> a[i].ff >> a[i].ss;
		a[i].ff--;
		a[i].ss--;
		temp.pb({a[i].ss - a[i].ff + current + 1, i});
		current = temp.back().ff;
	}
	for (auto i: temp) cout << i.ff << " ";
	cout << endl;
	while(q--){
		ll t;
		cin >> t;
		t--;
		if (t <= temp[0].ff){
			cout << s[a[0].ff + t] << endl;
		}else{
			// int l = 0, r = sz(temp) - 1;
			// while(l < r){
			// 	int mid = (l + r)/2;
			// 	if (temp[mid].ff > t){
			// 		r = mid - 1;
			// 	}else l = mid + 1;
			// }
			// if (l >= sz(temp)) l--;
			// cout << "L: " << l << endl;
			// cout << "temp[l]" << " " << temp[l].ff << endl;
			// int cu = a[l].ff + (t - temp[l].ff) - 2;
			// cout << "Cu: " << cu << endl;
			// cout << "Ans: " << s[cu] << endl;
		}
	}
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