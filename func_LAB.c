#include "func_LAB.h"

void readPGMImage(struct pgm *pio, char *filename)
{
  char path[50] = {"images/"};
  FILE *fp;
  char ch;

  if (!(fp = fopen(strcat(path, filename), "r")))
  {
    perror("Erro.");
    exit(1);
  }

  if ((ch = getc(fp)) != 'P')
  {
    puts("A imagem fornecida não está no formato pgm");
    exit(2);
  }
  pio->tipo = getc(fp) - 48;

  fseek(fp, 1, SEEK_CUR);

  while ((ch = getc(fp)) == '#')
  {
    while ((ch = getc(fp)) != '\n')
      ;
  }

  fseek(fp, -2, SEEK_CUR);

  fscanf(fp, "%d %d", &pio->c, &pio->r);
  if (ferror(fp))
  {
    perror(NULL);
    exit(3);
  }
  fscanf(fp, "%d", &pio->mv);
  fseek(fp, 1, SEEK_CUR);

  pio->pData = (unsigned char *)malloc(pio->r * pio->c * sizeof(unsigned char));

  switch (pio->tipo)
  {
  case 2:
    // puts("Lendo imagem PGM (dados em texto)");
    for (int k = 0; k < (pio->r * pio->c); k++)
    {
      fscanf(fp, "%hhu", pio->pData + k);
    }
    break;
  case 5:
    // puts("Lendo imagem PGM (dados em binario)");
    fread(pio->pData, sizeof(unsigned char), pio->r * pio->c, fp);
    break;
  default:
    puts("Não está implementado");
  }

  fclose(fp);
}

void writePGMImage(unsigned char *scm, char *filename, int f, int *n)
{
  FILE *fp;
  char ch;

  if (!(fp = fopen(filename, "ab")))
  {
    perror("Erro.");
    exit(1);
  }

  scm = (int)scm;
  fprintf(fp, "[");
  for (int i = 0; i < f * f; i++)
  {
    fprintf(fp, "%d,", *(scm + i));
  }
  fprintf(fp, "]");
  fprintf(fp, " ->%d\n\n", (*n) - 48);
  fclose(fp);
}

void viewPGMImage(struct pgm *pio)
{
  printf("Tipo: %d\n", pio->tipo);
  printf("Dimensoes: [%d %d]\n", pio->c, pio->r);
  printf("Max: %d\n", pio->mv);

  for (int k = 0; k < (pio->r * pio->c); k++)
  {
    if (!(k % pio->c))
      printf("\n");
    printf("%4hhu ", *(pio->pData + k));
  }
  printf("\n");
}

void quantizar(unsigned char *pm, int l, int c, int max, int f)
{
  int q = (max + 1) / f;
  for (int i = 0; i < (l * c); i++)
  {
    *(pm + i) = (int)(*(pm + i)) / q;
  }
}

void scm(unsigned char *p1, unsigned char *p2, unsigned char *s, int l, int c, int f)
{
  int k;
  for (int i = 0; i < (l * c); i++)
  {
    k = (int)*(p1 + i) * f + (*(p2 + i));
    *(s + k) = (int)*(s + k) + 1;
  }
}

void imprimir_scm(unsigned char *p, int x)
{
  for (int i = 0; i < x; i++)
  {
    for (int j = 0; j < x; j++)
    {
      printf("%4d ", *(p + (i * x) + j));
    }
    printf("\n");
  }
}