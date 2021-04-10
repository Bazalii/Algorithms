#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

void swap(int *x, int *y)
  {
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;
}

int Sort(int  *array, int size, int search_Position) {
    int left = 0, right = size - 1;
    while (true)
    {
        if (left + 1 >= right)
        {
            if (left + 1 == right && array[left] > array[right])
            {
                swap(&array[left], &array[right]);
            }
            return array[search_Position];
        }
        int middle = (left + right) / 2;
        swap(&array[middle], &array[left + 1]);
        if (array[left] > array[right])
            swap(&array[left], &array[right]);
 
        if (array[left + 1] > array[right])
            swap(&array[left + 1], &array[right]);
 
        if (array[left] > array[left + 1])
            swap(&array[left], &array[left + 1]);
        int current_left = left + 1;
        int current_right = right;
        int value = array[current_left];
        while (true)
        {
            do
            {
                current_left++;
            } while (array[current_left] < value);
            do
            {
                current_right--;
            } while (array[current_right] > value);
            if (current_left > current_right)
            {
                break;
            }
            swap(&array[current_left], &array[current_right]);
        }
        array[left + 1] = array[current_right];
        array[current_right] = value;
        if (current_right >= search_Position)
        {
            right = current_right - 1;
        }
        if (current_right <= search_Position)
        {
            left = current_left;
        }
    }
}
 
int main() {
    int n, k, a, b, c, first, second, *Array_main;
    FILE *fin, *fout;
    fin = fopen("kth.in", "r");
    fout = fopen("kth.out", "w");
    fscanf(fin, "%d%*c%d%*c%d%*c%d%*c%d%*c%d%*c%d%*c",&n, &k, &a, &b, &c, &first, &second);
    Array_main = (int*)malloc((n+1) * sizeof(int));
    Array_main[0] = first;
    if (n > 1) {
        Array_main[1] = second;
    }
    for (int i = 2; i < n; i++) {
        Array_main[i] = a * Array_main[i - 2] + b * Array_main[i - 1] + c;
    }
    Sort(Array_main, 0, n - 1);
    fprintf(fout, "%d",Sort(Array_main, n, k - 1));
    fclose(fin);
    fclose(fout);
    return 0;
}