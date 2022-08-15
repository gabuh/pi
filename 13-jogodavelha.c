/*
 13. Escreva um programa que permita dois usuários jogarem o jogo-da-velha. O programa deve pedir que os jogadores X e 0 informem os lances alternadamente. O programa exibe as posições do jogo da seguinte forma:
1 2 3
4 5 6
7 8 9

O jogador faz o lance informando o número da posição que deseja assinalar. Após cada lance, o programa
exibe o tabuleiro. Um exemplo de configuração de tabuleiro:

X X 3
4 5 6
7 8 9
*/

/*
Metodos e Functions: player(), mostrarQuadro(), verificarQuadro()
Variables
Saída int board[3][3]={1,2,3,4,5,6,7,8,9} <Array bidimensional para gerenciamento do quadro do game
Leitura: int jogada <Recebe valor do jogador pelo metodo player() 
controle: int rounds <Controla a jogada de dois jogadores até o fim do quadro
controle: int vitoria <Recebe o valor do vecendor pelo metodo verificarQuadro()
controle: int skip <Verifica se tem jogadas invalidas para serem removidas do contador rounds
Leitura: char op <Ler o valor do usuario para escolha de encerramento do programa ou não

GE=5 GR=5

*/

#include<stdio.h>
#include<string.h>

int player(int p,int rounds){ //chama jogador
    int jogada;
    if (rounds==4 && p != 1){
        printf("\nEMPATE !\n");
        return 0;
    }else{
        do{
        printf("Player %d, Sua vez: ",p);
        scanf("%d",&jogada);
        }while(jogada<=0);
        return -jogada;
    }
}

void mostrarQuadro(int board[][3]){ // mostra o quadro
    for(int i=0;i<=2;++i){ //print rounds
        for (int e=0;e<=2;++e){
         if (board[i][e]==-1){
            printf("X ");
         }else if(board[i][e]==-2){
            printf("O ");
         }
         else{
            printf("%d ",board[i][e]);
         }
        }
         printf("\n");
    }
}

int verificaQuadro(int board[][3]){ //verifica o quadro e retorna se existe vencendor
    int player=0;
    int lin[3]={0};
    int colu[3]={0};

    if (board[0][0]==-1 && board[1][1]==-1 && board[2][2]==-1 || board[2][0]==-1 && board[1][1]==-1 && board[0][2]==-1){
        player=1;
    }else if (board[0][0]==-2 && board[1][1]==-2 && board[2][2]==-2 || board[2][0]==-2 && board[1][1]==-2 && board[0][2]==-2){
        player=2;
    }else{

        for (int li=0;li<=2;++li){   
            for (int col=0;col<=2;++col){
            
                if (board[li][col] == -1){ 
                    lin[col]=1;
                }else if (board[li][col] == -2){ 
                    lin[col]=2;
                }

                if (board[col][li] == -1){
                    colu[col]=1;
                }else if (board[col][li] == -2){
                    colu[col]=2;
                }   

            }
                if(lin[0]==1 && lin[1]==1 && lin[2]==1 || colu[0]==1 && colu[1]==1 && colu[2]==1){
                    li=+10;
                    player=1;
                }else if(lin[0]==2 && lin[1]==2 && lin[2]==2 || colu[0]==2 && colu[1]==2 && colu[2]==2){
                    li=+10;
                    player=2;
                }

            lin[0]=0;lin[1]=0;lin[2]=0;
            colu[0]=0;colu[1]=0;colu[2]=0;
        
        }
    }
 return player;
}


int main(){ //menu, interacao principal
    int jogada;
    int rounds=0;
    int vitoria;
    int skip=0;
    char op[100];
do{
    int board[3][3]={1,2,3,4,5,6,7,8,9}; //quadro do jogo, matriz 3x3
    
    mostrarQuadro(board);

do{

    for (int roundControl=1;roundControl<=2;++roundControl){
            jogada=player(roundControl,rounds);
            if (jogada!=0){
                for(int i=0;i<=2;++i){
                    for (int e=0;e<=2;++e){ 
                        if (jogada == -board[i][e]){
                            board[i][e]=-roundControl;
                            skip=roundControl;                    
                        }
                    }
                }
                    mostrarQuadro(board);
                    vitoria=verificaQuadro(board);
                    if (vitoria > 0){ // to break the loop above.
                        roundControl=10;
                    }

                if(skip!=roundControl){
                    --roundControl;        }
            }
        }
        rounds++;
}while(rounds<=4 && vitoria != 1 && vitoria != 2);
if(vitoria>0){
    printf("\nPlayer %d Vitorioso, Parabens !\n",vitoria);
}
rounds=0;
vitoria=0;
printf("\n>Deseja jogar novamente? <Digite qualquer tecla >\n>Deseja sair <Digite exit>\n>>>> ");

scanf("%s",op);


}while(strcmp(op,"exit")!=0);

    return 0 ;
} 