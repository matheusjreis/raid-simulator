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
    
    return 0;
}
