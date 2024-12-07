#include <stdio.h>
#include <stdlib.h>

int find_smallest(int *tab,int *taille){
    int smallest=tab[0];
    int place_smallest=0;
    for(int i =0;i<(*taille);i++){
        if(smallest==-1 && tab[i]!=-1){
            smallest=tab[i];
        }
        if (tab[i]<=smallest && tab[i]!=-1){
            smallest=tab[i];
            place_smallest=i;
        }
    }
    tab[place_smallest]=-1;
    return smallest;
}

int boucle_calcul(int *tab1,int *tab2,int *taille){
    int small1;
    int small2;
    int somme=0;
    for(int i=0;i<(*taille);i++)
    {
        small1=find_smallest(tab1,taille);
        small2=find_smallest(tab2,taille);
        somme+=abs(small1-small2);
    }
    return somme;
    
}

void afficher_tableau(int *tab,int taille){
    for(int i=0;i<taille;i++){
        printf("%d \n",tab[i]);
    }
}

int calcul_simularity(int *list1,int *list2,int taille){
    int occurence[1000000]={0};
    int somme=0;
    for(int i =0 ;i<taille;i++){
        occurence[list2[i]]++;
    }
    for(int j = 0 ;j<taille;j++){
        list1[j]=list1[j]*occurence[list1[j]];
        somme+=list1[j];
    }
    return somme;
}


int main (){
    FILE *f;
    int result_scan=2;
    f=fopen("input_day1.txt","r");
    int i =0;
    int *taille=malloc(sizeof(int));
    int list1[1000]={0};
    int list2[1000];
    while (result_scan==2)
    {
        result_scan=fscanf(f,"%d %d",&list1[i],&list2[i]);
        i++;
        (*taille)++;
    }
    (*taille)=(*taille)-1;
    printf("%d",calcul_simularity(list1,list2,(*taille)));
}