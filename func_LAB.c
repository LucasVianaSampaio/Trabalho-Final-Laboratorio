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
#ifdef __linux__
  fseek(fp, 1, SEEK_CUR);
#elif _WIN32
  fseek(fp, 0, SEEK_CUR);
#endif

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

void writePGMImage(int *m_scm, char *filename, int nivel, int *rotulo)
{
  FILE *fp;

  if (!(fp = fopen(filename, "ab")))
  {
    perror("Erro.");
    exit(1);
  }

  fprintf(fp, "[");
  for (int i = 0; i < nivel * nivel; i++)
  {
    fprintf(fp, "%d, ", *(m_scm + i));
  }
  fprintf(fp, "]");
  fprintf(fp, " ->%d\n\n", (*rotulo) - 48);
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

void quantizar_matriz(unsigned char *Mat, int lin, int col, int max, int taxa)
{
  int q = (max + 1) / taxa;
  for (int i = 0; i < (lin * col); i++)
  {
    *(Mat + i) = (int)(*(Mat + i)) / q;
  }
}

void preencher_mat_scm(unsigned char *Mat1, unsigned char *Mat2, int *Mat_scm, int lin, int col, int niv)
{
  for (int i = 0; i < (lin * col); i++)
  {
    int k = (int)(*(Mat1 + i) * niv + *(Mat2 + i));
    *(Mat_scm + k) += 1;
  }
}

void imprimir_mat_scm(int *Mat, int TAM)
{
  for (int i = 0; i < TAM; i++)
  {
    for (int j = 0; j < TAM; j++)
    {
      printf("%4d ", *(Mat + (i * TAM) + j));
    }
    printf("\n");
  }
}