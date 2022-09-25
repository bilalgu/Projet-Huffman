#ifndef FONCTIONS_PH_H_INCLUDED
#define FONCTIONS_PH_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**
 * @file Fonctions_PH.h
 * @brief Headers des prototypes des Fonctions Principales Huffman
 *        Regroupant aussi toutes les structures utilisees
 *        Explications des fonctions dans le .c
 *
 * @author GUIRRE Bilal, HASSAN Sylla, CHOUKROUN, Simon JANES Lucas, et, BERDOUZ Nassim
 */

//STRUCTURES --------------------------------------------------------------------

typedef struct Element{
    int lettre;
    int occu;
    struct Element* next;
}Element;

typedef struct Noeud{
    int lettre;
    int occu;
    struct Noeud* left;
    struct Noeud* right;
}Noeud;

typedef struct ElementN{
    Noeud* node;
    struct ElementN* next;
}ElementN;

typedef struct PileElement{
    char car;
    struct PileElement* next;
}PileElement;

typedef struct ElementD{
    int lettre;
    char* occu;
    struct ElementD* next;
}ElementD;



//----------------PARTIE 1 -----------------------------------------------------------------------

//QUESTION A/1.1 ------------------------------------------------------------

char* convert_bin(int n);
int lecture_ecriture(FILE* f1,FILE* f2);

//QUESTION B/1.2 --------------------------------------------------------

int nbr_char_fic(FILE* fic);

//------------------------------------PARTIE 2 ----------------------------------------------

//QUESTION C/2.1 --------------------------------------------------------

Element* list_occu_char(FILE* fic);
Element* insert_list(Element* li,int lettre);

//QUESTION D/2.2 --------------------------------------------------------

Element* ranger_liste(Element* liste);
ElementN* convert_LC_to_LCN(Element* L);
Noeud* min_occu_LN(ElementN** L_N);
void Arbre_Huffman(ElementN** L_N);

//QUESTION E/2.3 --------------------------------------------------------

void ecrire_dico_pile(PileElement* pile,FILE* dic);
void dico(Noeud* Arbre,PileElement** nbr,FILE* dic);


//QUESTION F/2.4 --------------------------------------------------------

char* read_char(FILE* dic);
ElementD* dico_to_element(FILE* dic);
void convertion_txt_to_huffman(FILE* f2,FILE* f3,ElementD* L);

#endif // FONCTIONS_PH_H_INCLUDED

