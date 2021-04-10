#include <stdio.h>
#include <malloc.h>

void merge(int *Array, int left, int middle, int right, long long int* inversions_check) {
    int current_left = 0, current_right = 0, buffer_len = 0, *main_buffer;
    main_buffer = (int*)malloc((right - left) * sizeof(int));
    while (buffer_len < right - left) {
        if (current_left + left >= middle || (current_right + middle < right && Array[current_right + middle] < Array[current_left + left])) {
            main_buffer[buffer_len] = Array[current_right + middle];
            buffer_len++;
            current_right++;
            *inversions_check += (long long int)middle - (long long int)current_left - (long long int)left;
        }
        else {
            main_buffer[buffer_len] = Array[current_left + left];
            buffer_len++;
            current_left++;
        }
    }
    for (int i = 0; i < current_left + current_right; i++)
        Array[left + i] = main_buffer[i];
}

void Merge_Sort(int *Array, int left, int right, long long int* inversions_check) {
    if (right - left < 2)
        return;
    Merge_Sort(Array, left, left + (right - left) / 2, inversions_check);
    Merge_Sort(Array, left + (right - left) / 2, right, inversions_check);
    merge(Array, left, left + (right - left) / 2, right, inversions_check);
}

int main() {
    long long int inversion_number = 0;
    int size , *Array_main;
    FILE *fin, *fout;
    fin = fopen("inversions.in", "r");
    fout = fopen("inversions.out", "w");
    fscanf(fin, "%d",&size);
    Array_main = (int*)malloc((size+1) * sizeof(int));
    for (int i = 0; i < size; i++) {
        fscanf(fin, "%d",&Array_main[i]);
    }
    Merge_Sort(Array_main, 0, size, &inversion_number);
    fprintf(fout, "%lld",inversion_number);
    fclose(fin);
    fclose(fout);
    return 0;
}