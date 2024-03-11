#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct date
{
    int jour, mois, annee;
} date;
typedef struct les_taches
{
    char titre[100];
    char Description[255];
    char status[30];
    int id;
    date info;
    date creation;
} les_taches;

int n = 0;
les_taches tache[100];

void ajoute_une_seul_tache(les_taches tache[])
{
    time_t t;
    struct tm *today;
    time(&t);
    today = localtime(&t);           //la date actuelle
    tache[n].creation.jour = today->tm_mday;
    tache[n].creation.mois = today->tm_mon + 1;
    tache[n].creation.annee = today->tm_year + 1900;
    tache[n].id = n + 1;
    int k;
    printf("entrer le titre de la tache : ");
    scanf(" %[^\n]", tache[n].titre);
    strupr(tache[n].titre);
    printf("entrer le description de la tache : ");
    scanf(" %[^\n]", tache[n].Description);
    printf("entrer le status de la tache : \n");
    printf("appuyer sur 1 pour entrer: a realise\n");
    printf("appuyer sur 2 pour entrer: en cours de realisation\n");
    printf("appuyer sur 3 pour entrer: finalisee\n");
    printf("entrer votre choix:\n");
    
    
    while (1) {
        if (scanf(" %d", &k) != 1) {
            printf("Entrer un choix valide (1, 2 ou 3) : ");
            while (getchar() != '\n'); 
            continue; 
        }

        switch (k) {
            case 1:
                strcpy(tache[n].status, "a realise");
                break;
            case 2:
                strcpy(tache[n].status, "en cours de realisation");
                break;
            case 3:
                strcpy(tache[n].status, "finalisee");
                break;
            default:
                printf("Votre choix est invalide. Entrer un autre choix (1, 2 ou 3) : ");
                continue; 
        }
        break;  
    }

    printf("entrer le deadline de la tache : ");
    scanf("%d/%d/%d", &tache[n].info.jour, &tache[n].info.mois, &tache[n].info.annee);
    while (tache[n].info.jour > 32 || tache[n].info.mois > 12 || tache[n].info.annee < 2023 ||tache[n].info.mois < 1||tache[n].info.jour < 1) {
    printf("date invalide, veuillez entrer une autre date : ");
    scanf("%d/%d/%d", &tache[n].info.jour, &tache[n].info.mois, &tache[n].info.annee);
    printf("+-----------------------------------------------------------------------------------------------------------------+\n");
}
    n++;
}

void ajoute_une_plusieur_tache(les_taches tache[])
{
    int nb, p;
    printf("le nombre des taches que vous souhaitez saisir:\n");
    scanf("%d", &p);
    nb = p + n;
    for (int i = n; i < nb; i++)
    {
        ajoute_une_seul_tache(tache);
    }
}

void tri_par_order_alphabetique(les_taches tache[])
{
    les_taches temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(tache[i].titre, tache[j].titre) > 0)
            {
                temp = tache[i];
                tache[i] = tache[j];
                tache[j] = temp;
            }
        }
    }
    affichage(tache);
}

void tri_par_date(les_taches tache[])
{
    int i, delai, days;
    int table[n];
    int temp;
    les_taches temp2;
    time_t seconds = time(NULL);
    struct tm *current_time = localtime(&seconds);
    int currentYear = (current_time->tm_year + 1900);
    int currentMonth = (current_time->tm_mon + 1);
    int currentDay = current_time->tm_mday;

    for (i = 0; i < n; i++)
    {
        days = tache[i].info.annee * 365 + tache[i].info.mois * 30 + tache[i].info.jour;
        delai = days - (currentYear * 365 + currentMonth * 30 + currentDay);
        table[i] = delai;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (table[i] > table[j])
            {
                temp = table[i];
                table[i] = table[j];
                table[j] = temp;

                temp2 = tache[i];
                tache[i] = tache[j];
                tache[j] = temp2;
            }
        }
    }
    affichage(tache);
}

