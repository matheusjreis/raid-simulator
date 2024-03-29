#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void writeMatrixToFile(int matrix[ROWS][COLS], const char *filename) {
    FILE *file;
    
    file = fopen(filename, "w");
    
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!.\n");
        exit(1);
    }
    
    fprintf(file, "%d %d\n", ROWS, COLS);
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            fprintf(file, "%d ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }
    
    fclose(file);
}

int main() {
    int matrix[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    const char *folder = "disks";
    const char *filename = "disks/matrix.txt";
    
    system("mkdir -p disks");
    
    writeMatrixToFile(matrix, filename);
    
    printf("Dado foi gravado no disco!\n");
    
    return 0;
}