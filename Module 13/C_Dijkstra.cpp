#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adj_list[100005];
long long int dis[100005];
int parent[100005];
bool vis[100005];

void dijkstra(int src)
{
    priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int>>,greater<pair<long long int,long long int>>> pq;
    pq.push({0,src});
    dis[src] = 0;
    while(!pq.empty())
    {
        pair<int,int> par = pq.top();
        pq.pop();
        int par_node = par.second;
        int par_dis = par.first;
        if(vis[par_node])
            continue;
        vis[par_node] = true;
        for(auto child : adj_list[par_node])
        {
            int child_node = child.first;
            int child_dis = child.second;
            if(par_dis + child_dis < dis[child_node])
            {
                dis[child_node] = par_dis + child_dis;
                pq.push({dis[child_node], child_node});
                parent[child_node] = par_node;
            }
        }
    }
}

int main()
{
    int n,e;
    cin >> n >> e;
    while(e--)
    {
        long long int a,b,c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b,c});
        adj_list[b].push_back({a,c});
    }
    for(int i=1;i<=n;i++)
    {
        dis[i] = LLONG_MAX;
        parent[i] = -1;
        vis[i] = false;
    }
    dijkstra(1);
    if(!vis[n])
        cout << -1 << endl;
    else
    {
        int node = n;
        vector<int> ans;
        while(parent[node] != -1)
        {
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(node);
        reverse(ans.begin(),ans.end());
        for(int x : ans)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}