void delai(les_taches tache[])
{
    int i, delai, jours;
    int table[n];
    time_t seconds = time(NULL);
    struct tm *current_time = localtime(&seconds);
    int currentYear = (current_time->tm_year + 1900);
    int currentMonth = (current_time->tm_mon + 1);
    int currentDay = current_time->tm_mday;

    for (i = 0; i < n; i++)
    {
        jours = tache[i].info.annee * 365 + tache[i].info.mois * 30 + tache[i].info.jour;
        delai = jours - (currentYear * 365 + currentMonth * 30 + currentDay);
        table[i] = delai;
    }
    for (int i = 0; i < n; i++)
    {
        if (table[i] == 0)
        {
            printf("id : %d | Titre : %s | Deadline en : Aujourdui\n", tache[i].id, tache[i].titre);
        }
        else if (table[i] <= 3)
        {
            printf("id : %d | Titre : %s | Deadline en : %d jours\n", tache[i].id, tache[i].titre, table[i]);
        }
    }
    if (table[i]>3)
    {
        printf("vous n'avez aucune tache a accomplir dans trois jours\n");
    }
    
        
       
    
}

void affichage(les_taches tache[])
{
    printf("\t\t+-----------------------------------------------------------------------------------------------------+\n");
    printf("\t\t%-20s | %-30s | %-17s          | %-3s  | %-10s|\n", "Titre", "Description", "Status", "ID", "Date");
    for (int i = 0; i < n; i++)
    {
        printf("\t\t%-20s | %-30s | %-26s | %-4d | %02d/%02d/%04d|\n", 
               tache[i].titre, tache[i].Description, tache[i].status, tache[i].id,
               tache[i].info.jour, tache[i].info.mois, tache[i].info.annee);
        printf("\t\t-----------------------------------------------------+\n");
        printf("\t\tdate de creation: %d/%d/%d                          |\n",tache[i].creation.jour,tache[i].creation.mois,tache[i].creation.annee);
    printf("\t\t+-----------------------------------------------------------------------------------------------------+\n");
    }
}


int modifierId(les_taches tache[])
{
    int id ,choix, choix2;
    printf("Entrer l'ID de la tache : ");
    scanf("%d", &id);

    for (int i = 0; i < n; i++)
    {
        if (tache[i].id == id)
        {
            printf(" votre tache a modifier: titre: %s      Desciption: %s      status: %s      ID: %d       date :  %d/%d/%d\n", 
               tache[i].titre, tache[i].Description, tache[i].status, tache[i].id,
               tache[i].info.jour, tache[i].info.mois, tache[i].info.annee);
            printf("\nMENU DE MODIFICATION\n");
            printf("appuyer sur 1 pour modifier la Description\n");
            printf("appuyer sur 2 pour modifier le status\n");
            printf("appuyer sur 3 pour modifier la date\n");
            printf("appuyer sur 0 pour retourner au menu principal\n");
            printf("entrer votre choix : ");
            scanf("%d", &choix);

            switch (choix)
            {
            case 0:
                return 0; 
            case 1:
                printf("Entrer la nouvelle Description de la tache : ");
                scanf(" %[^\n]", tache[i].Description);
                break;
            case 2:
                printf("\t Entrez le nouveau statut : \n");
                printf("appuyer sur 1 si votre tache est a realiser: \n");
                printf("appuyer sur 2 si votre tache est en cours de realisation\n");
                printf("appuyer sur 3 si votre tache est finalisee\n");
                scanf("%d", &choix2);

                switch (choix2)
                {
                case 1:
                    strcpy(tache[i].status, "a realiser");
                    break;
                case 2:
                    strcpy(tache[i].status, "en cours de realisation");
                    break;
                case 3:
                    strcpy(tache[i].status, "finalisee");
                    break;
                default:
                    printf("Entrez un des trois choix cite.\n");
                    break;
                }
                break;
            case 3:
                do{
                    printf("Entrer la nouvelle date de la tache (jour mois annee) : ");
                    scanf("%d/%d/%d", &tache[i].info.jour, &tache[i].info.mois, &tache[i].info.annee);
                }while (tache[i].info.jour > 32 || tache[i].info.mois > 12 || tache[i].info.annee < 2023 ||tache[i].info.mois < 1||tache[i].info.jour < 1);
                break;
            default:
                printf("Choix invalide.\n");
            }
            return 0; // quitter la menu de modification
        }
    }
    printf("Tache non trouvee avec l'ID donne.\n");
}

