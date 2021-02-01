#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>

enum class ItemType{
    healthPotion,
    torch,
    arrow,
    count
};

using inventory_type = std::array<int, static_cast<int>(ItemType::count)>;

int getTotalItems(const inventory_type &items){
    return std::reduce(items.begin(), items.end());
}



int main()
{
    inventory_type items {
        {2, 5, 6}
    }; 

    std::cout << "The Player has " << getTotalItems(items) << " item(s) in total \n";

    std::cout << "The Player has " << items[static_cast<int>(ItemType::torch)] << " torches";
    return 0;
}



