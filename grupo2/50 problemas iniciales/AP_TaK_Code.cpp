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
vector<string> r = {"###.?????", "###.?????", "###.?????", "....?????", "?????????",
                    "?????....", "?????.###", "?????.###", "?????.###"};
vector<vector<char>> mapa(105, vector<char>(105, '?'));

bool checkRegion(int x, int y) {
    bool flag = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (mapa[i + x][j + y] != '#')
                flag = false;
        }
    }
    if (mapa[x + 3][y] != '.')
        flag = false;
    if (mapa[x + 3][y + 1] != '.')
        flag = false;
    if (mapa[x + 3][y + 2] != '.')
        flag = false;
    if (mapa[x + 3][y + 3] != '.')
        flag = false;
    if (mapa[x + 2][y + 3] != '.')
        flag = false;
    if (mapa[x + 1][y + 3] != '.')
        flag = false;
    if (mapa[x][y + 3] != '.')
        flag = false;

    for (int i = 6; i < 9; i++) {
        for (int j = 6; j < 9; j++) {
            if (mapa[i + x][j + y] != '#')
                flag = false;
        }
    }
    if (mapa[x + 5][y + 5] != '.')
        flag = false;
    if (mapa[x + 5][y + 6] != '.')
        flag = false;
    if (mapa[x + 5][y + 7] != '.')
        flag = false;
    if (mapa[x + 5][y + 8] != '.')
        flag = false;
    if (mapa[x + 6][y + 5] != '.')
        flag = false;
    if (mapa[x + 7][y + 5] != '.')
        flag = false;
    if (mapa[x + 8][y + 5] != '.')
        flag = false;
    return flag;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mapa[i][j];
        }
    }

    ll count = 0;
    for (int i = 0; i < n - 8; i++) {
        for (int j = 0; j < m - 8; j++) {
            if (checkRegion(i, j)) {
                cout << i + 1 << " " << j + 1 << endl;
            }
        }
    }
    return 0;
}
