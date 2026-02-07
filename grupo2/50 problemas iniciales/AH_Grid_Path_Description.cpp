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

string temp;
int visCount = 1;
int total = 0;
bool vis[7][7];

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

ii moveCell(int r, int c, char ch) {
    if(ch == 'R') return ii(r, c + 1);
    if(ch == 'L') return ii(r, c - 1);
    if(ch == 'U') return ii(r - 1, c);
    if(ch == 'D') return ii(r + 1, c);
}

bool checkMove(int r, int c) {
    return (r >= 0 and r < 7 and c >= 0 and c < 7 and !vis[r][c]);
}

void backtrack(int r, int c, int pos) {
    if(r == 6 and c == 0) {
        if(visCount == 49) total++;
        return;
    }
    if((!checkMove(r + di[0], c) and !checkMove(r + di[2], c) and checkMove(r, c + dj[1]) and checkMove(r, c + dj[3])) or
        (checkMove(r + di[0], c) and checkMove(r + di[2], c) and !checkMove(r, c + dj[1]) and !checkMove(r, c + dj[3]))) {
        return;
    }


    if(temp[pos] != '?') {
        ii newCell = moveCell(r, c, temp[pos]);
        if(checkMove(newCell.F, newCell.S)) {
            vis[newCell.F][newCell.S] = true;
            visCount++;
            backtrack(newCell.F, newCell.S, pos + 1);
            vis[newCell.F][newCell.S] = false;
            visCount--;
        }
    } else {
        forn(i, 4) {
            int nr = r + di[i];
            int nc = c + dj[i];
            if(checkMove(nr, nc)) {
                vis[nr][nc] = true;
                visCount++;
                backtrack(nr, nc, pos + 1);
                vis[nr][nc] = false;
                visCount--;
            }
        }
    }
}

void solve(){
	cin>>temp;
    forn(i, 7) forn(j, 7) vis[i][j] = false;
    vis[0][0] = true;

    backtrack(0, 0, 0);
    cout<<total<<endl;
}
int main(){
    FastIO;
    int t = 1; 
    // int t; cin>>t;
    while(t--) solve();
}