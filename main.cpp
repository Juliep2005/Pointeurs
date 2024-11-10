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

    while (*dest) {
        dest++;
    }
}

void concatene(char *dest, const char *source) {
    
    while (*dest) {
        dest++;
    }
    
     // Ajouter chaque caractère de source dans dest à partir de la fin de dest
    while (*source) {
        *dest = *source;
        dest++;
        source++;
    }
    
    // Ajouter le caractère nul '\0' à la fin de la chaîne concaténée
    *dest = '\0'; 
}

int compare(const char *chaine1, const char *chaine2) {
    
    // Parcourir chaque caractère des deux chaines
    while (*chaine1 && (*chaine1 == *chaine2)) {
        chaine1++;
        chaine2++;
    }
    
    // la différence
    return *chaine1 - *chaine2;
    
}

char *cherche_char(const char *chaine, char caratere)

    while (*chaine != "/0")
    {
        if (*chaine == caratere)
        {
            return chaine;
        }
        return nullptr
    }
    
    void inversion ( char *chaine)


    

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

    //Exercice 3 : Concaténation de chaînes
        char dest[200];  // Taille plus grande pour stocker la chaîne concaténée
        char source[100];  // Tableau pour la chaîne source

        // Demander à l'utilisateur d'entrer les chaînes
        std::cout << "Entrez la première chaîne (dest) : ";
        std::cin.getline(dest, sizeof(dest));

        std::cout << "Entrez la deuxième chaîne (source) : ";
        std::cin.getline(source, sizeof(source));

        // Appeler la fonction concatene pour ajouter source à la fin de dest
        concatene(dest, source);

        // Afficher la chaîne concaténée
        std::cout << "La chaîne concaténée est : " << dest << std::endl;

        //Exercice 4 : Comparaison de chaines
        char chaine [200];

        std::cout << "Entrez la  chaîne  : ";
        std::cin.getline(chaine1, sizeof(chaine));

        const char* result = recherche_
        if (resultat == 0) {
        std::cout << "0" << std::endl;
        } else if (resultat > 0) {
        std::cout << "positif" << std::endl;
        } else {
        std::cout << "negatif" << std::endl;
        }

        //Exercice 5
        char chaine1 [200];
        char chaine2 [200];

        std::cout << "Entrez la première chaîne pour comparaison : ";
        std::cin.getline(chaine1, sizeof(chaine1));
        std::cout << "Entrez la deuxième chaîne pour comparaison : ";
        std::cin.getline(chaine2, sizeof(chaine2));


        // Exercice 6


        // Exercice 7


        //Exercice 8


        // Exercice 9


        // Exercice 10


        // Exercice 11

    return 0;
}
