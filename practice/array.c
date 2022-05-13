#include <stdio.h>
#include <stdlib.h>
#define N 5
 
int main(void) {
    int score[N];
    
    printf("Please enter your scores:");

    for(int i=0; i<N; i++){
        scanf("%d", &score[i]);
        printf("The score%d is: %d\n", i+1, score[i]);
    }

    return 0;
}