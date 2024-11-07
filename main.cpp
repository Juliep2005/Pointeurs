#include <iostream>

int longueur(const char* chaine) {
    int compteur = 0;
    // Parcourir chaque caractère jusqu'à atteindre le caractère nul '\0'
    while (chaine[compteur] != '\0') { // initialisé à zéro
        compteur++;
    }
    return compteur;
}

void copie(char *dest, const char *source) {
    // Parcours de la chaîne source jusqu'au caractère nul '\0'
    int i = 0;
    while (source[i] != '\0') {
        dest[i] = source[i];  // Copie caractère par caractère
        i++;
    }
    dest[i] = '\0';  // Ajouter le caractère nul '\0' à la fin de la chaîne destinataire
}

int main() {

    // Exercice 1
        char texte[100]; // Réserve de l'espace pour la chaîne
        std::cout << "Entrez une chaîne : ";
        std::cin.getline(texte, sizeof(texte));  // Utilisation de std::cin.getline pour lire la chaîne

        // Afficher la longueur de la chaîne
        std::cout << "La longueur de la chaîne est : " << longueur(texte) << std::endl;

    // Exercice 2
        char copie_texte[100];  // Tableau pour stocker la chaîne copiée

        // Appeler la fonction copie pour copier la chaîne dans copie_texte
        copie(copie_texte, texte);

        // Afficher la chaîne copiée
        std::cout << "La chaîne copiée est : " << copie_texte << std::endl;

    return 0;
}
