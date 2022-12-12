#include "func_LAB.h"

int main(int argc, char **argv)
{
    float soma = 0;
    clock_t ini, fim;
    int cont = 0;

    if (argc != 3)
    {
        printf("Formato: \n\t %s <Frequencia> <nome arquivo escrita> \n", argv[0]);
        exit(1);
    }
    DIR *d;
    struct dirent *dir;
    struct pgm img;
    struct pgm img2;
    int c;

    int freq = atoi(argv[1]);

    d = opendir("./images");
    if (d)
    {
        seekdir(d, 2);

        while ((dir = readdir(d)) != NULL)
        {
            ini = clock();
            unsigned char *mat_scm = calloc((freq * freq), sizeof(unsigned char));
            if (!mat_scm)
            {
                printf("erro de alocacao de memoria!");
                exit(2);
            }
            // printf(" ->img1:%s\n", dir->d_name);
            c = (int)(*(dir->d_name + 0));
            readPGMImage(&img, dir->d_name);
            quantizar(img.pData, img.c, img.r, img.mv, freq);

            dir = readdir(d);

            // printf(" ->img:%s\n", dir->d_name);
            readPGMImage(&img2, dir->d_name);
            quantizar(img2.pData, img2.c, img2.r, img2.mv, freq);

            scm(img.pData, img2.pData, mat_scm, img.c, img.r, freq);

            // imprimir_scm(mat_scm, freq);
            writePGMImage(mat_scm, argv[2], freq, &c);
            cont += 2;
            // printf("________________________________________________\n");

            // Leitura da Imagem -PGM

            // Processar - Medir o tempo apenas nesta etapa.

            // Saída.
            free(mat_scm);
            fim = clock();
            soma = (float)(fim - ini) / CLOCKS_PER_SEC;
        }
        closedir(d);
    }
    printf("Tempo medio por imagem: %f\n", soma / cont);
    printf("Tempo total: %f", soma);
    return (0);
}