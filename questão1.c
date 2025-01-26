
//IMPORTAR BIBLIOTECAS 
#include <stdlib.h>//Nesse caso, usada para acessar o método rand responsável pelos numeros aleatorios 
#include <stdio.h>// Utilizada para realizar operações de entrada e saída

// DEFININDO CONSTANTES DO JOGO     
const int col = 3;  // quantidadeDeColunas
const int lin = 3;  // quantidadeDeLinhas 
const char user = 'X';
const char computador = 'O';
const char empate = 'E';

// DECLARAÇÃO DE FUNÇÕES USADAS NO CÓDIGO
    
struct coordenadas{/* modelo de estrutura que armazena coordenadas para serem usadas na matriz do tabuleiro*/
    int x;
    int y;
    
};

void AtualizadorDeCoordenadas(int num, struct coordenadas *coordenada) {
    switch (num) {
        case 1:
            coordenada->x = 0;
            coordenada->y = 0;
            break;
        case 2:
            coordenada->x = 0;
            coordenada->y = 1;
            break;
        case 3:
            coordenada->x = 0;
            coordenada->y = 2;
            break;
        case 4:
            coordenada->x = 1;
            coordenada->y = 0;
            break;
        case 5:
            coordenada->x = 1;
            coordenada->y = 1;
            break;
        case 6:
            coordenada->x = 1;
            coordenada->y = 2;
            break;
        case 7:
            coordenada->x = 2;
            coordenada->y = 0;
            break;
        case 8:
            coordenada->x = 2;
            coordenada->y = 1;
            break;
        case 9:
            coordenada->x = 2;
            coordenada->y = 2;
            break;
        default:
            break;
    }
}

void imprimirTabuleiro(char tabuleiro[lin][col]) {/*Recebe a matriz do tabuleiro e imprime ela de uma forma estilizada que pode ser alterada para todo o código por meiio desta função*/
    for (int c = 0; c < lin; c++) {
        for (int d = 0; d < col; d++) {
            printf("| %c ", tabuleiro[c][d]); 
        }
        printf("|\n"); 
        if (c < 2) {
            printf("-------------\n"); 
        }
    }
    printf("\n");
}

char vitoria(char tabuleiro[lin][col]){/*recebe o tabuleiro para verificar possiveis condições de vitória ou empate, 
podendo retornar user ('X')  computador ('O') e empate ('E')*/
        char resultado = empate;
        for(int col = 0 ; col < 3 ; col++ ){// verifica vitória por coluna completa do jogador user
            if(tabuleiro[0][col] == user &&   tabuleiro[1][col]  == user && tabuleiro[2][col] == user){
                resultado = user;
                break;
            }
        }

        for(int lin = 0 ; lin < 3 ; lin++ ){ // verifica vitória de linha completa do jogador user 
            if(tabuleiro[lin][0] == user &&  tabuleiro[lin][1] == user && tabuleiro[lin][2] == user){
                resultado = user;
                break;
            }
        }

        if(tabuleiro[0][0] == user && tabuleiro[1][1] == user && tabuleiro[2][2] == user){// verifica vitória pela primeira diagonal completa do jogador user
            resultado = user;
        }

        if(tabuleiro[0][2] == user && tabuleiro[1][1] == user && tabuleiro[2][0] == user){// verifica vitória pela primeira diagonal completa do jogador user
            resultado = user;
            
        }

        for(int col = 0 ; col < 3 ; col++ ){// verifica vitória por coluna completa do jogador computador
            if(tabuleiro[0][col] == computador && tabuleiro[1][col] ==computador &&  tabuleiro[2][col] == computador){
                resultado = computador;
                break;
            }
        }
        for(int lin = 0 ; lin < 3 ; lin++ ){ // verifica vitória de linha completa do jogador computador 
            if(tabuleiro[lin][0] ==computador &&  tabuleiro[lin][1] == computador && tabuleiro[lin][2] == computador){
                resultado = computador;
                break;
            }
        }
        if(tabuleiro[0][0] ==computador &&  tabuleiro[1][1] ==computador &&  tabuleiro[2][2] == computador){// verifica vitória pela primeira diagonal completa do jogador computador
            resultado = computador;    
        }
        if(tabuleiro[0][2] ==computador &&  tabuleiro[1][1] == computador && tabuleiro[2][0] == computador){// verifica vitória pela primeira diagonal completa do jogador computador
            resultado = computador; 
        }
        return(resultado);
}

