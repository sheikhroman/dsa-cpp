#include<bits/stdc++.h>
using namespace std;

// class for graph
typedef pair<int,int> edgeWeightPair;




class Graph{
    int V;
    list<edgeWeightPair> *adj;
public:
    Graph(int V){
        this->V = V;
        adj = new list<edgeWeightPair>[V];
    }
    void addEdge(int u,int v,int w){
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    void printEdge(int chk){
        cout<<chk<<". ";
        for(auto it = adj[chk].begin(); it != adj[chk].end();it++){
            cout<<"("<<(*it).first<<","<<(*it).second<<")";
            auto k = it;
            if(++k != adj[chk].end()){
                cout<<"->";
            }
        }
        cout<<endl;
    }

};


// V => Vertex/Node
// E => Edge


int main(){
    int V,E;
    cin>>V>>E;
    Graph g(V);
    for(int i=0;i<E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g.addEdge(u,v,w);
    }
    for(int i=0;i<V;i++){
        g.printEdge(i);
    }
    return 0;
}

/*
Bi directional weighted graph
input:
7 10
0 1 7
0 2 1
0 5 3
1 3 11
2 3 3
2 5 8
3 6 1
6 5 2
6 4 4
5 4 6


output:
0. (1,7)->(2,1)->(5,3)
1. (0,7)->(3,11)
2. (0,1)->(3,3)->(5,8)
3. (1,11)->(2,3)->(6,1)
4. (6,4)->(5,4)
5. (0,3)->(2,8)->(6,2)->(4,4)
6. (3,1)->(5,2)->(4,4)

*/
