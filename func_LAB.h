#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>

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
void writePGMImage(int *, char *, int, int *);
void quantizar_matriz(unsigned char *, int, int, int, int);
void preencher_mat_scm(unsigned char *, unsigned char *, int *, int, int, int);
void imprimir_mat_scm(int *, int);
