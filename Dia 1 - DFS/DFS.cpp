#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int MAXN = 100010;

struct par{
    int node1,node2;
};

vector<int> grafo[MAXN];
vector<int> resp;
vector<par> back_edges;
int marc[MAXN]{0}, prof[MAXN]{0}, pre[MAXN]{0}, low[MAXN]{0};
int t;

void dfs(int v, int pai){
    par duplas;
    marc[v] = 1;
    for(int i=0; i<grafo[v].size(); i++){
        int viz = grafo[v][i];
        if(marc[viz] == 0){
            prof[viz] = prof[v] + 1;
            dfs(viz, v);
        }
        else{
            if(viz != pai){
                duplas.node1 = v; duplas.node2 = viz;
                back_edges.push_back(duplas);
            }
        }
    }
}

int main(){
    int arestas, vertices, um, dois;
    cin >> arestas >> vertices;
    for(int i=0; i<arestas; i++){
        cin >> um >> dois;
        grafo[um].push_back(dois);
        grafo[dois].push_back(um);
    }
    dfs(0, -1);
    for(int i=0; i<back_edges.size(); i++){
        cout << back_edges[i].node1 << ", " << back_edges[i].node2 << endl;
    }
}

/*void bridges(int v, int pai){

}*/
