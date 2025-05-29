#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int h){
    int pivot = arr[l];
    int i = l;
    int j = h;

    while(i < j){
        do {
            i++;
        } while(i <= h && arr[i] <= pivot);

        do {
            j--;
        } while(j >= l && arr[j] > pivot);

        if(i < j){
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[l], &arr[j]);
    return j;
}

void quicksort(int arr[], int l, int h){
    if(l < h){
        int j = partition(arr, l, h);
        quicksort(arr, l, j);
        quicksort(arr, j + 1, h);
    }
}

int main() {
    int arr[8] = {1, 5, 9, 4, 2, 8, 6, 7};
    int n = 8;

    quicksort(arr, 0, n - 1); 

    printf("Sorted:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}
