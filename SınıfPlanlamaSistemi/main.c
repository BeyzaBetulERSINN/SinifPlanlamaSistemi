#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#define M 1000
#define y 10
#define N 500



struct ogrenci{
char ogrNo[8];
char ad[15];
char soyad[15];
char kayit_sirasi[4];
char ogr_tur[3];
}veri[M],veri2[M],ogrbir[N],ogriki[N];
int main(){
    time_t start,end;
    time(&start);  

listele();
  time(&end);  
  printf("Yazdigimiz kod %.2lfsaniye surdu\n\n",difftime(end,start));
    return 0;
}

    void listele(){
        time_t start,end;
    time(&start);  
    int i=0;
    FILE *dosya,*dosya1;
    dosya=fopen("ogrenci_kayit_bilgileri.txt","r");
    if(dosya==NULL){
        printf("dosya bulunamadi");
        exit(1);
    }else{
    while(!feof(dosya)){
        fscanf(dosya,"%s %s %s %s %s",veri[i].ogrNo,veri[i].ad,veri[i].soyad,veri[i].kayit_sirasi,veri[i].ogr_tur);

        i++;
}fclose(dosya);
printf("ogrenci sayisi:%d\n\n",i);
}
dosya1=fopen("yeni_liste.txt","w");
int j;
int t;
int s;
int c;
c=i;
            printf("2 ve daha fazla tekrar eden kayitlar\n\n");
            for(t=0;t<c;t++){
                    s=0;


                     for(j=t+1;j<c;j++){

        if(strcmp(veri[j].ad,veri[j+1].ad)==0 && strcmp(veri[j].soyad,veri[j+1].soyad)==0){
                s++;
               strcpy(veri[j+1].ogrNo," ");
               strcpy(veri[j+1].ad," ");
               strcpy(veri[j+1].soyad," ");
               strcpy(veri[j+1].ogr_tur," ");
               strcpy(veri[j+1].kayit_sirasi," ");
               if(s>1){
               printf("%s\t%s\n",veri[j].ad,veri[j].soyad);
               }
               }
               strcpy(veri2[j].ogrNo,veri[j].ogrNo);
               strcpy(veri2[j].ad,veri[j].ad);
               strcpy(veri2[j].soyad,veri[j].soyad);
               strcpy(veri2[j].ogr_tur,veri[j].ogr_tur);
               strcpy(veri2[j].kayit_sirasi,veri[j].kayit_sirasi);
               }
               }
               printf("2 ve daha fazla tekrar eden kayitlar silinmistir.\n\n");

time(&end);
  printf("silinme %.2lfsaniye surdu\n\n",difftime(end,start));


   time(&start); 

        int temp ;

          int dizi[c];
          for(t=0;t<c;t++){
          if(strcmp(veri2[t].ad," ")==0&&strcmp(veri2[t].soyad," ")==0){
                dizi[t]=500;
          }
             else{

            dizi[t]=atoi(veri2[t].kayit_sirasi);}

          }
          for(j=1;j<c;j++){//buble sort algoritması
            for(t=0;t<c-j;t++){


                if(dizi[t]>dizi[t+1]){
                temp=dizi[t];
                dizi[t]=dizi[t+1];
                dizi[t+1]=temp;
                strcpy(veri[t].kayit_sirasi,veri2[t].kayit_sirasi);
                strcpy(veri2[t].kayit_sirasi,veri2[t+1].kayit_sirasi);
                strcpy(veri2[t+1].kayit_sirasi,veri[t].kayit_sirasi);
                strcpy(veri[t].ad,veri2[t].ad);
                strcpy(veri2[t].ad,veri2[t+1].ad);
                strcpy(veri2[t+1].ad,veri[t].ad);
                strcpy(veri[t].soyad,veri2[t].soyad);
                strcpy(veri2[t].soyad,veri2[t+1].soyad);
                strcpy(veri2[t+1].soyad,veri[t].soyad);
                strcpy(veri[t].ogrNo,veri2[t].ogrNo);
                strcpy(veri2[t].ogrNo,veri2[t+1].ogrNo);
                strcpy(veri2[t+1].ogrNo,veri[t].ogrNo);
                strcpy(veri[t].ogr_tur,veri2[t].ogr_tur);
                strcpy(veri2[t].ogr_tur,veri2[t+1].ogr_tur);
                strcpy(veri2[t+1].ogr_tur,veri[t].ogr_tur);

                }
                }

          }




           for(t=0;t<c;t++){
            if(strcmp(veri2[t].ogrNo,"-")==0){

               strcpy(veri2[t].ogrNo,"170");
               if(strcmp(veri2[t].ogr_tur,"I")==0){
                strcat(veri2[t].ogrNo,"1");}
                else if(strcmp(veri2[t].ogr_tur,"II")==0){
                strcat(veri2[t].ogrNo,"2");}
                if(strlen(veri2[t].kayit_sirasi)==1){
                    strcat(veri2[t].ogrNo,"00");
                    strcat(veri2[t].ogrNo,veri2[t].kayit_sirasi);
                 }
                 if(strlen(veri2[t].kayit_sirasi)==2){
                    strcat(veri2[t].ogrNo,"0");
                    strcat(veri2[t].ogrNo,veri2[t].kayit_sirasi);
                 }
                 if(strlen(veri2[t].kayit_sirasi)==3){
                    strcat(veri2[t].ogrNo,veri2[t].kayit_sirasi);
                 }


          }
          }
time(&end);
  printf("ogrenci numaralarini verme  %.2lfsaniye surdu\n\n",difftime(end,start));

  time(&start);


   long dizi2[c];
    for(t=0;t<c;t++){
            dizi2[t]=atol(veri2[t].ogrNo);

}

           for(j=1;j<c;j++){  //buble sort algoritması
            for(t=0;t<c-j;t++){


                if(dizi2[t]>dizi2[t+1]){
                temp=dizi2[t];
                dizi2[t]=dizi2[t+1];
                dizi2[t+1]=temp;
                strcpy(veri[t].ogrNo,veri2[t].ogrNo);
                strcpy(veri2[t].ogrNo,veri2[t+1].ogrNo);
                strcpy(veri2[t+1].ogrNo,veri[t].ogrNo);
                strcpy(veri[t].ad,veri2[t].ad);
                strcpy(veri2[t].ad,veri2[t+1].ad);
                strcpy(veri2[t+1].ad,veri[t].ad);
                strcpy(veri[t].soyad,veri2[t].soyad);
                strcpy(veri2[t].soyad,veri2[t+1].soyad);
                strcpy(veri2[t+1].soyad,veri[t].soyad);
                strcpy(veri[t].kayit_sirasi,veri2[t].kayit_sirasi);
                strcpy(veri2[t].kayit_sirasi,veri2[t+1].kayit_sirasi);
                strcpy(veri2[t+1].kayit_sirasi,veri[t].kayit_sirasi);
                strcpy(veri[t].ogr_tur,veri2[t].ogr_tur);
                strcpy(veri2[t].ogr_tur,veri2[t+1].ogr_tur);
                strcpy(veri2[t+1].ogr_tur,veri[t].ogr_tur);

                }
                }

          }

           for(j=0;j<c;j++){

           fprintf(dosya1,"%-10s%-10s%-10s%-10s%-10s\n",veri2[j].ogrNo,veri2[j].ad,veri2[j].soyad,veri2[j].kayit_sirasi,veri2[j].ogr_tur);

           }
           printf("2'den fazla tekrar eden ogrenci yoktur\n\n");

           printf("kayit sirasi guncelenmistir\n\n");
           time(&end);
          printf("Numaralari siralama ve guncelleme %.2lfsaniye surdu\n\n",difftime(end,start));

           fclose(dosya1);

            int top1=0,top2=0;
           for(i=0;i<c;i++){
    if(strcmp(veri2[i].ogr_tur,"I")==0){


        strcpy(ogrbir[top1].ad,veri2[i].ad);
        strcpy(ogrbir[top1].soyad,veri2[i].soyad);
        strcpy(ogrbir[top1].kayit_sirasi,veri2[i].kayit_sirasi);
        strcpy(ogrbir[top1].ogrNo,veri2[i].ogrNo);
        strcpy(ogrbir[top1].ogr_tur,veri2[i].ogr_tur);
        top1++;
    }
       else if(strcmp(veri2[i].ogr_tur,"II")==0){
        strcpy(ogriki[top2].ad,veri2[i].ad);
        strcpy(ogriki[top2].soyad,veri2[i].soyad);
        strcpy(ogriki[top2].kayit_sirasi,veri2[i].kayit_sirasi);
        strcpy(ogriki[top2].ogrNo,veri2[i].ogrNo);
        strcpy(ogriki[top2].ogr_tur,veri2[i].ogr_tur);
        top2++;

        }
}


 int top3,top4;
 int top6,top7;
 top3=top1;
 top4=top2;
 top6=top1;
 top7=top2;
 printf("dersi alan 1. ogretim ogrenci sayisi: %d\n\n",top1);
 printf("dersi alan 2. ogretim ogrenci sayisi: %d\n\n",top2);




   int sayi;
   printf("sinif sayisini giriniz:\n\n");
            scanf("%d",&sayi);
            int sinif[sayi];

             int sinif3[sayi];
             int sinif4[sayi];

                 int a;
                 int sinif2[sayi];
                for(i=0;i<sayi;i++){
                   printf("%d.sinif kapasitelerini giriniz:",i+1);
                   scanf("%d",&a);
                   sinif[i]=a;
                   sinif2[i]=a;
                   sinif3[i]=a;
                   sinif4[i]=a;

                }



int ortbir,ortiki;
ortbir=ceil(top1/sayi);
ortiki=ceil(top2/sayi);

printf("%d\n",ortbir);
printf("%d\n",ortiki);
time(&start);

FILE *dosya2;
FILE *dosya3;
int temp2;
for(i=1;i<sayi;i++){ //buble sort algoritması
    for(j=0;j<sayi-i;j++){
            if(sinif[j]>sinif[j+1])
            {


                temp2=sinif[j];
                temp2=sinif2[j];
                sinif[j]=sinif[j+1];
                sinif2[j]=sinif2[j+1];
                sinif[j+1]=temp2;
                sinif2[j+1]=temp2;
}
}
}
int bas1=0,bas2=0;


for(i=0;i<sayi;i++){
    sprintf(ogrbir,"sinif1ogr1%desit.txt",i+1);//
    sprintf(ogriki,"sinif1ogr2%desit.txt",i+1);
    dosya2=fopen(ogrbir,"w+");
    dosya3=fopen(ogriki,"w+");

    if(sinif[i]>ortbir)
        sinif[i]=ortbir;


    if (i==(sayi-1))
        sinif[i]=ortbir;

    for(j=bas1;j<sinif[i]+bas1;j++)
       fprintf(dosya2,"%-10s%-10s%-10s%-10s%-10s\n",ogrbir[j].ogrNo,ogrbir[j].ad,ogrbir[j].soyad,ogrbir[j].kayit_sirasi,ogrbir[j].ogr_tur);
       bas1=sinif[i]+bas1;
        top1=top1-sinif[i];
        if(i!=(sayi-1))
            ortbir=top1/(sayi-i-1);


    if(sinif2[i]>ortiki)
        sinif2[i]=ortiki;

    if (i==(sayi-1))
        sinif2[i]=ortiki;

    for(j=bas2;j<sinif2[i]+bas2;j++)
       fprintf(dosya3,"%-10s%-10s%-10s%-10s%-10s\n",ogriki[j].ogrNo,ogriki[j].ad,ogriki[j].soyad,ogriki[j].kayit_sirasi,ogriki[j].ogr_tur);
       bas2=sinif2[i]+bas2;
        top2=top2-sinif2[i];
        if(i!=(sayi-1))
            ortiki=top2/(sayi-i-1);

    }


    printf("Esit Dagilimli Sinif Kapasiteleri:\n");
    printf("I. Ogretim Sinif Kapasiteleri:\n");
    for (i=0;i<sayi;i++)
    {

        printf("%d.sinif=%d\n",i+1,sinif[i]);
    }
    printf("II. Ogretim Sinif Kapasiteleri:\n");
    for (i=0;i<sayi;i++)
    {

        printf("%d.sinif=%d\n",i+1,sinif2[i]);
    }

    time(&end);
  printf("Esit kapasiteli sinif dagilimi %.2lfsaniye surdu\n",difftime(end,start));

  time(&start);
    FILE *dosya4;
    FILE *dosya5;

for(i=1;i<sayi;i++){
    for(j=0;j<sayi-i;j++){ //buble sort algoritması
            if(sinif3[j]<sinif3[j+1])
            {


                temp2=sinif3[j];
                temp2=sinif4[j];
                sinif3[j]=sinif3[j+1];
                sinif4[j]=sinif4[j+1];
                sinif3[j+1]=temp2;
                sinif4[j+1]=temp2;
}
}
}



bas1=0,bas2=0;



for(i=0;i<sayi;i++){  //dosyalar açýlýrken isimleri yazdýrsak
    sprintf(ogrbir,"sinif1ogr1%denaz.txt",i+1);//
    sprintf(ogriki,"sinif1ogr21%denaz.txt",i+1);
    dosya4=fopen(ogrbir,"w+");//kayit 1 sýnýf 1'e kadar yazdýrsak
    dosya5=fopen(ogriki,"w+");

    for(j=bas1;j<sinif3[i]+bas1;j++)

       fprintf(dosya4,"%-10s\t%-10s\t%-10s\t%-10s\t%-10s\n",ogrbir[j].ogrNo,ogrbir[j].ad,ogrbir[j].soyad,ogrbir[j].kayit_sirasi,ogrbir[j].ogr_tur);
       bas1=sinif3[i]+bas1;
        top3=top3-sinif3[i];






    for(j=bas2;j<sinif4[i]+bas2;j++)
       fprintf(dosya5,"%-10s\t%-10s\t%-10s\t%-10s\t%-10s\n",ogriki[j].ogrNo,ogriki[j].ad,ogriki[j].soyad,ogriki[j].kayit_sirasi,ogriki[j].ogr_tur);
       bas2=sinif4[i]+bas2;

        top4=top4-sinif4[i];








    }
 int e;
 int z;

    printf("En Az Dagilimli Sinif Kapasiteleri:\n");
    printf("I. Ogretim Sinif Kapasiteleri:\n");
    for (i=0;i<sayi;i++)
    {
        if(top6<=0){
            printf("%d.sinif=0\n",i+1);
        }
        else if(top6>0){
       printf("%d.sinif=%d\n",i+1,sinif3[i]);
        }
        top6=top6-sinif3[i];

    }

    printf("II. Ogretim Sinif Kapasiteleri:\n");
    for (i=0;i<sayi;i++)
    {
         if(top7<=0){
             printf("%d.sinif=0\n",i+1);
         }
         else{
        printf("%d.sinif=%d\n",i+1,sinif4[i]);
         }
         top7=top7-sinif4[i];
    }

    time(&end);
  printf("En az kapasiteli sinif dagilimi %.2lfsaniye surdu\n",difftime(end,start));

    fclose(dosya2);
    fclose(dosya3);
    fclose(dosya4);
    fclose(dosya5);



    }
