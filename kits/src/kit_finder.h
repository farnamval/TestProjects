#ifndef KIT_FINDER_H
#define KIT_FINDER_H

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "line_item.h"

// Функция для поиска набора в документе
std::vector<LineItem> findKit(std::vector<LineItem> document, std::map<std::string, int>& kit)
{
    for (auto& item: document)
    {
        std::vector<std::string> newCategories;
        for (const auto& category: item.categories)
        {
            if (kit.find(category) != kit.end())
                newCategories.push_back(category);
        }
        std::sort(newCategories.begin(), newCategories.end());
        std::swap(item.categories, newCategories);
    }

    std::sort(document.begin(), document.end());

    std::vector<LineItem> foundKit;

    for (auto& [requiredCategory, requiredQuantity] : kit)
    {
        for (auto& item : document)
        {
            for (const auto& itemCategory : item.categories)
                if (itemCategory == requiredCategory && item.quantity != 0)
                {
                    LineItem availableItem = {item.pos,
                                              item.productName,
                                              std::min(requiredQuantity, item.quantity),
                                              {requiredCategory}};
                    foundKit.push_back(availableItem);
                    if (requiredQuantity > item.quantity)
                    {
                        requiredQuantity -= item.quantity;
                        item.quantity = 0;
                    }
                    else
                    {
                        item.quantity -= requiredQuantity;
                        requiredQuantity = 0;
                        break;
                    }
                }
            if (requiredQuantity == 0)
                break;
        }
        if (requiredQuantity != 0)
        {
            return {};
        }
    }

    return foundKit;
}

#endif // KIT_FINDER_H
