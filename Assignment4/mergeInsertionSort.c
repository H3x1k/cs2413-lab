#include <stdio.h>

void insertionSort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        for (int j = i; j > left && arr[j - 1] > arr[j]; j--) {
            int temp = arr[j - 1];
            arr[j -1] = arr[j];
            arr[j] = temp;
        } 
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeInsertionSortHelper(int arr[], int l, int r, int k) {
    if (r - l + 1 <= k) {
        insertionSort(arr, l, r);
        return;
    }
    int m = (l + r) / 2;
    mergeInsertionSortHelper(arr, l, m, k);
    mergeInsertionSortHelper(arr, m + 1, r, k);
    merge(arr, l, m, r);
}

void mergeInsertionSort(int arr[], int size, int k) {
    mergeInsertionSortHelper(arr, 0, size - 1, k);
}

void printArray(int arr[], int size) {
    printf("{");
    for (int i = 0; i < size; i++) {
        if (i == size - 1) printf("%d}", arr[i]);
        else printf("%d, ", arr[i]);
    }
}

int main() {
    int arr[] = {39, 9, 81, 45, 90, 27, 72, 18};
    printArray(arr, 8);
    printf("\n");
    mergeInsertionSort(arr, 8, 2);
    printArray(arr, 8);
    return 0;
}