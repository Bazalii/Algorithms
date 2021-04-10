#include <stdio.h>
#include <malloc.h>

int main()
{
    int i, key, n, key_check, *Index_array;
    float *Array;
    FILE *fin, *fout;
    fin = fopen("sortland.in", "r");
    fout = fopen("sortland.out", "w");
    fscanf(fin, "%i",&n);
    Array = (float* )malloc((n+1) * sizeof(float));
    Index_array = (int* )malloc((n+1) * sizeof(int));
    for (int i = 0; i < n; ++i) {
        fscanf(fin,"%f", &Array[i]);
        Index_array[i] = i;
    }
    for (int j = 1; j < n; ++j) {
        key = Array[j];
        key_check = Index_array[j];
        i = j - 1;
        while (i >= 0 && Array[i] > key) {
            Array[i + 1] = Array[i];
            Index_array[i + 1]= Index_array[i];
            i -= 1;
        }
        Array[i + 1] = key;
        Index_array[i + 1] = key_check;
    }
    fprintf(fout, "%d%s%d%s%d", (Index_array[0]+1)," ", (Index_array[(n-1)/2]+1)," ", (Index_array[n-1]+1));
    fclose(fin);
    fclose(fout);
    return 0;
}
