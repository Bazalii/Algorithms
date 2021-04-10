#include <stdio.h>
#include <malloc.h>

void swap(int *x, int *y) {
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;
}

void heapify(int *Array, int n, int i) {
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;
        if (l < n && Array[l] > Array[largest])
            largest = l;
        if (r < n && Array[r] > Array[largest])
            largest = r;
        if (largest != i) {
            swap(&Array[i], &Array[largest]);
            heapify(Array, n, largest);
        }
}

void heapSort(int  *Array, int n) {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(Array, n, i);
        for (int i=n-1; i>=0; i--) {
            swap(&Array[0], &Array[i]);
            heapify(Array, i, 0);
        }
}

int main() {
    int number, *Array_main, check = 0;
    FILE *fin, *fout;
    int Array[] = {17, 10, 12, 10, 1, 8, 3, 7, 4};
    fin = fopen("sort.in", "r");
    fout = fopen("sort.out", "w");
    fscanf(fin, "%d", &number);
    Array_main = (int *) malloc((number + 1) * sizeof(int));
    for (int i = 0; i < number; i++) {
        fscanf(fin, "%d", &Array_main[i]);
    }
    heapify(Array, 9 ,1);
    for (int i = 0; i < number; i++) {
        printf("%i ", Array[i]);
    }
    heapSort(Array_main, number);
    for (int i = 0; i < number; i++) {
        fprintf(fout,"%i ", Array_main[i]);
    }
    return 0;
}