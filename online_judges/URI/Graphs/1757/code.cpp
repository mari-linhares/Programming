#include <bits/stdc++.h>
#define MAX 110
#define pb push_back

using namespace std;

struct edge {
    int from, to, w;
    edge(int from=0,int to=0, int w=0){
        this->from = from;
        this->to = to;
        this->w = w;
    }

    bool operator < (const edge & e) const {
        return w < e.w;
    }
};

int dist[MAX][MAX];
vector<edge> e;
int uni[MAX], r[MAX];
void initUni() { for(int i = 0; i < MAX; i++){ uni[i] = i; r[i] = 0;} }
int findSet(int x) { return x == uni[x] ? x : uni[x] = findSet(uni[x]);}
bool connected(int x,int y) { return findSet(x) == findSet(y);}
void connect(int x, int y){
    if(r[x] < r[y]) uni[x] = y;
    else if(r[x] > r[y]) uni[y] = x;
    else { r[x]++; uni[y] = x;}
}

int kruskall() {

    sort(e.begin(),e.end());
    int ans = 0;
    for(int i = 0; i < e.size(); i++){
        int x = findSet(e[i].from);
        int y = findSet(e[i].to);
        if(!connected(x,y)){
            connect(x,y);
            ans += e[i].w;
        }
    }
    return ans;
}


int main() {

    int t,n,m,x,y;
    scanf("%d",&t);
    for(int i = 0; i < t; i++){
        scanf("%d %d",&n,&m);

        initUni();
        e.clear();
        memset(dist, 0, sizeof dist);

        for(int i = 0; i < m; i++){
            scanf("%d %d",&x,&y);
            dist[x][y] = 1;
            dist[y][x] = 1;
        }

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++)
                e.pb(edge(i,j,dist[i][j]));
        }

        printf("%d\n",kruskall());
    }
    return 0;
}
