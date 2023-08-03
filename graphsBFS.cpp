#include<iostream>
#include<queue>

using namespace std;

void print(int **edges, int n, int sv, bool *visited){
    queue<int> remaining;
    remaining.push(sv);
    visited[sv] = true;
    while(remaining.size() != 0){
        int front = remaining.front();
        remaining.pop();
        cout<<front<<endl;
        // visited[front] = true;
        for(int i = 0; i < n;i++){
            if(i == front){
                continue;
            }
            if(edges[front][i] == 1 && !visited[i]){
                remaining.push(i);
                visited[i] = true;
            }
        }
    }
}

// int has_path(int **edges, int n, int sv, int *visited){
//     if()
// }

void printBFS(int **edges, int n){
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            print(edges, n, i, visited);
        }
    }
    delete[] visited;
}

int main(){
    int n, e;
    cin>>n>>e;
    int **edges = new int*[n];
    for(int i = 0; i < n; i++){
        edges[i] = new int[n];
        for(int j = 0; j < n; j++){
            edges[i][j] = 0;
        }
    }
    for(int i = 0; i < e; i++){
        int f, s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    // print(edges, n, 0, visited);
    printBFS(edges, n);

    // bool x = has_path(edges, n, 0, visited);

    // deleting the memory
    for(int i = 0;i<n;i++){
        delete[] edges[i];
    }
    delete[] edges;
    return 0;
}
