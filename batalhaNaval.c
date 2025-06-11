#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// Definições de constantes para o tabuleiro e navios
#define BOARD_SIZE 10 // Tamanho do tabuleiro (10x10)
#define SHIP_SIZE 3   // Tamanho fixo dos navios (3 posições)
#define WATER 0       // Representa água no tabuleiro
#define SHIP 3        // Representa uma parte de um navio no tabuleiro

// Função para inicializar o tabuleiro com água (valor 0)
void initializeBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = WATER; // Define cada célula como água
        }
    }
}

// Função para verificar se um navio pode ser posicionado nas coordenadas dadas
// sem sair dos limites do tabuleiro ou sobrepor outro navio.
// orientation: 0 para horizontal, 1 para vertical
int canPlaceShip(int board[BOARD_SIZE][BOARD_SIZE], int startRow, int startCol, int orientation) {
    if (orientation == 0) { // Navio horizontal
        // Verifica se o navio ultrapassa o limite direito do tabuleiro
        if (startCol + SHIP_SIZE > BOARD_SIZE) {
            return 0; // Não pode posicionar (fora dos limites)
        }
        // Verifica se há sobreposição com outro navio
        for (int j = 0; j < SHIP_SIZE; j++) {
            if (board[startRow][startCol + j] != WATER) {
                return 0; // Não pode posicionar (há sobreposição)
            }
        }
    } else { // Navio vertical
        // Verifica se o navio ultrapassa o limite inferior do tabuleiro
        if (startRow + SHIP_SIZE > BOARD_SIZE) {
            return 0; // Não pode posicionar (fora dos limites)
        }
        // Verifica se há sobreposição com outro navio
        for (int i = 0; i < SHIP_SIZE; i++) {
            if (board[startRow + i][startCol] != WATER) {
                return 0; // Não pode posicionar (há sobreposição)
            }
        }
    }
    return 1; // Pode posicionar o navio
}

// Função para posicionar um navio no tabuleiro
// orientation: 0 para horizontal, 1 para vertical
void placeShip(int board[BOARD_SIZE][BOARD_SIZE], int startRow, int startCol, int orientation) {
    if (orientation == 0) { // Navio horizontal
        for (int j = 0; j < SHIP_SIZE; j++) {
            board[startRow][startCol + j] = SHIP; // Marca as posições do navio
        }
    } else { // Navio vertical
        for (int i = 0; i < SHIP_SIZE; i++) {
            board[startRow + i][startCol] = SHIP; // Marca as posições do navio
        }
    }
}

// Função para exibir o tabuleiro no console
void displayBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    // Imprime os números das colunas
    printf("   ");
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf("%2d ", col);
    }
    printf("\n");

    // Imprime uma linha separadora para as colunas
    printf("   ");
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf("---");
    }
    printf("\n");

    // Imprime o tabuleiro linha por linha
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d|", i); // Imprime o número da linha
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%2d ", board[i][j]); // Imprime o valor da célula (0 para água, 3 para navio)
        }
        printf("\n"); // Nova linha após cada linha do tabuleiro
    }
}

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
        
    int board[BOARD_SIZE][BOARD_SIZE]; // Declaração da matriz do tabuleiro

    // Inicializa o tabuleiro com água
    initializeBoard(board);

    // --- Navio 1: Horizontal ---
    // Coordenadas e orientação do primeiro navio (definidos diretamente no código)
    int ship1_startRow = 2;
    int ship1_startCol = 1;
    int ship1_orientation = 0; // 0 para horizontal

    // Valida e tenta posicionar o Navio 1
    if (canPlaceShip(board, ship1_startRow, ship1_startCol, ship1_orientation)) {
        placeShip(board, ship1_startRow, ship1_startCol, ship1_orientation);
        printf("Navio 1 (Horizontal) posicionado com sucesso em (%d, %d)\n", ship1_startRow, ship1_startCol);
    } else {
        printf("Erro: Não foi possível posicionar o Navio 1 (Horizontal) em (%d, %d). Verifique as coordenadas ou sobreposição.\n", ship1_startRow, ship1_startCol);
    }

    // --- Navio 2: Vertical ---
    // Coordenadas e orientação do segundo navio (definidos diretamente no código)
    int ship2_startRow = 4;
    int ship2_startCol = 5;
    int ship2_orientation = 1; // 1 para vertical

    // Valida e tenta posicionar o Navio 2
    if (canPlaceShip(board, ship2_startRow, ship2_startCol, ship2_orientation)) {
        placeShip(board, ship2_startRow, ship2_startCol, ship2_orientation);
        printf("Navio 2 (Vertical) posicionado com sucesso em (%d, %d)\n", ship2_startRow, ship2_startCol);
    } else {
        printf("Erro: Não foi possível posicionar o Navio 2 (Vertical) em (%d, %d). Verifique as coordenadas ou sobreposição.\n", ship2_startRow, ship2_startCol);
    }

    // Exibe o tabuleiro final com os navios posicionados
    printf("\n--- Tabuleiro Final do Jogo ---\n");
    displayBoard(board);

    return 0; // Retorna 0 para indicar que o programa foi executado com sucesso
}