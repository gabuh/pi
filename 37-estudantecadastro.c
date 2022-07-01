/*
37. Escreva uma estrutura para armazenar o id do estudante, nome, idade (entre 11 e 14) e o endereço dos estudantes. Necessário que a estrutura armazene mais de 10 estudantes.
1 - Escreva uma função para mostrar os nomes de todos os estudantes que tenham a idade maior que 14 anos. 
2 - Escreva outra função para mostrar os nomes de todos os estudantes que tenham números de id ímpares. 
3 - Escreva outra função que mostra detalhes de estudantes em que o id é fornecido pelo o usuário.

Metodos e funcoes: mostrarIdImpar(),mostrarIdade(),procurarId();

Variaveis de entrada: nome, idade, idEstudante, endereco, id;

Variaveis de saida: nome, idade, idEstudante, endereco;

Variaveis de controle: op, control, cont; 

GE=1 GE=2

*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define TAM 4

struct escola{
char nome[1000];
int idade;
char endereco[1000];
int idEstudante;

};

void mostrarIdImpar(struct escola aluno[]);
void mostrarIdade(int idade,struct escola aluno[]);
void procurarId(struct escola aluno[]);

void main(){

struct escola aluno[TAM];
char op[100];
int control=0;

    do{
        printf("\n Area de Cadastro > Tamanho definido: [%d]",TAM);

        for (int i=0; i<TAM;++i){
            printf("\n>Digite o nome: ");
            scanf(" %[^\n]s",aluno[i].nome);
            printf("\n>Digite o endereco: ");
            scanf(" %[^\n]",aluno[i].endereco);     
            printf("\n>Digite a idade: ");
            scanf("%d",&aluno[i].idade);
            srand(time(NULL));
            aluno[i].idEstudante=(rand()%3000+1000)+i;
            printf("\n Cadastrado %s, com id %d\n",aluno[i].nome,aluno[i].idEstudante);
        }
        printf("\n");
       
       
        do{

            printf("\n [1]Listar Alunos maiores que 14 anos\n [2]Listar Alunos de Id Estudante Impar\n [3]Procurar Aluno por Id Estudante\n [4]Recadastrar alunos\n [0]Sair\n>>>");
            scanf(" %[^\n]s",op);
            if(strcmp(op,"1")==0){
            mostrarIdade(14,aluno);
            }else if(strcmp(op,"2")==0){
            mostrarIdImpar(aluno);
            }else if(strcmp(op,"3")==0){
                procurarId(aluno);            
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



void procurarId(struct escola aluno[]){
    int id=0;
    int cont=0;
    while(id<1000 || id>3000){
    printf("\nDigite o ID: ");
    scanf("%d",&id);
    }
    printf("\n[nome] - [idade] - [id-aluno] - [endereco]\n");
    for (int i=0;i<TAM;++i){
        if(aluno[i].idEstudante==id){
        printf("%s | %d | %d | %s\n",aluno[i].nome,aluno[i].idade,aluno[i].idEstudante,aluno[i].endereco);
        cont++;
        }
    }
    if(cont == 0){
        printf("Estudante nao econtrado, Porfavor verifique o ID do aluno");
    }
}


void mostrarIdImpar(struct escola aluno[]){
    printf("\nAlunos com id estudante impar:\n [nome] - [idade] - [id-aluno] - [endereco]\n");
    for (int i=0;i<TAM;++i){
        if(aluno[i].idEstudante-2*(aluno[i].idEstudante/2)!=0){
            printf("%s | %d | %d | %s\n",aluno[i].nome,aluno[i].idade,aluno[i].idEstudante,aluno[i].endereco);
        }
    }
}




void mostrarIdade(int idade, struct escola aluno[]){
    printf("\nAlunos com idade superior a [%d]:\n [nome] - [idade] - [id-aluno] - [endereco]\n",idade);
    for(int i=0; i<TAM;++i){
        if(aluno[i].idade>idade){
            printf("%s | %d | %d | %s\n",aluno[i].nome,aluno[i].idade,aluno[i].idEstudante,aluno[i].endereco);
        }
    }

}