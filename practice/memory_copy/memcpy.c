#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int a[5] = {1,5,7,2,3};
    int b[5] = {0};

    printf("Before memory copy:\n");
    for(int i=0; i<sizeof(b)/sizeof(b[0]); i++){
        printf("b[%d] = %d\n", i, b[i]);
    }

    printf("\n");
    memcpy(b, a, sizeof(int)*5);

    printf("After memory copy:\n");
    for(int i=0; i<sizeof(b)/sizeof(b[0]); i++){
        printf("b[%d] = %d\n", i, b[i]);
    }

    return 0;
}