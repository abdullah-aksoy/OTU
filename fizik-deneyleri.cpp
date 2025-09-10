#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265

int main()
{
    float radian,cosValue,s_deneysel,s_ilk_hiz,s_son_hiz,m1,m2,t1, t2, t3, tort, g,a, g_deny, delta_ivme, error_percentage,y,a_deny,a_beklenen,a_delta,bx,by,ay,v_hava,by_ivme,ay_ivme,t1_hava,sarkac_m,sarkac_uzun,aci,top_m;
    int secim;

    do
    {
        printf("\n\n1.Serbest Dusme\n");
        printf("2.Atwood Makinesi\n");
        printf("3.Hava Masasi\n");
        printf("4.Balistik Sarkac\n");
        printf("5.Cikis\n\n");
        printf("Secim yapiniz: ");
        scanf("%d", &secim);

        switch (secim)
        {

        case 1:
            printf("\nt1 degeri: ");
            scanf("%f", &t1);
            printf("t2 degeri: ");
            scanf("%f", &t2);
            printf("t3 degeri: ");
            scanf("%f", &t3);

          
          
            if ((t1 <= 0 || t2 <= 0 || t3 <= 0))
            {
                printf("Gecersiz girdi. Tum degerler sifirdan buyuk olmalidir.\n");
                break;
            }

            tort = (t1 + t2 + t3)/3;
            g = 9.81;

            y=0.5;
            
            g_deny = 2*y/(tort*tort);

            delta_ivme = fabs(g - g_deny);
            error_percentage = delta_ivme * 100 / g;

            printf("\n zaman ortalamasi:%.4f, deneysel ivme:%.4f, delta ivme: %.4f, hata orani:%.4f", tort, g_deny, delta_ivme, error_percentage);
            break;
            
            
      	  
      	  case 2:
            printf("\nm1 degeri: ");
            scanf("%f", &m1);
            printf("m2 degeri: ");
            scanf("%f", &m2);
    
            
            printf("t1 degeri: ");
            scanf("%f", &t1);
            printf("t2 degeri: ");
            scanf("%f", &t2);
            printf("t3 degeri: ");
            scanf("%f", &t3);

          
            if (t1 <= 0 || t2 <= 0 || t3 <= 0 || m1<=0 || m2<=0)
            {
                printf("Gecersiz girdi. Tum degerler sifirdan buyuk olmalidir.\n");
                break;
            }
            
            tort = (t1 + t2 + t3)/3;
            
            g = 9.81;
            y=0.5;
            a_deny = 2*y/(tort*tort);
            a_beklenen=(m2-m1)/(m1+m2)*9.81;           
        	a_delta= fabs(a_beklenen-a_deny);
       		error_percentage = (a_delta * 100) / a_beklenen;

		
			printf("\n zaman ortalamasi: %.4f, deneysel ivmesi:%.4f, beklenen ivmesi %.4f, delta ivmesi:%.4f, hata orani:%.4f", tort, a_deny, a_beklenen,a_delta, error_percentage);
            break;
            
			
		       
		   case 3:
    
			printf("\nYorunge B x degeri: ");
			scanf("%f",&bx);  
        	
 			printf("Yorunge B y degeri: ");
			scanf("%f",&by);     
			
			printf("Yorunge A y degeri: ");
			scanf("%f",&ay);
			
			   
            t1_hava=0.5;
            v_hava=bx/t1_hava;
            by_ivme=(2*by) /(t1_hava*t1_hava);
            ay_ivme=(2*ay)/(t1_hava*t1_hava);
            


			printf("\n B yorungesi x duzleminde hizi:%.4f, Y duzleminde ivmesi:%.4f, A yorungesi duzleminde ivmesi:%.4f", v_hava, by_ivme, ay_ivme);
			break;
			
			
case 4:
    printf("\nTop Kutlesi: ");
    scanf("%f", &top_m);

    printf("Sarkac Kutlesi: ");
    scanf("%f", &sarkac_m);

    printf("Sarkac Uzunlugu: ");
    scanf("%f", &sarkac_uzun);

    printf("Aci Degeri: ");
    scanf("%f", &aci);
    
    if ((top_m <= 0 || sarkac_m <= 0 || sarkac_uzun <= 0)){
	

        printf("Gecersiz girdi. Tum degerler sifirdan buyuk olmalidir.\n");
       break;
            }
	
	radian = aci*(PI / 180);
    cosValue = cos(radian);
 

    s_deneysel = sarkac_uzun * (1 - cosValue);
    s_ilk_hiz = (top_m + sarkac_m) / top_m * sqrt(2 * 9.81 * s_deneysel);
    s_son_hiz = sqrt(2 * 9.81 * s_deneysel);

    printf("\n top atildiginda ciktigi yukseklik:%.4f, carpismadan onceki hiz:%.4f, carpismadan hemen sonraki hiz:%.4f", s_deneysel, s_ilk_hiz, s_son_hiz);
    break;

        
        default:
            printf("\nCikis yaptiniz\n");
        	break;
        }

    } while (secim!=5);


    return 0;
}
