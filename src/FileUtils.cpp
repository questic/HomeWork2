#include "FileUtils.h"
#include <fstream>
#include <iostream>
#include <bitset>

Matrix ReadImageFromFile(const std::string &fileName) {
    std::ifstream file(fileName);
    Matrix result{};

    if (file.is_open()) {
        for (int i = 0; i < COLS; i++) {

            for (int j = 0; j < ROWS; j++) {
                int pixel;

                file >> pixel;
                result.matrix[i][j] = pixel;
            }

        }
    } else {
        std::cout << "Failed to open file." << std::endl;
    }

    return result;
}

Matrix ReadMaskFromFile(const std::string &fileName) {
    return ReadImageFromFile(fileName);
}

void SaveImageToFile(Matrix image, const std::string &fileName) {
    std::ofstream file(fileName);

    if (file.is_open()) {
        for (int i = 0; i < COLS; i++) {

            for (int j = 0; j < ROWS; j++) {
                file << image.matrix[i][j] << ' ';
            }

            file << std::endl;
        }

        std::cout << "File saved successfully." << std::endl;
    } else {
        std::cout << "Failed to create output file." << std::endl;
    }
}

Matrix ReadCompressedMaskFromFile(const std::string &fileName) {
    std::ifstream file(fileName);
    Matrix result{};

    if (file.is_open()) {
        for (int i = 0; i < COLS; i++) {
            int number;
            file >> number;
            std::bitset<ROWS> bits(number);

            for (int j = 0; j < ROWS; j++) {
                result.matrix[i][j] = bits[ROWS - j - 1];
            }
        }
    } else {
        std::cout << "Failed to open file." << std::endl;
    }

    return result;
}


