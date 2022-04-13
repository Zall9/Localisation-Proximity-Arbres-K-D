#include "forces.h"
Force gravite(double gx, double gy)
{
  Force f;
  f.type = GRAVITE;
  f.params[0] = gx;
  f.params[1] = gy;
  return f;
}
//, Obstacle *o
void appliqueForce(Particule *p, Force *f) 
{
  switch (f->type)
  {
  case GRAVITE:
    /// La force de gravité est proportionnel à la masse de l'objet.
    p->f[0] += p->m * f->params[0];
    p->f[1] += p->m * f->params[1];
  case GRAVITATION_UNIV:
    /// La force de gravitation est proportionnelle a G* Ma*Mb/d²
    break;
  }
}
