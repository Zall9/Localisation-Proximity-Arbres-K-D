#ifndef _ARBRE_H_
#define _ARBRE_H_
/* A vous de changer cela. */
#include "obstacles.h"
typedef Obstacle Donnee;

/**
 * Copie une donnée dans une autre. Cette fonction est utile lorsque
 * le type Donnee est complexe et que l'opérateur d'affectation du C
 * ne fonctionne pas bien.
 *
 * @param d1 un pointeur vers la première donnée à recopier.  
 *
 * @param d2 un pointeur vers la deuxième donnée, qui sera écrasée et
 * prendra les valeurs de d1.
 */
extern void CopierDonnees( Donnee* d1, Donnee* d2 );


/*****************************************************************************/
/* Les arbres */
/*****************************************************************************/

/**
 * Un noeud dans un arbre binaire contient une donnée, et
 * éventuellement un pointeur vers un fils gauche et/ou vers un fils
 * droit.  On pourrait aussi stocker le noeud père ici, mais on ne
 * s'en servira pas dans les algorithmes développés.
 */
typedef struct SNoeud { 
  Donnee data; 
  struct SNoeud* gauche; 
  struct SNoeud* droit; 
} Noeud;


/**
 * Un arbre binaire est un noeud appelé racine.  On utilisera le type
 * Arbre lorsqu'on désignera le noeud racine et le type Noeud
 * lorsqu'on désigne un noeud quelconque.
 */
typedef Noeud Arbre;


extern int mediane(Donnee *T, int a, int i, int j);
/**
 * @return l'arbre vide.
 */
extern Arbre* ArbreVide();

/**
 * Détruit un arbre et désalloue tous ses éléments alloués.
 *
 * @param A un pointeur vers un arbre valide.
 */
extern void Detruire( Arbre* A );

/**
 * Crée et retourne un arbre avec un seul noeud qui recopie la donnée
 * pointée par ptr_d.
 *
 * @param ptr_d un pointeur vers une donnée.
 *
 * @return un pointeur vers l'arbre créé (ie. un pointeur vers sa
 * racine).
 */
extern Arbre* Creer0( Donnee* ptr_d );

/**
 * Crée et retourne un arbre qui l'union de deux sous-arbres plus un
 * noeud qui recopie la donnée pointée par ptr_d.
 *
 * @param ptr_d un pointeur vers une donnée.
 *
 * @param G un pointeur vers le futur sous-arbre gauche. Attention il
 * ne faut plus s'en servir après, car il est intégré à l'arbre A.
 *
 * @param D un pointeur vers le futur sous-arbre droit. Attention il
 * ne faut plus s'en servir après, car il est intégré à l'arbre A.
 *
 * @return un pointeur vers l'arbre créé (ie. un pointeur vers sa
 * racine).
 */
extern Arbre* Creer2( Donnee* ptr_d, Arbre* G, Arbre* D );

/**
 * Retourne le noeud racine de A (éventuellement NULL si arbre vide).
 *
 * @param A un pointeur vers un arbre valide.
 */
extern Noeud* Racine( Arbre* A );

/**
 * @return le noeud fils gauche de N (éventuellement NULL si N n'avait
 * pas de fils gauche).
 *
 * @param N un pointeur vers un noeud valide.
 */
extern Noeud* Gauche( Noeud* N );

/**
 * Modifie le noeud N de façon à ce que SG devienne sous nouveau
 * sous-arbre gauche. L'ancien sous-arbre gauche de N est désalloué.
 *
 * @param N un pointeur vers un noeud valide.
 * @param SG le nouveau sous-arbre, éventuellement vide ou réduit à un noeud.
 */
extern void ModifieGauche( Noeud* N, Arbre* SG );

/**
 * @return le noeud fils droit de N (éventuellement NULL si N n'avait
 * pas de fils droit).
 *
 * @param N un pointeur vers un noeud valide.
 */
extern Noeud* Droit( Noeud* N );

/**
 * Modifie le noeud N de façon à ce que SD devienne sous nouveau
 * sous-arbre droit. L'ancien sous-arbre droit de N est désalloué.
 *
 * @param N un pointeur vers un noeud valide.
 * @param SD le nouveau sous-arbre, éventuellement vide ou réduit à un noeud.
 */
extern void ModifieDroit( Noeud* N, Arbre* SD );


/**
 * Permet la lecture et l'écriture dans la donnée associée au noeud N.
 *
 * @return un pointeur vers la donnee du noeud N.
 *
 * @param N un pointeur vers un noeud valide.
 */
extern Donnee* Valeur( Noeud* N );

extern Arbre* KDT_Creer( Donnee* T, int i, int j, int a );

/**
 * compare deux points de données en fonction de x et renvoie 1 si le premier est supérieur au second, -1 si le
 * premier est inférieur au second et 0 s'ils sont égaux.
 * 
 * @param a pointeur vers le premier élément à comparer
 * @param b le nombre d'arbres à construire.
 * 
 * @return un pointeur sur un entier.
 */
extern int compare_x(const void *a, const void *b);
/**
 * compare deux points de données en fonction de y et renvoie 1 si le premier est supérieur au second, -1 si le
 * premier est inférieur au second et 0 s'ils sont égaux.
 * 
 * @param a pointeur vers le premier élément à comparer
 * @param b le nombre d'arbres à construire.
 * 
 * @return un pointeur sur un entier.
 */
extern int compare_y(const void *a, const void *b);

// extern void afficheTab(Donnee *T, int i, int j, int a);
#endif
