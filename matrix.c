#include<stdio.h>
#include<string.h>


#define TAM 20

int main(){
    int matrix[TAM][TAM]={0};


    for (int i=0;i<TAM;++i){
        for (int ii=0;ii<TAM;++ii){
            if (i==ii){
                printf("X ");
            }else if(TAM-i-1==ii){
                printf("X ");
            }else{
                printf("%d ",matrix[i][ii]);
            }
        }
    printf("\n");
    }


    return 0;
}