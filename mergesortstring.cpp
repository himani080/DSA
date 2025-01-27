// #include<iostream>

// using namespace std;

// void swap(int *a, int *b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// int partition(int start, int end, int arr[]) {
//     int pivot = arr[start];
//     int count = 0;
//     for (int i = start + 1; i <= end; i++) {
//         if (arr[i] < pivot) {
//             count++;
//         }
//     }
//     int pivotindex = start + count;
//     swap(&arr[start], &arr[pivotindex]);

//     int i = start;
//     int j = end;
//     while (i < pivotindex && j > pivotindex) {
//         while (arr[i] < pivot) {
//             i++;
//         }
//         while (arr[j] > pivot) {
//             j--;
//         }
//         if (arr[i] <= pivot && arr[j] > pivot) {
//             swap(&arr[i++], &arr[j--]);
//         }
//     }
//     return pivotindex;
// }

// void quicksort(int start, int end, int arr[]) {
//     if (start >= end) {
//         return;
//     }
//     int pivotindex = partition(start, end, arr);

//     // Print array after each partition (each pass)
//     cout << "Pass: ";
//     for (int i = 0; i <= end; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     quicksort(start, pivotindex - 1, arr);
//     quicksort(pivotindex + 1, end, arr);
// }

// int main() {
//     int n;
//     cout << "Enter size of array: ";
//     cin >> n;
//     cout << "Enter elements of array: ";
//     int arr[n];
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     quicksort(0, n - 1, arr);

//     cout << "Sorted array: ";
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Edge {
    int src, dest, weight;
};
bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}
void kruskalMST(vector<Edge>& edges, int n) {
  
    sort(edges.begin(), edges.end(), compareEdges);

    vector<vector<int> > adjMatrix(n, vector<int>(n, 0));

    int totalCost = 0;
    vector<pair<int, int> > mstEdges; 

    for (size_t i = 0; i < edges.size(); i++) {
        int src = edges[i].src;
        int dest = edges[i].dest;
        int weight = edges[i].weight;

        if (adjMatrix[src][dest] == 0 && adjMatrix[dest][src] == 0) {
            adjMatrix[src][dest] = weight;
            adjMatrix[dest][src] = weight; 
            mstEdges.push_back({src, dest});
            totalCost += weight;
        }
    }

    cout << "Edge \tWeight\n";
    for (size_t i = 0; i < mstEdges.size(); i++) {
        cout << mstEdges[i].first << " - " << mstEdges[i].second << "\t" 
             << adjMatrix[mstEdges[i].first][mstEdges[i].second] << "\n";
    }

    cout << "\nTotal cost of MST: " << totalCost << endl;
}

int main() {
    int n = 5; 

    vector<Edge> edges;
    edges.push_back(Edge{0, 1, 2});
    edges.push_back(Edge{0, 3, 6});
    edges.push_back(Edge{1, 2, 3});
    edges.push_back(Edge{1, 3, 8});
    edges.push_back(Edge{1, 4, 5});
    edges.push_back(Edge{2, 4, 7});
    edges.push_back(Edge{3, 4, 9});

    kruskalMST(edges, n);

    return 0;
}

{
  "model": "image-to-image",
  "input_data": {
    "image_url": "https://runwayml.com/assets/sample_image.jpg",
    "style": "vivid"
  }
}

{
  "status": "success",
  "generated_media_url": "https://runwayml.com/output/generated_media4567",
  "message": "Media generated successfully."
}



{
  "status": "success",
  "models": [
    {
      "model_id": "image-to-image",
      "description": "Transforms input images into new styles or variations."
    },
    {
      "model_id": "text-to-image",
      "description": "Generates images from textual descriptions."
    }
  ]
}



{
  "user_id": "user123",
  "media_url": "https://runwayml.com/output/generated_media4567",
  "media_name": "Vivid Landscape"
}


{
  "status": "success",
  "message": "Media saved successfully to your account."
}


{
  "genre": "chillwave",
  "mood": "relaxed",
  "duration": "3:30"
}


{
  "status": "success",
  "generated_music_url": "https://soundraw.io/output/musicTrack1234",
  "message": "Music track generated successfully."
}


{
  "status": "success",
  "genres": [
    {
      "genre_id": "chillwave",
      "description": "Relaxing and mellow electronic music with soft beats."
    },
    {
      "genre_id": "lo-fi",
      "description": "Low-fidelity music with a calming vibe."
    },
    {
      "genre_id": "pop",
      "description": "Upbeat and catchy music suited for mainstream audiences."
    }
  ]
}

{
  "user_id": "user456",
  "music_url": "https://soundraw.io/output/musicTrack1234",
  "music_name": "Chillwave Dream"
}


{
  "status": "success",
  "message": "Music saved successfully to your account."
}

