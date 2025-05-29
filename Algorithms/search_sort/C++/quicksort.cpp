#include <vector>

using namespace std;

void swap(vector<int>&, int, int);
int partition(vector<int>&, int, int);
void sort(vector<int>&, int, int);

void swap(vector<int> &arr, int left, int right){

    int t = arr[left];
    arr[left]  = arr[right];
    arr[right] = t;
}

int partition(vector<int> &arr, int left, int right){

    int pivot = arr[left];
    int ind = left;
    while(left < right){

        while(left < arr.size() && arr[left] <= pivot)
            ++left;
        while(arr[right] > pivot)
            --right;
        if(left < right){
            swap(arr, left, right);
        }
    }
    swap(arr, right, ind);
    return right;

}


void sort(vector<int> &arr, int left, int right){
    if(left < right){

        int p = partition(arr, left, right);
        sort(arr, p + 1, right);
        sort(arr, left, p - 1);
    }
}
