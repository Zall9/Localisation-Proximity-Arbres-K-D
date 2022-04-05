#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include "obstacles.h"
void initObstacle( Obstacle* o, double x, double y, double r, double att,double cr,double cg, double cb)
{
    o->x[0] = x;
    o->x[1] = y;
    o->r = r;
    o->att = att;
    o->cr = cr;
    o->cg = cg;
    o->cb = cb;
}

void TabObstacles_init(TabObstacles *tab)
{
    tab->taille = 10;
    tab->nb = 0;
    tab->obstacles = (Obstacle *)malloc(tab->taille * sizeof(Obstacle));
}

void TabObstacles_ajoute(TabObstacles *tab, Obstacle o)
{
    if (tab->nb == tab->taille)
        TabObstacles_agrandir(tab);
    tab->obstacles[tab->nb++] = o;
}

void TabObstacles_set(TabObstacles *tab, int i, Obstacle p)
{
    assert(i < tab->nb);
    tab->obstacles[i] = p;
}

Obstacle TabObstacles_get(TabObstacles *tab, int i)
{
    assert(i < tab->nb);
    return tab->obstacles[i];
}

int TabObstacles_nb(TabObstacles *tab)
{
    return tab->nb;
}

void TabObstacles_termine(TabObstacles *tab)
{
    if (tab->obstacles != NULL)
        free(tab->obstacles);
    tab->taille = 0;
    tab->nb = 0;
    tab->obstacles = NULL;
}

Obstacle *TabObstacles_ref(TabObstacles *tab, int i)
{
    assert(i < tab->nb);
    return tab->obstacles + i;
}

void TabObstacles_agrandir(TabObstacles *tab)
{
    tab->taille *= 2;
    tab->obstacles = (Obstacle *)realloc(tab->obstacles, tab->taille * sizeof(Obstacle));
}