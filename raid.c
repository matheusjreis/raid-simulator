#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 3
#define COLS 3

void writeMatrixToFile(int matrix[ROWS][COLS], const char *filename) {
    FILE *file;
    
    file = fopen(filename, "w");
    
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!.\n");
        exit(1);
    }
    
    fprintf(file, "** RAID 4 - SIMULATOR **\n");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            fprintf(file, "%d ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }
    
    fclose(file);
}

void readMatrixFromFile(int matrix[ROWS][COLS], const char *filename) {
    FILE *file;
    
    file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!.\n");
        exit(1);
    }

    char line[100];
    int row = 0;

    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file) && row < ROWS) {
        char *token = strtok(line, " ");
        int col = 0;

        while (token != NULL && col < COLS) {
            matrix[row][col] = atoi(token);
            col++;
            token = strtok(NULL, " ");
        }

        row++;
    }

    fclose(file);
}

int main() {
    int matrix[ROWS][COLS];
    
    const char *folder = "disks";
    const char *filename = "disks/raid_output.txt";
    
    system("mkdir -p disks");
    
    printf("Digite os blocos do disco linha por linha, pressionando Enter apos cada linha:\n");
    
    for (int i = 0; i < ROWS; i++) {
        printf("Blocos da linha %d: ", i + 1);
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &matrix[i][j]); 
        }
        getchar(); 
    }
    
    writeMatrixToFile(matrix, filename);
    
    printf("Dado foi gravado no disco!\n");

    readMatrixFromFile(matrix, filename);

    printf("Discos contidos no sistema lida do arquivo:\n");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}