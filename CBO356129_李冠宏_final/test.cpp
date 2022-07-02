#include <iostream>
#include <string>
#include <string.h>
using namespace std;

void setID(char ID[100], char input[100]){
    strcpy(ID, input);
}

int main(void){
    char ID[100];
    setID(ID, "Test");
    printf("%s\n", ID);
    return 0;
}