#include "ImageUtils.h"
#include <iostream>
#include <bitset>
#include <climits>

Matrix ApplyMaskToImage(Matrix image, Matrix mask) {
    Matrix result{};

    for (int i = 0; i < COLS; i++) {

        for (int j = 0; j < ROWS; j++) {
            std::bitset<CHAR_BIT * sizeof(image.matrix[i][j])> imagePixelBitSet(image.matrix[i][j]);
            std::bitset<CHAR_BIT * sizeof(mask.matrix[i][j])> maskPixelBitSet(0);

            if (mask.matrix[i][j] == 1) {
                maskPixelBitSet = INT32_MAX;
            }

            if ((imagePixelBitSet & maskPixelBitSet) != 0) {
                result.matrix[i][j] = image.matrix[i][j];
            } else {
                result.matrix[i][j] = 0;
            }
        }
    }

    return result;
}

void PrintImage(Matrix image) {
    for (int i = 0; i < COLS; i++) {

        for (int j = 0; j < ROWS; j++) {
            std::cout << image.matrix[i][j] << ' ';
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
}