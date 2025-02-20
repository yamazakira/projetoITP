#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Função para checar se a posição atual é segura para colocar uma rainha
bool posicaoSegura(char **tabuleiro, int N, int linha, int coluna)
{
    // Verifica a coluna
    for (int i = 0; i < linha; i++)
        if (tabuleiro[i][coluna] == 'Q')
            return false;

    // Verifica a diagonal esquerda
    for (int i = linha - 1, j = coluna - 1; i >= 0 && j >= 0; i--, j--)
        if (tabuleiro[i][j] == 'Q')
            return false;

    // Verifica a diagonal direita
    for (int i = linha - 1, j = coluna + 1; i >= 0 && j < N; i--, j++)
        if (tabuleiro[i][j] == 'Q')
            return false;

    return true;
}

bool colocarRainhas(char **tabuleiro, int N, int linha)
{   
    // Esta função se chama recursivamente, aumentando por 1 a variável 'linha'
    // Quando chegar na iteração em que linha>=N, retorna true, parando o loop
    if (linha >= N)
    {
        return true;
    }

    // Tenta colocar uma rainha em cada coluna da linha
    for (int coluna = 0; coluna < N; coluna++) {
        if (posicaoSegura(tabuleiro, N, linha, coluna)) {
            tabuleiro[linha][coluna] = 'Q';  // Coloca a rainha

            // Testa recursivamente se NA PROXIMA LINHA, é possível adicionar uma nova rainha (Q). Se for, ele passa para a próxima linha. mas se não for, ele ativa o proximo passo
            if (colocarRainhas(tabuleiro, N, linha + 1))
                return true;

            // Caso na proxima linha não dê para colocar uma nova rainha, ele remove a rainha atual com a linha abaixo e tentará o próximo item da mesma linha. Assim a gente garante que o número de rainhas serpa = a N.
            tabuleiro[linha][coluna] = '.';  
        }
    }

    return false;
}

// Função para imprimir a matriz do tabuleiro
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

    // Aloca o espaço para os ponteiros das linhas do tabuleiro.
    // tabuleiro é um ponteiro para um ponteiro, representando uma matriz 2d
    char **tabuleiro = (char **)malloc(N * sizeof(char *));

    // Alocação do espaço das linhas em si. Cada linha terá N itens
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

    if (colocarRainhas(tabuleiro, N, 0))
    {
        printf("Solução encontrada com %d rainhas:\n", N);
        imprimirMatriz(tabuleiro, N);
    } else {
        printf("Não encontrou solução");
    }

    // Liberando memória
    for (int i = 0; i < N; i++)
    {
        free(tabuleiro[i]);
    }
    free(tabuleiro);

    return 0;
}