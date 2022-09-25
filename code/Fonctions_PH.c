#include"Fonctions_PH.h"
#include"fonctions_secondaires.h"
/**
 * @file Fonctions_PH.c
 * @brief Fonctions Principales Huffman
 *
 * @author GUIRRE Bilal, HASSAN Sylla, CHOUKROUN, Simon JANES Lucas, et, BERDOUZ Nassim
 */
//----------------PARTIE 1 -----------------------------------------------------------------------

//QUESTION A/1.1 ------------------------------------------------------------
/**
 * @brief Converti le code ASCII d'un caractere en binaire stocke dans une chaine de caractere
 * @param n : code ASCII du caractere
 * @return char* : binaire stocke sous forme de chaine de caractere
 */
  char* convert_bin(int n){
    int i;
    int p;
    char* bin = (char*)malloc(8*sizeof(char));

    for (i=0;i<8;i++){

        p = (int)pow(2,7-i); //2 puissance 7-i

        if (n >= p){ //conversion en binaire
            bin[i] = '1';
            n = n - p;
        }
        else{
            bin[i] = '0';
        }
    }
    return bin;
}

/**
 * @brief Lit dans le fichier f1 caractere par caractere et ecrit/converti chaque carac par son binaire dans le fichier f2
 * @param f1 : fichier de lecture "input.txt"
 * @param f2 : fichier ecriture "bin.txt"
 * @return int : compte rendu erreur : 0 s'il y a pas d'erreur
 */
int lecture_ecriture(FILE* f1,FILE* f2){

    int lettre=0,i;
    char* bin;

    if (f1 == NULL){
        return 1;
    }

    while( (lettre = fgetc(f1)) != EOF ){ //lecture caractère par caractère s'arrete quand on est à la fin du fichier : EOF

        bin = convert_bin(lettre); //converti le code ASCII en son binaire
        for (i=0;i<8;i++){
            fputc(bin[i],f2); //écrit dans le fichier f2 le binaire correspondant
        }
    }
    return 0;
}

//QUESTION B/1.2  ----------------
/**
 * @brief Renvoit le nombre de caractere dans un fichier fic
 * @param fic : fichier de lecture
 * @return int : nombre de caractere dans le fichier
 */
int nbr_char_fic(FILE* fic){

    int n=0,lettre=0;

    if (fic == NULL){
        return 1;
    }

    while( (lettre = fgetc(fic)) != EOF ){ //lecture caractère par caractère s'arrete quand on est à la fin du fichier : EOF

        n = n+1;
    }

    return n;
}

//-----------------------------------PARTIE 2-----------------
//QUESTION C/2.1  ----------------
/**
 * @brief Inserer un Element qui a pour champ lettre=lettre et occurence=1 au debut de la liste chaine li
 * @param li : pointeur sur la liste chaine de Element qui ont pour champs : lettre et occurence
 * @param lettre : code ASCII d'une lettre
 * @return Element* : pointeur sur la liste chaine de Element modife
 */
Element* insert_list(Element* li,int lettre){

    Element* element = malloc(sizeof(Element));

	element->occu = 1;
	element->lettre = lettre;
    //place element en tête de liste
	if(li == NULL)
		element->next = NULL;
	else
		element->next = li;

	return element;

}

/**
 * @brief Creer une liste chaine de Element ayant pour champs : lettre et occurence a partir d'un fichier "input.txt"
 * @param fic : fichier de lecture "input.txt"
 * @return Element* : pointeur sur la liste chaine de Element
 */
Element* list_occu_char(FILE* fic){

    int lettre,verif=0;
    Element* L = malloc(sizeof(Element));

    L->lettre = fgetc(fic); //initialisation de la liste
    L->occu = 1;
    L->next = NULL;

    Element* temp = L;

    if (fic == NULL ){
        return NULL;
    }

    while ( (lettre = fgetc(fic)) != EOF ){ //parcours du fichier

        while(temp != NULL){ //parcours de la liste

            if ( lettre == temp->lettre){ //présence du caractere dans la liste
                temp->occu = temp->occu +1;
                verif = 1;
            }
            temp = temp->next;
        }

        if (verif == 0){ //non présence du caractere dans la liste
            L = insert_list(L,lettre); //insere l'element ayant pour champ lettre=lettre et occurence=1 au début de la liste
        }
        verif = 0;
        temp = L;
    }

    return L;

}

