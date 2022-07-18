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
void solve()
{
	int n;
	cin >> n;
	vector<ll> a(n);
	read(a);
	map<ll, int> cur;
	vector<vector<int>> temp(n + 1, vector<int>());
	for (int i = 0; i<n; i++){
		cur[a[i]]++;
		temp[a[i]].pb(i);
	}
	for (int i = 1; i<=n; i++){
		if (cur[i] == 0){
			cout << 0 << " ";
		}else{
			int res = 1;
			for (int j = 1; j < sz(temp[i]); j++){
				if ((temp[i][j] - temp[i][j-1] + 1) % 2 == 0) res++;
			}
			cout << res << " ";
		}
	}
	cout << endl;
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