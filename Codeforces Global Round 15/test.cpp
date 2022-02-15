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
map<pair<int, int>, pair<pair<int, int>, int>> cur;
void merge(int x, int y, int x1, int y1, int dt){
	if ({x, y} ==  cur[{x,y}].ff){
		return;
	}else{
		cur[{x,y}]
	}
}
void solve()
{
    int n, m, q, type, x, y, x1, y1;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    for (int i = 0; i<n; i++){
    	for (int j = 0; j<m; j++) {
    		cin >> a[i][j];
    		cur[{i, j}] = {{i, j}, a[i][j]};
    	}
    }
	cin >> q;
	for (int i = 0; i<1; i++){
		cin >> type;
		if (type == 1){
			cin >> x >> y;
		}else{
			cin >> x >> y >> x1 >> y1;
		}
	}
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}