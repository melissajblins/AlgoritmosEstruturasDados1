#include <stdio.h>
#include <stdlib.h>

void substituir_palavra(char *texto, char *palavra1, char *palavra2)
{
    int tamanho_palavra1 = 0;
    int tamanho_palavra2 = 0;
    int varre_texto = 0;
    int varre_texto_alterado = 0;
    char texto_alterado[5000];
    int percorre_texto = 0;
    int percorre_texto_alterado = 0;
    int quantidadeCorrespondecia = 0;

    while (palavra1[tamanho_palavra1] != '\0')
    {
        tamanho_palavra1++;
    }

    while (palavra2[tamanho_palavra2] != '\0')
    {
        tamanho_palavra2++;
    }

    while (texto[varre_texto] != '\0')
    {
        if (texto[varre_texto] == palavra1[0] || texto[varre_texto] == (palavra1[0] + 32) || texto[varre_texto] == (palavra1[0] - 32))
        {
            int posicao_inicial = varre_texto;
            int varre_palavra1 = 0;
            int varre_palavra2 = 0;
            int corresponde = 1;
            int julga_posterior = 0;
            for (varre_texto; varre_texto < posicao_inicial + tamanho_palavra1; varre_texto++)
            {
                if (texto[varre_texto] == palavra1[varre_palavra1] || texto[varre_texto] == (palavra1[varre_palavra1] + 32) || texto[varre_texto] == (palavra1[varre_palavra1] - 32))
                {
                    varre_palavra1++;
                }
                else
                {
                    corresponde = 0;
                    break;
                }
            }
            if (texto[varre_texto] == ' ' || texto[varre_texto] == '.')
            {
                julga_posterior = 1;
            }
            if (corresponde == 1 && julga_posterior == 1)
            {
                quantidadeCorrespondecia++;
                printf("Corresponde: index: %d: \n", varre_texto_alterado);
                for (int i = 0; i < tamanho_palavra2; i++)
                {
                    texto_alterado[varre_texto_alterado] = palavra2[i];
                    printf("Seta >>>> varre_texto: %d: varre_texto_alterado: %d,  %s\n", varre_texto, varre_texto_alterado, texto_alterado);
                    varre_texto_alterado++;
                }
                varre_texto_alterado--;
                varre_texto--;

                //printf("%s\n",texto_alterado);
                //varre_texto = varre_texto - 1;
                //varre_texto_alterado = varre_texto_alterado - quantidadeCorrespondecia;
                //varre_texto_alterado--;
            }
            else
            {
                printf("Não Corresponde: %d\n", posicao_inicial);
                varre_texto = posicao_inicial;
                texto_alterado[varre_texto_alterado] = texto[varre_texto];
                printf("aaaaaaaaaaaa: %d\n", varre_texto);
                
            }
        }
        else
        {

            // printf("varre_texto: %d; varre_texto_alterado: %d\n",varre_texto,varre_texto_alterado);
            texto_alterado[varre_texto_alterado] = texto[varre_texto];
            printf(">>>>varre_texto: %d: varre_texto_alterado: %d,  %s\n", varre_texto, varre_texto_alterado, texto_alterado);
        }

        varre_texto_alterado++;
        varre_texto++;
    }

    texto[0] = '\0';
    varre_texto_alterado = 0;
    while (texto_alterado[varre_texto_alterado] != '\0')
    {
        texto[varre_texto_alterado] = texto_alterado[varre_texto_alterado];
        varre_texto_alterado++;
    }
    texto[varre_texto_alterado] = '\0';
}

int main()
{
    char texto[5000] = "Uma linguagem de programacao muito usada eh o Java.";
    char palavra1[50] = "Java";
    char palavra2[50] = "C";

    substituir_palavra(texto, palavra1, palavra2);

    printf("%s", texto);

    return 0;
}