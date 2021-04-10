#include <stdio.h>
#include <malloc.h>

int* merge_sort(int *Main, int *Check, unsigned int left, unsigned int right)
{
    if (left == right)
    {
        Check[left] = Main[left];
        return Check;
    }
    unsigned int middle = (left + right) / 2;
    int *left_subarray = merge_sort(Main, Check, left, middle);
    int *right_subarray = merge_sort(Main, Check, middle + 1, right);
    int *outcome = left_subarray == Main ? Check : Main;
    unsigned int current_left = left, current_right = middle + 1;
    for (unsigned int i = left; i <= right; i++)
    {
        if (current_left <= middle && current_right <= right)
        {
            if (left_subarray[current_left] < right_subarray[current_right])
            {
                outcome[i] = left_subarray[current_left];
                current_left++;
            }
            else
            {
                outcome[i] = right_subarray[current_right];
                current_right++;
            }
        }
        else if (current_left <= middle)
        {
            outcome[i] = left_subarray[current_left];
            current_left++;
        }
        else
        {
            outcome[i] = right_subarray[current_right];
            current_right++;
        }
    }
    return outcome;
}

int main(){
    int number, *Array_main, *Array_check;
    FILE *fin, *fout;
    fin = fopen("sort.in", "r");
    fout = fopen("sort.out", "w");
    fscanf(fin, "%d",&number);
    Array_main = (int*)malloc((number+1) * sizeof(int));
    Array_check = (int*)malloc((number+1) * sizeof(int));
    for (int i = 0; i < number; ++i) {
        fscanf(fin,"%i", &Array_main[i]);
    }
    Array_main = merge_sort(Array_main, Array_check, 0, number-1);
    for (int i = 0; i < number; ++i) {
        fprintf(fout, "%i%s", Array_main[i], " ");
    }
    fclose(fin);
    fclose(fout);
    return 0;
}