//QUESTION D/2.2  ----------------

/**
 * @brief Tri une liste de Element en fonction de l'occurence dans l'ordre croissant
 * @param liste : pojnteur sur la liste d'Element
 * @return Element* : pointeur sur la liste de Element trier
 *
 */
Element* ranger_liste(Element* liste){

    Element* temp,*p;
    int lettre,occu;
    if (liste != NULL){
        for(temp=liste;temp->next!=NULL;temp=temp->next){ //parcours de la liste
            for(p=temp->next;p!=NULL;p=p->next){ //parcours de la liste->next

                if (p->occu < temp->occu ){ //echange des valeurs des champs si on trouve une occurence plus petite
                    occu = p->occu;
                    lettre = p->lettre;
                    p->occu = temp->occu;
                    p->lettre = temp->lettre;
                    temp->occu = occu;
                    temp->lettre = lettre;
                }
            }
        }
    }
    return liste;

}

/**
 * @brief Converti une liste de Element donner avec pour champs occurence, lettre et next
 *        en une liste de ElementN avec pour champs node, et next donc une liste de noeud
 *        (node ayant pour champs lettre,occurence,left,right)
 * @param L : pointeur sur la liste de Element
 * @return ElementN* : pointeur sur la liste de Noeud
 */
ElementN* convert_LC_to_LCN(Element* L){

    ElementN* L_N = NULL;
    Element* temp = L;
    while ( temp != NULL ){
        //prend le noeud dans temp qu'on ajoute dans à la fin de L_N
        add_noeud_LN(&L_N,temp);
        temp = temp->next;
    }

    return L_N;
}

/**
 * @brief Trouve le Noeud avec la plus petite occurence dans la liste de Noeud, extrait, le supprime de la liste, et le renvoit
 * @param L_N : double pointeur sur la liste de noeud
 * @return Noeud* : pointeur sur le noeud avec la plus petite occurence
 */
Noeud* min_occu_LN(ElementN** L_N){

    if (*L_N != NULL){

        ElementN* temp = *L_N;
        Noeud* N = NULL;
        int min_occu = (*L_N)->node->occu;
        // Prend le noeud avec la plus petite occu de *L_N
        while(temp!=NULL){

            if (temp->node->occu <= min_occu){
                min_occu = temp->node->occu;
                N = temp->node;
            }
            temp = temp->next;
        }
        //Supprime ce noeud de *L_N
        suppr_noeud_LN(L_N,N);
        return N;
    }
}

/**
 * @brief Creer un arbre de huffman a partir de une liste de noeud
 * @param L_N : double pointeur sur la liste de noeud
 * @return void : la racine sera le noeud du seul element present dans la liste a la fin
 */
void Arbre_Huffman(ElementN** L_N){

    while( (*L_N)->next != NULL ){ //Tant qu'il n'y  a pas un seul élement dans la liste de ElementN

        Noeud* min1 = min_occu_LN(L_N); //prend les deux plus petit element avec la plus petite occurence
        Noeud* min2 = min_occu_LN(L_N);

        Noeud* huffman_N = create_noeud_huffman(min1,min2); //créer un noeud de huffman à partir de ces minimum, noeud huffman : lettre = 128
        add_noeud_fin_LN(L_N,huffman_N);

    }
}


//QUESTION E/2.3 ------------------------------------------------

/**
 * @brief fonction recursive qui ecrit dans le fichier dic la suite binaire contenue dans la pile en partant du bas de la pile
 * @param pile : pointeur sur la pile
 * @param dic : pointeur sur le fichier "Dictionnaire.txt"
 * @return void
 */
void ecrire_dico_pile(PileElement* pile,FILE* dic){
    if (pile != NULL){
        ecrire_dico_pile(pile->next,dic); //parcours qui permet d'ecrire à partir du bas de la pile
        fputc(pile->car,dic);

    }
}

