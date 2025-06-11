#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// Definições de constantes para o tabuleiro e navios
#define BOARD_SIZE 10 // Tamanho do tabuleiro (10x10)
#define SHIP_SIZE 3   // Tamanho fixo dos navios (3 posições)
#define WATER 0       // Representa água no tabuleiro
#define SHIP 3        // Representa uma parte de um navio no tabuleiro

// Enumeração para as orientações dos navios, tornando o código mais legível
typedef enum {
    HORIZONTAL,
    VERTICAL,
    DIAGONAL_PRINCIPAL, // Ex: (0,0), (1,1), (2,2) -> linha e coluna aumentam
    DIAGONAL_SECUNDARIA // Ex: (0,9), (1,8), (2,7) -> linha aumenta, coluna diminui
} ShipOrientation;

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
int canPlaceShip(int board[BOARD_SIZE][BOARD_SIZE], int startRow, int startCol, ShipOrientation orientation) {
    // Loop para verificar cada célula que o navio ocuparia
    for (int k = 0; k < SHIP_SIZE; k++) {
        int currentRow = startRow;
        int currentCol = startCol;

        // Ajusta as coordenadas com base na orientação do navio
        switch (orientation) {
            case HORIZONTAL:
                currentCol = startCol + k;
                break;
            case VERTICAL:
                currentRow = startRow + k;
                break;
            case DIAGONAL_PRINCIPAL: // Linha e coluna aumentam
                currentRow = startRow + k;
                currentCol = startCol + k;
                break;
            case DIAGONAL_SECUNDARIA: // Linha aumenta, coluna diminui
                currentRow = startRow + k;
                currentCol = startCol - k; // Coluna diminui
                break;
            default:
                return 0; // Orientação inválida
        }

        // 1. Validação de Limites: Verifica se as coordenadas estão dentro do tabuleiro
        if (currentRow < 0 || currentRow >= BOARD_SIZE ||
            currentCol < 0 || currentCol >= BOARD_SIZE) {
            return 0; // Fora dos limites do tabuleiro
        }

        // 2. Validação de Sobreposição: Verifica se a célula já está ocupada por outro navio
        if (board[currentRow][currentCol] != WATER) {
            return 0; // Célula já ocupada (sobreposição)
        }
    }
    return 1; // Pode posicionar o navio
}

// Função para posicionar um navio no tabuleiro, marcando suas posições
void placeShip(int board[BOARD_SIZE][BOARD_SIZE], int startRow, int startCol, ShipOrientation orientation) {
    for (int k = 0; k < SHIP_SIZE; k++) {
        int currentRow = startRow;
        int currentCol = startCol;

        // Ajusta as coordenadas com base na orientação do navio e marca a célula
        switch (orientation) {
            case HORIZONTAL:
                board[currentRow][startCol + k] = SHIP;
                break;
            case VERTICAL:
                board[startRow + k][currentCol] = SHIP;
                break;
            case DIAGONAL_PRINCIPAL:
                board[startRow + k][startCol + k] = SHIP;
                break;
            case DIAGONAL_SECUNDARIA:
                board[startRow + k][startCol - k] = SHIP;
                break;
            default:
                // Não deve acontecer se canPlaceShip for chamado antes
                break;
        }
    }
}

// Função para exibir o tabuleiro no console
void displayBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    // Imprime os números das colunas
    printf("   ");
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf("%2d ", col); // Espaçamento para números de 0 a 9
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

    // --- Posicionamento dos Quatro Navios ---

    // Navio 1: Horizontal (NOVAS COORDENADAS para evitar sobreposição com diagonais)
    // Movido para o meio do tabuleiro
    int ship1_startRow = 5;
    int ship1_startCol = 2;
    ShipOrientation ship1_orientation = HORIZONTAL;

    if (canPlaceShip(board, ship1_startRow, ship1_startCol, ship1_orientation)) {
        placeShip(board, ship1_startRow, ship1_startCol, ship1_orientation);
        printf("Navio 1 (Horizontal) posicionado em (%d, %d)\n", ship1_startRow, ship1_startCol);
    } else {
        printf("ERRO: Não foi possível posicionar Navio 1 (Horizontal) em (%d, %d). Ajuste as coordenadas.\n", ship1_startRow, ship1_startCol);
    }

    // Navio 2: Vertical (NOVAS COORDENADAS para evitar sobreposição com diagonais)
    // Movido para a parte inferior direita
    int ship2_startRow = 6;
    int ship2_startCol = 7;
    ShipOrientation ship2_orientation = VERTICAL;

    if (canPlaceShip(board, ship2_startRow, ship2_startCol, ship2_orientation)) {
        placeShip(board, ship2_startRow, ship2_startCol, ship2_orientation);
        printf("Navio 2 (Vertical) posicionado em (%d, %d)\n", ship2_startRow, ship2_startCol);
    } else {
        printf("ERRO: Não foi possível posicionar Navio 2 (Vertical) em (%d, %d). Ajuste as coordenadas.\n", ship2_startRow, ship2_startCol);
    }

    // Navio 3: Diagonal Principal (conforme a regra tabuleiro[i][i])
    // Começa no canto superior esquerdo
    int ship3_startRow = 0;
    int ship3_startCol = 0;
    ShipOrientation ship3_orientation = DIAGONAL_PRINCIPAL;

    if (canPlaceShip(board, ship3_startRow, ship3_startCol, ship3_orientation)) {
        placeShip(board, ship3_startRow, ship3_startCol, ship3_orientation);
        printf("Navio 3 (Diagonal Principal) posicionado em (%d, %d)\n", ship3_startRow, ship3_startCol);
    } else {
        printf("ERRO: Não foi possível posicionar Navio 3 (Diagonal Principal) em (%d, %d). Ajuste as coordenadas.\n", ship3_startRow, ship3_startCol);
    }

    // Navio 4: Diagonal Secundária (conforme a regra tabuleiro[i][9-i])
    // Começa no canto superior direito
    int ship4_startRow = 0;
    int ship4_startCol = 9;
    ShipOrientation ship4_orientation = DIAGONAL_SECUNDARIA;

    if (canPlaceShip(board, ship4_startRow, ship4_startCol, ship4_orientation)) {
        placeShip(board, ship4_startRow, ship4_startCol, ship4_orientation);
        printf("Navio 4 (Diagonal Secundária) posicionado em (%d, %d)\n", ship4_startRow, ship4_startCol);
    } else {
        printf("ERRO: Não foi possível posicionar Navio 4 (Diagonal Secundária) em (%d, %d). Ajuste as coordenadas.\n", ship4_startRow, ship4_startCol);
    }

    // Exibe o tabuleiro final com todos os navios posicionados
    printf("\n--- Tabuleiro Final do Jogo ---\n");
    displayBoard(board);

    return 0; // Retorna 0 para indicar que o programa foi executado com sucesso
}