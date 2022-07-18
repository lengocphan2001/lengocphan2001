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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	read(a);
	sort(all(a));
	if (k > a.back() || (k == a.back() && k == a[0]) || n == 1){
		cout << 0 << endl;
		return;
	}
	if (k == a.back()){
		cout << 1 << endl;
		return;
	}
	if (k == a[0]){
		cout << a.back()/k - 1 << endl;
		return;
	}
	vector<set<int>> t(n);
	for (int i = 0; i<n; i++){
		for (int j = 1; j <= k; j++){
			t[i].insert(a[i]/j);
		}
	}
	int temp = INT_MAX;
	int mi, mx;
	for (auto i: t[0]){
		for (auto j: t[1]){
			int c = abs(i - j);
			if (temp > c){
				temp = c;
				mi = i;
				mx = j;
			}
		}
	}
	if (mi > mx) swap(mi, mx); 
	cout << "Min max: " << mi << " " << mx << endl;
	set<int> cur = {mi, mx};
	for (int i = 2; i<n; i++){
		auto it = t[i].upper_bound(mi);
		auto it2 = t[i].upper_bound(mx);
		cout << "I: " << i << endl;
		for (auto it: t[i]){
			cout << it << " ";
		}
		cout << endl;
		if (it == t[i].end() || it2 == t[i].end()) cur.insert(*--t[i].end());
		else{
			cur.insert(min(*it, *it2));
		}
		cout << "Set" << endl;
		for (auto i: cur) cout << i << " ";
		cout << endl;
 	}
 	auto it = --cur.end();
	cout << "Ans: " << *it - *cur.begin() << endl; 
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