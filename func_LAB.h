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
void writePGMImage(int *scm, char *filename, int f, int *n);
void quantizar_matriz(unsigned char *Mat, int lin, int col, int max, int taxa);
void preencher_mat_scm(unsigned char *Mat1, unsigned char *Mat2, int *Mat_scm, int lin, int col, int niv);
void imprimir_mat_scm(int *Mat, int TAM);
