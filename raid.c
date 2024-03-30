#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DISK_SIZE 3
#define DISK_QUANTITY 3
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

int *getBitsOnDisk()
{
    char line[256];
    int lineBit = 1;
    int *bitDisks = NULL;
    int linesQuantity = 0;
    int diskCounter = 0;

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    while (fgets(line, sizeof(line), file))
    {
        linesQuantity++;
    }

    bitDisks = (int *)malloc(linesQuantity * sizeof(int));
    rewind(file);

    while (fgets(line, sizeof(line), file))
    {
        bitDisks[diskCounter] = atoi(line);
        diskCounter++;
    }
    fclose(file);
    return bitDisks;
}

void writeBitsToFile()
{
    system("mkdir -p disks");

    FILE *file;
    file = fopen(filename, "w");
    int diskBits[DISK_QUANTITY];
    printf("Digite os bits dos dados no disco,linha por linha, pressionando Enter apos cada linha:\n");

    for (int i = 0; i < DISK_QUANTITY; i++)
    {
        printf("Bits - Disco %d: ", i + 1);
        scanf("%d", &diskBits[i]);
        getchar();
    }

    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!.\n");
        exit(1);
    }

    for (int i = 0; i < DISK_QUANTITY; i++)
    {
        fprintf(file, "%d", diskBits[i]);
        if(i != DISK_QUANTITY - 1){
            fprintf(file, "\n");
        }
    }

    printf("Dados inseridos com sucesso!.\n");
    fclose(file);
}

void addLineToFile(int line) {
    FILE *file = fopen(filename, "a");
    
    if (file == NULL) {
        printf("Erro: Não foi possível abrir arquivo %s\n", filename);
        return;
    }

    fprintf(file, "\n%d", line);

    fclose(file);
}

void recoveryBitData(){
    int* bitsOnDisk = getBitsOnDisk();
    int arrayLength = sizeof(bitsOnDisk) / sizeof(bitsOnDisk[0]);
    int xorResult = 0;

    for (int i = 0; i <= arrayLength; i++)
    {
        printf("%d \n",bitsOnDisk[i]);
        xorResult ^= bitsOnDisk[i];
    }

    addLineToFile(xorResult);
    printf("VALOR RECUPERADO: || %d ||\n", xorResult);
}


void menu()
{
    int option = 1;

    while (option != 5)
    {
        printf("************************\n");
        printf("** RAID 5 - SIMULATOR **\n");
        printf("************************\n");

        printf("1 - INSERIR DADOS\n");
        printf("3 - CONSULTAR DADOS\n");
        printf("4 - RECUPERAR DADO PERDIDO\n");
        printf("5 - SAIR\n");

        printf("Digite uma opção: \n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            writeBitsToFile();
            break;
        case 2:
            break;
        case 3:
            readBitDisksFromFile(filename);
            break;
        case 4:
            recoveryBitData();
            break;
        default:
            readBitDisksFromFile(filename);
        }
    }

    printf("SIMULADOR FINALIZADO COM SUCESSO! \n");
}

int main()
{
    menu();
    return 0;
}