#include <MainBase.h>

void setzeros(void *body, int counts);

void centry(char *cad, int lenth, int *lnth);

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
        if(c == '\n'){
            cad[i] = '\n';
            break;
        }
        else{
            cad[i] = c;
        }
    }
    *lnth = i;
}