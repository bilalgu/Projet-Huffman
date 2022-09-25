#ifndef FONCTIONS_SECONDAIRES_H_INCLUDED
#define FONCTIONS_SECONDAIRES_H_INCLUDED
#include"Fonctions_PH.h"
/**
 * @file fonctions_secondaires.h
 * @brief Headers des prototypes des fonctions secondaires facilitant les Fonctions PH
 *        Explications de certaines fonctions dans le .c
 * @author GUIRRE Bilal, HASSAN Sylla, CHOUKROUN, Simon JANES Lucas, et, BERDOUZ Nassim
 */

void print_tree(Noeud* tree);
Noeud* creer_noeud(int lettre,int occu);
int tree_compare(Noeud* n1,Noeud* n2);
void print_tree_H(Noeud* tr);
void add_noeud_LN(ElementN** L_N,Element* L);
void suppr_noeud_LN(ElementN** L_N,Noeud* N);
void add_noeud_fin_LN(ElementN** L_N,Noeud* N);
Noeud* create_noeud_huffman(Noeud* n1,Noeud* n2);
void afficher_LC(Element* L);
PileElement* creer_PileElement(char car);
PileElement* empiler(PileElement* pile,char car);
PileElement* depiler(PileElement* pile);




#endif // FONCTIONS_SECONDAIRES_H_INCLUDED
