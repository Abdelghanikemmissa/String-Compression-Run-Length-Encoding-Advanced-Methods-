#include <stdio.h>
#include <stdlib.h>

typedef struct box {
         char c;
         int count;
         struct box* next;
} box;

box* creerNode(char c, int count) {
    box* nouveau = (box*)malloc(sizeof(box));
    if (!nouveau) {
         printf("Erreur d'allocation mémoire\n");
         return NULL;
    }
    nouveau->c = c;
    nouveau->count = count;
    nouveau->next = NULL;
    return nouveau;
}

// fonction pour ajouter un élément à la fin de la liste
box* addFin(box* debut, char c, int count) {
    box* nv = creerNode(c, count);
    if (!nv) return debut;
    // si la liste est vide, retourner le nouvel élément
    if (!debut) return nv; 

    box* temp = debut;
    while (temp->next) {
         temp = temp->next;
    }
    temp->next = nv;

    return debut;
}

// fonction pour afficher la liste chaînée
void afficher(box* debut) {
         if (!debut) {
                  printf("La chaîne est vide\n");
         }
         box* temp = debut;
         while (temp) {
                  printf("%d%c", temp->count, temp->c);
                  temp = temp->next;
         }
         printf("\n");
}

// fonction de compression (Run-Length Encoding)
box* compression(box* debut) {
         if (!debut) return NULL;

         box* compressee = NULL;
         box* temp = debut;

         while (temp) {
         char c = temp->c;
         int count = 0;

         while (temp && temp->c == c) {
                  count++;
                  temp = temp->next;
         }

         // ajouter le caractère et son nombre d'occurrences à la liste compressée
         compressee = addFin(compressee, c, count);
         }
         return compressee;
}

// fonction de décompression (Run-Length Decoding)
box* decompression(box* compressee) {
         if (!compressee) return NULL;
         box* decompressed = NULL;
         box* temp = compressee;
     
         while (temp) {
                  for (int i = 0; i < temp->count; i++) {
                           decompressed = addFin(decompressed, temp->c, 1);
                  }
                  temp = temp->next;
         }
         return decompressed;
          
}

// j'ai creé cette fonction pour afficher la liste au-dessus (decompressed)
void afficherDecompresse(box* debut) {
         if (!debut) {
                  printf("La chaîne est vide\n");
                  return;
         }

         box* temp = debut;
         while (temp) {
                  for (int i = 0; i < temp->count; i++) {
                  printf("%c", temp->c); 
                  }
                  temp = temp->next;
         }
         printf("\n");
}

// fonction pour comparer les deux listes
int islongue(box* originalList , box* compressedList){
    int originalListlength = 0;
    int compressedListlength = 0 ;
    box* count = originalList;
    while (count!=NULL){
        originalListlength++;
        count = count->next;
    }
    
    count = compressedList;
    while (count!=NULL){
        compressedListlength++;
        count = count->next;
    }

    if (originalListlength > compressedListlength){
        printf("La compression est plus efficace.\n");
    }else{
        printf("La compression est plus longue que l'originale.\n");
    }
    return 0;
}

// fonction pour libérer la mémoire
void libererListe(box* debut) {
         box* temp;
          while (debut) {
                  temp = debut;
                  debut = debut->next;
                  free(temp);
         }
}

int main() {
         box* liste = NULL;
         char caractere;
         int nbr;

         printf("Veuillez saisir la taille de la liste : ");
         scanf("%d", &nbr);

         printf("Veuillez saisir les elements de la liste :\n");
         for (int i = 0; i < nbr; i++) {
                  scanf(" %c", &caractere); 
                  liste = addFin(liste, caractere, 1); 
         }

         printf("Liste originale : ");
         box* temp = liste;
         while (temp) {
                  printf("%c", temp->c);
                  temp = temp->next;
         }
         printf("\n");

         // compression
         box* compressee = compression(liste);
         printf("Liste compresser : ");
         afficher(compressee);

         // decompression
         box* decompressed = decompression(compressee);
         printf("Liste decompresser : ");
         afficherDecompresse(decompressed);
         // test la compression
         islongue(liste,compressee);
         // liberation de la mémoire
         libererListe(liste);
         libererListe(compressee);
         libererListe(decompressed);


         return 0;
}