/**
 * @brief Fonction recursive qui ecrit dans "Dictionnaire.txt" le dictionnaire de Huffman grace a arbre de Huffman
 * @param Arbre : pointeur sur arbre de huffman
 * @param nbr : double pointeur sur la pile contenant le binaire des caracteres
 * @param dic : pointeur sur le fichier ecriture "Dictionnaire.txt"
 * @return void
 */
void dico(Noeud* Arbre,PileElement** nbr,FILE* dic){

    if ( Arbre != NULL ){

        if (Arbre->left != NULL){

            if (Arbre->left->lettre != 128){ //ce n'est pas un noeud de huffman si lettre != 128
                        (*nbr) = empiler((*nbr),'0');
                        fprintf(dic,"%c : ",Arbre->left->lettre);
                        ecrire_dico_pile((*nbr),dic);
                        fputc('\n',dic);
                        dico(Arbre->left,nbr,dic);
            }
            else{
                (*nbr) = empiler((*nbr),'0');
                dico(Arbre->left,nbr,dic);
            }
            (*nbr) = depiler((*nbr)); //dépile en revenant sur nos pas
        }

        if (Arbre->right != NULL){

            if (Arbre->right->lettre != 128){ //ce n'est pas un noeud de huffman si lettre != 128
                    (*nbr) = empiler((*nbr),'1');
                    fprintf(dic,"%c : ",Arbre->right->lettre);
                    ecrire_dico_pile((*nbr),dic);
                    fputc('\n',dic);
                    dico(Arbre->right,nbr,dic);
                }
            else{
                (*nbr) = empiler((*nbr),'1');
                dico(Arbre->right,nbr,dic);
            }
            (*nbr) = depiler((*nbr)); //dépime en revenant sur nos pas
        }
    }
}


//QUESTION F/2.4 ----------------------------------------------------

/**
 * @brief Lit une suite de caractere dans un fichier et le stock dans une chaine de caractere
 * @param dic : pointeur sur le fichier de lecture
 * @return char* : pointeur sur la chaine de caractere
 */
char* read_char(FILE* dic){

    char* L = malloc(40*sizeof(char)); //FIXE
    fscanf(dic,"%s",L);
    return L;
}

/**
 * @brief A partir du fichier "Dictionnaire.txt" extrait une liste chaine de ElementD ayant pour champs :
 *        lettre et occurence (binaire sotcke dans une chaine de caractere)
 * @param dic : pointeur sur le fichier de lecteur "Dictionnaire.txt"
 * @return ElementD* : pointeur sur la liste chaine de ElementD
 */
ElementD* dico_to_element(FILE* dic){

    int lettre;

    if ( (lettre = fgetc(dic)) == EOF ){
        return NULL;
    }

    ElementD* L = malloc(sizeof(ElementD));
    L->lettre = lettre;

    lettre = fgetc(dic); //déplace le curseur
    lettre = fgetc(dic); //lit un caractère
    lettre = fgetc(dic);

    L->occu = read_char(dic); //lit la chaine de caractere de 0 et 1 et la renvoit

    lettre = fgetc(dic);

    L->next = dico_to_element(dic);
    return L;
}

/**
 * @brief Lit dans le fichier "input.txt" et ecrit/converti dans un fichier "Encode_Huffman.txt"
 * @param f2 : fichier de lecture "input.txt"
 * @param f3 : fichier ecriture "Encodage_Huffman.txt"
 * @param L : pointeur sur la liste de ElementD extrait a partir du Dictionnaire de Huffman
 * @return void
 */
void convertion_txt_to_huffman(FILE* f2,FILE* f3,ElementD* L){

    int lettre=0,verif=0;
    ElementD* temp = L;

    while( (lettre = fgetc(f2)) != EOF ){//Lecture du fichier

        while (temp != NULL || verif == 0 ){ //parcours liste ElementD
            if (temp->lettre == lettre){
                fputs(temp->occu,f3); //écrit une ligne
                verif = 1;
            }
            temp = temp->next;
        }
        temp = L;
    }

}
