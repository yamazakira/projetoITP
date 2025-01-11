#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int checarDiagonais(char **tabuleiro, int N, int i, int j)
{
    if (i == j)
    {
        for (int k = 0; k < N; k++)
        {
            if (tabuleiro[k][k] == 'Q')
            {
                return 1;
            }
        }
    }

    // verificar essa parte
    if (i + j == N - 1)
    {
        for (int k = 0; k < N; k++)
        {
            if (tabuleiro[k][N - k - 1] == 'Q')
            {
                return 1;
            }
        }
    }
    return 0;
}

void colocarRainhas(char **tabuleiro, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int jaTemQ = 0;

            // procurar Q na linha i
            for (int k = 0; k < N; k++)
            {
                if (tabuleiro[i][k] == 'Q')
                {
                    jaTemQ = 1;
                    break;
                }
            }

            for (int k = 0; k < N; k++)
            {
                if (tabuleiro[k][j] == 'Q')
                {
                    jaTemQ = 1;
                    break;
                }
            }

            // Verifica se já existe um 'Q' nas diagonais
            if (jaTemQ != 1 && checarDiagonais(tabuleiro, N, i, j) != 1)
            {
                tabuleiro[i][j] = 'Q';
            }
        }
    }
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

    // Aloca N espaços para cada já tabuleiro alocado
    for (int i = 0; i < N; i++)
    {
        tabuleiro[i] = (char *)malloc(N * sizeof(char));
    }

    // Preenche com .
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            tabuleiro[i][j] = '.';
        }
    }

    colocarRainhas(tabuleiro, N);

    imprimirMatriz(tabuleiro, N);

    // liberar memória
    for (int i = 0; i < N; i++)
    {
        free(tabuleiro[i]);
    }
    free(tabuleiro);

    return 0;
}