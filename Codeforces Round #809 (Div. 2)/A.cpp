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
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	string s = string(m, 'B');
	read(a);
	for (int i = 0; i<n; i++){
		string temp = s;
		string cur = s;
		temp[a[i]-1] = 'A';
		cur[m - a[i]] = 'A';
		if (temp < cur) s = temp;
		else s = cur;
	}
	cout << s << endl;
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