#include <stdio.h>

int main() {
    float satisTutar, ucret = 0, enCokSatis = 0;
    int aracKodu, renaSatis = 0, mazdaSatis = 0, hondaSatis = 0, fordSatis = 0;
    int renaToplam = 0, mazdaToplam = 0, hondaToplam = 0, fordToplam = 0;
    char m1 = 'r', m2 = 'r';

    printf("Arac kodunu giriniz (car codes): '1-Renault','2-Mazda','3-Honda','4-Ford'\n");
    scanf("%d", &aracKodu);

    while (aracKodu != 111) {
        switch (aracKodu) {
            case 1:
                printf("Renault arac satis tutarini giriniz (fuel sales amount): ");
                scanf("%f", &satisTutar);
                renaSatis += satisTutar;
                renaToplam++;
                ucret += satisTutar;
                break;

            case 2:
                printf("Mazda arac satis tutarini giriniz (fuel sales amount): ");
                scanf("%f", &satisTutar);
                mazdaSatis += satisTutar;
                mazdaToplam++;
                ucret += satisTutar;
                break;

            case 3:
                printf("Honda arac satis tutarini giriniz (fuel sales amount): ");
                scanf("%f", &satisTutar);
                hondaSatis += satisTutar;
                hondaToplam++;
                ucret += satisTutar;
                break;

            case 4:
                printf("Ford arac satis tutarini giriniz (fuel sales amount): ");
                scanf("%f", &satisTutar);
                fordSatis += satisTutar;
                fordToplam++;
                ucret += satisTutar;
                break;

            default:
                printf("Hatali islem yaptiniz (Error).\n");
                break;
        }

        printf("Arac kodu giriniz (car code): ");
        scanf("%d", &aracKodu);
    }

    // Determine the most frequently sold car
    int enCokGelen = renaToplam;
    if (enCokGelen < mazdaToplam) {
        enCokGelen = mazdaToplam;
        m1 = 'm';
    }
    if (enCokGelen < hondaToplam) {
        enCokGelen = hondaToplam;
        m1 = 'h';
    }
    if (enCokGelen < fordToplam) {
        enCokGelen = fordToplam;
        m1 = 'f';
    }

    // Determine the car that generated the most revenue
    enCokSatis = renaSatis;
    if (enCokSatis < mazdaSatis) {
        enCokSatis = mazdaSatis;
        m2 = 'm';
    }
    if (enCokSatis < hondaSatis) {
        enCokSatis = hondaSatis;
        m2 = 'h';
    }
    if (enCokSatis < fordSatis) {
        enCokSatis = fordSatis;
        m2 = 'f';
    }

    printf("En cok gelen arac (the most incoming vehicles): %c (%d kez)\n", m1, enCokGelen);
    printf("En cok kazandiran arac (the most profitable vehicle): %c (%.2f TL ile)\n", m2, enCokSatis);

    return 0;
}
