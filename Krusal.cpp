#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct edge{
    int u,v; //u dinh dau, v dinh cuoi
    int w; //trong so cac canh
};

const int maxn = 1001; //so luong dinh max
int n, m;//so luong dinh, so luong canh cua do thi
int parent[maxn], sz[maxn]; // khai bao mang dung cho thuat toan DSU (Disjoint set union) - CHECK CHU TRINH
vector <edge> canh;

//thiet lap cau truc DSU
void make_set(){
    for(int i = 1; i<=n; i++){
        parent[i] = i;
        sz[i] = 1; //so luong cua i 
    }
}

int find(int v){
    if(v==parent[v]) return v;
    return parent[v] = find(parent[v]); // 
}

bool Union(int a, int b){
    //check co gop a va b vao voi nhau duoc khong
    a = find(a);
    b = find(b);
    if(a==b) return false; // cung tap hop, khong the goop a, b vao voi nhau
    if(sz[a]<sz[b]) swap(a,b);
    parent[b] = a;
    sz[a] +=sz[b];
    return true;
}

void input(){
    cin>>n>>m;
    for(int i = 0; i < m; i++){//duyet m canh
        int x, y, w; // x dinh dau, y dinh cuoi, w trong so
        cin>>x>>y>>w;
        edge e;
        e.u = x;
        e.v = y;
        e.w = w;
        canh.push_back(e);
    }
}

bool cmp (edge a, edge b){
    return a.w < b.w;
}
void kruskal(){
    //tao cay khung cuc tieu rong
    vector<edge> mst;
    int d = 0; // do trong so cua cay khung cuc tieu
    //sort danh sach canh theo chieu dai tang dan
    sort(canh.begin(), canh.end(), cmp);
    //Lap
    for(int i = 0; i<m; i++){
        if(mst.size() == n-1) break;
        edge e = canh[i]; //canh e la canh nho nhat trong vector canh
        if(Union(e.u, e.v)){
            mst.push_back(e);
            d += e.w;
        }
    }
    //tra ve ket qua
    if(mst.size()!= n-1){
        cout<< "KHONG TON TAI CAY KHUNG\n";
    }
    else{
        cout<<"MST:" << d << endl;
        for(auto it : mst){
            cout << it.u << " "<< it.v << " "<< it.w << endl; 
        }
    }
}
int main(){
    input();
    make_set();
    kruskal();
    return 0;
}