#include <stdio.h>
#define LINHA 3
#define COLUNA 3
/* 

 */
int muda_jogador(int jogador){
      if(jogador ==1){
        
        return 2;
    }
    else 
    {
       
       return 1;
    }
}
 char muda_simbulo(int jogador){
    if(jogador ==1){
        jogador=2;
        return 'X';
    }
    else 
    {
        jogador=1;
       return 'O';
    }
    

 }
int main() {

    char tabuleiro[LINHA][COLUNA];
    int linha, coluna,jogador_atual=1;
    for(size_t i=0; i<LINHA; i++){
        
        for (size_t j = 0; j < COLUNA; j++)
        {
            tabuleiro[i][j] ='-';
          
        }
        
    }
    do{
    for(size_t i=0; i<LINHA; i++){
      
        for (size_t j = 0; j < COLUNA; j++)
        {
     
            printf("%c", tabuleiro[i][j]);
        }
          printf("\n");
    }

printf("Em qual posicao quer jogar? (linha e coluna\n)");
scanf("%d%d", &linha, &coluna);

tabuleiro[linha][coluna] = muda_simbulo(jogador_atual);
jogador_atual=muda_jogador(jogador_atual);



    }while (1);
    
    



    printf("FIM \n");
    return 0;
}