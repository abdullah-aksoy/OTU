#include <iostream>
#include <string>

using namespace std;

class AracKira {
    bool kira;
    int gun;

public:
    double bakiye;

    AracKira(double baslangic) : kira(false), bakiye(baslangic) {}

    void aracKirala() {
        if (!kira) {
            kira = true;
            cout << "Arac kiralama islemi baslatildi" << endl;
        } else {
            cout << "Zaten bir arac kiraladiniz." << endl;
        }
    }

    void aracIade() {
        if (kira) {
            kira = false;
            cout << "Arac iadesi baslatildi" << endl;
        } else {
            cout << "Kiralanmis bir arac yok." << endl;
        }
    }

    void fiyatHesapla(int gun, int fiyat) {
        this->gun = gun;
        int toplamFiyat = fiyat * gun;
        cout << "Odenecek tutar: " << toplamFiyat << " TL" << endl;

        if (toplamFiyat > bakiye) {
            cout << "Yetersiz bakiye. Lutfen bakiyenizi yukleyin." << endl;
            system("pause");
        } else {
            bakiye -= toplamFiyat;
            cout << "Bakiyeniz: " << bakiye << " TL" << endl;
        }
    }
};

int main() {
    AracKira arac1(500);

    int secim, secim1, gun;

    cout << "Bakiyenizi giriniz: ";
    cin >> arac1.bakiye;

    do {
        cout << "\nYapmak istediginiz islemi seciniz: " << endl;
        cout << "1. Araba Kiralama" << endl;
        cout << "2. Araba Iadesi Yapma" << endl;
        cout << "3. Sistemden Cikma" << endl;
        cout << "Secim: ";
        cin >> secim;

        switch (secim) {
            case 1:
                arac1.aracKirala();
                cout << "1. Renault (500 TL/gun)" << endl;
                cout << "2. BMW (600 TL/gun)" << endl;
                cout << "3. Mazda (700 TL/gun)" << endl;
                cout << "4. Porsche (1000 TL/gun)" << endl;
                cout << "5. Cikis" << endl;
                cout << "Kiralamak istediginiz aracin numarasini giriniz: ";
                cin >> secim1;

                if (secim1 >= 1 && secim1 <= 4) {
                    cout << "Kiralamak istediginiz gun sayisini giriniz: ";
                    cin >> gun;

                    switch (secim1) {
                        case 1:
                            arac1.fiyatHesapla(gun, 500);
                            break;
                        case 2:
                            arac1.fiyatHesapla(gun, 600);
                            break;
                        case 3:
                            arac1.fiyatHesapla(gun, 700);
                            break;
                        case 4:
                            arac1.fiyatHesapla(gun, 1000);
                            break;
                    }
                } else if (secim1 == 5) {
                    break;
                } else {
                    cout << "Hatali giris yaptiniz." << endl;
                }
                break;

            case 2:
                arac1.aracIade();
                break;

            case 3:
                cout << "Sistemden cikildi" << endl;
                return 0;

            default:
                cout << "Hata olustu" << endl;
                break;
        }
    } while (secim != 3);

    return 0;
}
