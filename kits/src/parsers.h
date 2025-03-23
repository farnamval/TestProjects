#ifndef PARSERS_H
#define PARSERS_H

#include <sstream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include "line_item.h"

// Функция для разбора строки из файла документа
std::vector<LineItem> parseDocumentFile(std::ifstream& documentFile)
{
    std::vector<LineItem> document;
    std::string line;
    while (getline(documentFile, line))
    {
        LineItem item;
        std::istringstream iss(line);
        std::string posStr, productName, quantityStr, unit, categoryStr;

        iss >> posStr;
        item.pos = std::stoi(posStr);

        // Читаем название продукта (все символы до первого числа)
        std::string temp;
        while (iss >> temp)
        {
            if (isdigit(temp[0]))
            {
                quantityStr = temp;
                break;
            }
            productName += (productName.empty() ? "" : " ") + temp;
        }

        item.productName = productName;
        item.quantity = stoi(quantityStr);

        // Читаем единицу измерения ("шт")
        iss >> unit;

        // Читаем категории (в скобках)
        getline(iss, categoryStr);
        size_t start = categoryStr.find('(');
        size_t end = categoryStr.find(')');
        if (start != std::string::npos && end != std::string::npos)
        {
            std::string categoriesStr = categoryStr.substr(start + 1, end - start - 1);
            if (categoriesStr == "---")
                item.categories = {};
            else
            {
                // Разделяем категории
                size_t pos = 0;
                while ((pos = categoriesStr.find(", ")) != std::string::npos)
                {
                    std::string category = categoriesStr.substr(0, pos);
                    item.categories.push_back(category);
                    categoriesStr.erase(0, pos + 2);
                }
                if (!categoriesStr.empty())
                    item.categories.push_back(categoriesStr);
            }
        }

        document.push_back(item);
    }

    return document;
}

// Функция для разбора строки из файла набора
std::map<std::string, int> parseKitFile(std::ifstream& kitFile)
{
    std::map<std::string, int> kit;
    std::string line;
    while (getline(kitFile, line))
    {
        std::istringstream iss(line);
        std::string category, quantityStr;
        // Вырезаем из строки категорию
        getline(iss, category, '-');
        category.erase(remove_if(category.begin(), category.end(), ::isspace), category.end());
        iss >> quantityStr;
        int quantity = stoi(quantityStr);
        kit[category] += quantity;
    }
    
    return kit;
}

#endif // PARSERS_H
