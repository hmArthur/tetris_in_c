#include "piece.h"

int checkCollision(int shape[4][4], Piece* piece, int** grid, int offsetX, int offsetY) {
    int newX, newY;
    int i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (shape[i][j]) {
                newX = piece->velocity.x + j + offsetX;
                newY = piece->velocity.y + i + offsetY;

                if (newX < 0 || newX >= GRID_WIDTH || newY >= GRID_HEIGHT)
                    return 1;

                if (newY >= 0 && grid[newY][newX])
                    return 1;
            }
        }
    }
    return 0;
}

int randomPiece() {
    return rand()%7;
}

void rotatePiece(Piece* piece, int** grid) {
    int temp[4][4];
    int i, j;

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            temp[j][3 - i] = piece->shape[i][j];
  

    if (!checkCollision(temp, piece, grid, 0, 0)) 
        for (i = 0; i < 4; i++)
            for (j = 0; j < 4; j++)
                piece->shape[i][j] = temp[i][j];
}

Piece* createPiece(int shapeIndex) {
    Piece* piece = (Piece*) malloc(sizeof(Piece));
    piece->shape = malloc(sizeof(int[4][4]));
	piece->color = pallete[shapeIndex];
    

    int i, j;

    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
            piece->shape[i][j] = shapes[shapeIndex][i][j];

    piece->velocity.x = 3;
    
    if(shapeIndex != 3) 
        piece->velocity.y = -1;
    else  
        piece->velocity.y = -2;

    return piece;
}


void refreshPiece(Piece* piece) {
    int i, j;

    for(i = 0; i < 4; i++) 
        for(j = 0; j < 4; j++)
            if (piece->shape[i][j] != 0)
                    DrawRectangle(
                        X_GRID + (piece->velocity.x * SPEED) + (j * SQUARE_SIZE),
                        Y_GRID + (piece->velocity.y * SPEED) + (i * SQUARE_SIZE),
                        SQUARE_SIZE, SQUARE_SIZE,
                        piece->color
                    );
}

void fixPieceOnBoard(Piece* piece, int** grid) {
    int i, j;
    int y, x;

    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
            if (piece->shape[i][j]) {
                y = piece->velocity.y + i;
                x = piece->velocity.x + j;

                if (x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT)
                    grid[y][x] = piece->shape[i][j];
            }
}


void checkPiecePosition(Piece* piece, int** grid) {
    switch (GetKeyPressed()) {
        case KEY_LEFT:
        case KEY_A:
            if (!checkCollision((int(*)[4])piece->shape, piece, grid, -1, 0))
                piece->velocity.x--;
            break;
        case KEY_RIGHT:
        case KEY_D:
            if (!checkCollision((int(*)[4])piece->shape, piece, grid, 1, 0))
                piece->velocity.x++;
            break;
        case KEY_DOWN:
        case KEY_S:
            if (!checkCollision((int(*)[4])piece->shape, piece, grid, 0, 1))
                piece->velocity.y++;
            break;
        case KEY_UP:
        case KEY_W:
            rotatePiece(piece, grid);
            break;
        case KEY_SPACE:
            while(!checkCollision((int(*)[4])piece->shape, piece, grid, 0, 1))
                piece->velocity.y++;
            break;
    }
}

void gravity(Piece* piece, int** grid, int* nextPiece, int* gameOver) {
    if (!checkCollision((int(*)[4])piece->shape, piece, grid, 0, 1)) {
        piece->velocity.y++;
    } else if(piece->velocity.y < 0) {
        *gameOver = 1;
    } else {
        fixPieceOnBoard(piece, grid);
        resetPiece(piece, *nextPiece);
        *nextPiece = randomPiece();
    }
}

void resetPiece(Piece* piece, int shapeIndex) {
    int i, j;
            
    piece->velocity.x = 3;

    if(shapeIndex != 3) 
        piece->velocity.y = -1;
    else  
        piece->velocity.y = -2;
    
    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
            piece->shape[i][j] = shapes[shapeIndex][i][j];

    piece->color = pallete[shapeIndex];
}

