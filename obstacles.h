#include "points.h"
typedef enum { DISQUE } ObstacleType;

typedef struct SObstacle {
  ObstacleType type; //< Le type de l'obstacle. Ici on aura juste des DISQUEs.
  double x[ DIM ];   //< Les coordonnées du centre de l'obstacle.
  double r;          //< Le rayon de l'obstacle
  double att;        //< le facteur d'atténuation de l'obstacle (0.0 amortisseur parfait, 1.0 rebondisseur parfait, 3.0 "bumper" comme dans un flipper.)
  double cr, cg, cb; //< couleurs rgb de l'obstacle.
} Obstacle;

/**
 * Initialiser une particule obstacle avec les paramètres donnés
 * 
 * @param o l'obstacle
 * @param x Coordonnée x du centre de la particule.
 * @param y Coordonnée y du centre de l'obstacle.
 * @param r rayon de la particule
 * @param att l'attenuation
 * @param cr composant de couleur rouge
 * @param cg Le composant de couleur verte de la particule.
 * @param cb composante de couleur bleue
 */
void initObstacle(Obstacle* o, double x, double y, double r, double att , double cr, double cg, double cb );

/// Représente un tableau dynamique de particules.
typedef struct STabObstacle {
  int taille;
  int nb;
  Obstacle* obstacles;
} TabObstacles;

/**
 * Initialiser une structure TabObstacles
 * 
 * @param tab la structure TabObstacles que vous souhaitez initialiser.
 */
void TabObstacles_init( TabObstacles* tab );
/**
 * Ajouter un obstacle à la fin de la liste
 * 
 * @param tab le tableau pour y ajouter l'obstacle
 * @param p Obstacle à ajouter au TabObstacles.
 */
void TabObstacles_ajoute( TabObstacles* tab, Obstacle p );
/**
 * modifie l'obstacle à l'index i
 * 
 * @param tab le tableau à modifier
 * @param i L'indice de l'obstacle à régler.
 * @param p le pointeur vers l'onglet
 */
void TabObstacles_set( TabObstacles* tab, int i, Obstacle p );

/**
 * Étant donné un pointeur vers un objet TabObstacles et un index, recupere l'obstacle à cet index
 * 
 * @param tab la structure TabObstacles
 * @param i L'indice de l'obstacle à franchir.
 * 
 * @return Un pointeur vers l'obstacle.
 */
Obstacle TabObstacles_get( TabObstacles* tab, int i );

/**
 * Renvoie le nombre d'obstacles dans le tableau
 * 
 * @param tab la structure TabObstacles
 * 
 * @return Le nombre d'obstacles dans l'onglet.
 */
int TabObstacles_nb( TabObstacles* tab );

/**
 * Il libère la mémoire allouée au tableau d'obstacles.
 * 
 * @param tab le pointeur vers la structure d'obstacle
 */
void TabObstacles_termine( TabObstacles* tab );

/**
 * Renvoie le i-ème ptr vers l'élément du tableau d'obstacles.
 * 
 * @param tab la structure TabObstacles
 * @param i L'indice de l'obstacle à retourner.
 * 
 * @return Un pointeur vers l'obstacle à l'indice i.
 */
Obstacle* TabObstacles_ref( TabObstacles* tab, int i );

/**
 * Double la taille du tableau d'obstacles.
 * 
 * @param tab la structure TabObstacles à redimensionner.
 */
void TabObstacles_agrandir( TabObstacles* tab );