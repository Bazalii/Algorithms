#include <stdio.h>
#include <malloc.h>

int main()
{
    int w, h, **Array;
    FILE *fin, *fout;
    fin = fopen("turtle.in", "r");
    fout = fopen("turtle.out", "w");
    fscanf(fin, "%i%*c%i", &h, &w);
    Array = (int **)malloc(w * sizeof(int*));
    for(int i = 0; i < w; i++) {
        Array[i] = (int *) malloc(h * sizeof(int));
    }
    for (int i = h - 1; i >= 0; i--) {
            for (int j = 0; j < w; j++) {
                fscanf(fin, "%i", &Array[i][j]);
            }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (i == 0 && j == 0)
                ;
            else{
                if (i == 0)
                    Array[i][j] = Array[i][j] + Array[i][j-1];
                else if (j == 0)
                    Array[i][j] = Array[i][j] + Array[i-1][j];
                else{
                    Array[i][j] = Array[i][j] + (Array[i-1][j] > Array[i][j-1] ? Array[i-1][j] : Array[i][j-1]);
                }
            }
        }
    }
    fprintf(fout,"%i", Array[h-1][w-1]);
    fclose(fin);
    fclose(fout);
    return 0;
}
