// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

typedef struct Disciplina Disciplina;
struct Disciplina
{
    int cod;
    char *nome;
    int creditos;
    Disciplina *requisito;
};

typedef struct Curso Curso;
struct Curso
{
    int cod_curso;
    char *nome_curso;
    Disciplina *ultima_disciplina;
};

void insere_disciplina(Curso *curso, Disciplina *nova_disciplina)
{
     if (curso->ultima_disciplina == NULL)
     {
         curso->ultima_disciplina = nova_disciplina;
     }
     else
     {

         Disciplina *atual = curso->ultima_disciplina;
         int tamanho_nome_disciplina = 0;
         while (nova_disciplina->nome[tamanho_nome_disciplina] != '\0')
         {
             tamanho_nome_disciplina++;
         }

         Disciplina *posterior = NULL;

         while (atual != NULL)
         {
             
              printf("\n=============\nAtual nome %s\n=====================\n", atual->nome);
             
             
               int maior = 0;
               int tamanho_nome_diciplina_atual = 0;
               while (atual->nome[tamanho_nome_diciplina_atual] != '\0')
               {
                   tamanho_nome_diciplina_atual++;
               }

              for (int i = 0; i < tamanho_nome_disciplina; i++)
              {
                  printf("i: %d; atual: %d; nova: %d\n",i,atual->nome[i], nova_disciplina->nome[i]);
                  
                  if (i == tamanho_nome_diciplina_atual 
                  || nova_disciplina->nome[i] > atual->nome[i])
                  {
                      maior = 1;
                      break;
                  }else if(nova_disciplina->nome[i] < atual->nome[i]){
                      break;
                  }
              }
              
               printf("Maior %d\n", maior);

              if (maior)
              {
                  nova_disciplina->requisito = atual;
                  if (posterior != NULL)
                  {
                      printf("Posterior %s\n", posterior->nome);
                      posterior->requisito = nova_disciplina;
                  }
                  else
                  {
                      printf("Posterior null %d\n", maior);
                      curso->ultima_disciplina = nova_disciplina;
                  }
                  atual = NULL;
              }
              else
              {   posterior = atual;
                  
                  if(atual->requisito == NULL){
                      atual->requisito = nova_disciplina;
                      break;
                  }
                  atual = atual->requisito;
              }
         }
     }
}

int main() {
    // Write C code here
    printf("Start\n");
    
    // 99 Disciplina30 1
    // 1 Curso
    // 2
    // 10 Disciplina10 4
    // 20 Disciplina20 6

   Disciplina disciplina10;
   disciplina10.nome = malloc(sizeof(char) * 100);
   disciplina10.requisito = malloc(sizeof(Disciplina));
   disciplina10.cod = 10;
   disciplina10.nome =  "Disciplina10";
   disciplina10.creditos = 4;
   disciplina10.requisito = NULL;
   
   Disciplina disciplina20;
   disciplina20.nome = malloc(sizeof(char) * 100);
   disciplina20.requisito = malloc(sizeof(Disciplina));
   disciplina20.cod = 20;
   disciplina20.nome =  "Disciplina20";
   disciplina20.creditos = 6;
   disciplina20.requisito = &disciplina10;
   
   Curso curso;
   curso.nome_curso = malloc(sizeof(char) * 100);
   curso.ultima_disciplina = malloc(sizeof(Disciplina));
   curso.cod_curso = 1;
   curso.nome_curso = "curso";
   curso.ultima_disciplina = &disciplina20;
   
   Disciplina disciplina30;
   disciplina30.nome = malloc(sizeof(char) * 100);
   disciplina30.requisito = malloc(sizeof(Disciplina));
   disciplina30.cod = 99;
   disciplina30.nome =  "Disciplina30";
   disciplina30.creditos = 1;
   disciplina10.requisito = NULL;
   
   insere_disciplina(&curso, &disciplina30);
   
   printf("=======================\n");
   
   Disciplina *atual = curso.ultima_disciplina;
   while(atual != NULL){
       printf(">>>> %s\n", atual->nome);
       atual = atual->requisito;
   }
    
    printf("End\n");
    
    
    return 0;
}