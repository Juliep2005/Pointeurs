#include <stdio.h>

int longueur(const char* chaine) {
    int compteur = 0;
    // Parcourir chaque caractère jusqu'à atteindre le caractère nul '\0'
    while (chaine[compteur] != '\0') { // initialisé à zéro
        compteur++;
    }
    return compteur;
}

int main() {
    // Fonction qui retourne la longueur d'une chaîne de caractère
     char texte[100]; // Réserve de l'espace pour la chaîne
    printf("Entrez une chaîne : ");
    fgets(texte, sizeof(texte), stdin); // Lecture d'une ligne de texte
    printf("La longueur de la chaîne est : %d\n", longueur(texte));
    return 0;
}
