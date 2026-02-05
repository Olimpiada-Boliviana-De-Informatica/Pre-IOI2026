#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define forit(i, str) for(auto i = str.begin(); i != str.end(); i++)
#define dbg(x) cerr << #x << " = " << (x) << endl
#define all(v) (v).begin(),(v).end()
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long 
#define ii pair<int,int>
#define vi vector<int>
#define F first
#define S second
#define pb push_back
#define pf push_front
#define mp make_pair
#define el "\n"
using namespace std;
ll gcd(ll a, ll b) {
	while(b) { ll t = a%b; a = b; b = t; }
	return a;
}
ll lcm(ll a, ll b) {
	if(a == 0 or b == 0) return 0;
	ll g = gcd(a, b);
	return (a/g) * b;
}

void solve(){
    int n; cin>>n;
    vi weeks;
    forn(i, n) {
        int sum = 0;
        forn(j, 7) {
            int a; cin>>a;
            sum += a;
        }
        weeks.pb(sum);
    }

    forn(i, n) cout<<weeks[i]<<" \n"[i + 1 == n];
}
int main(){
    FastIO;
    int t = 1; 
    // int t; cin>>t;
    while(t--) solve();
}