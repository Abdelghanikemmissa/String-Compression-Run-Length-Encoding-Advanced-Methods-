#include <stdio.h>
#include <stdlib.h>

typedef struct Element element;
struct Element
{
    int occurence;
    char caractere;
    element *suivant;
};

typedef struct Liste liste;
struct Liste
{
    element *premier;
};

liste* initialisation(int nombre)
{
    element *p = malloc(sizeof(element));
    liste *l = malloc(sizeof(liste));
    l->premier = p;
    int i;
    printf("entrer la caractere souhaiter : \n");
    for (i = 1; i <= nombre; i++)
    {
        scanf(" %c", &p->caractere);
        p->occurence = 0;
        if (i == nombre)
            p->suivant = NULL;
        else
        {
            p->suivant = malloc(sizeof(element));
            p = p->suivant;
        }
    }
    return l;
}



int nom_occurence(element *courant, char c)
{
    element *q = courant;
    int compteur = 0;
    while (q != NULL)
    {
        if (q->caractere == c)
            ++compteur;
        else
        {
            int caractere = compteur;
            compteur = 0 ;
            return caractere;
        }
        q = q->suivant;
    }
    return compteur;
}
//La compression

liste* compresser(liste *l)
{
    liste *nouv = malloc(sizeof(liste));
    nouv->premier = NULL;
    element *p = l->premier;
    element *dernier = NULL;
    while (p != NULL)
    {


        element *q = malloc(sizeof(element));
        q->caractere = p->caractere;
        q->occurence = nom_occurence(p, p->caractere); // fhad ligne dowzt lfonction nom_occurence element p bach ihssb man elemnt li kaypointer 3lih p, hit illa dowzt lih liste kamalla kolla mrra ghay3awd ihhsb le meme caractere mn lowl
        q->suivant = NULL;
        if (nouv->premier == NULL)
            nouv->premier = q;
        else
        {
            dernier->suivant = q;
        }
        dernier = q;
        for (int i = 0; i < q->occurence && p != NULL; i++) //fhad boucle dart lut mno howa idwz liya les elemnt consecutif : bhal daba 3titou une liste li fiha a a d v a khasso iy3tina 2a1d1va m3a lboucle, mais ila madrt boucle ghay3tine 2a1a1d1v1a
            p = p->suivant;

    }
    return nouv;
}

//La decompression

liste* decompresser (liste *l)
{
    element *p = malloc(sizeof(element));
    liste *decompresser  = malloc(sizeof(liste));
    decompresser->premier = p;
    element *q = l->premier;
    while ( q != NULL)
    {
        int i;
        for (i = 0; i < q->occurence; ++i)
        {
            p->caractere = q->caractere;
            if (i < q->occurence - 1 || q->suivant != NULL)
            {
                p->suivant = malloc(sizeof(element));
                p = p->suivant;
            }

        }
    q=q->suivant;
    }
    p->suivant = NULL;
    return decompresser;
}

void affiche(liste l)
{
    element *p = l.premier;
    while (p != NULL)
    {
        printf("%d%c", p->occurence, p->caractere);
        p = p->suivant;
    }
    printf("\n");
}
void affich(liste l)
{
    element *p = l.premier;
    while (p != NULL)
    {
        printf("%c", p->caractere);
        p = p->suivant;
    }
    printf("\n");
}

int taille (liste l)
{
    element *p = l.premier;
    int compteur = 0;
    while (p != NULL)
    {
        ++compteur;
        p = p->suivant;
    }
    return compteur;
}

int main()
{
    liste *l = initialisation(5);
    affich(*l);
    liste *lm = compresser(l);
    affiche(*lm);
    liste *decom = decompresser(lm);
    affich(*decom);
    if (taille(*lm) < taille(*l))
        printf("la chaine compresser est court\n");
    else
        printf("la chaine originale est court\n");

    return 0;
}
