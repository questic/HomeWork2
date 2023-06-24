#include "FileUtils.h"
#include <fstream>
#include <iostream>

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



