#include <iostream>
#include <queue>
#include <forward_list>
#include <chrono>
using namespace std;
using namespace std::chrono;

forward_list <int> *manhattan;
int V;


bool bfs(int s, int t, int parent[]){
    
    bool visited[V];
    for(int i = 0; i < V; i ++){
        visited[i] = false;
    }

    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()){ 
        int u = q.front(); 
        q.pop(); 
        for (auto v : manhattan[u]) { 
            if (visited[v] == false) { 
                q.push(v); 
                parent[v] = u; 
                visited[v] = true; 
            } 
        }
    } 
    return (visited[t] == true);
}


int edmondsKarp(int s, int t){

    int max_flow = 0;
    int parent[V];
    int u = V;

    while(bfs(s, t, parent)){

        for (int v = t; v != s; v = parent[v]) { 
            u = parent[v]; 
            for(auto j : manhattan[u]){
                if (j == v){
                    manhattan[u].remove(j);
                    break;
                }      
            }

            manhattan[v].push_front(u);
        } 
        
        max_flow += 1;
    }
    
    return max_flow;
}

int main(){

    auto start = high_resolution_clock::now();

    int M; //total number of avenues
    int N; //total number of streets
    scanf("%d %d", &M, &N);

    V = 2*M*N+2;  //total number of vertices

    int S; //total number of supermarkets
    int C; //total number of citizens
    scanf("%d %d", &S, &C);


    manhattan = new forward_list<int> [V];

    for(int i = 0; i < V-2; i++){
        if(i%2 == 0){ //input edge
            manhattan[i].push_front(i + 1); 
        } 
        else{ //output edge
            if((i - N*2 -1) >= 0) manhattan[i].push_front(i - N*2 - 1); //top vertx
            if((i + N*2 -1) < V-2) manhattan[i].push_front(i + N*2 - 1);; //down vertex
            if((i+1)%(2*N) != 0) manhattan[i].push_front(i+1); //right vertex
            if((i-1)%(2*N) != 0) manhattan[i].push_front(i - 3); //left vertex
        }
    }

    int a, s;
    for(int i = 0; i < S; i++){
        scanf("%d %d", &a, &s);
        manhattan[((a-1)*N + (s-1))*2 + 1].push_front(V - 1);
    }

    for(int i = 0; i < C; i++){
        scanf("%d %d", &a, &s);
        manhattan[V-2].push_front(((a-1)*N + (s-1))*2);
    }

    int maxFlow = edmondsKarp(V-2, V-1);
    printf("%d\n", maxFlow);

    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    printf("Duration %ld microseconds\n", duration.count());
    
    delete[] manhattan;
}