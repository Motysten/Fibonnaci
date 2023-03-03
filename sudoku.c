#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


/*
Pour l'exercice vous aurez besoin de generer des entiers aléatoire : rand() renvoit un entier aléatoire.
il s'utilise : rand() % NOMBREMAX + 1 
Pour un entier aléatoire entre 0 et 1 il faut donc faire rand() %2
voir dans la methode main.
*/

// Ecrire la fonction generer(), elle prend en paramètre la grille et renvoie le nombre d'éléments non nuls

// Ce lien vous sera utile : https://www.geeksforgeeks.org/pass-2d-array-parameter-c/

int generer(int solution[9][9], int grille[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if ((rand()%3) > 0) {
                grille[i][j] = solution[i][j];
            }
        }
    }
    
    int count = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (grille[i][j] == 0) {
                count++;
            }
        }
    }
    return count;
}

/*Écrire une fonction saisir() qui demande à l’utilisateur de saisir au clavier les indices i et j et la valeur v à placer à l’emplacement (i,j).
La fonction doit vérifier la validité des indices et de la valeur.
Si la case n’est pas occupée, la valeur doit être placée dans la grille. remplissage est alors incrémentée*/

void saisir(int arr[9][9], int remplissage) {
    int i, j, v, end = 0;
    while (end == 0) {
        printf("Inserer l'indice i (vertical) : ");
        scanf("%d", &i);
        printf("\nInserer l'indice j (horizontal) : ");
        scanf("%d", &j);
        printf("\nInserer la valeur v : ");
        scanf("%d", &v);
        if (arr[i][j] == 0 && v <= 9) {
            arr[i][j] = v;
            end = 1;
            remplissage--;
        } else {
            printf("Impossible de placer cette valeur a cet endroit. Veuillez verifier les valeurs entrees !\n");
        }
    }
}

/*
Écrire la fonction verifierLigneColonne() qui prend en paramètre un numéro et un sens (HORIZ ou VERT)
qui vérifie que la ligne ou la colonne (suivant les cas) numéro est bien remplie.
On pourra utiliser un tableau intermédiaire pour vérifier cela. La fonction retournera 1 si tout s’est bien passé, 0 sinon.
Les constantes HORIZ de valeur 0 et VERT de valeur 1 sont à définir.
*/

int verifierLigneColonne(int num, char sens[5], int grille[9][9]) {
    int numbers[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    if (strcmp("HORIZ", sens) == 0) {
        int line[9];
        for (int i = 0; i < 9; i++) {
            line[i] = grille[num][i];
            if (line[i] != 0) {
                for (int j = 0; j < 9; j++) {
                    if (line[i] == numbers[j]) {
                        return 0;
                    } else if (numbers[j] == 0) {
                        numbers[j] = line[i];
                        break;
                    }
                }
            } else {
                return 0;
            }
        }
        return 1;
    } else if (strcmp("VERT", sens) == 0) {
        int column[9];
        for (int i = 0; i < 9; i++) {
            column[i] = grille[i][num];
            if (column[i] != 0) {
                for (int j = 0; j < 9; j++) {
                    if (column[i] == numbers[j]) {
                        return 0;
                    } else if (numbers[j] == 0) {
                        numbers[j] = column[i];
                        break;
                    }
                }
            } else {
                return 0;
            }
        }
        return 1;
    }
}

/*
Écrire la fonction verifierRegion() qui prend en paramètre deux indices k et l qui correspondent à la région (k,l)
et qui renvoie 1 si la région est correctement remplie, 0 sinon.
*/

int verifierRegion(int k, int l, int grille[9][9]) {
    int i = k * 3;
    int imax = i + 3;

    int square[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int numbers[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int index = 0;

    for (i; i < imax; i++) {
        int j = l * 3;
        int jmax = j + 3;
        for (j; j < jmax; j++) {
            square[index] = grille[i][j];
            index++;
        }
    }
    
    for (int i = 0; i < 9; i++) {
        if (square[i] != 0) {
            for (int j = 0; j < 9; j++) {
                if (square[i] == numbers[j]) {
                    return 0;
                } else if (numbers[j] == 0) {
                    numbers[j] = square[i];
                    break;
                }
            }
        } else {
            return 0;
        }
    }    
    return 1;
}

//Écrire la fonction verifierGrille() qui renvoie 1 si la grille est correctement remplie et 0 sinon

int verifierGrille(int grille[9][9]) {
    //Horizontal & Vertical
    for (int i = 0; i < 9; i++) {
        if (verifierLigneColonne(i, "HORIZ", grille) == 0) {
            return 0;
        }
        if (verifierLigneColonne(i, "VERT", grille) == 0) {
            return 0;
        }
    }

    //Regions
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (verifierRegion(i, j, grille) == 0) {
                return 0;
            }
        }
    }

    return 1;
}


//Écrire le programme principal, en supposant que la seule condition d’arrêt est la réussite du sudoku (ce test ne devra être fait que si nécessaire)


int main(){
    // Ne pas toucher le code entre les commentaires
    srand( time( NULL ) );


    int i, j, k;
    int solution[9][9];
    printf("SOLUTION");  
    printf("\n");  
    printf("---------------------------------");  
    printf("\n");  
    for(j=0;j<9; ++j) 
    {
    for(i=0; i<9; ++i)
        solution[j][i] = (i + j*3 +j /3) %9 +1 ; 
    }
    
    for(i=0;i<9; ++i) 
    {
    for(j=0; j<9; ++j)
        printf("%d ", solution[i][j]);
    printf("\n");  
    }
    printf("---------------------------------");  
    printf("\n");  
    //toucher le code entre les commentaires 

    int grille[9][9];

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            grille[i][j] = 0;
        }
    }

    int count = generer(solution, grille);
    printf("Cette grille a %d cases a remplir. A vous de les completer :\n", count);

    while (count > 0) {
        printf("---------------------------------\n");  
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d ", grille[i][j]);
            }
            printf("\n");
        }
        saisir(grille, count);
    }
    printf("---------------------------------\n");

    if (verifierGrille(grille) == 1) {
        printf("Bravo vous avez gagne !\n");
    } else {
        printf("Il y a malheureusement des erreurs dans votre grille.\n");
    }

    //Ne pas toucher au code ci dessous
    system("pause");
    return 0;
}
