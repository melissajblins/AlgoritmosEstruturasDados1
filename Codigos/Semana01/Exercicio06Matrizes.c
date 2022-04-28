#include <stdio.h>

/* 
Melissa Junqueira de Barros Lins, 11201920583
*/

void remover_numeros_matriz(int l, int c, int n_linhas, int n_colunas, int m[n_linhas][n_colunas])
{
    int valorTroca = m[l][c];
    m[l][c] = 0;
    trocarNumero(valorTroca,l,c,n_linhas,n_colunas,m);
}


void trocarNumero(int valorTroca, int l, int c, int n_linhas, int n_colunas, int m[n_linhas][n_colunas])
{

    int adjacentes[4][2];
    for (int i = 0; i < 4; i++)
    {
        adjacentes[i][0] = -1;
        adjacentes[i][1] = -1;
    }

    if (c != 0)
    {
        adjacentes[0][0] = l;
        adjacentes[0][1] = (c - 1);
    }

    if (l != 0)
    {
        adjacentes[1][0] = (l - 1);
        adjacentes[1][1] = (c);
    }

    if (c < (n_colunas - 1))
    {
        adjacentes[2][0] = l;
        adjacentes[2][1] = (c + 1);
    }

    if (l < (n_linhas - 1))
    {
        adjacentes[3][0] = (l + 1);
        adjacentes[3][1] = (c);
    }

    for (int i = 0; i < 4; i++)
    {
        if(adjacentes[i][0] > -1){
            int nova_l = adjacentes[i][0];
            int nova_c = adjacentes[i][1];
            int numero = m[nova_l][nova_c];
            printf("[%d][%d] = %d\n", nova_l, nova_c,numero);
            if(numero == valorTroca){
                m[nova_l][nova_c] = 0;
                trocarNumero(valorTroca, nova_l, nova_c, n_linhas, n_colunas, m);
            }
            
        }
    }
}

int main()
{

    int m[5][5];
    m[0][0] = 11;
    m[0][1] = 22;
    m[0][2] = 33;
    m[0][3] = 22;
    m[0][4] = 55;
    m[1][0] = 22;
    m[1][1] = 22;
    m[1][2] = 22;
    m[1][3] = 11;
    m[1][4] = 11;
    m[2][0] = 22;
    m[2][1] = 22;
    m[2][2] = 33;
    m[2][3] = 44;
    m[2][4] = 11;
    m[3][0] = 11;
    m[3][1] = 22;
    m[3][2] = 22;
    m[3][3] = 22;
    m[3][4] = 22;
    m[4][0] = 11;
    m[4][1] = 11;
    m[4][2] = 11;
    m[4][3] = 22;
    m[4][4] = 55;

    remover_numeros_matriz(4, 2, 5, 5, m);
    return 0;
}