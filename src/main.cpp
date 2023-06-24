#include <string>
#include <iostream>
#include "FileUtils.h"
#include "ImageUtils.h"

const std::string imagePath("..//files//image.txt");
const std::string maskPath("..//files//mask.txt");
const std::string resultPath("..//files//result.txt");
const std::string compressedMaskPath("..//files//compressed_mask.txt");

int main() {
    Matrix image = ReadImageFromFile(imagePath);
    Matrix mask = ReadMaskFromFile(maskPath);
    Matrix compressedMask = ReadCompressedMaskFromFile(compressedMaskPath);
    Matrix result = ApplyMaskToImage(image, mask);
    Matrix resultWithCompressedMask = ApplyMaskToImage(image, compressedMask);

    std::cout << "Original image:" << std::endl;
    PrintImage(image);
    std::cout << "Mask:" << std::endl;
    PrintImage(mask);
    std::cout << "Compressed mask after decompressing:" << std::endl;
    PrintImage(compressedMask);
    std::cout << "Result image:" << std::endl;
    PrintImage(result);
    std::cout << "Result image with compressed mask:" << std::endl;
    PrintImage(resultWithCompressedMask);


    //SaveImageToFile(result, resultPath);
    return 0;
}
