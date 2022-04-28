#include <stdio.h>

char oitavas[] = "ABCDEFGHIJKLMNOP";
char quartas[8];
char semifinal[4];
char final[2];
char ganhador[2];

void jogo(int quantidade_jogos, char *times_jogando, char *ganhadores) {
  int i = 0;
  int gols1, gols2;
  for (i; i < quantidade_jogos; i++) {
    scanf("%d %d", &gols1, &gols2);
    if (gols1 > gols2)
      ganhadores[i] = times_jogando[i * 2];
    else
      ganhadores[i] = times_jogando[i * 2 + 1];
  }
}  

int main() {
  jogo(8, oitavas, quartas);
  jogo(4, quartas, semifinal);
  jogo(2, semifinal, final);
  jogo(1, final, ganhador);
  
  printf("%c", ganhador[0]);

  return 0;
}