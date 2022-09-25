#include"code/Fonctions_PH.h"
#include"tests/test.h"
/**
 * @file main.c
 * @brief Creer arbre de Huffman, genere le dictionnaire et encode a partir du fichier "input.txt"
 * @author GUIRRE Bilal, HASSAN Sylla, CHOUKROUN, Simon JANES Lucas, et, BERDOUZ Nassim
 */

/**
 * @brief Application generale : meme proprete que le file
 * @return int : compte rendu erreur : 0 si il y en a pas
 */
int main()
{
    //Convetisseur normale en binaire, lit "input.txt" et cr�er "bin.txt"
    test_0();

    //Cr�er et Affiche une liste d'Element � partir de "input.txt"
    //test_1();

    //Cr�er et Affiche un arbre de Huffman � partir de "input.txt"
    //test_2();

    //ENSEMBLE DU CODAGE HUFFMAN, A partir de "input.txt" cr�er "Dictionnaire.txt" et "Encodage.txt"
    test_3();

    return 0;

}
