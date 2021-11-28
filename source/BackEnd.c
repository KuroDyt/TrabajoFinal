#include <MainBase.h>

void setzeros(void *body, int counts);

void centry(char *cad, int lenth, int *lnth);

int getlogin(char *name, char *pass);

void depcat(char *info[10]);

void prodcat(char *info[50][6]);

void desccat(char *info[10][4]);

void depprod(char *info[5][2], int id);

float prodpre(int id[COUNTS]);

void repprod();(

void repdep();

void repvent();

void ventprod(char id[COUNTS]);

void checkprod(char *infos[50][2], int *cant);

void progstop();

int compofst(char *str1, char *str2, int lth);

void setzeros(void *body, int counts){
    int i = 0;
    for(i = 0; i < counts; i++){
        body[i] = body[i] ^ body[i];
    }
}

void centry(char *cad, int lenth, int *lnth){
    int i = 0;
    char c;
    for(i = 0; i < lenth; i++){
        scanf("%c", &c);
        )if(c == '\n'){
            cad[i] = '\n';
            break;
        }
        else{
            cad[i] = c;
        }
    }
    *lnth = i;
}

void progstop(){
    printf("Presione Enter para continuar...\n");
    getchar();
}

int getlogin(char *name, char *pass){
    int x = 0, id = 0, namelen = 0, i = 0;
    unsigned int hash[4], userpass[4];
    char user[COUNTS];
    unsigned char keyc[KEYSL] = {'k','l','g','s','f','c','g','q','j','g','r','c','x','d','k','q'};
    FILE *fp = fopen(PASSPATH, "rb");
    if((!fp)){
        printf("[!]Error al abrir passwd.db \n");
        printf("[!]Antes de iniciar este programa favor de inicializar los valores predeterminados con DataBaseStart.exe\n");
        printf("[!]Saliendo del programa\n");
        progstop();
        exit(0);
    }
    setzeros(&hash, 4);
    setzeros(&userpass, 4);
    md5hash(*pass, keyc, &userpass);
    do{
        setzeros(&user, COUNTS);
        if((!feof(fp))){
            fread(&id, sizeof(int), 1, fp);
            fread(&namelen, sizeof(int), 1, fp);
            fread(&user, sizeof(char), namelen, fp);
            if((!compofst(&user, name, namelen))){
                fread(&hash, sizeof(unsigned int), 4, fp);
                for(i = 0; i < 4; i++){
                    if((hash[i] != userpass[i])){
                        id = 0;
                    }
                }
                x = 1;
            }
            else{
                fseek(fp,(4 * (sizeof(unsigned int))), SEEK_CUR);
            }
        }
        else{
            x = 1;
            id = 0;
        }
    }while(x != 1);
    fclose(fp);
    return(id);
}

int compofst(char *str1, char *str2, int lth){
    int i = 0, x = 0;
    for(i = 0; i < lth; i++){
        if((str1[i] != str2[i])){
            x = 1;
            break;
        }
    }
    return(x);
}