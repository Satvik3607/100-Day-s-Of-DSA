void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {

    int rows = matrixSize;
    int cols = matrixColSize[0];

    int firstRowZero = 0;
    int firstColZero = 0;

    // Check first row
    for(int j = 0; j < cols; j++) {
        if(matrix[0][j] == 0)
            firstRowZero = 1;
    }

    // Check first column
    for(int i = 0; i < rows; i++) {
        if(matrix[i][0] == 0)
            firstColZero = 1;
    }

    // Mark zeros
    for(int i = 1; i < rows; i++) {
        for(int j = 1; j < cols; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Set inner matrix
    for(int i = 1; i < rows; i++) {
        for(int j = 1; j < cols; j++) {
            if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // First row
    if(firstRowZero) {
        for(int j = 0; j < cols; j++)
            matrix[0][j] = 0;
    }

    // First column
    if(firstColZero) {
        for(int i = 0; i < rows; i++)
            matrix[i][0] = 0;
    }
}