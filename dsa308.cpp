#include <bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int>> &dist) {
    int n=dist.size(), mod=1e8;
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dist[i][k] !=mod && dist[k][j] !=mod){
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    /*
    for(int i=0; i<n; i++){
	    if(dist[i][i]<0) "negative cycle"
    }
    */
}

