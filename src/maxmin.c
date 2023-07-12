/*
Returns the maximum and minimum number
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10

void max_min(int a[], int n, int *max, int *min);
void read_list();

int main(void) {
    srand(time(NULL));

    
    int b[N], i, big, small;
    printf("Array: ");
    for (i=0; i<N; i++){
        b[i] = rand();
        printf("%d, ", b[i]);
    }
    printf("\n");

    max_min(b, N, &big, &small);
    printf("Max: %d\n", big);
    printf("Min: %d\n", small);

    return 0;
}

void max_min(int a[], int n, int *max, int *min){
    int i;
    *max=*min= a[0];
    for(i=0; i<n; i++){
        if (a[i] > *max){
            *max = a[i];
        } else if (a[i] < *min){
            *min = a[i];
        }
    }
}

void read_list(){
    int b[N];

    printf("Enter %d numbers: ", N);


    for (int i=0;i<N;i++){
        scanf("%d", &b[i]);
    }
}
