#include <stdio.h>
#include <malloc.h>


int main()
{
    int i, key, number, *Array;
    FILE *fin, *fout;
    fin = fopen("smallsort.in", "r");
    fout = fopen("smallsort.out", "w");
    fscanf(fin, "%d",&number);
    Array = (int*)malloc((number+1) * sizeof(int));
    for (int i = 0; i < number; ++i) {
        fscanf(fin,"%i", &Array[i]);
    }
    for (int j = 1; j < number; ++j) {
        key = Array[j];
        i = j-1;
            while (i >= 0 && Array[i] > key){
                Array[i+1] = Array[i];
                i -= 1;
            }
        Array[i+1] = key;
        }
    for (int i = 0; i < number; ++i) {
        fprintf(fout, "%i%s", Array[i], " ");
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
