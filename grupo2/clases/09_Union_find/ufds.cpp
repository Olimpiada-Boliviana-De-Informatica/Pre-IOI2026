//Definir MAXN
int p[MAXN], rank[MAXN];
void initUF(){
    for(int i=0;i<MAXN;i++) p[i]=i, rank[i]=0;
}
int UFfind(int x){
    if(p[x]==x)return x;
    return p[x]=UFfind(p[x]);
}
void UFunion(int x, int y){
    x=UFfind(x);y=UFfind(y);
    if(x==y)return;
    if(rank[x]>rank[y])swap(x,y);
    p[x]=y;
    if(rank[x]==rank[y])rank[y]++;
}
