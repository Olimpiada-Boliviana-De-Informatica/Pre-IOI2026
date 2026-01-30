#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
using namespace std;

//para entrada y salida de datos en sublime(ignorar si usas otra IDE)
void init_code(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif 
}

//global
const int N = 100+10;
vector<int> G[N]; // matriz o vector de vectores, lista de adyacencia
bool vis[N]; //visitados 0--> no esta visitado, 1--> si fue visitado   0/1

//DFS

void dfs(int node){
    vis[node] = true; //true == 1 / false == 0
    for (int i = 0; i < G[node].size(); ++i)
    {
        int v = G[node][i];//vecino
        if(vis[v] == false){
            dfs(v); // vamos a visitar v, recursivamente
        }
    }
}

void bfs(int node){
    queue<int> q;//cola
    q.push(node);
    vis[node] = true;
    while(!q.empty()){
        int v = q.front();//sacar el primero de la cola
        q.pop(); //eliminar el primero de la cola
        for (int i = 0; i < G[v].size(); ++i)
        {
            int u = G[v][i];//amigo
            if(vis[u] == false){
                vis[u] = true;
                q.push(u);//pendiente pa despues
            }
        }

    }
}


int main() {
    init_code();//para la lectura de datos en sublime;
    ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
     
    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; ++i)
        {
            int u, v;
            cin >> u >> v;
            G[u].pb(v);
            G[v].pb(u);
        }
        int X , Y;
        cin >> X >> Y;
        // dfs(X); //dfs desde x
        bfs(X);//bfs desde x
        //el chisme llego al amigo Y?
        if(vis[Y] == true){
            cout << "SI\n";
        }
        else{
            cout << "NO\n";
        }
    }


    return 0;
}