void supprimer(les_taches tache[])
{
    int id, j;
    printf("entrer id de la tache:");
    scanf("%d", &id);

    for (int i = 0; i < n; i++)
    {
        if (tache[i].id == id)
        {
            for (j = i; j < n ; j++)
            {
                tache[i] = tache[j + 1];
                i++;
            }
            n--;
        }
        else{printf("tache non trouve\n");}
    }
}

void chercher(les_taches tache[])
{
    int id, r;
    char titre[100];
    printf("appuyer sur 1 pour chercher par ID\n");
    printf("appuyer sur 2 pour chercher par titre\n");
    scanf("%d", &r);
    switch (r)
    {
    case 1:
        printf("entrer id de tache:");
        scanf("%d", &id);
        for (int i = 0; i < n; i++)
        {
            if (tache[i].id == id)
            {
                printf("\t%s | %s | %s | %d |%d/%d/%d\n", tache[i].titre, tache[i].Description, tache[i].status, tache[i].id, tache[i].info.jour, tache[i].info.mois, tache[i].info.annee);
            }
        }
        break;
    case 2:
        printf("entrer titre de tache:");
        scanf(" %[^\n]", &titre);
        strupr(titre);
        for (int j = 0; j < n; j++)
        {
            if (strcmp(tache[j].titre, titre) == 0)
            {
                printf("\t%s | %s | %s | %d |%d/%d/%d\n", tache[j].titre, tache[j].Description, tache[j].status, tache[j].id, tache[j].info.jour, tache[j].info.mois, tache[j].info.annee);
            }
        }
        break;
    default:
        printf("entrer une choix valable");
    }
}

void statics1(les_taches tache[])
{
    int nb_total_des_taches = 0;
    for (int i = 0; i < n; i++)
    {
        nb_total_des_taches++;
    }

    printf("le nombre total des taches %d\n", nb_total_des_taches);
}

void statics2(les_taches tache[])
{
    int complete = 0;
    int incomplete = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        if (strcmp(tache[i].status, "a realise") == 0 || strcmp(tache[i].status, "en cours de realisation") == 0)
        {
            incomplete++;
        }
        else
            complete++;
    }
    printf("Le nombre des taches complets : %d\n", complete);
    printf("Le nombre des taches incomplets : %d\n", incomplete);
}

void statics3(les_taches tache[])
{
    int i, delai, days;
    int table[n];
    time_t seconds = time(NULL);
    struct tm *current_time = localtime(&seconds);
    int currentYear = (current_time->tm_year + 1900);
    int currentMonth = (current_time->tm_mon + 1);
    int currentDay = current_time->tm_mday;

    for (i = 0; i < n; i++)
    {
        days = tache[i].info.annee * 365 + tache[i].info.mois * 30 + tache[i].info.jour;
        delai = days - (currentYear * 365 + currentMonth * 30 + currentDay);
        table[i] = delai;
    }
    for (int i = 0; i < n; i++)
    {
        if (table[i] == 0)
        {
            printf("id : %d | Titre : %s | Deadline en : Aujourdui\n", tache[i].id, tache[i].titre);
        }
        else
            printf("id : %d | Titre : %s | Deadline en : %d jours\n", tache[i].id, tache[i].titre, table[i]);
    }
}

