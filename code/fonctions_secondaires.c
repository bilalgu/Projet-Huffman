#include"fonctions_secondaires.h"
/**
 * @file fonctions_secondaires.c
 * @brief fonctions secondaires facilitant les Fonctions PH
 * @author GUIRRE Bilal, HASSAN Sylla, CHOUKROUN, Simon JANES Lucas, et, BERDOUZ Nassim
 */

/**
 * @brief Affiche un arbre de Huffman
 * @param tree : arbre de huffman
 * @return void
 */
void print_tree(Noeud* tree){
    if(tree != NULL){
        if (tree->lettre == 128 ){ printf("(%d)  ",tree->occu); }
        else { printf("%c: occurence: %d \n", tree->lettre,tree->occu); }
        print_tree(tree->left);
        print_tree(tree->right);
    }
}

Noeud* creer_noeud(int lettre,int occu){
    Noeud* n = malloc(sizeof(Noeud));
    n->left = NULL;
    n->right = NULL;
    n->lettre = lettre;
    n->occu = occu;

    return n;
}

void add_noeud_LN(ElementN** L_N,Element* L){

    Noeud* new_N = creer_noeud(L->lettre,L->occu);
    ElementN* new_LN = malloc(sizeof(ElementN*));
    new_LN->node = new_N;
    new_LN->next = NULL;


    if (*L_N == NULL ){
        *L_N = new_LN;
    }
    else{
        ElementN* temp = *L_N;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_LN;

    }

}

/**
 * @brief Compare si un arbre est egale a l'autre
 * @param n1 : arbre 1
 * @param n2 : arbre 2
 * @return int : renvoit 1 si les 2 arbres sont egaux, 0 sinon
 */
int tree_compare(Noeud* n1,Noeud* n2)
{
    if (n1 == n2)
        return 1;

    if ((n1 == NULL) || (n2 == NULL))
        return 0;
    //Si a un moment un enfant n'est pas égale à l'autre alors un 0 apparait et la somme = 0
    return ((n1->lettre == n2->lettre) && (n1->occu == n2->occu)  && tree_compare (n1->left, n2->left)&& tree_compare (n1->right, n2->right));
}


void suppr_noeud_LN(ElementN** L_N,Noeud* N){

    if (*L_N != NULL && N != NULL){

        //Recherche le noeud dans la liste et on le supprime
        if(tree_compare((*L_N)->node,N) == 1 ){
            ElementN* temp = *L_N;
            *L_N = (*L_N)->next;
            free(temp);

        }
        else{

            suppr_noeud_LN(&((*L_N)->next),N);
        }
    }

}

Noeud* create_noeud_huffman(Noeud* n1,Noeud* n2){

    if (n1!=NULL && n2!=NULL){
        //creer un noeud qui prend la somme des occu des 2 et qui n'a pas de lettre donc lettre = 128
        Noeud* huffman_N = creer_noeud(128,( (n1->occu) +(n2->occu) ));
        huffman_N->left = n1;
        huffman_N->right = n2;
        return huffman_N;
    }
}

void add_noeud_fin_LN(ElementN** L_N,Noeud* N){

    ElementN* new_LN = malloc(sizeof(ElementN));
    new_LN->node = N;
    new_LN->next = NULL;

    if (*L_N == NULL){

        *L_N = new_LN;
    }
    else{

        ElementN* temp = *L_N;
        //Parcours jusqu'au dernier LN
        while(temp->next != NULL){
            temp = temp->next;
        }
        //Dernier LN->next = new_LN
        temp->next = new_LN;
    }
}

void afficher_LC(Element* L){

    if ( L != NULL ){
        printf("%c occurence: %d\n",L->lettre,L->occu);
        afficher_LC(L->next);
    }
}


PileElement* creer_PileElement(char car){
    PileElement* p = malloc(sizeof(PileElement));
    p->car = car;
    p->next = NULL;
    return p;
}

PileElement* empiler(PileElement* pile,char car){

    if (pile == NULL){
        return creer_PileElement(car);
    }
    else{
        PileElement* new_p = creer_PileElement(car);
        new_p->next = pile;
        return new_p;
    }

}

PileElement* depiler(PileElement* pile){
    if (pile == NULL){
        return pile;
    }
    else{

        PileElement* temp = pile->next;
        free(pile);
        return temp;
    }
}

void print_tree_H(Noeud* tr){
    if(tr == NULL)
        return;

    if(tr->lettre != 128)
        printf("[%c|%d]\n",tr->lettre, tr->occu);
    else
        printf("[%d]\n", tr->occu);

    if(tr->left != NULL)
        print_tree_H(tr->left);

    if(tr->right != NULL)
        print_tree_H(tr->right);
}



