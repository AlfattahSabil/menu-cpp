#include <iostream>
using namespace std;

// Function 
void ordFood(char yOrNo);
void ordDrink(int inpFood, int numOrds);
void orderItemFood(string itemType, int& inpFood);
void orderItemDrink(string itemType, int& inpDrink);
void cetakOrd(int numOrds, int numOrds2, int inpFood, int inpDrink, string catatan);

// variables
char yOrNo;
int numOrds, numOrds2, inpFood, inpDrink;
string catatan;

int orderedFood[50], orderedDrink[50]; 
int foodQuantities[50], drinkQuantities[50]; 
int foodCount = 0, drinkCount = 0; 

// Prices for food and drinks
int foodPrices[] = {10000, 13000, 15000, 18000, 14000};  // Indomie, Nasi Goreng, Ayam Goreng, Ayam Bakar, Ayam Geprek
int drinkPrices[] = {6000, 2000, 8000, 10000};  // Teh manis, Air putih, Jeruk, Good Day

int main(){
    cout << "========================================================\n";
    cout << "     Selamat datang di FattahCafe, ingin memesan? \n";
    cout << "========================================================\n\n";
    cout << "===> (y/n) ";
    cin >> yOrNo;

    cout << "\n";

    if (yOrNo == 'y' || yOrNo == 'Y'){
        system("cls");
        ordFood(yOrNo);
    } else {
        cout << "========================================================\n";
        cout << "|             Terima Kasih sudah mampir!\n             |";           
        cout << "========================================================\n";
        return 0;
    }
}

void orderItemFood(string itemType, int& inpFood){
    do {
        cout << "Silahkan pesan " << itemType << " yang tersedia\n";
        cout << "========================================================\n";
        cout << "| NO.  |   Makanan Tersedia        |   Harga           |\n";
        cout << "|======================================================|\n";
        cout << "| 1.   |  Indomie (Goreng/Rebus)   |  Rp. 10.000       |\n";
        cout << "| 2.   |  Nasi Goreng              |  Rp. 13.000       |\n";
        cout << "| 3.   |  Ayam Goreng              |  Rp. 15.000       |\n";
        cout << "| 4.   |  Ayam Bakar               |  Rp. 18.000       |\n";
        cout << "| 5.   |  Ayam Geprek              |  Rp. 14.000       |\n";
        cout << "========================================================\n";

        cout << " ==> Pesanan anda (1-5): ";
        cin >> inpFood;

        if (inpFood > 5 || inpFood < 1) {
            cout << "===========================================\n";
            cout << "|Maaf pilihan anda tidak terdaftar di list|\n";
            cout << "===========================================";
        }
    } while (inpFood > 5 || inpFood < 1);
}

void orderItemDrink(string itemType, int& inpDrink){
    do {
        cout << "Silahkan pesan " << itemType << " yang tersedia\n";
        cout << "|======================================================|\n";
        cout << "| NO.  |   Minuman Tersedia        |   Harga           |\n";
        cout << "|======================================================|\n";
        cout << "| 1.   |  Teh manis (Hangat/Dingin)|  Rp. 6.000        |\n";
        cout << "| 2.   |  Air putih (Hangat/Dingin)|  Rp. 2.000        |\n";
        cout << "| 3.   |  Jeruk (Hangat/Dingin)    |  Rp. 8.000        |\n";
        cout << "| 4.   |  Good Day (Hangat/Dingin) |  Rp. 10.000       |\n";
        cout << "|======================================================|\n";

        cout << " ==> Pesanan anda (1-4): ";
        cin >> inpDrink;

        if (inpDrink > 4 || inpDrink < 1) {
            cout << "===========================================\n";
            cout << "|Maaf pilihan anda tidak terdaftar di list|\n";
            cout << "===========================================";
        }
    } while (inpDrink > 4 || inpDrink < 1);
}

