#include <stdio.h>
#include <vector>
#include <utility>

#define MAX 1000

#define vi vector<int>
#define vpi vector<pair<int,int> >
#define pb push_back

using namespace std;

vpi adj[MAX]; 
vi tree;
bool visited[MAX];

void dfs(int v) {
	tree.pb(v);
	visited[v] = true;
	for(int i = 0 ; i < adj[v].size() ; i++)
		if(!visited[adj[v][i].first])
			dfs(adj[v][i].first);
}

int main() {

	//example
	adj[1].pb(make_pair(2,0));
	adj[2].pb(make_pair(3,1));
	adj[3].pb(make_pair(4,0));
	
	dfs(1);
	for(int i = 0 ; i < tree.size() ; i++)
		printf("%d ",tree[i]);
	
	printf("\n");
	return 0;
}
