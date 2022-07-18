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
	int n;
	cin >> n;
	vector<int> a(n);
	read(a);
	int i = -1, j = n;
	for (int k = 0; k<n-1; k++){
		if (a[k] != 0){
		 	i = k;
		 	break;
		}
	}
	if (i == -1){
		cout << 0 << endl;
		return;
	}
	for (int k = n - 2; k>i; k--){
		if (a[k] != 0){
			j = k;
			break;
		} 
	}
	int ans = 0, zero = 0;
	for (int k = i; k<n-1; k++) if (a[k] == 0) zero++;
	for (int k = i; k<=j; k++){
		ans += a[k];
	}
	cout << ans + zero << endl;

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