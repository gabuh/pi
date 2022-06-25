#include<stdio.h>

int player(int p,int rounds){ //chama jogador
    int jogada;
    if (rounds==4 && p != 1){
        printf("\nEMPATE !\n");
        return 0;
    }else{
        printf("Player %d, Sua vez: ",p);
        scanf("%d",&jogada);
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
                }
                if (board[li][col] == -2){ 
                    lin[col]=2;
                }

                if (board[col][li] == -1){
                    colu[col]=1;
                }else if (board[col][li] == -2){
                    colu[col]=2;
                }   

                if(lin[0]==1 && lin[1]==1 && lin[2]==1 || colu[0]==1 && colu[1]==1 && colu[2]==1){
                    li=+10;
                    player=1;
                }else if(lin[0]==2 && lin[1]==2 && lin[2]==2 || colu[0]==2 && colu[1]==2 && colu[2]==2){
                    li=+10;
                    player=2;
                }
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
    char op[]=" ";
do{
    int board[3][3]={1,2,3,4,5,6,7,8,9}; //quadro do jogo, matriz 3x3
    
    mostrarQuadro(board);

do{

    for (int round=1;round<=2;++round){
            jogada=player(round,rounds);
            if (jogada!=0){
                for(int i=0;i<=2;++i){
                    for (int e=0;e<=2;++e){ 
                        if (jogada == -board[i][e]){
                            board[i][e]=-round;
                            skip=round;                    
                        }
                    }
                }
                    mostrarQuadro(board);
                    vitoria=verificaQuadro(board);
                    if (vitoria > 0){ // to break the loop above.
                        round=10;
                    }

                if(skip!=round){
                    --round;        }
            }
        }
        rounds++;
}while(rounds<=4 && vitoria != 1 && vitoria != 2);
if(vitoria>0){
    printf("\nPlayer %d Vitorioso, Parabens !\n",vitoria);
}
rounds=0;
vitoria=0;
printf("\n>Deseja jogar novamente? <Digite qualquer tecla >\n>Deseja sair <Digite 0>\n>>>> ");

scanf("%s",op);


}while(op[0]!='0');

    return 0 ;
} 