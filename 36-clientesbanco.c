
/*

36. Escreva uma estrutura para armazenar nomes, números de conta e saldo monetário de clientes (mais de 10).

1 - Mostrar os nomes de todos os clientes que tenham um saldo monetário menor que R$ 200.
2 - Adicionar R$ 100 no saldo monetário de todos os clientes que tem mais de R$ 1000 em seu saldo monetário e depois mostre o valor incrementado do saldo deles.



Estrutura: clientesbanco.cliente

Variaveis de entrada: nome, contaId, saldo;

Variaveis de processamento: control, op;

Variaveis de saida: nome, contaId, saldo

GE=2 GR=2
*/




#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define TAM 4




struct clientebanco
{
    char nome[1000];
    int contaId;
    float saldo;
};


void addSaldoShow(struct clientebanco cliente[]);
void mostrarLowSaldo(struct clientebanco cliente[]);



void main(){
    struct clientebanco cliente[TAM];
    char op[100];
    int control=0;

    do{
        printf("\n Area de Cadastro ");

        for (int i=0; i<TAM;++i){
            printf("\n>Digite o nome: ");
            scanf(" %[^\n]s",cliente[i].nome);
            printf("\n>Digite o saldo: ");
            scanf("%f",&cliente[i].saldo);
            srand(time(NULL));
            cliente[i].contaId=(rand()%2000+1000)+i;
            printf("\n Cadastrado:%s com saldo: R$ %f, conta %d\n",cliente[i].nome,cliente[i].saldo,cliente[i].contaId);
        }
        printf("\n");
        do{

            printf("\n [1]Listar clientes\n [2]Adicionar R$100 no saldo de clientes com saldo acima de R$1000\n [3]Verificar clientes com o saldo abaixo de R$200\n [4]Recadastrar clientes\n [0]Sair\n>>>");
            scanf(" %[^\n]s",op);
            if(strcmp(op,"1")==0){
                printf(">[Nome] [id conta] [saldo]\n");
                for(int i=0;i<TAM;++i){
                    printf(">[%s] [%d] [%f]\n",cliente[i].nome,cliente[i].contaId,cliente[i].saldo);
                }
            }else if(strcmp(op,"2")==0){
            addSaldoShow(cliente);
            }else if(strcmp(op,"3")==0){
            mostrarLowSaldo(cliente);   
            }else if(strcmp(op,"4")==0){
                strcpy(op,"0");
                control++;
            }
        }while(strcmp(op,"0")!=0);

        if (control>0){
            strcpy(op,"control");
            control=0;
        }


    }while(strcmp(op,"0")!=0);


}



void addSaldoShow(struct clientebanco cliente[]){
    for (int i=0;i<TAM;i++){
        if(cliente[i].saldo>1000){
            cliente[i].saldo=cliente[i].saldo+100;
            printf("Cliente, %s com saldo R$, %f, foi adicionado +R$100\nSaldo atual: %f\n",cliente[i].nome,cliente[i].saldo-100,cliente[i].saldo);
        }
    }
}

void mostrarLowSaldo(struct clientebanco cliente[]){
    printf("Clientes com o saldo menor que R$200\n");
    printf(">[Nome] [saldo] [id conta]\n");
    for(int i=0;i<TAM;++i){
        if(cliente[i].saldo<200){
            printf(">[%s] [%f] [%d]\n",cliente[i].nome,cliente[i].saldo,cliente[i].contaId);
        }
    }
}