#include"test.h"
/**
 * @file test.c
 * @brief test des differents moments du code
 * @author GUIRRE Bilal, HASSAN Sylla, CHOUKROUN, Simon JANES Lucas, et, BERDOUZ Nassim
 */

void test_0(){ //Convetisseur normale en binaire, lit "input.txt" et créer "bin.txt"
    FILE* f1 = fopen("textes/input.txt","r");
    FILE* f2 = fopen("textes/bin.txt","w");

    lecture_ecriture(f1,f2);

    fclose(f1);
    fclose(f2);

    FILE* f3 = fopen("textes/input.txt","r");
    FILE* f4 = fopen("textes/bin.txt","r");
    printf("Il y a %d de charactere dans input.txt et %d charactere dans bin.txt\n",nbr_char_fic(f3),nbr_char_fic(f4));
}

void test_1(){ //Créer une liste d'Element et l'affiche à partir de "input.txt"
    FILE* f1 = fopen("textes/input.txt","r");

    Element* L = list_occu_char(f1);
    L = ranger_liste(L);
    afficher_LC(L);

    fclose(f1);
}

void test_2(){ //Créer et affiche un arbre de Huffman à partir de "input.txt"

    FILE* f1 = fopen("textes/input.txt","r");

    Element* L = list_occu_char(f1);
    L = ranger_liste(L);

    ElementN* L_N = convert_LC_to_LCN(L);
    Arbre_Huffman(&L_N);
    print_tree_H(L_N->node);


    fclose(f1);
}

void test_3(){ //ENSEMBLE DU CODAGE HUFFMAN, A partir de "input.txt" créer "Dictionnaire.txt" et "Encodage.txt"

    FILE* f1 = fopen("textes/input.txt","r"); //lecture
    FILE* dic = fopen("textes/Dictionnaire.txt","w"); //écriture
    PileElement* nbr = NULL;

    Element* L = list_occu_char(f1);
    L = ranger_liste(L);
    ElementN* L_N = convert_LC_to_LCN(L);

    Arbre_Huffman(&L_N);
    dico(L_N->node,&nbr,dic);

    fclose(f1);
    fclose(dic);

    FILE* dico = fopen("textes/Dictionnaire.txt","r"); //lecture
    FILE* f2 = fopen("textes/input.txt","r");   //lecture
    FILE* f3 = fopen("textes/Encodage_Huffman.txt","w");//écriture

    ElementD* L_dico = dico_to_element(dico);
    convertion_txt_to_huffman(f2,f3,L_dico);

    fclose(dico);
    fclose(f2);
    fclose(f3);
}



