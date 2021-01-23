#include <string.h>

class ProductData
{
protected:
    //Kitchen products details
    string kitchenProductName[4] = {
        "Plate",
        "Bottle",
        "Pressure Cooker",
        "Pan",
    };

    int kitchenProductPrice[4] = {
        30,
        25,
        412,
        40,
    };

    //Clothes products details
    string clothesProductName[4] = {
        "T-shirts",
        "Shirts",
        "Pants",
        "jacket",
    };

    int clothesProductPrice[4] = {
        150,
        250,
        180,
        400,
    };

    //Electronic products details
    string electronicProductName[4] = {
        "Watch",
        "Keyboard",
        "Mouse",
        "Bulb",
    };

    int electronicProductPrice[4] = {
        800,
        999,
        400,
        50,
    };
    
    //Cold Drinks products details
    string coldDrinkProductName[4] = {
        "Mango juice",
        "Appke juice",
        "ThumsUp",
        "Pepsi",
    };

    int coldDrinkProductPrice[4] = {
        20,
        20,
        20,
        20,
    };


public:
    void getKitchenProducts()
    {
        for (int i = 0; i < 4; i++)
        {
            cout << "\t\t\t\t" << i + 1 << ". " << kitchenProductName[i] << " ---->  Rs." << kitchenProductPrice[i] << "\n\n";
        }
    }

    void getClothesProducts()
    {
        for (int i = 0; i < 4; i++)
        {
            cout << "\t\t\t\t" << i + 1 << ". " << clothesProductName[i] << " ---->  Rs." << clothesProductPrice[i] << "\n\n";
        }
    }
    void getElectronicProducts()
    {
        for (int i = 0; i < 4; i++)
        {
            cout << "\t\t\t\t" << i + 1 << ". " << electronicProductName[i] << " ---->  Rs." << electronicProductPrice[i] << "\n\n";
        }
    }
    void getColdDrinkProducts()
    {
        for (int i = 0; i < 4; i++)
        {
            cout << "\t\t\t\t" << i + 1 << ". " << coldDrinkProductName[i] << " ---->  Rs." << coldDrinkProductPrice[i] << "\n\n";
        }
    }
};