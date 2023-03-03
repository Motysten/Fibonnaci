#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        printf("Prix / unite : ");
        scanf("%f", &products[num_products].price);
        printf("Quantite : ");
        scanf("%d", &products[num_products].quantity);

        printf("Voulez-vous continuer ? (o/N) : ");
        scanf("%s", response);

        num_products++;
    } while (strcmp(response, "o") == 0 && num_products < 100);

    float total = 0;
    printf("| Titre de l'article | Prix / unite | Quantite | Prix avec taxes |\n");
    printf("-------------------------------------------\n");
    for (int i = 0; i < num_products; i++) {
        printf("| %s | %.2f euros | %d | %.2f euros |\n",
               products[i].title, products[i].price, products[i].quantity,
               products[i].price * products[i].quantity);
        total += products[i].price * products[i].quantity;
    }
    printf("-------------------------------------------\n");
    printf("| TOTAL | | | %.2f euros |\n", total);

    return 0;
}