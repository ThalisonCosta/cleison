#include <dirent.h>
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
      char *rows = NULL;
      char *h_rows = NULL;
      int first = 1;

      while (1) {
        char key[100];
        char value[100];
        char *h_key;
        char *h_value;
        char *row = NULL;

        printf("Insira Nome do Campo: ");
        scanf("%s", key);
        h_key = (char *)malloc((strlen(key) + 1) * sizeof(char));
        strcpy(h_key, key);

        printf("Insira Valor do Campo: ");
        scanf(
            "%s",
            value); // TODO:
                    // https://www.geeksforgeeks.org/program-check-input-integer-string/
                    // and also add some kind of validation to boolean
                    // values to remove the ""
        h_value = (char *)malloc((strlen(value) + 1) * sizeof(char));
        strcpy(h_value, value);

        row = (char *)malloc((strlen(h_key) + strlen(h_value) + 10) *
                             sizeof(char));
        if (first) {
          sprintf(row, "\t\"%s\":\"%s\"", h_key, h_value);
          first = 0;
        } else {
          sprintf(row, ",\n\t\"%s\":\"%s\"", h_key, h_value);
        }

        if (h_rows == NULL) {
          h_rows = (char *)malloc((strlen(row) + 1) * sizeof(char));
          strcpy(h_rows, row);
        } else {
          h_rows = (char *)realloc(h_rows, (strlen(h_rows) + strlen(row) + 1) *
                                               sizeof(char));
          strcat(h_rows, row);
        }

        free(h_key);
        free(h_value);
        free(row);

        char stop[5] = "n";
        printf("Quer continuar? ");
        scanf("%s", continue_inside);

        int result;
        result = strcmp(stop, continue_inside);

        if (result != 0) {
          continue;
        }

        char filename[300];
        printf("Qual o nome do arquivo? ");
        scanf("%s", filename);
        strcat(filename, ".json");

        FILE *output = fopen(filename, "w");
        if (output == NULL) {
          printf("Erro ao abrir o arquivo.\n");
          exit(1);
        }

        fprintf(output, "{\n%s\n}", h_rows);
        fclose(output);
        free(h_rows);

        printf("saved your new json to %s\n", filename);
        break;
      }
    } else {

      DIR *folder;
      struct dirent *entry;

      folder = opendir(".");
      if (folder == NULL) {
        perror("Unable to read directory");
        return (1);
      }

      char *contains;
      while ((entry = readdir(folder))) {
        contains = strstr(entry->d_name, ".json");
        if (contains) {
          printf("%s\n", entry->d_name);
        }
      }

      closedir(folder);

      char filename[300];
      printf("Choose one of the files above\n");
      scanf("%s", filename);

      strcat(filename, ".json");
      FILE *file = fopen(filename, "r");
      char string[100];
      while (fgets(string, 100, file)) {
        printf("%s\n", string);
      }

      fclose(file);
    }

    break;
  }

  return 0;
}
