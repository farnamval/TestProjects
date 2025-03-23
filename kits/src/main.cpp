#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include "line_item.h"
#include "parsers.h"
#include "kit_finder.h"

int main(int argc, char* argv[])
{
    // Проверка количества аргументов
    if (argc != 3)
    {
        std::cerr << "Ошибка: необходимо передать два аргумента - имя файла документа и имя файла набора.\n";
        return 1;
    }

    std::string documentFileName = argv[1];
    std::string kitFileName = argv[2];

    // Чтение данных из файла документа
    std::ifstream documentFile(documentFileName);
    if (!documentFile.is_open())
    {
        std::cerr << "Ошибка: не удалось открыть файл документа.\n";
        return 1;
    }

    std::vector<LineItem> document = parseDocumentFile(documentFile);
    documentFile.close();

    // Чтение данных из файла набора
    std::ifstream kitFile(kitFileName);
    if (!kitFile.is_open())
    {
        std::cerr << "Ошибка: не удалось открыть файл набора.\n";
        return 1;
    }

    std::map<std::string, int> kit = parseKitFile(kitFile);
    kitFile.close();

    std::vector<LineItem> foundKit = findKit(document, kit);

    if (foundKit.empty())
    {
        std::cout << "Набор не входит в документ.\n";
        return 0;
    }

    std::cout << "Набор содержится в документе.\n";
    std::cout << "Состав набора:\n";

    for (auto& item: foundKit)
        std::cout << item.pos << " " << item.productName 
                  << " (" << item.categories[0] << ") - " << item.quantity << " шт\n";

    return 0;
}
