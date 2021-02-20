#include<bits/stdc++.h>

#define int long long

using namespace std ;

const int INF = 1e9 + 7 ;

int32_t main()
{
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;

    int nodes, edges, start_point = 0, finish_point ;
    cin >> nodes >> edges ;
    finish_point = nodes - 1 ;
    vector< vector< pair<int, int> > > g(nodes) ;
    for(int i = 0 ; i < edges ; i ++ ){
        int x, y, cost ;
        cin >> x >> y >> cost ;
        x --, y -- ;
        g[x].push_back( make_pair(y, cost) ) ;
        g[y].push_back( make_pair(x, cost) ) ;
    }
    vector<int> distance(nodes, INF) , path(nodes);
    vector<bool> used(nodes) ;

    distance[start_point] = 0 ;

    for(int i = 0 ; i < nodes ; i ++ ){
        int v = -1 ;
        for(int j = 0 ; j < nodes ; j ++ ){
            if( !used[j] && (v == -1 || distance[j] < distance[v] ) ){
                v = j ;
            }
        }
        if( distance[v] == INF ){
            break ;
        }
        used[v] = true ;
        for(int j = 0 ; j < g[v].size() ; ++ j){
            int to = g[v][j].first , len = g[v][j].second ;
            if( distance[v] + len < distance[to] ){
                distance[to] = distance[v] + len ;
                path[to] = v ;
            }
        }
    }

    if( distance[finish_point] == INF ){
        cout << "There is no path :( " ;
    } else {
        vector<int> path_answer ;

        for(int v = nodes - 1 ; v != start_point ; v = path[v]){
            path_answer.push_back(v) ;
        }
        path_answer.push_back(start_point) ;

        reverse(path_answer.begin(), path_answer.end()) ;
        string ans = "" ;
        for(auto i : path_answer ){
            ans += to_string(i + 1) + ' ' ;
        }
        cout << ans ;
    }

    return 0 ;
}
