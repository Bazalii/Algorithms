#include <stdio.h>
#include <malloc.h>

int main() {
    int number, *Array_main, check;
    FILE *fin, *fout;
    fin = fopen("antiqs.in", "r");
    fout = fopen("antiqs.out", "w");
    fscanf(fin, "%d", &number);
    Array_main = (int *) malloc((number + 1) * sizeof(int));
    for (int i = 0; i < number; i++) {
        Array_main[i] = i + 1;
    }
     for (int i = 2; i < number; i++) {
        check = Array_main[i];
        Array_main[i] = Array_main[i / 2];
        Array_main[i / 2] = check;
    }
    for (int i = 0; i < number; ++i) {
        fprintf(fout,"%i ", Array_main[i]);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}