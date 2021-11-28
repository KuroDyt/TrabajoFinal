#include <MainBase.h>

void setzeros(void *body, int counts);

void centry(char *cad, int lenth, int *lnth);

int getlogin(char *name, char *pass);

void depcat(char *info[10]);

void prodcat(char *info[50][6]);

void desccat(char *info[10][4]);

void depprod(char *info[5][2], int id);

float prodpre(int id[COUNTS]);

void repprod();

void repdep();

void repvent();

void ventprod(char id[COUNTS]);

void checkprod(char *infos[50][2], int *cant);

void progstop();