/**
 * 
 * 18. Escreva uma classe Estatística que contenha métodos estáticos que recebam um vetor de inteiros, juntamente com o número de elementos, e calculam respectivamente:
 * a) a moda dos elementos no vetor (elemento mais frequente)
 * b) a mediana dos elementos no vetor (elemento central)
 * c) a média
 * 
 *
 * Vetores
 * inteiro: intermediario,vetor,moda;
 * 
 * Variable de Processamento
 * inteiro: temp,ocorrencia;
 * 
 * Variable Entrada
 * inteiro: vetor;
 * 
 * Variable Saida
 * inteiro: mediana, media, moda;
 * 
 * GE=3 GR=3
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define TAM 20


struct estatistica
{
    int vetor[TAM];
};


int main(){   
struct estatistica est;
int intermedio[TAM];
int ocorrencia=0;
int mediana;
int media=0;
int moda[TAM];
int temp;

//ADICIONANDO VALOR AO VETOR
srand(time(NULL));
for (int i=0; i<TAM;++i){
    est.vetor[i]=rand()%100;
}

printf("\nVetor Aleatorio:\n");
for (int i=0; i<TAM;++i){
    printf("%d, ",est.vetor[i]);
}


    for(int i=0; i<TAM;++i){   //ORDENA O VETOR EM SEQUENCIA CRESCENTE
        for(int ii=i; ii<TAM; ++ii){
                temp=est.vetor[i];
            if(est.vetor[ii]<est.vetor[i] ){
                est.vetor[i]=est.vetor[ii];
                est.vetor[ii]=temp;  
            }
        }
    }
// -----------------------ESCREVE A ORDENACAO
printf("\nOrdenado:\n");
for (int i=0; i<TAM;++i){
    printf("%d, ",est.vetor[i]);
}
printf("\n");

//---------------------------TRATANDO A MEDIANA
if (TAM%2==0){ //VERIFICA SE E PAR OU IMPAR PARA ACHAR A MEDIANA SE PAR (TAM / 2) = N ENTAO VETOR[N-1] + VETOR[N+1] / 2 = MEDIANA
    mediana=(est.vetor[(TAM/2)-1] + est.vetor[(TAM/2)]) /2; 
}else{ //SE IMPAR ((TAM -1) / 2) = N ENTAO VETOR[N+1] = MEDIANA
    mediana=est.vetor[((TAM-1)/2)]; //COMO O INDEX COMECA COM [0] NAO ADICIONA +1
}

//-------------------------TRATANDO A MODA
for (int i=0;i<TAM;++i){
    for(int ii=0;ii<TAM;++ii){
        if(est.vetor[i]==est.vetor[ii]){ //VERIFICA A OCORRENCIA E GUARDA A LISTA NO VETOR INTERMEDIO
            ocorrencia++;
        }
    }
    intermedio[i]=ocorrencia;
    ocorrencia=0;
}
//----------------------------
temp=0;
for (int i=0;i<TAM;i++){ //ADICIONA A MAIOR QUANTIDADE DE OCORRENCIA
    for (int ii=0;ii<TAM;++ii){
        if (intermedio[i]>intermedio[ii]){ 
            temp=intermedio[i];
        }
    }
}

if(temp!=0){ //CONDICAO VERIFICA SE TEM MODA 
    ocorrencia++;
    for (int i=0;i<TAM;i++){
        if(temp==intermedio[i] && est.vetor[i]!=moda[ocorrencia-1]) { //COMPARA VETOR DE ENTRADA COM O INTERMEDIO E ADICIONA OS VALORES NO VETOR MODA
            moda[ocorrencia]=est.vetor[i];
            ocorrencia++;            
        }
    }
    for(int i=0;i<ocorrencia-1;++i){
        printf("Moda: ");
        printf("%d \n",moda[i+1]);
    }
}else{
    printf("\nNao tem moda\n");
}

//------------------------------- ESCREVE MEDIANA
printf("\nEste e o Valor da mediana: %d\n",mediana);

//------------------------------- TRATANDO A MEDIA
for(int i=0;i<=TAM;i++){
    media=media+est.vetor[i];
}
media=media/TAM;
printf("\nMedia: %d",media);
printf("\nExperimente alterar o valor do TAM definido.");




    return 0;
}

