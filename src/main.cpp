#include <string>
#include "FileUtils.h"
#include "ImageUtils.h"

const std::string imagePath("..//files//image.txt");
const std::string maskPath("..//files//mask.txt");
const std::string resultPath("..//files//result.txt");

int main() {
    Matrix image = ReadImageFromFile(imagePath);
    Matrix mask = ReadMaskFromFile(maskPath);
    Matrix result = ApplyMaskToImage(image, mask);

    PrintImage(image);
    PrintImage(mask);
    PrintImage(result);

    SaveImageToFile(result, resultPath);
    return 0;
}
