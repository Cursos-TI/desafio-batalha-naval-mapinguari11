#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).

    int tabuleiro[10][11]; //11 colunas para poder implementar a coluna dos números do tabuleiro.

    //inicializa o tabuleiro
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if (j == 0)
            {
                tabuleiro[i][j] = i + 1; //Para gerar os números na primeira coluna
            } 
            else 
            {
                tabuleiro[i][j] = 0; //para gerar as casas com 0
            }
            
        }
    }

    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.

    //Navio horizontal: tabuleiro[3][3], tabuleiro[3][4], tabuleiro[3][5]
    //Navio vertical: tabuleiro[1][6], tabuleiro[1][7], tabuleiro[1][8]
    
    tabuleiro[3][3] = 3; 
    tabuleiro[3][4] = 3; 
    tabuleiro[3][5] = 3;

    tabuleiro[5][8] = 3; 
    tabuleiro[6][8] = 3;
    tabuleiro[7][8] = 3;

    //Primeira diagonal - não vai ser a diagonal principal, porque a matriz é 10x11 (apesar do tabuleiro ser 10x10). É a diagonal que começa do A2 e vai até o I10
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if (i == j && i >= 4 && i <=6)
            {
                if(tabuleiro[i][j] == 3) break;
                tabuleiro[i][j] = 3;
            }
            
        }
    }

    //Segunda diagonal - Não é a segunda diagonal principal, mas sim a diagonal que vai do C1 ao A3.
    for (int i = 0; i < 5; i++) // i< 5 porque a a coluna 0 não tem letra
    {
        for (int j = 0; j < 5; j++)
        {
            if (i+j == 3 && i < 3) // i < 3 porque em i == 3 tabuleiro[3][0] == 4, que é a coluna de referência do tabuleiro
            {
                tabuleiro[i][j] = 3;
            }
            
        }
        
    }
    
    //Cone - O 1 representa a área afetada. O 5 representa partes de navio que foram atingidas pelo cone (se alguma for afetada)
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if ((i == 0 && j == 8) || (i == 1 && j >= 7 && j <= 9) || (i == 2 && j >=6 && j <= 10))
            {
                if (tabuleiro[i][j] == 3) {
                    tabuleiro[i][j] = 5;
                } else
                {
                    tabuleiro[i][j] = 1;
                }
            }
            
        }
        
    }

    //Octaedro - O 1 representa a área afetada. O 5 representa partes de navio que foram atingidas pelo cone (se alguma for afetada)
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if ((i == 0 && j == 3) || (i == 1 && j >= 2 && j <= 4) || (i == 2 && j ==3))
            {
                if (tabuleiro[i][j] == 3) {
                    tabuleiro[i][j] = 5;
                } else
                {
                    tabuleiro[i][j] = 1;
                }
            }
            
        }
        
    }

    //Cruz - O 1 representa a área afetada. O 5 representa partes de navio que foram atingidas pelo cone (se alguma for afetada)
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if ((i == 5 && j == 7) || (i == 6 && j >= 5 && j <= 9) || (i == 7 && j == 7))
            {
                if (tabuleiro[i][j] == 3) {
                    tabuleiro[i][j] = 5;
                } else
                {
                    tabuleiro[i][j] = 1;
                }
            }
            
        }
        
    }

    printf("   A B C D E F G H I J\n"); //para gerar a linha no topo do tabuleiro
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if (j == 0) //esse if e os ifs aninhados são puramente estéticos, para que todas as linhas e colunas fiquem alinhadas corretamente
            {
                if (i == 9)
                {
                    printf("%d ", tabuleiro[i][j]);
                }
                else
                {
                    printf("%d  ", tabuleiro[i][j]);
                }
            }
            else
            {
                printf("%d ", tabuleiro[i][j]);
            }
        }
        printf("\n");
    }
    

    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    
    printf("\nNavio horizontal:\n");
    printf("C4, D4, E4\n");
    printf("\n");
    printf("Navio vertical:\n");
    printf("H6, H7, H8\n");


    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
