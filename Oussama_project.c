#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;
struct Node {
    char character;
    int compt;
    Node* suivant;
};

Node* creation(char character, int compt) {
    Node* nv = malloc(sizeof(Node));
    nv->character = character;
    nv->compt = compt;
    nv->suivant = NULL;
    return nv;
}

Node* compretion(const char* chaine) {
    int length = strlen(chaine);
    Node* p = NULL;
    Node* q = NULL;

    for (int i = 0; i < length; i++) {
        int compt = 1;

        while (i < length - 1 && chaine[i] == chaine[i + 1]) {
            compt++;
            i++;
        }

        Node* nv = creation(chaine[i], compt);

        if (p == NULL) {
            p = nv;
            q = nv;
        } else {
            q->suivant = nv;
            q = nv;
        }
    }
    return p;
}

char* decompression(Node* p) {
    int length = 0;
    Node* valeur = p;
    while (valeur != NULL) {
        length += valeur->compt;
        valeur = valeur->suivant;
    }

    // Allouer de la mémoire pour la chaîne décompressée
    char* chaine_decompressee = malloc(length + 1);
    chaine_decompressee[length] = '\0';  // Ajouter le terminateur

    // Remplir la chaîne décompressée
    valeur = p;
    int index = 0;
    while (valeur != NULL) {
        for (int i = 0; i < valeur->compt; i++) {
            chaine_decompressee[index++] = valeur->character;
        }
        valeur = valeur->suivant;
    }

    return chaine_decompressee;
}

void free_list(Node* p) {
    Node* valeur  = p;
    while (valeur != NULL) {
        Node* nv = valeur->suivant;
        free(valeur);
        valeur = nv;
    }
}

void Afficher_liste(Node* p) {
    Node* valeur = p;
    while (valeur != NULL) {
        printf("%d%c", valeur->compt, valeur->character);
        valeur = valeur->suivant;
    }
    printf("\n");
}

int main() {
    const char* chaine = "aaabbaabbb";
    Node* compretion_chaine = compretion(chaine);
    printf("La compression de cette chaîne est : ");
    Afficher_liste(compretion_chaine);

    char* decompression_chaine = decompression(compretion_chaine);
    printf("La décompression de cette chaîne est : %s\n", decompression_chaine);  // Correction ici

    free(decompression_chaine);
    free_list(compretion_chaine);

    return 0;
}
