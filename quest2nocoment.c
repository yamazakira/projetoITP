#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool posicaoSegura(char **tabuleiro, int N, int linha, int coluna)
{
    for (int i = 0; i < linha; i++)
        if (tabuleiro[i][coluna] == 'Q')
            return false;

    for (int i = linha - 1, j = coluna - 1; i >= 0 && j >= 0; i--, j--)
        if (tabuleiro[i][j] == 'Q')
            return false;

    for (int i = linha - 1, j = coluna + 1; i >= 0 && j < N; i--, j++)
        if (tabuleiro[i][j] == 'Q')
            return false;

    return true;
}

bool colocarRainhas(char **tabuleiro, int N, int linha)
{   
    if (linha >= N)
    {
        return true;
    }

    for (int coluna = 0; coluna < N; coluna++) {
        if (posicaoSegura(tabuleiro, N, linha, coluna)) {
            tabuleiro[linha][coluna] = 'Q';

            if (colocarRainhas(tabuleiro, N, linha + 1))
                return true;

            tabuleiro[linha][coluna] = '.';  
        }
    }

    return false;
}

void imprimirMatriz(char **tabuleiro, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int N;

    printf("Insira o tamanho do tabuleiro: ");
    scanf("%d", &N);

    char **tabuleiro = (char **)malloc(N * sizeof(char *));

    for (int i = 0; i < N; i++)
    {
        tabuleiro[i] = (char *)malloc(N * sizeof(char));
    }

    // Preencher com .
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            tabuleiro[i][j] = '.';
        }
    }

    if (colocarRainhas(tabuleiro, N, 0))
    {
        imprimirMatriz(tabuleiro, N);
    } else {
        printf("Não encontrou solução");
    }

    for (int i = 0; i < N; i++)
    {
        free(tabuleiro[i]);
    }
    free(tabuleiro);

    return 0;
}
