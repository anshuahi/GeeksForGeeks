/*
GeeksForGeeks POTD:
    City With the Smallest Number of Neighbors at a Threshold Distance

POTD Link:
    https://www.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1

Approach:
    1. find shortest distance for each node, using dijkstra algorithm
    2. Finds the city with the minimum number of cities within the distance threshold and returns its index

*/

#define pii pair<int, int>
#define pb push_back
class Solution {
  public:
    // dijkstra's algorithm for shortest Path
    void dfsDijkstra(int idx, vector<vector<pii>> &gr, int distanceThreshold, vector<int> &dist){
        for(auto nbr: gr[idx]){
            int node = nbr.first, distance = nbr.second;
            if(dist[node] > distance + dist[idx] && distance + dist[idx] <= distanceThreshold){
                dist[node] = distance + dist[idx];
                dfsDijkstra(node, gr, distanceThreshold, dist);
            }
        }
    }
    
    int countVisitedCities(vector<int> &dist, int &distanceThreshold){
        int count = 0;
        for(auto d: dist){
            if(d <= distanceThreshold) count++;
        }
        return count;
    }

    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pii>> gr(n);
        for(auto edge: edges){
            gr[edge[0]].pb({edge[1], edge[2]});
            gr[edge[1]].pb({edge[0], edge[2]});
        }

        int minVisitedCity = n;
        int ans = 0;
        for(int node = 0; node < n; node++){

            vector<int> dist(n, INT_MAX);
            dist[node] = 0;
            dfsDijkstra(node, gr, distanceThreshold, dist);

            int count = countVisitedCities(dist, distanceThreshold);
            if(count <= minVisitedCity){
                minVisitedCity = count;
                ans = node;
            }
        }
        
        return ans;
    }
};