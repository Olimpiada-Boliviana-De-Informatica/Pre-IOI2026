#include <iostream>
#include <vector>

using namespace std;

vector<long long> arr(200005);
vector<long long> st(4 * 200000 + 10);

void init(int node, int l, int r) {
    if (l == r) {
        st[node] = arr[l];
        return;
    }
    int izquierda = 2 * node + 1;
    int derecha = 2 * node + 2;
    init(izquierda, l, (l + r) / 2);
    init(derecha, (l + r) / 2 + 1, r);
    st[node] = st[izquierda] + st[derecha];
}

long long query(int node, int l, int r, int p, int q) {
    if (l >= p && r <= q)
        return st[node];
    if (l > q || r < p)
        return 0;
    int izquierda = 2 * node + 1;
    int derecha = 2 * node + 2;
    long long consulta_l = query(izquierda, l, (l + r) / 2, p, q);
    long long consulta_r = query(derecha, (l + r) / 2 + 1, r, p, q);
    return consulta_l + consulta_r;
}

void update(int node, int l, int r, int pos, long long val) {
    if (l == r && l == pos) {
        st[node] = val;
        arr[pos] = val;
        return;
    }
    if (l > pos || r < pos) {
        return;
    }
    int izquierda = 2 * node + 1;
    int derecha = 2 * node + 2;
    update(izquierda, l, (l + r) / 2, pos, val);
    update(derecha, (l + r) / 2 + 1, r, pos, val);
    st[node] = st[izquierda] + st[derecha];
}

int main() {
    int n, q;
    cin >> n;
    cin >> q;
    for (int a = 0; a < n; a++) {
        cin >> arr[a];
    }
    init(0, 0, n - 1);
    int consulta;
    int pos;
    long long val;
    int P, Q;
    while (q--) {
        cin >> consulta;
        if (consulta == 1) {
            cin >> pos >> val;
            update(0, 0, n - 1, pos - 1, val);
        } else {
            cin >> P >> Q;
            cout << query(0, 0, n - 1, P - 1, Q - 1) << endl;
        }
    }
    return 0;
}
