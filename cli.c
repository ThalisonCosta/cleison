#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  while (1) {
    printf("1 - Criar JSON\n2 - Visualizar JSONs\n");
    int action;
    scanf("%d", &action);

    if (action == 1) {
      char key[100]; 
      char value[100];
      char *h_key;
      char *h_value;

      printf("Insira Nome do Campo: ");
      scanf("%s", key);
      h_key = (char *)malloc((strlen(key) + 1) * sizeof(char));
      strcpy(h_key, key);

      printf("Insira Valor do Campo: ");
      scanf("%s", value);
      h_value = (char *)malloc((strlen(value) + 1) * sizeof(char));
      strcpy(h_value, value);

      printf("\n{\n\t\"%s\":\"%s\"\n}\n", h_key, h_value);

      free(h_key); 
      free(h_value);
    } else {
      printf("Visualizar JSONs\n");
    }

    break;
  }

  return 0;
}
