#include <iostream>
#include<vector>
#include<queue>
using namespace std;
void printpath(vector<int>& path)
{
    int size = path.size();
    for (int i = 0; i < size; i++)
        cout << path[i] << " ";
    cout << endl;
}
int isNotVisited(int x, vector<int>& path)
{
    int size = path.size();
    for (int i = 0; i < size; i++)
        if (path[i] == x)
            return 0;
    return 1;
}
void findpaths(vector<vector<int> >&g, int src, int dst, int v)
{
    queue<vector<int> > q;
    vector<int> path;
    path.push_back(src);
    q.push(path);
    while (!q.empty()) {
        path = q.front();
        q.pop();
        int last = path[path.size() - 1];
        if (last == dst)
            printpath(path);
        for (int i = 0; i < g[last].size(); i++) {
            if (isNotVisited(g[last][i], path)) {
                vector<int> newpath(path);
                newpath.push_back(g[last][i]);
                q.push(newpath);
            }
        }
    }
}
int main()
{
    vector<vector<int> > g;
    cout<<"Enter the number of vertices \n";
    int v;
    cin>>v;
    g.resize(v);
    int n;
    cout<<"Enter the number of pairs\n";
    cin>>n;
    int v1,v2;
    cout<<"Enter vertices\n";
    for(int i=0;i<n;i++)
    {
        cin>>v1>>v2;
        g[v1].push_back(v2);
    }
    int src,dst;
    cout<<"Enter the  source and destination \n";
    cin>>src>>dst;
    cout << "path from src " << src << " to dst " << dst << " are \n";
    findpaths(g, src, dst, v);
    return 0;
}
