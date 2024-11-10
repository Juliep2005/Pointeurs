#include <iostream>
#include <cctype> // Pour les caractère en majuscule et en minuscule


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

char *cherche_char(const char *chaine, char caractere) {
    while (*chaine) {
        if (*chaine == caractere) {
            return const_cast<char*>(chaine); // Retourne un pointeur vers la première occurrence
        }
        chaine++;
    }
    return nullptr; // Retourne nullptr si le caractère n'est pas trouvé
}
    
void inverse(char *chaine) {
    int longueur = 0;
    while (chaine[longueur] != '\0') {
        longueur++;
    }

    for (int i = 0; i < longueur / 2; i++) {
        char temp = chaine[i];
        chaine[i] = chaine[longueur - i - 1];
        chaine[longueur - i - 1] = temp;
    }
}

void to_upper(char *chaine) {
    while (*chaine) {
        *chaine = std::toupper(*chaine);
        chaine++;
    }
}

void to_lower(char *chaine) {
    while (*chaine) {
        *chaine = std::tolower(*chaine);
        chaine++;
    }
}


char *cherche_mot(const char *phrase, const char *mot) {
    while (*phrase) {
        const char *p = phrase;
        const char *m = mot;

        while (*m && *p == *m) {
            p++;
            m++;
        }

        if (*m == '\0') {
            return const_cast<char*>(phrase); // Le mot est trouvé
        }
        phrase++;
    }
    return nullptr; // Retourne nullptr si le mot n'est pas trouvé
}


void sous_chaine(const char *source, char *dest, int debut, int longueur) {
    for (int i = 0; i < longueur; i++) {
        dest[i] = source[debut + i];
    }
    dest[longueur] = '\0'; // Terminer la chaîne avec '\0'
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
        char chaine [100];

        std::cout << "Entrez la  chaîne  : ";
        std::cin.getline(chaine, sizeof(chaine));

        const char *com_result = chaine;
        if (com_result == nullptr) {
        std::cout << "0" << std::endl;
        } else if (com_result != nullptr) {
        std::cout << "positif" << std::endl;
        } 

    //Exercice 5
        char caractere;

        std::cout << "Entrez une chaîne : ";
        std::cin.getline(chaine, 100);

        std::cout << "Entrez un caractère à rechercher : ";
        std::cin >> caractere;

        char *result = cherche_char(chaine, caractere);

        if (result) {
            std::cout << "Le caractère '" << caractere << "' est trouvé à la position : " 
                    << result - chaine << std::endl;
        } else {
            std::cout << "Caractère non trouvé." << std::endl;
        }

    // Exercice 6

        std::cout << "Entrez une chaîne à inverser : ";
        std::cin.getline(chaine, sizeof(chaine));

        inverse(chaine);

        std::cout << "La chaîne inversée est : " << chaine << std::endl;


    // Exercice 7
        char choix;

        std::cout << "Entrez une chaîne : ";
        std::cin.getline(chaine, 100);

        std::cout << "Choisissez 'M' pour majuscules ou 'm' pour minuscules : ";
        std::cin >> choix;

        if (choix == 'M' || choix == 'm') {
            to_upper(chaine);
            std::cout << "Chaîne en majuscules : " << chaine << std::endl;
        } else if (choix == 'M' || choix == 'm') {
            to_lower(chaine);
            std::cout << "Chaîne en minuscules : " << chaine << std::endl;
        } else {
            std::cout << "Choix invalide." << std::endl;
        }

    // Exercice 8
        char phrase[200];
        char mot[100];

        std::cout << "Entrez une phrase : ";
        std::cin.getline(phrase, 200);


        char *resultat = cherche_mot(phrase, mot);

        if (resultat) {
            std::cout << "Le mot '" << mot << "' est trouvé dans la phrase." << std::endl;
        } else {
            std::cout << "Mot non trouvé." << std::endl;
        }


    // Exercice 9
        int debut, longueur;

        std::cout << "Entrez une chaîne source : ";
        std::cin.getline(source, 200);

        std::cout << "Entrez la position de début : ";
        std::cin >> debut;

        std::cout << "Entrez la longueur de la sous-chaîne : ";
        std::cin >> longueur;

        sous_chaine(source, dest, debut, longueur);

        std::cout << "La sous-chaîne extraite est : " << dest << std::endl;


        // Exercice 10


        // Exercice 11

    return 0;
}
