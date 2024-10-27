#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int optimalMerge(vector<int> &files)
{

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int file : files)
    {
        minHeap.push(file);
    }

    int totalCost = 0;

    while (minHeap.size() > 1)
    {

        int file1 = minHeap.top();
        minHeap.pop();
        int file2 = minHeap.top();
        minHeap.pop();

        int mergeCost = file1 + file2;
        totalCost += mergeCost;

        minHeap.push(mergeCost);

        cout << "Merged files with sizes " << file1 << " and " << file2 << " => New file size: " << mergeCost << endl;
    }

    return totalCost;
}

int main()
{
    vector<int> files = {100, 250, 50, 400};

    int result = optimalMerge(files);

    cout << "Minimum cost of merging files: " << result << endl;

    return 0;
}
