#include <iostream>
#include <forward_list>
#include <stack>
using namespace std;

int* grades;
int tick = 0;

void visit(int v, forward_list<int>* graph, int* disc, int* lows, bool* onStack, stack<int>* ancestors){
    ancestors -> push(v);
    onStack[v] = true;
    disc[v] = lows[v] = tick ++;
    
    for(auto adj : graph[v]){
        grades[v] = max(grades[v], grades[adj]);
        if(disc[adj] == -1){
            visit(adj, graph, disc, lows, onStack, ancestors);
            grades[v] = max(grades[v], grades[adj]);
        }
        if(onStack[adj]) {
            lows[v] = min(lows[v], lows[adj]);
        }
    }
    if(disc[v] == lows[v]){
        for(int anc = ancestors -> top();; anc = ancestors -> top()){
            ancestors -> pop();
            onStack[anc] = false;
            grades[anc] = grades[v] = max(grades[v], grades[anc]);
            if(anc == v) break;
        }
    }
}

void tarjan(int maxV, forward_list<int>* graph){
    int *disc = new int[maxV+1];       //stores the discovery time of each visited vertex
    int *lows = new int[maxV+1];       //earliest visited vertex reachable from subtree
    stack<int> ancestors;              //stacks all of the connected ancestors
    bool* onStack = new bool[maxV+1];
    
    for(int v = 1; v <= maxV; v++){
        disc[v] = lows[v] = -1;         //every vertex will be initialized with -1, so that we know it wasn't visited
        onStack[v] = false;
    }

    for(int v = 1; v <= maxV; v++){
        if(disc[v] == -1)
            visit(v, graph, disc, lows, onStack, &ancestors);
        printf("%d\n", grades[v]);
    }
    delete[] onStack;
    delete[] disc;
    delete[] lows;
}

int main(){

    int N; // total number of students
    int M;// total number of connections
    scanf("%d,%d", &N, &M);

    grades = new int[N+1];          //initial grades of the 1..N students
    for(int i=1; i <= N ; i++) {    //every index of the array grades[] represents a student's ID,
        scanf("%d", &grades[i]);    //therefore the index 0 will be ignored
    }
    
    forward_list<int> *connections = new forward_list<int>[N+1]; //connections[] stores all of the friendships between the students
    int u, v;
    for(int i=1; i <= M; i++){
        scanf("%d %d", &u, &v);       //student u has v as a friend
        connections[u].push_front(v); //each index stands for a student, which has a list of friends
    } 

    tarjan(N, connections);
    
    delete[] connections;
    delete[] grades;
    return 0;
}