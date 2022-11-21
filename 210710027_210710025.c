#include <stdio.h>
#include <stdlib.h>
#define KDV_ORANI 0.08 // kdv orani sabit oldugu icin define tanimladik
int main()
{
float yuzde_konut,yuzde_isyeri,yuzde_kamu,yuzde_turistik,yuzde_konut_kademe,yuzde_isyeri_kademe,sayac_konut=0,sayac_isyeri=0,sayac_kamu=0,sayac_turistik=0,sayac_konut_kademe=0,sayac_isyeri_kademe=0;
int gun_sayisi,abone_tipi,su_kullanim_miktari=0,onceki_sayac_degeri,simdiki_sayac_degeri;//,sayac degerlerinin farkini su kullanimina esitledik
float su_tuketim_konut=0,su_tuketim_isyeri=0,su_tuketim_kamu=0,su_tuketim_turistik=0,toplam_su_konut=0,toplam_gun_konut=0,ort_su_konut,max_ort_konut_su,max=0;
float toplam_su_isyeri=0,toplam_gun_isyeri=0,ort_su_isyeri,toplam_su_kamu=0,toplam_gun_kamu=0,ort_su_kamu;
float toplam_su_turistik=0,toplam_gun_turistik=0,ort_su_turistik,atik_su_ucreti_konut=0,atik_su_ucreti_isyeri=0,atik_su_ucreti_kamu=0,atik_su_ucreti_turistik=0;
float kdv_tutari_konut=0,kdv_tutari_isyeri=0,kdv_tutari_kamu=0,kdv_tutari_turistik=0,max_su_tuketim_konut=0,max_su_tuketim_isyeri=0,max_su_tuketim_kamu=0,max_su_tuketim_turistik=0;
float max_su_kullanim_miktari_konut,max_su_kullanim_miktari_isyeri,max_su_kullanim_miktari_kamu,max_su_kullanim_miktari_turistik,su_fatura,su_tuketim,atik_su_ucreti,kdv_tutari;
float max_atik_su_tuketim_konut=0,max_atik_su_tuketim_isyeri=0,max_atik_su_tuketim_kamu=0,max_atik_su_tuketim_turistik=0,max_atik_su_konut,max_atik_su_isyeri,max_atik_su_kamu,max_atik_su_turistik;
char secim;
    do // baska bir abone girilip girilmeyecegini test edet " e/h"
    {
printf("Abone Tipi Kodlari : \n==================== \n 1-Konut Tipi \n 2-Isyeri \n 3-Kamu Kurumu \n 4-Turistik Tesis \n");
printf("Abone Tipi Kodunuzu Giriniz : ");
scanf("%d",&abone_tipi);

while(abone_tipi<1 || abone_tipi>4 ) // gecersiz abone kodu girilip girilmedigini test eder
{
    printf("hatali abone tipi girdiniz lutfen tekrar deneyiniz ");
    scanf("%d",&abone_tipi);
}

switch (abone_tipi) // girilen abone tipi kodunu
{
    case 1:
        sayac_konut++;
        printf("----KONUT ABONE TIPI----\n");
        do // onceki sayac degeri daha buyuk girilsin kontrolunu sagla
        {
        do{
        printf("Onceki sayac degeri giriniz : ");
        scanf("%d",&onceki_sayac_degeri);
        if(onceki_sayac_degeri<0)
        {
         printf("Hatali sayac degeri girildi lutfen tekrar giriniz!!!!\n ");
		}
	}while(onceki_sayac_degeri<0);
        printf("Simdiki sayac degeri giriniz : ");
        scanf("%d",&simdiki_sayac_degeri);
        if(simdiki_sayac_degeri<onceki_sayac_degeri)
        {
        printf("Sayac degerleri hatali girildi lutfen tekrar giriniz!!!!\n");
        }
        }while(onceki_sayac_degeri>simdiki_sayac_degeri);

        su_kullanim_miktari=simdiki_sayac_degeri-onceki_sayac_degeri;
         do{
		printf("Gun sayisini giriniz :  ");
        scanf("%d",&gun_sayisi);
        if(gun_sayisi<=0)
        printf("Gun sayisi hatali girildi lutfen tekrar giriniz!!!!\n");
    }while(gun_sayisi<=0);
        printf("==========================\n");

          if (su_kullanim_miktari<=((13*gun_sayisi)/30))
          {
                printf("Su Tuketim miktari : %d Ton\n",su_kullanim_miktari);
                su_tuketim=su_kullanim_miktari*2.24;
                printf("Su tuketim ucreti: %.2f TL \n",su_tuketim);
                atik_su_ucreti=su_kullanim_miktari*1.91;
                printf("Atik su ucerti : %.2f TL \n",atik_su_ucreti);
                kdv_tutari=(atik_su_ucreti+su_tuketim)*KDV_ORANI;
                printf("KDV tutari : %.2f TL \n",kdv_tutari);
                su_fatura=kdv_tutari+atik_su_ucreti+su_tuketim;
                printf("Fatura Tutari : %.2f TL\n\n ",su_fatura);
                sayac_konut_kademe++;
          }

          else if(su_kullanim_miktari<=((20*gun_sayisi)/30) &&(su_kullanim_miktari>((13*gun_sayisi)/30)) )
          {
                printf("Su Tuketim miktari : %d Ton\n",su_kullanim_miktari);
                su_tuketim=(13*(gun_sayisi/30))*2.24+su_kullanim_miktari-(13*(gun_sayisi/30)*5.78);
                printf("Su tuketim ucreti: %.2f TL \n",su_tuketim);
                atik_su_ucreti=su_kullanim_miktari*1.91;
                printf("Atik su ucerti : %.2f TL \n",atik_su_ucreti);
                kdv_tutari=(atik_su_ucreti+su_tuketim)*KDV_ORANI;
                printf("KDV tutari : %.2f TL \n",kdv_tutari);
                su_fatura=kdv_tutari+atik_su_ucreti+su_tuketim;
                printf("Fatura Tutari : %.2f TL\n\n ",su_fatura);

          }
          else
          {
                printf("Su Tuketim miktari : %d Ton\n",su_kullanim_miktari);
                su_tuketim=((13*(float)gun_sayisi/30)*2.24)+((7*(float)gun_sayisi/30)*5.78)+((su_kullanim_miktari-(20*(float)gun_sayisi/30))*9.33) ;
                printf("Su tuketim ucreti: %.2f TL \n",su_tuketim);
                atik_su_ucreti=su_kullanim_miktari*1.91;
                printf("Atik su ucerti : %.2f TL \n",atik_su_ucreti);
                kdv_tutari=(atik_su_ucreti+su_tuketim)*KDV_ORANI;
                printf("KDV tutari : %.2f TL \n",kdv_tutari);
                su_fatura=kdv_tutari+atik_su_ucreti+su_tuketim;
                printf("Fatura Tutari : %.2f TL\n\n ",su_fatura);

          }

		  if(su_tuketim>max_su_tuketim_konut){                   // 5.istatistik sorusu icin default bir max tanimlayip  konut tipindeki
		  	max_su_tuketim_konut=su_tuketim;                    // max su tuketim ucreti ve o aboneye ait su tuketim miktarini bulur
		    max_su_kullanim_miktari_konut=su_kullanim_miktari;
		  }

		   toplam_su_konut=toplam_su_konut+su_kullanim_miktari;   // Konut tipindeki abonelerin gunluk ortalama su tuketim miktarini verir.
           toplam_gun_konut=toplam_gun_konut+gun_sayisi;

           max_ort_konut_su=su_kullanim_miktari/gun_sayisi;//konut tipi aboneler arasinda gunluk ort su tuketim harcamasi ve karsilastirilmasi
           if(max<max_ort_konut_su)
                max=max_ort_konut_su;

           if(max_atik_su_tuketim_konut<atik_su_ucreti) //konut tipi abonelerin atik su ucretini karsilastirma
           {
               max_atik_su_tuketim_konut=atik_su_ucreti;
               max_atik_su_konut=su_kullanim_miktari;
           }

            su_tuketim_konut=su_tuketim+su_tuketim_konut;
            atik_su_ucreti_konut=atik_su_ucreti_konut+atik_su_ucreti;
            kdv_tutari_konut=kdv_tutari_konut+kdv_tutari; //devlete odenen aylik toplam kdv tutari bulunur
          break;

    case 2 :
        sayac_isyeri++;
         printf("----ISYERI ABONE TIPI----\n");
         do // onceki sayac degeri daha buyuk girilsin kontrolunu sagla
        {
        do{
        printf("Onceki sayac degeri giriniz : ");
        scanf("%d",&onceki_sayac_degeri);
        if(onceki_sayac_degeri<0)
        {
         printf("Hatali sayac degeri girildi lutfen tekrar giriniz!!!!\n ");
		}
	}while(onceki_sayac_degeri<0);
        printf("Simdiki sayac degeri giriniz : ");
        scanf("%d",&simdiki_sayac_degeri);
        if(simdiki_sayac_degeri<onceki_sayac_degeri)
        {
        printf("Sayac degerleri hatali girildi lutfen tekrar giriniz!!!!\n");
        }
        }while(onceki_sayac_degeri>simdiki_sayac_degeri);

		su_kullanim_miktari=simdiki_sayac_degeri-onceki_sayac_degeri;
         do{
		printf("Gun sayisini giriniz :  ");
        scanf("%d",&gun_sayisi);
        if(gun_sayisi<=0)
        printf("Gun sayisi hatali girildi lutfen tekrar giriniz!!!!\n");
    }while(gun_sayisi<=0);
        printf("==========================\n");
        if(su_kullanim_miktari<=(10*(gun_sayisi/30)))
		{
		printf("Su Tuketim miktari : %d Ton\n",su_kullanim_miktari);
                su_tuketim=su_kullanim_miktari*7.71;
                printf("Su tuketim ucreti: %.2f TL \n",su_tuketim);
                atik_su_ucreti=su_kullanim_miktari*3.79;
                printf("Atik su ucerti : %.2f TL \n",atik_su_ucreti);
                kdv_tutari=(atik_su_ucreti+su_tuketim)*KDV_ORANI;
                printf("KDV tutari : %.2f TL \n",kdv_tutari);
                su_fatura=kdv_tutari+atik_su_ucreti+su_tuketim;
                printf("Fatura Tutari : %.2f TL\n\n ",su_fatura); }
        else {
		       sayac_isyeri_kademe++;
                printf("Su Tuketim miktari : %d Ton\n",su_kullanim_miktari);
                su_tuketim=(10*(gun_sayisi/30)*7.71)+(su_kullanim_miktari-(10*(gun_sayisi/30)))*8.88;
                printf("Su tuketim ucreti: %.2f TL \n",su_tuketim);
                atik_su_ucreti=su_kullanim_miktari*3.79;
                printf("Atik su ucerti : %.2f TL \n",atik_su_ucreti);
                kdv_tutari=(atik_su_ucreti+su_tuketim)*KDV_ORANI;
                printf("KDV tutari : %.2f TL \n",kdv_tutari);
                su_fatura=kdv_tutari+atik_su_ucreti+su_tuketim;
                printf("Fatura Tutari : %.2f TL\n\n ",su_fatura);
				}
        toplam_su_isyeri=toplam_su_isyeri+su_kullanim_miktari;
        toplam_gun_isyeri=toplam_gun_isyeri+gun_sayisi;
        su_tuketim_isyeri=su_tuketim+su_tuketim_isyeri;
        atik_su_ucreti_isyeri=atik_su_ucreti_isyeri+atik_su_ucreti;
        kdv_tutari_isyeri=kdv_tutari_isyeri+kdv_tutari; //devlete odenen aylik toplam kdv tutari bulunur.
         if(su_tuketim>max_su_tuketim_isyeri) //case 1 deki islem ile ayni
		 {
		 max_su_tuketim_isyeri=su_tuketim;
		  max_su_kullanim_miktari_isyeri=su_kullanim_miktari;
		 }
		  if(max_atik_su_tuketim_isyeri<atik_su_ucreti)
           {
               max_atik_su_tuketim_isyeri=atik_su_ucreti;
               max_atik_su_isyeri=su_kullanim_miktari;
           }
        break;
  case 3 :
   sayac_kamu++;
   printf("----KAMU KURUMU ABONE TIPI----\n");
        do // onceki sayac degeri daha buyuk girilsin kontrolunu sagla
        {
        do{
        printf("Onceki sayac degeri giriniz : ");
        scanf("%d",&onceki_sayac_degeri);
        if(onceki_sayac_degeri<0)
        {
         printf("Hatali sayac degeri girildi lutfen tekrar giriniz!!!!\n ");
		}
	}while(onceki_sayac_degeri<0);
        printf("Simdiki sayac degeri giriniz : ");
        scanf("%d",&simdiki_sayac_degeri);
        if(simdiki_sayac_degeri<onceki_sayac_degeri)
        {
        printf("Sayac degerleri hatali girildi lutfen tekrar giriniz!!!!\n");
        }
        }while(onceki_sayac_degeri>simdiki_sayac_degeri);
        su_kullanim_miktari=simdiki_sayac_degeri-onceki_sayac_degeri;
         do{
		printf("Gun sayisini giriniz :  ");
        scanf("%d",&gun_sayisi);
        if(gun_sayisi<=0)
        printf("Gun sayisi hatali girildi lutfen tekrar giriniz!!!!\n");
    }while(gun_sayisi<=0);
        printf("==========================\n");
        printf("Su Tuketim miktari : %d Ton\n",su_kullanim_miktari);
        su_tuketim=su_kullanim_miktari*6.64;
        printf("Su tuketim ucreti: %.2f TL \n",su_tuketim);
        atik_su_ucreti=su_kullanim_miktari*2.56;
        printf("Atik su ucerti : %.2f TL \n",atik_su_ucreti);
        kdv_tutari=(atik_su_ucreti+su_tuketim)*KDV_ORANI;
        printf("KDV tutari : %.2f TL \n",kdv_tutari);
        su_fatura=kdv_tutari+atik_su_ucreti+su_tuketim;
        printf("Fatura Tutari : %.2f TL\n\n ",su_fatura);
        toplam_su_kamu=toplam_su_kamu+su_kullanim_miktari;
        toplam_gun_kamu=toplam_gun_kamu+gun_sayisi;
        su_tuketim_kamu=su_tuketim+su_tuketim_kamu;
        atik_su_ucreti_kamu=atik_su_ucreti_kamu+atik_su_ucreti;
         kdv_tutari_kamu=kdv_tutari_kamu+kdv_tutari;
          if(su_tuketim>max_su_tuketim_kamu)
		  {
		  max_su_tuketim_kamu=su_tuketim;
		   max_su_kullanim_miktari_kamu=su_kullanim_miktari;
		  }
          if(max_atik_su_tuketim_kamu<atik_su_ucreti)
           {
               max_atik_su_tuketim_kamu=atik_su_ucreti;
               max_atik_su_kamu=su_kullanim_miktari;
           }
        break;
    case 4 :
        sayac_turistik++;
          printf("----TURISTIK TESIS ABONE TIPI----\n");
       do // onceki sayac degeri daha buyuk girilsin kontrolunu sagla
        {
        do{
        printf("Onceki sayac degeri giriniz : ");
        scanf("%d",&onceki_sayac_degeri);
        if(onceki_sayac_degeri<0)
        {
         printf("Hatali sayac degeri girildi lutfen tekrar giriniz!!!!\n ");
		}
	}while(onceki_sayac_degeri<0);
        printf("Simdiki sayac degeri giriniz : ");
        scanf("%d",&simdiki_sayac_degeri);
        if(simdiki_sayac_degeri<onceki_sayac_degeri)
        {
        printf("Sayac degerleri hatali girildi lutfen tekrar giriniz!!!!\n");
        }
        }while(onceki_sayac_degeri>simdiki_sayac_degeri);
        su_kullanim_miktari=simdiki_sayac_degeri-onceki_sayac_degeri;
        do{
		printf("Gun sayisini giriniz :  ");
        scanf("%d",&gun_sayisi);
        if(gun_sayisi<=0)
        printf("Gun sayisi hatali girildi lutfen tekrar giriniz!!!!\n");
    }while(gun_sayisi<=0);
        printf("==========================\n");
        printf("Su Tuketim miktari : %d Ton\n",su_kullanim_miktari);
        su_tuketim=su_kullanim_miktari*5.78;
        printf("Su tuketim ucreti: %.2f TL \n",su_tuketim);
        atik_su_ucreti=su_kullanim_miktari*1.91;
        printf("Atik su ucerti : %.2f TL \n",atik_su_ucreti);
        kdv_tutari=(atik_su_ucreti+su_tuketim)*KDV_ORANI;
        printf("KDV tutari : %.2f TL \n",kdv_tutari);
        su_fatura=kdv_tutari+atik_su_ucreti+su_tuketim;
        printf("Fatura Tutari : %.2f TL\n\n ",su_fatura);
        toplam_su_turistik=toplam_su_turistik+su_kullanim_miktari;
        toplam_gun_turistik=toplam_gun_turistik+gun_sayisi;
        su_tuketim_turistik=su_tuketim+su_tuketim_turistik;
         atik_su_ucreti_turistik=atik_su_ucreti_turistik+atik_su_ucreti;
        kdv_tutari_turistik=kdv_tutari_turistik+kdv_tutari;
         if(su_tuketim>max_su_tuketim_turistik)
		 {
		 max_su_tuketim_turistik=su_tuketim;
         max_su_kullanim_miktari_turistik=su_kullanim_miktari;
		}
          if(max_atik_su_tuketim_turistik<atik_su_ucreti)
           {
               max_atik_su_tuketim_turistik=atik_su_ucreti;
               max_atik_su_turistik=su_kullanim_miktari;
           }
        break;
}
    printf("Baska bir kullanici giricek misiniz ? e/h   \t");
    scanf(" %c",&secim); // note the space
    printf("================================================\n");
  while(secim!='e' && secim!='E' && secim!='h' && secim!='H'){         //baska abone almak icin girilen char degerinin dogru olup olmadigini kontrol eder.

    printf("Hatali kisa kod girisi lutfen tekrar deneyiniz: \n");      //yanlis ise tekrar deger alir
	printf("Baska bir kullanici giricek misiniz ? e/h \t");
    scanf(" %c",&secim); // note the space

	}
}while(secim=='e' || secim=='E');

    ort_su_konut=(toplam_su_konut/toplam_gun_konut);
    ort_su_isyeri=(toplam_su_isyeri/toplam_gun_isyeri);
    ort_su_kamu=(toplam_su_kamu/toplam_gun_kamu);
    ort_su_turistik=(toplam_su_turistik/toplam_gun_turistik);
    yuzde_konut=(sayac_konut/(sayac_kamu+sayac_isyeri+sayac_konut+sayac_turistik))*100.00;
    yuzde_isyeri=(sayac_isyeri/(sayac_kamu+sayac_isyeri+sayac_konut+sayac_turistik))*100.00;
    yuzde_kamu=(sayac_kamu/(sayac_kamu+sayac_isyeri+sayac_konut+sayac_turistik))*100.00;
    yuzde_turistik=(sayac_turistik/(sayac_kamu+sayac_isyeri+sayac_konut+sayac_turistik))*100.00;
    yuzde_konut_kademe=(sayac_konut_kademe/sayac_konut)*100.00;   //1.kademeyi asmayan konut tipi abone yuzdesi
    yuzde_isyeri_kademe=(sayac_isyeri_kademe/sayac_isyeri_kademe)*100.00;  //1.kademeyi asan isyeri tipi abone yuzdesi

   printf("1)\nAbone Tipi                Abone Sayisi                Yuzde             Gunluk Ort Tuk\n");
   printf("---------------          ------------                ------            ---------------\n");
   printf("  KONUT                       %.0f                      %.2f                %.2f ton\n  ",sayac_konut,yuzde_konut,ort_su_konut);
   printf("ISYERI                      %.0f                      %.2f                %.2f ton\n  ",sayac_isyeri,yuzde_isyeri,ort_su_isyeri);
   printf("KAMU                        %.0f                      %.2f                %.2f ton\n  ",sayac_kamu,yuzde_kamu,ort_su_kamu);
   printf("TURISTIK                    %.0f                      %.2f                %.2f ton\n ",sayac_turistik,yuzde_turistik,ort_su_turistik);
   printf("************************************************************************************************************************\n\n");
   printf("2)\n1.kadameyi asmayan konut abonelerinin : \n sayisi : %.0f \n yuzdesi : %.2f\n\n",sayac_konut_kademe,yuzde_konut_kademe);
   printf("************************************************************************************************************************\n\n");
   printf("3)\n1. kademeyi asan isyeri  abonelerinin : \n sayisi : %.0f \n yuzdesi : %.2f\n\n",sayac_isyeri_kademe,yuzde_isyeri_kademe);
   printf("************************************************************************************************************************\n\n");
   printf("4)\nGunluk ortalama su tuketim miktari en yuksek olan konut tipi abonenin gunluk ortalama su tuketim miktari: %.2f ton\n\n",max);
   printf("************************************************************************************************************************\n\n");
   printf("5)\n");

    if(max_su_tuketim_konut>max_su_tuketim_isyeri && max_su_tuketim_konut>max_su_tuketim_kamu && max_su_tuketim_konut>max_su_tuketim_turistik)
    printf("Abone Tipi: Konut \nAylik su tuketim miktari : %.0f  \nOdedigi aylik  su tuketim ucreti: %.2f\n\n", max_su_kullanim_miktari_konut,max_su_tuketim_konut);

   else if(max_su_tuketim_isyeri>max_su_tuketim_kamu && max_su_tuketim_isyeri>max_su_tuketim_turistik)
        printf("Abone Tipi: Isyeri\nAylik su tuketim miktari : %.0f  \nOdedigi aylik  su tuketim ucreti: %.2f\n\n", max_su_kullanim_miktari_isyeri,max_su_tuketim_isyeri);

   else if(max_su_tuketim_isyeri>max_su_tuketim_turistik)
       printf("Abone Tipi: Kamu \nAylik su tuketim miktari : %.0f  \nOdedigi aylik  su tuketim ucreti: %.2f\n\n", max_su_kullanim_miktari_kamu,max_su_tuketim_kamu);

   else
       printf("Abone Tipi: Turistik \nAylik su tuketim miktari : %.0f   \nOdedigi aylik  su tuketim ucreti: %.2f\n\n", max_su_kullanim_miktari_turistik,max_su_tuketim_turistik);

   printf("************************************************************************************************************************\n\n");
   printf("6)\n");

   if(max_atik_su_tuketim_konut>max_atik_su_tuketim_isyeri && max_atik_su_tuketim_konut>max_atik_su_tuketim_kamu && max_atik_su_tuketim_konut>max_atik_su_tuketim_turistik)
    printf("Abone Tipi: Konut \nAylik su tuketim miktari : %.0f  \nOdedigi aylik atik su tuketim ucreti: %.2f\n\n", max_atik_su_konut,max_atik_su_tuketim_konut);

   else if( max_atik_su_tuketim_isyeri>max_atik_su_tuketim_kamu && max_atik_su_tuketim_isyeri>max_atik_su_tuketim_turistik)
        printf("Abone Tipi: Isyeri\nAylik su tuketim miktari : %.0f  \nOdedigi aylik atik su tuketim ucreti: %.2f\n\n", max_atik_su_isyeri,max_atik_su_tuketim_isyeri);

   else if(max_atik_su_tuketim_kamu>max_atik_su_tuketim_turistik)
       printf("Abone Tipi: Kamu \nAylik su tuketim miktari : %.0f  \nOdedigi aylik atik su tuketim ucreti: %.2f\n\n", max_atik_su_kamu,max_atik_su_tuketim_kamu);

   else
       printf("Abone Tipi: Turistik \nAylik su tuketim miktari : %.0f   \nOdedigi aylik atik su tuketim ucreti: %.2f\n\n", max_atik_su_turistik,max_atik_su_tuketim_turistik);

   printf("************************************************************************************************************************\n\n");
   printf("7)\nAbone Tipi                  Toplam su Tuketim miktari\n ");
   printf("----------                  -------------------------------\n");
   printf("KONUT                            %.0f ton\n",toplam_su_konut);
   printf("ISYERI                           %.0f ton\n",toplam_su_isyeri);
   printf("KAMU                             %.0f ton\n",toplam_su_kamu);
   printf("TURISTIK                         %.0f ton\n\n",toplam_su_turistik);
   printf("Toplam                          %.0f ton\n\n",toplam_su_konut+toplam_su_isyeri+toplam_su_kamu+toplam_su_turistik);
   printf("************************************************************************************************************************\n\n");
   printf("8)\nAbone Tipi                  Toplam su Tuketim Ucreti\n ");
   printf("----------                  -------------------------\n");
   printf("KONUT                            %.2f TL\n",su_tuketim_konut);
   printf("ISYERI                           %.2f TL\n",su_tuketim_isyeri);
   printf("KAMU                             %.2f TL\n",su_tuketim_kamu);
   printf("TURISTIK                         %.2f TL\n\n",su_tuketim_turistik);
   printf("TOPLAM                           %.2f TL\n\n",su_tuketim_konut+su_tuketim_isyeri+su_tuketim_kamu+su_tuketim_turistik);
   printf("************************************************************************************************************************\n\n");
   printf("9)\nTum abonelerden elde edilen aylik toplam atik su ucerti : %.2f TL\n\n",atik_su_ucreti_konut+atik_su_ucreti_isyeri+atik_su_ucreti_kamu+atik_su_ucreti_turistik);
   printf("************************************************************************************************************************\n\n");
   printf("10)\nDevlete odenen aylik toplam KDV tutari: %.2f TL\n\n",kdv_tutari_konut+kdv_tutari_isyeri+kdv_tutari_kamu+kdv_tutari_turistik);
   printf("************************************************************************************************************************\n\n");
return 0;
}
