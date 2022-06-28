/*
21. Escreva um programa para achar a máxima frequência de aparição de um caracteres em uma frase. Escreva-o e também informe a quantidade de vezes que foi apresentado na frase.
A entrada:
Meu elenco eterno
deve produzir a seguinte saída:
A maior frequência é: 'e' 
‘e’ apareceu 5 vezes.

Separar o que é vogal e consoante.

Metodos: nenhum;

Variaveis de entrada: frase, op;

Variaveis de saida: consoantes, vogal, max;

Variabeis de processo: vogais, ocorrencia, add, sinal, size;

GE = 3 GR =3
*/

#include <stdio.h>
#include <string.h>

int main(){
char vogais[]={'a','e','i','o','u'};
char vogal;
char frase[2000]={};
char consoante[2000]={};
char op[100];
int ocorrencia=0;
int add;
int sinal;
int max=0;
int size;
do{
    printf(" Digite a frase: \n>>>");
    fgets(frase,2000,stdin);

    size=strlen(frase);

    add=0; 
    sinal=0;
    for (int i=0;i<=size;++i){
        for (int ii=0;ii<5;++ii){
            if(frase[i] != vogais[ii] && frase[i] != ' ' && frase[i] != '\0'){
                sinal++;
            }
        }
        if (sinal==5){
                consoante[add]=frase[i];
                add++;                
            }
        sinal=0;
    }

    for (int i=0; i<5;++i){
        for (int ii=0;ii<size;ii++){
            if(vogais[i] == frase[ii]){
                ocorrencia++;
            }
        }

    if(ocorrencia>max){
        max=ocorrencia;
        vogal=vogais[i];
    }
    ocorrencia=0;
    }

    if(max>1){
    printf("\nVogal:%c com %d Ocorrencias \nConsoantes: ",vogal,max);
    }else{
    printf("\nVogal:%c com %d Ocorrencia \nConsoantes: ",vogal,max);
    }

    for(int i=0;i<=add;++i){
    printf("%c ",consoante[i]);       
    } 

    printf("\nDeseja repetir <Digite qualquer tecla> <Digite [0] para sair>?\n>>>");
    fgets(op,100,stdin);

}while(op[0]!='0');



    return 0;
}
/*OUTPUT
 Digite a frase:
>>>meu nome e gabriel e eu gostaria de adotar uma postura diferente

Vogal:e com 10 Ocorrencias
Consoantes: m n m g b r l g s t r d d t r m p s t r d f r n t

Deseja repetir <Digite qualquer tecla> <Digite [0] para sair>?
>>>

*/