#include<iostream>
#include<vector>
using namespace std;

int count0(vector<int> arr){
    int count = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == 0) count++;
    }
    return count;
}

int count1(vector<int> arr){
    int count = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == 1) count++;
    }
    return count;
}

int count2(vector<int> arr){
    int count = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == 2) count++;
    }
    return count;
}

void sort012(vector<int>& arr){
    int countof0 = count0(arr);
    int countof1 = count1(arr);
    int countof2 = count2(arr);

    for(int i = 0; i < countof0; i++)
        arr[i] = 0;

    for(int i = countof0; i < countof0 + countof1; i++)
        arr[i] = 1;

    for(int i = countof0 + countof1; i < countof0 + countof1 + countof2; i++)
        arr[i] = 2;
}

int main(){
    int n, input;
    cout << "Enter size: ";
    cin >> n;

    vector<int> arr;
    for(int i = 0; i < n; i++){
        cin >> input;
        arr.push_back(input);
    }

    sort012(arr);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
