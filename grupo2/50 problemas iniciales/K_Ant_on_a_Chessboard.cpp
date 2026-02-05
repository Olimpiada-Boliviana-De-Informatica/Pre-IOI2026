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
int main(){
    // Sacar la capa con raiz
    // ver de donde finaliza, depende si la raiz es par o impar, si estamos en columna o fila
    // sacar la distancia con el ultimo valor de la capa d = up^2 - v
    // si d <= up calcular fila o columna depende del caso
    // si no swap fila y columna d -= up y calcular el opuesto

    FastIO;
    while(true) {
        int n; cin>>n;
        if(n == 0) break;

        int up = sqrt(n);
        if(up * up < n) up++;

        int x = 1, y = 1;
        if(up%2 == 1) {
            y = up;
        } else {
            x = up;
        }

        int d = up * up - n;
        if(d < up) {
            if(up%2 == 1) x += d;
            else y += d;
        } else {
            x = y = up;
            d -= up - 1;
            if(up%2 == 1) {
                y -= d;
            } else x -= d;
        }

        cout<<x<<" "<<y<<endl;
    }
}