 
 /*
 39. Desenvolva um programa em C para vendas de passagens de ônibus.
 Defina uma STRUCT, crie o menu de opções e todas as funções necessárias para manipular esta STRUCT.
 
 Metodos e funcoes: vendaBilhete, verificarVenda, alterarPreco;

 variaveis de entrada: validacao, idBilhete, preco, venda, novoPreco;

 variaveis de saida: preco, cont, idBilhete;

 variaveis de controle: control, op,sum;
 
 GE=5 GR=4
 
 */
 
 
 
 
 #include<stdio.h>
 #include<stdlib.h>
 #include<time.h>
 #include<string.h>
 #define TAM 10

struct onibus{
    int validacao;
    int idBilhete;
    float preco;
};


void vendaBilhete(struct onibus bilhete[]);
void verificarVenda(struct onibus bilhete[]);
void alterarPreco(struct onibus bilhete[]);

int main(){
struct onibus bilhete[TAM];
int control=0;
char op[100];



 do{
        printf("\nDefina o valor do bilhete em R$: ");
        scanf("%f",&bilhete[0].preco);
        printf("\n Gerando Bilhetes com preco R$%f > Quantidade de bilhetes definida: [%d]",bilhete[0].preco,TAM);
        for (int i=0; i<TAM;++i){      
            srand(time(NULL));
            bilhete[i].idBilhete=(rand()%3000+1000)+i;
            printf("\n %d/%d",i+1,TAM);
            bilhete[i].preco=bilhete[0].preco;
            bilhete[i].validacao=0;
        }
        printf("[%d] Bilhetes gerados\n",TAM);
       
       
        do{

            printf("\n [1]Vender Bilhete\n [2]Verificar Venda\n [3]Alterar Preco\n [4]Resetar Viagem\n [0]Sair\n>>>");
            scanf(" %[^\n]s",op);
            if(strcmp(op,"1")==0){
                vendaBilhete(bilhete);
            }else if(strcmp(op,"2")==0){
                verificarVenda(bilhete);
            }else if(strcmp(op,"3")==0){
                alterarPreco(bilhete);            
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


void vendaBilhete(struct onibus bilhete[]){
    char op[100];
    int venda;
    int cont;
    do{
        cont=0;
    for(int i=0;i<TAM;++i){
        if(bilhete[i].validacao==0){
            cont++;
        }
    }
    
        printf("\n [1]Vender 1\n [2]Vender quantidade\n [3]Voltar \n %d Bilhetes disponiveis\n>>>",cont);
        scanf(" %[^\n]s",op);
        if(strcmp(op,"1")==0 && cont!=0){
            for (int i=0;i<TAM;++i){
                if(bilhete[i].validacao==0){
                    bilhete[i].validacao=1;
                    printf("\nbilhete: %d vendido",bilhete[i].idBilhete);
                    break;
                }
            }
        }else if(strcmp(op,"2")==0 && cont!=0){
            printf("\n%d Disponiveis, Quanto deseja vender?\n>>>",cont);
            scanf("%d",&venda);
                if(venda<=cont && venda > 0){
                    printf("\n");
                    for(int i=0;i<venda;++i){
                        for (int ii=0;ii<TAM;++ii){
                            if(bilhete[ii].validacao==0 && cont!=0){
                                bilhete[ii].validacao=1;
                                printf("\nbilhete: %d vendido",bilhete[ii].idBilhete);
                                cont=-1;
                                break;
                            }
                        }
                    }
                }else{
                    printf("\nTente novamente\n");
                }
                if (cont==0){
                    strcpy(op,"3");
                }
        }        
    }while(strcmp(op,"3")==1);


}

void verificarVenda(struct onibus bilhete[]){
    float sum=0;
    int cont=0;
    printf("\nbilhetes disponiveis para venda\n  [ID]  -  [Preco]\n");
    for (int i=0; i<TAM;++i){
        if(bilhete[i].validacao==0){
            printf("%d   -   %f \n",bilhete[i].idBilhete,bilhete[i].preco);
        }
    }
    for(int i=0;i<TAM;++i){
        if(bilhete[i].validacao==1){
        sum=sum+bilhete[i].preco;
        cont++;
        }

    }
    printf("\nJa vendidos: %d, Valor total da venda: R$%f",cont,sum);
}


void alterarPreco(struct onibus bilhete[]){
    float novoPreco;
    printf("Preco atual: $R%f",bilhete[TAM-1].preco);
    printf("\nDefina o valor do bilhete em R$: ");
    scanf("%f",&novoPreco);
    for(int i=0;i<TAM;++i){
        if(bilhete[i].validacao==0){
            bilhete[i].preco=novoPreco;
        }
    }
}