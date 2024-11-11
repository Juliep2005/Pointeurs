#include <iostream>
#include <cctype> // Pour les caractère en majuscule et en minuscule
#include <cstdlib> 


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

int compare_chaine(const char* chaine1, const char* chaine2) {
    int i = 0;

    // Parcourir les chaînes jusqu'à trouver une différence ou atteindre la fin
    while (chaine1[i] != '\0' && chaine2[i] != '\0') {
        if (chaine1[i] < chaine2[i]) {
            return -1; // chaîne1 est lexicographiquement plus petite
        }
        if (chaine1[i] > chaine2[i]) {
            return 1;  // chaîne1 est lexicographiquement plus grande
        }
        i++;
        }
        if (chaine1[i] == '\0' && chaine2[i] == '\0') {
            return 0;  // Les chaînes sont égales
        }
        if (chaine1[i] == '\0') {
            return -1; // chaîne1 est plus courte que chaîne2
        }
        return 1;      // chaîne1 est plus longue que chaîne2
        
        // Instruction de retour de secours (au cas où)
    return 0;
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
    
void inverse(char *testchaine) {
    int longueur = 0;
    while (testchaine[longueur] != '\0') {
        longueur++;
    }

    for (int i = 0; i < longueur / 2; i++) {
        char temp = testchaine[i];
        testchaine[i] = testchaine[longueur - i - 1];
        testchaine[longueur - i - 1] = temp;
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

    int i = 0;
    int sourceLen = 0;

    // Calcul de la longueur de source
    while (source[sourceLen] != '\0') {
        sourceLen++;
    }

    // Vérification des limites
    if (debut >= 0 && debut + longueur <= sourceLen) {
        for (i = 0; i < longueur; i++) {
            dest[i] = source[debut + i];
        }
        dest[i] = '\0'; // Ajout du caractère de fin
    } else {
        dest[0] = '\0'; // Si indices invalides, dest est vide
    }
}

void supprime_caractere(char *chaine, char caractere) {
    int i = 0, j = 0;
    while (chaine[i] != '\0') {
        if (chaine[i] != caractere) {
            chaine[j] = chaine[i];
            j++;
        }
        i++;
    }
    chaine[j] = '\0'; // Terminaison de la chaîne
}

int compte_mots(const char *phrase) {
    int count = 0;
    bool inWord = false;

    while (*phrase != '\0') {
        if (*phrase != ' ' && !inWord) {
            inWord = true;
            count++;
        } else if (*phrase == ' ') {
            inWord = false;
        }
        phrase++;
    }
    return count;
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
        char chaine1[100], chaine2[100];

        std::cout << "Entrez la première chaîne : ";
        std::cin.getline(chaine1, sizeof(chaine1));

        std::cout << "Entrez la deuxième chaîne : ";
        std::cin.getline(chaine2, sizeof(chaine2));

        int compresult = compare_chaine(chaine1, chaine2);

        if (compresult == 0) {
            std::cout << "Les deux chaînes sont égales." << std::endl;
        } else if (compresult > 0) {
            std::cout << "La première chaîne est lexicographiquement plus grande." << std::endl;
        } else {
            std::cout << "La première chaîne est lexicographiquement plus petite." << std::endl;
        }
        

    //Exercice 5
        char caractere;

        std::cout << "Entrez une chaîne : ";
        std::cin.getline(chaine2, 100);

        std::cout << "Entrez un caractère à rechercher : ";
        std::cin >> caractere;

        char *result = cherche_char(chaine2, caractere);

        if (result) {
            std::cout << "Le caractère '" << caractere << "' est trouvé à la position : " 
                    << result - chaine2 << std::endl;
        } else {
            std::cout << "Caractère non trouvé." << std::endl;
        }

    // Exercice 6

        char testChaine[] = "Bonjour";

        inverse(testChaine);

        std::cout << "Test d'inversion de 'Bonjour' : " << testChaine << std::endl;


    // Exercice 7
        char chaine[100];
        char choix;

        std::cout << "Entrez une chaîne : ";
        std::cin.getline(chaine, 100);

        std::cout << "Choisissez 'M' pour majuscules ou 'm' pour minuscules : ";
        std::cin >> choix;

        if (choix == 'M') {
            to_upper(chaine);
            std::cout << "Chaîne en majuscules : " << chaine << std::endl;
        } else if ( choix == 'm') {
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

        std::cout << "Entrez une chaîne : ";
        std::cin.getline(chaine, 100);

        std::cout << "Entrez le caractère à supprimer : ";
        std::cin >> caractere;

        supprime_caractere(chaine, caractere);
        std::cout << "Résultat après suppression : " << chaine << std::endl;
    

    // Exercice 11

        std::cout << "Entrez une phrase : ";
        std::cin.getline(phrase, sizeof(phrase));

        int mots = compte_mots(phrase);
        std::cout << "Nombre de mots dans la phrase : " << mots << std::endl;

      // fin des exercices  


    return 0;
}
