#pragma once
#include <string>

const int ROWS = 8;
const int COLS = 8;

struct Matrix {
    int matrix[ROWS][COLS];
};

Matrix ReadImageFromFile(const std::string &fileName);
Matrix ReadMaskFromFile(const std::string &fileName);
void SaveImageToFile(Matrix image, const std::string &fileName);
Matrix ReadCompressedMaskFromFile(const std::string &fileName);

