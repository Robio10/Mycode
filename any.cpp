/*
        Function in my algorithm
        1. Make DFS Tree (T) rooted at dummy node.
        2. Disjoint set partition of DFS Tree (T).
        3. Make Subset of adjacent of every vertex.
        4. INFO function for giving information about DFS in path or Tree.
        5. ISROOT giving that is current node is root or not.
        6. PATHPARAM giving information about if current vertex is present in  path then end point of path.
        7. Query for nearest vertex.
        8. A node have poitner of path_param, root, parent, value, belons to tree or path.
*/

#include<bits/stdc++.h>
using namespace std;

int *parent;
bool *info;

class GRAPH{
	int V;
	list<int>*adj;
	//bool *info;
	void DFS_TREE(int , bool *);
	public:
		GRAPH(int);
		void addedge(int , int );
		void DFS(int);
		int root(int);
		void initializer();
};

GRAPH::GRAPH(int V){
	adj = new list<int>[V+1];
	parent = new int[V+1];
	info = new bool[V+1];
}

void GRAPH::initializer(){
	for(int i=0; i<=V; i++)
        parent[i] = 0;
	for(int i=0; i<=V; i++)
        info[i] = true;
}

void GRAPH::addedge(int a, int b){
	adj[a].push_back(b);
}

void GRAPH::DFS_TREE(int v, bool visit[]){
	visit[v] = true;
	cout<<v<<" ";
	list<int>::iterator it;
	for(it=adj[v].begin(); it!=adj[v].end(); it++){
		parent[*it] = v;
		if(!visit[*it])
			DFS_TREE(*it, visit);
	}
	//cout<<"\n";
}

void GRAPH::DFS(int v){
	bool *visit = new bool[V+1];
	for(int i=0;i<=V;i++)
		visit[i] = false;
	DFS_TREE(v, visit);
}

int GRAPH::root(int v){
	while(parent[v] != 0){
		v = parent[v];
	}
	return v;
}

int main(){
	freopen("ABCD.txt","r",stdin);
	int V,E;
	//cout<<"Enter number of vertex and edge \n";
	cout<<"Enter veter between [1,V] \n";
	cin>>V>>E;
	GRAPH G(V);
	G.initializer();
	cout<<"dfrf";
	for(int i=0;i<E;i++){
		int a,b;
		cin>>a>>b;
		G.addedge(a,b);
	}
	for(int i=0;i<V;i++)
		G.addedge(0,i+1);
	G.DFS(0);
	cout<<"Nahi \n";
	return 0;
}