#include <iostream>
#include <cstdlib> 
#include <thread>
#include <chrono>
#include <ctime>
using namespace std;

void temizle() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    srand(time(0));

    int bahis;
    cout << "===  SLOT MACHINE  ===\n";
    cout << "Bahis miktari: ";
    cin >> bahis;

    // Hedef sayılar
    int hedef_a = rand() % 10;
    int hedef_b = rand() % 10;
    int hedef_c = rand() % 10;

    cout << "\nSpinning...\n";
    this_thread::sleep_for(chrono::milliseconds(500));

    // Animasyon
    for (int i = 0; i <= 15; i++) {
        temizle();
        cout << "===  SLOT MACHINE  ===\n\n";

        int a = rand() % 10;
        int b = rand() % 10;
        int c = rand() % 10;

        // Son frame'de gerçek sonucu göster
        if (i == 15) {
            a = hedef_a;
            b = hedef_b;
            c = hedef_c;
        }

        cout << "=============\n";
        cout << "= " << a << " = " << b << " = " << c << " =\n";
        cout << "=============\n";

        this_thread::sleep_for(chrono::milliseconds(100 + i * 20));
    }

    // Sonuç
    cout << "\n";
    if (hedef_a == hedef_b && hedef_b == hedef_c) {
        cout << ":O JACKPOT! \n";
        cout << "Kazanc: " << bahis * 10 << " TL\n";
    }
    else if (hedef_a == hedef_b || hedef_b == hedef_c || hedef_a == hedef_c) {
        cout << ":) Ikili! \n";
        cout << "Kazanc: " << bahis * 2 << " TL\n";
    }
    else {
        cout << ":( Kaybettin!\n";
        cout << "Kayip: -" << bahis << " TL\n";
    }

    return 0;
}