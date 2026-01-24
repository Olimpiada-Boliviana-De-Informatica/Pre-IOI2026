#include <bits/stdc++.h>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag,
// __gnu_pbds::tree_order_statistics_node_update > ordered_set;

// #include "debugging.h"

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define F first
#define S second
#define endl '\n'
#define FOR(i, x, y) for (int i = x; i < y; i++)
#define lcm(a, b) (a * b) / __gcd(a, b)
#define sqr(x) ((x) * (x))
#define cube(x) ((x) * (x) * (x))
#define dbg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename... Args>

#define show(v)                    \
    cerr << #v << ": " << v << " " \
         << "\n";
#define INT(n) \
    int n;     \
    cin >> n;
const ll INF = LLONG_MAX / 2;
const double PI = acos(-1);
const int MOD = 1e9 + 7;

void solve() {
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll a;
    cin >> a;
    if (400 % a == 0) {
        cout << 400 / a << endl;
    } else
        cout << -1 << endl;
    return 0;
}
