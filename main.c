#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int heure;
    int jour;
    int mois;
}Date;

typedef enum {a_realiser, en_cours, finalisee} Statut;

typedef struct Tache{
    int id;
    char titre[20];
    char description[200];
    Date deadline;
    Statut st;
}Tache;
int count = 0;
Tache taches[100];

void ajouterTache() {
    int n;
    printf("Combien de nouvelles taches voulez-vous ajouter ? \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        if (count >= 100) {
            printf("Le nombre maximum de tâches est atteint.\n");
            return;
        }
        taches[count].id = count;
        printf("Titre de la tâche : ");
        scanf(" %[^\n]s", taches[count].titre);
        printf("Description de la tâche : ");
        scanf(" %[^\n]s", taches[count].description);
        printf("Deadline (heure jour mois) : ");
        scanf("%d %d %d", &taches[count].deadline.heure, &taches[count].deadline.jour, &taches[count].deadline.mois);
        printf("Statut (0 - a realiser, 1 - en cours, 2 - finalisee) : ");
        scanf("%d", (int*)&taches[count].st);
        count++;
    }
}

void afficherTaches() {
    for (int i = 0; i < count; i++) {
        printf("id: %d\n",taches[i].id);
        printf("Titre: %s\n",taches[i].titre);
        printf("Description: %s\n",taches[i].description);
        printf("Deadline: %d/%d/%d\n", taches[i].deadline.jour,
               taches[i].deadline.mois, taches[i].deadline.heure);
        printf("Statut: %d\n\n", (int)taches[i].st);
    }
}

void trierTachesAlpha() {
    Tache temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(taches[i].titre, taches[j].titre) > 0) {
                temp = taches[i];
                taches[i] = taches[j];
                taches[j] = temp;
            }
        }
    }
    printf("Les taches ont ete triees par titre.\n");
    afficherTaches();
}

void trierTachesD() {
    Tache temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (taches[i].deadline.mois > taches[j].deadline.mois ||
               (taches[i].deadline.mois == taches[j].deadline.mois && taches[i].deadline.jour > taches[j].deadline.jour) ||
               (taches[i].deadline.mois == taches[j].deadline.mois && taches[i].deadline.jour == taches[j].deadline.jour && taches[i].deadline.heure > taches[j].deadline.heure)) {
                temp = taches[i];
                taches[i] = taches[j];
                taches[j] = temp;
            }
        }
    }
    printf("Les tâches ont été triées par deadline.\n");
    afficherTaches();
}


void modifierTache() {
    int id;
    printf("Entrez l'id de la tache a modifier : ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (taches[i].id == id) {
            int choix;
            printf("1 - Modifier la description\n");
            printf("2 - Modifier le statut\n");
            printf("3 - Modifier le deadline\n");
            scanf("%d", &choix);

            switch (choix) {
                case 1:
                    printf("Nouvelle description : ");
                    scanf(" %[^\n]s", taches[i].description);
                    break;
                case 2:
                    printf("Nouveau statut (0 - a realiser, 1 - en cours, 2 - finalisee) : ");
                    scanf("%d", (int*)&taches[i].st);
                    break;
                case 3:
                    printf("Nouveau deadline (heure jour mois) : ");
                    scanf("%d %d %d", &taches[i].deadline.heure, &taches[i].deadline.jour, &taches[i].deadline.mois);
                    break;
                default:
                    printf("Choix invalide.\n");
            }
            return;
        }
    }
    printf("Tache non trouvee.\n");
}

void supprimerTache(){
    int id;
    printf("entrez l'id de la tache que vous voulez supprimer \n");
    scanf("%d", &id);
    int i ;
    for( i = 0 ; i< count ; i++){
        if(taches[i].id == id){
            break;
        }
    }
    if(i == count ){
        printf("Taches non trouvee. \n");
        return ;
    }
    for(int i= id; i<count-1; i++){
        taches[i]=taches[i+1];
    }
    count--;
    printf("Tache supprimee. \n");
}

void rechercherTache() {
    int choix;
    printf("1 - Rechercher par id\n");
    printf("2 - Rechercher par titre\n");
    scanf("%d", &choix);

    if (choix == 1) {
        int id;
        printf("Entrez l'id de la tache a rechercher : ");
        scanf("%d", &id);

        for (int i = 0; i < count; i++) {
            if (taches[i].id == id) {
                printf("id: %d\n",taches[i].id);
                printf("Titre: %s\n",taches[i].titre);
                printf("Description: %s\n",taches[i].description);
                printf("Deadline: %d/%d/%d\n", taches[i].deadline.jour,
                        taches[i].deadline.mois, taches[i].deadline.heure);
                printf("Statut: %d\n\n", (int)taches[i].st);
                return;
            }
        }
        printf("Tache non trouvee.\n");
    } else if (choix == 2) {
        char titre[20];
        printf("Entrez le titre de la tache à rechercher : ");
        scanf(" %[^\n]s", titre);

        for (int i = 0; i < count; i++) {
            if (strcmp(taches[i].titre, titre) == 0) {
                printf("id: %d\n",taches[i].id);
                printf("Titre: %s\n",taches[i].titre);
                printf("Description: %s\n",taches[i].description);
                printf("Deadline: %d/%d/%d\n", taches[i].deadline.jour,
                        taches[i].deadline.mois, taches[i].deadline.heure);
                printf("Statut: %d\n\n", (int)taches[i].st);
                return;
            }
        }
        printf("Tache non trouvee.\n");
    } else {
        printf("Choix invalide.\n");
    }
}




int main(){
    int choix;
    int choix2;
    int choix4;
    int choix5;
    int choix6;
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
            ajouterTache();
            break;
        case 2:
            printf("1-trier les taches par ordre alphabetique\n");
            printf("2-trier les taches par deadline \n");
            printf("3-afficher les taches dont le deadline est dans 3 jours ou moins \n");
            scanf("%d", choix2);

            if      (choix2==1){
                trierTachesAlpha();
            }else if(choix2==2){
                trierTachesD();
            }else if(choix2==3){
              //todo
            }else {
                printf("choix invalide");
                }
            break;
        case 3:
            modifierTache();
            break;
        case 4:
            supprimerTache();
            break;
        case 5:
            rechercherTache();
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
