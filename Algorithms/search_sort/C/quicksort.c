#include <stdio.h>
#include <stdlib.h>


int partition(int* arr, int left, int right, int len){
    int pivot = *(arr + left);
    int index = left;
    while(left < right){
        while(left < len && *(arr + left) <= pivot)
            ++left;
        while(*(arr + right) > pivot)
            --right;
        if(left < right){
            *(arr + left) += *(arr + right);
            *(arr + right) = *(arr + left) - *(arr + right);
            *(arr + left) -= *(arr + right);
        }
    }
    *(arr + index) += *(arr + right);
    *(arr + right) = *(arr + index) - *(arr + right);
    *(arr + index) = *(arr + index) - *(arr + right);
    return right;
}

void sort(int* arr, int left, int right , int len){
    if(left < right){
        int p = partition(arr, left, right, len);
        sort(arr, left, p - 1, len);
        sort(arr, p + 1, right, len);
    }
}

int main(){

    int *arr = malloc(10 * sizeof(int));
    for(int i = 0; i < 10; i++)
        scanf("%d", arr + i);
    sort(arr, 0, 9, 10);
    for(int i = 0; i < 10; i++)
        printf("%d ", *(arr + i));
    free(arr);
    return 0;
}