int posicaoAleatoria(){/*é responsável pelas jogadas do computador retornando numeors aleatórios entre 0 e 9*/
    int numeroAleatorio = (rand() % 9) + 1;
    return numeroAleatorio;
}





int main(){//PASSO : PARTE PRINCIPAL DO CÓDIGO 

    char tabuleiro[lin][col];// CRIANDO O TABULEIRO INICIAL
    int contador = 1;

    for (int c = 0; c < lin; c++) {// adicionando um valor inicial para as casas do tabuleiro 
        for (int d = 0; d < col; d++) {
            tabuleiro[c][d] = '0' + contador;//conversão implicita da variável contador de inteiro para char 
            contador++;

        }
    }

    // DECLARAÇÃO DE VARIÁVEIS GLOBAIS  
    int posicao;
    int contadorDeJogadas = 0;
    char atualJogador = user;
    char gameOver = empate;

    //APRESENTAÇÃO INICIAL DO TABULEIRO 
    imprimirTabuleiro(tabuleiro);// demonstração inicial do tabuleiro 

    //LOOP INFINITO QUE PERMITE QUE O JOGO CONTINUE INDEFINIDAMENTE

    while(1){// loop infinito

        if (atualJogador == user){//O TURNO EM QUE O USUÁRIO JOGA
            printf("sua vez,  (%c) \n" , atualJogador );
            scanf("%d" , &posicao  );//Recebe a posição digitada pelo jogador
            struct coordenadas cdTeste;
            AtualizadorDeCoordenadas(posicao, &cdTeste);// retorna as coordenadas da posição escolhida cd.x (linhas) e cd.y (colunas)

            if(posicao < 1 || posicao > 9 ){
                printf("erro! Essa posição não existe \n");
                continue; // 
            }else if (tabuleiro[cdTeste.x][cdTeste.y] == user || tabuleiro[cdTeste.x][cdTeste.y] == computador){
                printf("erro! Essa posição já foi escolhida \n");
                continue; 
            }
            
        } else if (atualJogador == computador) {//O TURNO EM QUE O COMPUTADOR JOGA 
            struct coordenadas cdTeste;
            printf(" jogada do computador (%c) \n" , atualJogador );
            do {
                posicao = posicaoAleatoria();  
                AtualizadorDeCoordenadas(posicao, &cdTeste); // Gera coordenadas para a posição
            } while (tabuleiro[cdTeste.x][cdTeste.y] == user || tabuleiro[cdTeste.x][cdTeste.y] == computador);
        }


        //MARCANDO A POSIÇÃO ESCOLHIDA PELO JOGADOR ATUAL NO TABULEIRO 

        struct coordenadas cd;
        AtualizadorDeCoordenadas(posicao, &cd);                               // retorna as coordenadas da posição escolhida cd.x (linhas) e cd.y (colunas)
        tabuleiro[cd.x][cd.y] = atualJogador;
        imprimirTabuleiro(tabuleiro);                                         // imprime o tabuleiro atualizado em jogadas válidas


        //ALTERNANDO O JOGADOR A CADA TURNO
        contadorDeJogadas++;                      // incrementação que só ocorrerá em caso de jogadas válidas, já que os continues que são executados com as inválidas não permitem a execução destas chegarem até aqui
        if(contadorDeJogadas% 2 == 0){            // difinição de qual o jogador do atual turno 
            atualJogador = user;
        }else{atualJogador = computador;}
   

        //VARIÁVEL QUE É ATUALIZADA a cada turno SOBRE O ESTADO DO JOGO, Podendo ser empate, vitória de X ou vitória de O
        gameOver = vitoria(tabuleiro);

        //PASSO : CONDIÇÕES PARA FIM DE JOGO E DEMONSTRAÇÃO DOS RESULTADOS 


        if(gameOver == computador){                                       // mostrar o resultado do jogo em caso de vitória do computador
            printf("vitoria para o computador (%c)",  gameOver);
            break;
        }else if(gameOver == user){                                      // mostrar o resultado do jogo em caso de vitória do user 
            printf(" Você venceu (%c)",  gameOver);
            break;
        }else if(contadorDeJogadas >= 8 && gameOver ==empate ){          // mostrar o resultado do jogo em caso de empate 
            printf("empate");
            break;
        }
    }

}