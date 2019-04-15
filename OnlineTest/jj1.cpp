#include <bits/stdc++.h>
#include <math.h>
#include <set>
using namespace std;
#define N 1005
vector<int>G[N];
int f[N];

void dfs(int u,int fa) {
    int d=G[u].size();
    for(int i = 0;i<d;i++) {
        int v=G[u][i];
        if (v!=fa){
            dfs(v,f[v]=u);
        }
    }
}
int main() {
    int n;
    scanf("%d",&n);
    int root = 1;
  //  scanf("%d",&root);
    for(int i=0;i<n-1;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    f[root]=0;
    dfs(root,-1);
//    printf("%d",f[1]);
//    for(int i=2;i<=n;i++)
//        printf(" %d",f[i]);
    set<int> a;
    for(int i = 1; i<= n; i++)
    {
        a.insert(f[i]);
    }
    cout << a.size() << endl;
    return 0;
}
