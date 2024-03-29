#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DISK_SIZE 3
#define ROWS 5
#define COLS 5

const char *folder = "disks";
const char *filename = "disks/raid_output.txt";

void writeDiskBitsToFile(int diskBits[DISK_SIZE], const char *filename)
{

    // TODO - CHECK IF  ITS INTEGER AND ITS HAS ONLY 1s AND 0s
    FILE *file;

    file = fopen(filename, "w");

    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!.\n");
        exit(1);
    }

    for (int i = 0; i < DISK_SIZE; i++)
    {
        fprintf(file, "%d ", diskBits[i]);
    }

    fclose(file);
}

void readBitDisksFromFile(const char *filename)
{
    char line[256];
    int lineBit = 1;
    int diskNumber = 1;

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    printf("\n####################################\n");
    while (fgets(line, sizeof(line), file))
    {
        printf("Dados Disco %d: %s", diskNumber, line);
        diskNumber++;
    }
    printf("\n####################################\n");

    printf("\n");

    fclose(file);
}

void writeMatrixToFile(int matrix[ROWS][COLS], const char *filename)
{
    FILE *file;

    file = fopen(filename, "w");

    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!.\n");
        exit(1);
    }

    fprintf(file, "** RAID 4 - SIMULATOR **\n");

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            fprintf(file, "%d ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

void readMatrixFromFile(int matrix[ROWS][COLS], const char *filename)
{
    FILE *file;
    char line[100];
    int row = 0;

    file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!.\n");
        exit(1);
    }

    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file) && row < ROWS)
    {
        char *token = strtok(line, " ");
        int col = 0;

        while (token != NULL && col < COLS)
        {
            matrix[row][col] = atoi(token);
            col++;
            token = strtok(NULL, " ");
        }

        row++;
    }

    fclose(file);
}

void menu()
{
    int option = 1;

    while (option != 4)
    {
        printf("************************\n");
        printf("** RAID 5 - SIMULATOR **\n");
        printf("************************\n");

        printf("1 - INSERIR DADOS\n");
        printf("2 - REMOVER DADOS\n");
        printf("3 - CONSULTAR DADOS\n");
        printf("4 - SAIR\n");

        printf("Digite uma opção: \n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            readBitDisksFromFile(filename);
            break;
        case 4:
            break;
        default:
            readBitDisksFromFile(filename);
        }
    }

    printf("SIMULADOR FINALIZADO COM SUCESSO! \n");
}

int main()
{
    int matrix[ROWS][COLS];
    int option;

    system("mkdir -p disks");

    menu();
    // printf("Digite os blocos do disco linha por linha, pressionando Enter apos cada linha:\n");

    // for (int i = 0; i < ROWS; i++) {
    //     printf("Blocos da linha %d: ", i + 1);
    //     for (int j = 0; j < COLS; j++) {
    //         scanf("%d", &matrix[i][j]);
    //     }
    //     getchar();
    // }

    // writeMatrixToFile(matrix, filename);

    // printf("Dado foi gravado no disco!\n");

    // readMatrixFromFile(matrix, filename);

    // printf("Discos contidos no sistema lida do arquivo:\n");

    // for (int i = 0; i < ROWS; i++) {
    //     for (int j = 0; j < COLS; j++) {
    //         // TODO - COLORIR BLOCO DE PARIDADE
    //         printf("%d ", matrix[i][j]);
    //     }
    //     printf("\n");
    // }    

    return 0;
}