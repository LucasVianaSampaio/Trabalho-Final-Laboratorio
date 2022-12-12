#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <time.h>

struct pgm
{
  int tipo;
  int c;
  int r;
  int mv;
  unsigned char *pData;
};

void readPGMImage(struct pgm *, char *);
void viewPGMImage(struct pgm *);
void writePGMImage(unsigned char *scm, char *filename, int f, int *n);
void quantizar(unsigned char *pm, int l, int c, int max, int f);
void scm(unsigned char *p1, unsigned char *p2, unsigned char *s, int l, int c, int f);
void imprimir_scm(unsigned char *p, int x);