void ordFood(char yOrNo){
    orderItemFood("makanan", inpFood);
    orderedFood[foodCount] = inpFood;

    cout << "Jumlah pesanan: ";
    cin >> numOrds;
    foodQuantities[foodCount] = numOrds;
    foodCount++; 

    cout << "\n";

    cout << "Ingin memesan lagi (y/n)? ";
    cin >> yOrNo;

    while (yOrNo == 'y' || yOrNo == 'Y') {
        orderItemFood("makanan", inpFood);
        orderedFood[foodCount] = inpFood;

        cout << "Jumlah pesanan: ";
        cin >> numOrds;
        foodQuantities[foodCount] = numOrds;
        foodCount++;

        cout << "\nIngin memesan lagi (y/n)? ";
        cin >> yOrNo;
    }

    cout << "\n";

    ordDrink(numOrds, inpFood); 
}

void ordDrink(int inpFood, int numOrds){
    orderItemDrink("minuman", inpDrink);
    orderedDrink[drinkCount] = inpDrink;

    cout << "Jumlah pesanan: ";
    cin >> numOrds2;
    drinkQuantities[drinkCount] = numOrds2;
    drinkCount++; 

    cout << "\n";

    cout << "Ingin memesan lagi (y/n)? ";
    cin >> yOrNo;
    cin.ignore(); 

    while (yOrNo == 'y' || yOrNo == 'Y') {
        orderItemDrink("minuman", inpDrink);
        orderedDrink[drinkCount] = inpDrink;

        cout << "Jumlah pesanan: ";
        cin >> numOrds2;
        drinkQuantities[drinkCount] = numOrds2;
        drinkCount++; 

        cout << "\nIngin memesan lagi (y/n)? ";
        cin >> yOrNo;
        cin.ignore(); 
    }

    cout << "\n";

    cout << "Catatan untuk pesanan anda: ";
    getline(cin, catatan); 

    system("cls");
    cetakOrd(numOrds, numOrds2, inpFood, inpDrink, catatan);
}

void cetakOrd(int numOrds, int numOrds2, int inpFood, int inpDrink, string catatan) {
    cout << "========================================================\n";
    cout << "                     Pesanan Anda\n";
    cout << "========================================================\n";

    int totalHarga = 0;

    for (int i = 0; i < foodCount; i++) {
        cout << "Makanan: ";
        switch (orderedFood[i]) {
            case 1: 
                cout << "Indomie"; 
                totalHarga += foodPrices[0] * foodQuantities[i]; 
                break;
            case 2: 
                cout << "Nasi Goreng"; 
                totalHarga += foodPrices[1] * foodQuantities[i]; 
                break;
            case 3: 
                cout << "Ayam Goreng"; 
                totalHarga += foodPrices[2] * foodQuantities[i]; 
                break;
            case 4: 
                cout << "Ayam Bakar"; 
                totalHarga += foodPrices[3] * foodQuantities[i]; 
                break;
            case 5: 
                cout << "Ayam Geprek"; 
                totalHarga += foodPrices[4] * foodQuantities[i]; 
                break;
        }
        cout << " (Jumlah: " << foodQuantities[i] << ")\n";
    }

    for (int i = 0; i < drinkCount; i++) {
        cout << "Minuman: ";
        switch (orderedDrink[i]) {
            case 1:
                cout << "Teh manis"; 
                totalHarga += drinkPrices[0] * drinkQuantities[i]; 
                break;
            case 2: 
                cout << "Air putih"; 
                totalHarga += drinkPrices[1] * drinkQuantities[i]; 
                break;
            case 3: 
                cout << "Jeruk"; 
                totalHarga += drinkPrices[2] * drinkQuantities[i]; 
                break;
            case 4: 
                cout << "Good Day"; 
                totalHarga += drinkPrices[3] * drinkQuantities[i]; 
                break;
        }
        cout << " (Jumlah: " << drinkQuantities[i] << ")\n";
    }

    cout << "========================================================\n";
    cout << "Total Harga: Rp. " << totalHarga << "\n";
    cout << "========================================================\n";

    cout << "Catatan Anda: " << catatan << "\n";

    cout << "========================================================\n";
    cout << "Terima kasih atas pesanan Anda!\n";
    cout << "========================================================\n";
}