int affichage_menu1(les_taches tache[])
{
    int b;
    printf("\20t|------------------appuyer sur 1 pour afficher les taches(sans tri)-------------------|\n");
    printf("\20t|------------------appuyer sur 2 pour afficher les taches par order alphabetique------|\n");
    printf("\20t|------------------appuyer sur 3 pour afficher les taches par deadline----------------|\n");
    printf("\20t|------------------appuyer sur 4 Afficher les taches dont le deadline est dans 3 jours|\n");
    printf("\20t|------------------appuyer sur 0 pour retour a la menu principal----------------------|\n");
    printf("\20t entrer votre choix:\n");
    scanf("%d", &b);
    switch (b)
    {
    case 1:
        affichage(tache);
        break;
    case 2:
        tri_par_order_alphabetique(tache);
        break;
    case 3:
        tri_par_date(tache);
        break;
    case 4:
        delai(tache);
        break;
    case 0:
        return 0;
    default:
        printf("entrer une choix valable");
        break;
    }
}

void menu_stat(les_taches tache[])
{
    int j;
    printf("\25t MENU STATISTIQUE\n");
    printf("\20t appuyer sur 1 pour afficher le nombre total des taches\n");
    printf("\20t appuyer sur 2 pour afficher la nombre total des taches complets/incomplets\n");
    printf("\20t appuyer sur 3 pour Afficher le nombre de jours restants jusqu'au delai de chaque tache\n");
    printf("\20t appuyer sur 0 pour quitter le programme\n");
    printf("\20t entrer votre choix : \n");
    scanf("%d", &j);
    switch (j)
    {
    case 1:
        statics1(tache);
        system("pause");
        break;
    case 2:
        statics2(tache);
        system("pause");
        break;
    case 3:
        statics3(tache);
        system("pause");
        break;
    default:
        break;
    }
}

void printasciiArt() {
    printf(" **********   *******         *******     *******         **        **  ********  **********\n");
    printf("/////**///   **/////**       /**////**   **/////**       /**       /**  **//////  /////**/// \n");
    printf("    /**     **     //**      /**    /** **     //**      /**       /**  /**            /**    \n");
    printf("    /**    /**      /**      /**    /**/**      /**      /**       /**  /*********     /**    \n");
    printf("    /**    /**      /**      /**    /**/**      /**      /**       /**  ////////**     /**    \n");
    printf("    /**    //**     **       /**    ** //**     **       /**       /**        /**      /**    \n");
    printf("    /**     //*******        /*******   //*******        /******** /**   ********      /**    \n");
    printf("    //       ///////         ///////     ///////         ////////  //   ////////        //     \n");
}

int main()
{
    int d;
    
    do
    {
           
        printasciiArt();
        
        printf("\20t|------------------appuyer sur 1 pour ajouter une seul tache------------------------|\n");
        printf("\20t|------------------appuyer sur 2 pour ajouter plusieur tache------------------------|\n");
        printf("\20t|------------------appuyer sur 3 pour afficher la menu d'affichage------------------|\n");
        printf("\20t|------------------appuyer sur 4 pour modifier une tache----------------------------|\n");
        printf("\20t|------------------appuyer sur 5 pour supprimer une tache---------------------------|\n");
        printf("\20t|------------------appuyer sur 6 pour rechercher une tache--------------------------|\n");
        printf("\20t|------------------appuyer sur 7 pour acceder a la menu statistique-----------------|\n");
        printf("\20t|------------------appuyer sur 0 pour quitter le program----------------------------|\n");
        printf("\20t entrer votre choix:\n");
        if(scanf("%d", &d)!=1){
            printf("entrer une choix valable!!!\n");
            while (getchar() != '\n');  //efface l'espace
            
        }else{
        switch (d)
        {
        case 1:
            ajoute_une_seul_tache(tache);
            system("pause");            
            break;
        case 2:
            ajoute_une_plusieur_tache(tache);
            system("pause");   
            break;
        case 3:
            affichage_menu1(tache);
            system("pause");   
            break;
        case 4:
            modifierId(tache);
            system("pause");   
            break;
        case 5:
            supprimer(tache);   
            break;
        case 6:
            chercher(tache);
            system("pause");   
            break;
        case 7:
            menu_stat(tache);  
            break;
        case 0:
            printf("Merci pour choisir notre programme");
            exit(0);
        default:
            printf("veuillez tapez une autre choix");
            break;
        }
        }
        
    }while(d != 0);
    return 0;
}