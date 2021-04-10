#include <stdio.h>
#include <malloc.h>

int main() {
    //Task6
    int number, *Array_main, check = 0;
    FILE *fin, *fout;
    fin = fopen("isheap.in", "r");
    fout = fopen("isheap.out", "w");
    fscanf(fin, "%d", &number);
    Array_main = (int *) malloc((number + 1) * sizeof(int));
    for (int i = 1; i <= number; i++) {
        fscanf(fin,"%d", &Array_main[i]);
    }
    for (int i = 1; i < number; i++) {
        if (2*i <= number && Array_main[i] > Array_main[2*i]){
            check = 1;
            break;
        }
        else if ((2*i + 1) <= number && Array_main[i] > Array_main[2*i + 1]){
            check = 1;
            break;
        }
    }
    if (check == 1){
        fprintf(fout,"%s", "NO");
    }
    else{
        fprintf(fout,"%s", "YES");
    }
    return 0;
}
