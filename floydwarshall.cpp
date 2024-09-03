#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
using namespace std;

void floydwarshall(vector<vector<int>>& graph, vector<string>& locations, int V) {
    vector<vector<int>> dist = graph;

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    cout << " travel times" << endl;
    cout << setw(12) << " ";
    for (int i = 0; i < V; i++) {
        cout << setw(12) << locations[i];
    }
    cout << endl;

    for (int i = 0; i < V; i++) {
        cout << setw(12) << locations[i];
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX) {
                cout << setw(12) << "INF";
            } else {
                int minutes = dist[i][j] / 60;
                int seconds = dist[i][j] % 60;
                cout << setw(5) << minutes << "min " << setw(2) << seconds << "sec";
            }
        }
        cout << endl;
    }
}

int main() {
    int V = 5;
    vector<string> locations = {"sus", "mulshi", "pashan", "viman Nagar", "baner"};

    vector<vector<int>> graph = {
        {0, 243, INT_MAX, 300, INT_MAX},    
        {INT_MAX, 0, 60, INT_MAX, 360},      
        {120, INT_MAX, 0, 180, INT_MAX},     
        {INT_MAX, INT_MAX, 60, 0, 120},     
        {60, INT_MAX, INT_MAX, 240, 0}      
    };

    floydwarshall(graph, locations, V);
    return 0;
}
