#include <stdio.h>
#include <stdlib.h>

int main() {
  int action;

  while (1) {
    printf("1 - Criar JSON\n2 - Visualizar JSONs\n");
    action = scanf("%d", &action);

    if (action == 1) {
      char key;
      char value;

      printf("Insira Nome do Campo: ");
      scanf("%s", &key);

      printf("Insira Valor do Campo: ");
      scanf("%s", &value);

      printf("\n%s:%s\n", &key, &value);

    } else {
      printf("visualizar jsons\n");
    }

    break;
  }
  return 1;
}
