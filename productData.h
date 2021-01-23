#include <string.h>
#define NumberOfProducts 4

class ProductData
{
public:
    //Kitchen products details
    string kitchenProductName[NumberOfProducts] = {
        "Plate",
        "Bottle",
        "Pressure Cooker",
        "Pan",
    };

    float kitchenProductPrice[NumberOfProducts] = {
        30,
        25,
        412,
        40,
    };

    //Clothes products details
    string clothesProductName[NumberOfProducts] = {
        "T-shirts",
        "Shirts",
        "Pants",
        "jacket",
    };

    float clothesProductPrice[NumberOfProducts] = {
        150,
        250,
        180,
        400,
    };

    //Electronic products details
    string electronicProductName[NumberOfProducts] = {
        "Watch",
        "Keyboard",
        "Mouse",
        "Bulb",
    };

    float electronicProductPrice[NumberOfProducts] = {
        800,
        999,
        400,
        50,
    };
    
    //Cold Drinks products details
    string coldDrinkProductName[NumberOfProducts] = {
        "Mango juice",
        "Apple juice",
        "ThumsUp",
        "Pepsi",
    };

    float coldDrinkProductPrice[NumberOfProducts] = {
        20,
        20,
        20,
        20,
    };


public:
    void getKitchenProducts()
    {
        for (int i = 0; i < NumberOfProducts; i++)
        {
            cout << "\t\t\t\t" << i + 1 << ". " << kitchenProductName[i] << " ---->  Rs." << kitchenProductPrice[i] << "\n\n";
        }
    }

    void getClothesProducts()
    {
        for (int i = 0; i < NumberOfProducts; i++)
        {
            cout << "\t\t\t\t" << i + 1 << ". " << clothesProductName[i] << " ---->  Rs." << clothesProductPrice[i] << "\n\n";
        }
    }
    void getElectronicProducts()
    {
        for (int i = 0; i < NumberOfProducts; i++)
        {
            cout << "\t\t\t\t" << i + 1 << ". " << electronicProductName[i] << " ---->  Rs." << electronicProductPrice[i] << "\n\n";
        }
    }
    void getColdDrinkProducts()
    {
        for (int i = 0; i < NumberOfProducts; i++)
        {
            cout << "\t\t\t\t" << i + 1 << ". " << coldDrinkProductName[i] << " ---->  Rs." << coldDrinkProductPrice[i] << "\n\n";
        }
    }


};
