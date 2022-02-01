#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int n; // Число вершин
    int s; // Стартовая вершина (вершины везде нумеруются с нуля)
    int to; // Кратчайший путь до какой-то вершины to
    
    cin>> n >> s >> to;
    
    vector < vector <int> > g(n, vector <int> (n) );
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> g[i][j]; 
        }
    }
    
    
    // Сам обход
    queue<int> q;
    q.push (s);
    vector<bool> used (n);
    vector<int> d (n), p (n);
    used[s] = true;
    p[s] = -1;
    while (!q.empty()) 
    {
        int v = q.front();
        q.pop();
        for (size_t i=0; i<g[v].size(); ++i) 
        {
            int to = g[v][i];
            if (!used[to]) 
            {
                used[to] = true;
                q.push (to);
                d[to] = d[v] + 1;
                p[to] = v;
            }
        }
    }
    
    // вывести кратчайший путь до какой-то вершины to
    if (!used[to])
    {
        cout << "No path!";
    }
    else 
    {
        vector<int> path;
        for (int v=to; v!=-1; v=p[v])
        {
            path.push_back (v);
        }
        reverse (path.begin(), path.end());
        cout << "Path: ";
        for (size_t i=0; i<path.size(); ++i)
        {
            cout << path[i] + 1 << " ";
        }
    }
    
    return 0;
}
