#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ogrenciler {
    char adsoyad[30];
    char ders[20];
    int vize1, final_not;
    float ort;
}ogrenci[3];

void bilgi_gir(struct ogrenciler* a) {
    printf("ogrenci adi soyadi :"); fgets(a->adsoyad, sizeof(a->adsoyad), stdin);
    if (a->adsoyad[strlen(a->adsoyad) - 1] == '\n') {
        a->adsoyad[strlen(a->adsoyad) - 1] = '\0';
    }
    printf("ogrenci ders :"); fgets(a->ders, sizeof(a->ders), stdin);
    if (a->ders[strlen(a->ders) - 1] == '\n') {
        a->ders[strlen(a->ders) - 1] = '\0';
    }
    printf("ogrenci vize 1 :"); scanf("%d", &a->vize1);
    printf("ogrenci final :"); scanf("%d", &a->final_not);
    getchar();      //tekrar cagirildiginda sorun yapmasin
    a->ort = ((float)a->vize1 * 4 / 10) + ((float)a->final_not * 6 / 10);
}


int main() {
    FILE* dosya;
    
    dosya = fopen("C:/Users/bugra/OneDrive/Masa�st�/ogrenciler.txt", "w");
    
    for (int i = 0; i < 3; i++) {
        //bilgi aliyor
        bilgi_gir(&ogrenci[i]);
        printf("*************\n");        //konsol guzel dursun
    }

    for (int i = 0; i < 3; i++) {
        //bilgileri aldi simdi yazdirsin ...
        fprintf(dosya, "ogrenci adi soyadi :");
        fwrite(ogrenci[i].adsoyad, sizeof(char), strlen(ogrenci[i].adsoyad), dosya);
        fprintf(dosya, "\nogrenci aldigi ders :");
        fwrite(ogrenci[i].ders, sizeof(char), strlen(ogrenci[i].ders), dosya);
        fprintf(dosya, "\nogrenci vize : %d",ogrenci[i].vize1);
        fprintf(dosya, "\nogrenci final : %d", ogrenci[i].final_not);
        fprintf(dosya, "\nogrenci ders ortalamasi : %.2f", ogrenci[i].ort);
        fprintf(dosya,"\n**************************\n");
    }

    fclose(dosya);
    return 0;
}
