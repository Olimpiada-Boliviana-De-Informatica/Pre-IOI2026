// Enlace al problema: https://cses.fi/problemset/task/1648/
// Tutorial de CP-Algorithms: https://cp-algorithms.com/data_structures/segment_tree.html

#include <iostream>
#include <vector>

using namespace std;

vector<long long> arr(200005);
vector<long long> st(4 * 200000 + 10);

void init(int node, int l, int r) {
    if (l == r) {
        // Estoy en el nodo hoja, o sea el nodo que representa un solo elemento del arreglo
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
    if (l >= p && r <= q)  // Estoy completamente dentro del rango de consulta
        return st[node];
    if (l > q || r < p)  // Estoy completamente fuera del rango de consulta
        return 0;
    // Estoy parcialmente dentro del rango de consulta, tengo que consultar a mis hijos
    int izquierda = 2 * node + 1;
    int derecha = 2 * node + 2;
    long long consulta_l = query(izquierda, l, (l + r) / 2, p, q);
    long long consulta_r = query(derecha, (l + r) / 2 + 1, r, p, q);
    return consulta_l + consulta_r;
}

void update(int node, int l, int r, int pos, long long val) {
    if (l == r && l == pos) {
        // Estoy en el nodo hoja que representa el elemento que quiero actualizar
        st[node] = val;
        arr[pos] = val;
        return;
    }
    if (l > pos || r < pos) {
        // Estoy completamente fuera del rango del nodo, no tengo que actualizar nada, retorno algo
        // neutro, que no afecte a la consulta, en este caso como la consulta es una suma, el neutro
        // es el 0
        return;
    }
    // Estoy dentro del rango del nodo, pero no soy el nodo hoja que representa el elemento que
    // quiero actualizar, tengo que actualizar a mis hijos
    int izquierda = 2 * node + 1;
    int derecha = 2 * node + 2;
    update(izquierda, l, (l + r) / 2, pos, val);
    update(derecha, (l + r) / 2 + 1, r, pos, val);
    // Mis hijos ya están actualizados, ahora tengo que actualizar mi valor
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
