#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int action;

  while (1) {
    printf("1 - Criar JSON\n2 - Visualizar JSONs\n");
    action = scanf("%d", &action);

    if (action == 1) {
      printf("criar json\n");
    } else {
      printf("visualizar jsons\n");
    }

    break;
  }
  return 1;
}
