#include <stdio.h>
#define N 5

int main(void) {
    int sum = 0;
    int score[N];
    double avg;

    printf("Please enter your scores:");
    for(int i=0; i<N; i++){
        scanf("%d", &score[i]);
    }

    for(int i=0; i<N; i++){
        sum += score[i];
    }

    avg = (double)sum / N;

    printf("sum score= %d\n", sum);
    printf("average score = %.2f\n", avg);

    return 0;
}