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
int can(vector<int> &a, int n, int k){
	vector<vector<int>> t(n, vector<int>());
	for (int i = 0; i<k; i++){
		for (int j = 1; j <= k && a[i] >= j; j++){
			t[i].pb(a[i]/j);
		}
		sort(all(t[i]));
	}
	int mi = min(t[0].back(), t[1].back());
	set<int> cur = {t[0].back(), t[1].back()};
	for (int i = 2; i<n; i++){
		auto it = lower_bound(all(t[i]), mi);
		if (it == t[i].end()) cur.insert(t[i].back());
		else{
			cur.insert(*it);
		}
	}
	return *cur.end() - *cur.begin();
}
void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	read(a);
	sort(all(a));
	if (k < a.back() || (k == a.back() && k == a[0]) || n == 1){
		cout << 0 << endl;
		return;
	}
	if (k == a.back()){
		cout << 1 << endl;
		return;
	}
	if (k < a[0]){
		cout << a.back()/k - a[0]/k << endl;
		return;
	}else if (k == a[0]){
		cout << a.back()/k - 1 << endl;
		return;
	}
	cout << can(a, n, k) << endl;
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