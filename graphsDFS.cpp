#include<iostream>
#include<vector>

using namespace std;

void print(int **edges, int n, int sv, bool *visited){
    // sv = starting vertex
    cout<< sv << endl;
    visited[sv] = true;
    for(int i = 0; i < n;i++){
        if(visited[i] or i == sv){
            continue;
        }
        else if(edges[sv][i]){
            print(edges, n, i, visited);
        }
    }
}

int has_path(int **edges, int n, int sv,int ev, bool *visited){
    if(sv == ev){return 1;}
    visited[sv] == 1;

    int x = 0;
    for(int i = 0;i < n; i++){
        if(i == sv or visited[i]){ continue; }
        if(edges[sv][i] == 1){
            x += has_path(edges, n, i, ev, visited);
        }
        if(x){ break;}
    }
    return x;
}

void printDFS(int **edges, int n){
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                print(edges, n, i, visited);
            }
        }
    delete[] visited;
}

vector<int> paths;
vector<int> getPath(int **edges, int n, int sv, int ev, bool *visited){
    if(sv == ev){
        paths.push_back(ev);
        paths.push_back(sv);
        return paths;
    }
    visited[sv];
    for(int i = 0; i < n; i++){
        if(i == sv or visited[i]){continue;}
        if(edges[sv][i] == 1){
            vector<int> path = getPath(edges, n, i, ev, visited);
            if(path.size()){
                paths.push_back(i);
                break;
            }
        }
    }
}

int main(){
    int n;
    int e;
    cin>> n >> e;
    int **edges = new int*[n];
    for(int i = 0; i<n;i++){
        edges[i] = new int[n];
        for(int j = 0;j<n;j++){
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++){
        int f,s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    // print(edges, n, 0, visited);
    // printDFS(edges, n);

    bool *visited = new bool[n];
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }
    // bool x = has_path(edges, n, 0, 4, visited);
    // cout<<x<<endl;

    // vector<int> path = getPath(edges, n, 0, 4, visited);
    for(int i = 0; i < paths.size(); i++){
        cout<<paths.at(i)<<"->";
    }
    //deleting all the memory
    for(int i = 0; i < n; i++){
        delete[] edges[i];
    }
    delete[] edges;
    delete[] visited;
}
