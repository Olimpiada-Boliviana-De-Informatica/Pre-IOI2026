#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define hash long long
#define ii pair<int,int>
#define vi vector<int>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define all(v) (v).begin(),(v).end()
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define DBG(x) cerr << #x << " = " << (x) << endl
#define F first
#define S second
#define pb push_back
#define pf push_front
#define mp make_pair
#define el "\n"

void solve(){
    ll x, y; cin>>x>>y;
    ll v = 0;
    if(x < y){
        v = y * y;
        if(y%2 == 0) {
            v = v - 2 * y + 2;
            x--;
            cout<<v + x<<el;
        }
        else {
            x--;
            cout<<v - x<<el;
        }
    }
    else {
        v = x * x;
        if(x%2 == 0) {
            y--;
            cout<<v - y<<el;
        }
        else {
            v = v - 2 * x + 2;
            y--;
            cout<<v + y<<el;
        }
    }
    
    
}

int main(){
    FastIO;
    int t; cin>>t;
    while(t--) 
}