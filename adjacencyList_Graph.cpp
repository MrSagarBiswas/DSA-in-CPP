#include <iostream>
#include <queue>
using namespace std;

void addEdge(vector<int> adj[], int v1, int v2)
{
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
}

void Print(vector<int> adj[], int v)
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

void BFSCall(vector<int> adj[], int s, bool visited[])
{
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        cout << temp << " ";
        for (int v: adj[temp])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

int BFS(vector<int> adj[], int v){
    bool visited[v]= {0};

    int connectedComponents = 0;
    for(int i=0; i<v; i++){
        if(visited[i]==0){
            connectedComponents++;
            BFSCall(adj, i, visited);
        }
    }
    return connectedComponents;
}

void DFSRec(vector<int> adj[], int s, bool visited[]){
    cout<<s<<" ";
    visited[s]=1;
    for(int u: adj[s]){
        if(visited[u]==false)
        DFSRec(adj, u, visited);
    }
}

int DFS(vector<int> adj[], int v){
    bool visited[v]= {0};
    int connectedComponents = 0;
    for(int i=0; i<v; i++){
        if(visited[i]==false){
            connectedComponents++;
            DFSRec(adj, i, visited);
        }
    }
    return connectedComponents;
}

int main()
{
    int v = 6;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 5);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 5);

    int ccBFS = BFS(adj, v);
    cout<<endl<<ccBFS<<endl;

    int ccDFS = DFS(adj, v);
    cout<<endl<<ccDFS<<endl;

    return 0;
}