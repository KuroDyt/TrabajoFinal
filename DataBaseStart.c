#include <MainBase.h>
#define LENT 100

void main(){
    int i = 0, pasl = 0, usl = 0;;
    char entrylvl[LENT], passentry[PASSL], keyc[16] = {'k','l','g','s','f','c','g','q','j','g','r','c','x','d','k','q'}, response[4];
    system(CLEAN);
    printf("Generacion de las bases de datos\n");
    printf("Iniciando con la generacion de las contraseñas\n");
    FILE  *fp = fopen("../passwd.db", "wb");
    if((!fp)){
        printf("[!]Fatal Error, cannot create file, please check permissions\n");
        printf("[*]Exiting program\n");
        getchar();
        exit(0);
    }
    printf("Se generaran los usuarios que desee con sus respectivas contraseñas\n");
    printf("Presione Enter para continuar...\n");
    getchar();
    for(i = 0;;i++){
        setzeros(&entrylvl, LENT);
        setzeros(&passentry, PASSL);
        setzeros(&response, 4);
        system(CLEAN);
        printf("Entrada id %d\n", i);
        printf("Username: ");
        centry(&entrylvl, LENT, usl);
        printf("Password: ");
        centry(&passentry, PASSL, pasl);
        md5hash(passentry, keyc, &response);
    }
    exit(0);
}