#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  while (1) {
    printf("1 - Criar JSON\n2 - Visualizar JSONs\n");
    int action;
    scanf("%d", &action);

    if (action == 1) {
      char continue_inside[5];
      char rows[4098];

      while (1) {
        char key[100];
        char value[100];
        char *h_key;
        char *h_value;
        char row[512];

        printf("Insira Nome do Campo: ");
        scanf("%s", key);
        h_key = (char *)malloc((strlen(key) + 1) * sizeof(char));
        strcpy(h_key, key);

        printf("Insira Valor do Campo: ");
        scanf("%s", value);
        h_value = (char *)malloc((strlen(value) + 1) * sizeof(char));
        strcpy(h_value, value);

        sprintf(row, "\n\t\"%s\":\"%s\",\n", h_key, h_value);

        strcat(rows, row);
        printf("\n{%s}\n", rows);

        char stop[] = "nao";
        printf("Quer continuar? ");
        scanf("%s", continue_inside);

        int result;
        result = strcmp(stop, continue_inside);

        if (result == 0) {
          char filename[300];
          printf("Qual o nome do arquivo? ");
          scanf("%s", filename);

          free(h_key);
          free(h_value);

          // TODO: save into a file
          printf("saved your new json to %s\n", filename);
          break;
        }
      }
    } else {
      printf("Visualizar JSONs\n");
    }

    break;
  }

  return 0;
}
