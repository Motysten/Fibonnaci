#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <exercice.c>

typedef struct {
    char title[50];
    float price;
    int quantity;
} Product;

int main() {
    Product products[150];
    int num_products = 0;

    char response[10];
    do {
        printf("Titre de l'article : ");
        scanf("%s", products[num_products].title);
        printf("Prix / unité : ");
        scanf("%f", &products[num_products].price);
        printf("Quantité : ");
        scanf("%d", &products[num_products].quantity);

        printf("Voulez-vous continuer ? (o/N) : ");
        scanf("%s", response);

        num_products++;
    } while (mystrcmp(response, "o") == 0 && num_products < 100);

    float total = 0;
    printf("| Titre de l'article | Prix / unité | Quantité | Prix avec taxes |\n");
    printf("-------------------------------------------\n");
    for (int i = 0; i < num_products; i++) {
        printf("| %s | %.2f € | %d | %.2f € |\n",
               products[i].title, products[i].price, products[i].quantity,
               products[i].price * products[i].quantity);
        total += products[i].price * products[i].quantity;
    }
    printf("-------------------------------------------\n");
    printf("| TOTAL | | | %.2f € |\n", total);

    return 0;
}