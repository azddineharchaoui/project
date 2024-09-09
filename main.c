#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Date{
    int heure;
    int jour;
    int mois;
}Date;

enum statut{a_realiser, en_cours, finalisee};

typedef struct Tache{
    int id;
    char titre[20];
    char description[200];
    Date deadline;
    enum statut st;
}Tache;
int count = 0;
Tache taches[100];
int main(){
    int choix;
    int choix2;
    int choix3;
    int choix4;
    int choix5;
    int id_;
    char * str;
    do{
        printf("---Menu---\n\n");
        printf("1- Ajouter une nouvelle tache \n");
        printf("2- Afficher la liste de tous les taches \n");
        printf("3- Modifier une tache \n");
        printf("4- Supprimer une tache \n");
        printf("5- Rechercher une tache\n");
        printf("6- Afficher les Statistiques \n");
        printf("7- Quitter \n");
        scanf("%d",&choix);
        switch(choix){
        case 1:
            taches[count].id = count;
            printf("entrez le titre de la tache \n");
            scanf("%s", taches[count].titre);
            printf("entrez la description de la tache \n");
            scanf("%s", taches[count].description);
            printf("Entrez le deadline h/j/m/a\n");
            scanf("%d", &taches[count].deadline.heure);
            scanf("%d", &taches[count].deadline.jour);
            scanf("%d", &taches[count].deadline.mois);
            printf("entrez le statut : 0(a realiser ), 1(en cours), 2(finalisee)");
            scanf("%d", &taches[count].st);
            count++;
            break;
        case 2:
            printf("1-trier les taches par ordre alphabetique\n");
            printf("2-trier les taches par deadline \n");
            printf("3-afficher les taches dont le deadline est dans 3 jours ou moins \n");
            scanf("%d", choix2);
            if      (choix2==1){
                int i, j ;
                Tache temp;
                for(i=0; i<count -1; i++){
                    for(j=0; j<count -i-1; j++){
                        if(strcmp(taches[j].titre, taches[j+1].titre)>0){
                            temp = taches[j];
                            taches[j] = taches[j+1];
                            taches[j+1] = temp;
                        }
                    }
                }

            }else if(choix2==2){
            /*    int i , j;
                int tmp;
                for( i =0 ; i< count-1; i++){
                    for (j=0; j<count -i -1; j++){
                        if(taches[j].deadline.mois > taches[j+1].deadline.mois)
                    }
                }
*/
            }else if(choix2==3){
               /* for (int i =0 ; i<count; i++){
                    if(taches[i].deadline)
                }*/
            }else {
                printf("choix invalide");
                }
                break;
        case 3:
            printf("1-Modifier la description d'une tache \n");
            printf("2-Modifier le statut d'une tache \n");
            printf("3-Modifier le deadline d'une tache \n");
            scanf("%d", &choix3);
            if(choix3==1){
                int id_;
                printf("entrer l'id de la tache que vous voulez modifier \n");
                scanf("%d", id_);
                for (int i = 0 ; i<count; i++){
                    if(taches[i].id == id_){
                        scanf("%s", &taches[i].description);
                    }
                }
            } else if (choix3 == 2){
                int id_;
                printf("entrer l'id de la tache que vous voulez modifier \n");
                scanf("%d", id_);
                for (int i = 0 ; i<count; i++){
                    if(taches[i].id == id_){
                        scanf("%d", &taches[i].st);
                    }
                }
            }else if(choix3==3){
                int id_;
                printf("entrer l'id de la tache que vous voulez modifier \n");
                scanf("%d", id_);
                for (int i = 0 ; i<count; i++){
                    if(taches[i].id == id_){
                        printf("Entrez l'heure du nouveau deadline\n");
                        scanf("%d", taches[i].deadline.heure);

                        printf("Entrez l'heure du nouveau deadline\n");
                        scanf("%d", taches[i].deadline.jour);

                        printf("Entrez l'heure du nouveau deadline\n");
                        scanf("%d", taches[i].deadline.mois);
                    }
                }
            }else {printf("choix invalide \n");}
            break;
        case 4:
            printf("entrez l'id de la tache que vous voulez supprimer \n");
            scanf("%d", &id_);
            for(int i= id_; i<count-1; i++){
                taches[i]=taches[i+1];
            }
            count--;
            break;
        case 5:
            printf("1-Rechercher une tache par son identifiant \n");
            printf("2-Rechercher une tache par son titre \n");
            scanf("%d", choix4);
            if(choix4==1){
                printf("entrez l'identifiant que vous recherchez \n");
                scanf("%d", &id_);
                for (int i = 0 ; i<count ; i++){
                    if(taches[i].id==id_){
                        printf("%d, %s, %s, %d/%d/%d, statut : %d\n",
                               id_, taches[i].titre, taches[i].description, taches[i].deadline.heure, taches[i].deadline.jour, taches[i].deadline.mois, taches[i].st);


                    }
                }

            } else if (choix4==2){
                printf("entrez le titre de la tache que vous recherchez\n");
                scanf("%s", str);
                for (int i = 0; i< count ; i++){
                    if(!strcmp(taches[i].titre, str)){
                        printf("%d, %s, %s, %d/%d/%d, statut : %d\n",
                               id_, taches[i].titre, taches[i].description, taches[i].deadline.heure, taches[i].deadline.jour, taches[i].deadline.mois, taches[i].st);

                    }
                }
            }
            else {printf("choix invalide"); }
            break ;
            case 6:
                printf("1-Afficher le nombre total des taches \n");
                printf("2-Afficher le nombre de taches completes et incompletes \n");
                printf("3-Afficher le nombre de jours restants juqu'au delai de chaque tache \n");
                scanf("%d", &choix5);
                if(choix5==1) return count;
                else if(choix5==2) {
                    int counter = 0 ;
                    for (int i = 0 ; i<count; i++){
                        if(taches[i].st==2){counter++; }
                    }
                    printf("le nombre de taches completes est %d\n", counter);
                    printf("le nombre de taches incompletes est %d", count -counter );
                }else if(choix5==3){}
                else {printf("choix invalide "); }
            default:
                break;

        }

    }while(choix != 0);
    return 0;
}
