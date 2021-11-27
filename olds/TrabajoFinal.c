#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define UPATH "data/passwd.db"
#define BPATH "data/users.db"
#define SPATH "data/database.db"
#define CLEAN "clear"
#define PTSZE 11

void logon(void *dat[PTSZE]);
void getdata(int id);
void adminmen();
void usermen();
void shop(int id);
void check(void *dat[PTSZE], unsigned int comp[4]);

void md5hash(unsigned char pass[64],unsigned char key[16], unsigned int *res);
int minum(float a);
float absolute(float num);


void main(){
    unsigned char user[10], pass[64], seed[16] = {'k','l','g','s','f','c','g','q','j','g','r','c','x','d','k','q'};
    char usdata[4][10], c;
    int id = 0;
    FILE *opas = fopen(UPATH, "r"), *ous = fopen(BPATH, "r"), *odb = fopen(SPATH, "r");
    if((!opas)){
        printf("Error en passwd\n");
        printf("Cerrando programa\n");
        getchar();
        exit(0);
    }
    if((!ous)){
        printf("Error en users\n");
        printf("Cerrando programa\n");
        getchar();
        exit(0);
    }
    if((!odb)){
        printf("Error en database\n");
        printf("Cerrando programa\n");
        getchar();
        exit(0);
    }
    void *datas[PTSZE] = {&user, &pass, &seed, &id, &usdata[0], &usdata[1], &usdata[2], &usdata[3], opas, ous, odb};
    logon(datas);
    if(id){
        printf("Exito\n");
        getchar();
    }
    fclose(opas);
    fclose(ous);
    fclose(odb);
    exit(0);
}

void getdata(int id){
}

void logon(void *dat[PTSZE]){
    unsigned char *user = dat[0], *pass = dat[1], *seed = dat[2];
    unsigned int comp[4]; 
    int x = 0, y = 0, *id = dat[3];
    bzero(pass, 64);
    do{
        //system(CLEAN);
        y = 0;
        printf("Sistema de administracion de la tienda\nInicie sesion para cotinuar\n");
        do{
            printf("Usuario: ");
            scanf("%s",user);
            printf("Contraseña: ");
            scanf("%s",pass);
            printf("Hashing password\n");
            md5hash(pass, seed, &comp[0]);
            printf("Checking password\n");
            check(dat, comp);
            printf("Checked password\n");
            if(id){
                printf("Inicio de sesion exitoso\n");
                printf("Presione Enter para continuar\n");
                y = 3;
                x = 1;
            }
            else{
                printf("Nombre de usuario o contraseña invalida\n");
                y = y + 1;
            }
        }while(y != 3);
    }while(x != 1);
}

void check(void *dat[PTSZE], unsigned int comp[4]){
    FILE *pass = dat[8];
    unsigned char username[10], *user = dat[0];
    unsigned int passw[4];
    int *id = dat[3], a[10][3], x = 0, i = 0, j = 0, b = 0, y = 0;
    char c;
    for(i = 0; i < 10; i++){
        for(j = 0; j < 3; j++){
            a[i][j] = 0;
        }
    }
    i = 0;
    j = 0;
    do{
        for(j = 0;((j < 10) && (c != EOF)); j++){
            for(i = 0; ((i < 3) && ((c=fgetc(pass))!= EOF)); b++){
                if(c == '|'){
                    printf("Stepper %d\n", i);
                    if(i == 2){
                        a[j][i] = (b+j+1) - 3;
                    }
                    else{
                        a[j][i] = (b+j+1);
                    
                    }
                    i = i + 1;
                }
            }
        }
        printf("Stepper located\n");
        fseek(pass, 0, SEEK_SET);
        i = 0;
        printf("Checking  password\n");
        do{
            c = fgetc(pass);
            fread(id, sizeof(char), 1, pass);
            c = fgetc(pass);
            fread(username, sizeof(unsigned char), (a[i][1] - a[i][2] - 2), pass);
            username[(a[i][1] - a[i][2]) - 1] = '\n';
            c = fgetc(pass);
            fseek(pass, 0, SEEK_SET);
            fread(passw, sizeof(unsigned int), 4, pass);
            if(!(strcmp(username, user))){
                printf("Correct password\n");
                for(y = 0; y < 4; y++){
                    printf("%x ?? %x", passw[y], comp[y]);
                    if(passw[y] != comp[y]){
                        *id = 0;
                        i = j;
                        x = 1;
                        break;
                    }
                }
                if (*id != 0){
                    i = j;
                    x = 1;
                }
                
            }
            else{
                *id = 0;
                bzero(username, 10);
                bzero(passw, 4);
                i = i + 1;
            }
        }while(i < j);
    }while(x != 1);
}

void md5hash(unsigned char pass[64], unsigned char key[16], unsigned int *res){
    unsigned int bits[16], keys[4], trans = 0, f = 0,g = 0,i = 0, x = 0, k[64], s[64] = {7,12,17,22,7,12,17,22,7,12,17,22,5,9,14,20,5,9,14,20,5,9,14,20,4,11,16,23,4,11,16,23,4,11,16,23,6,10,15,21,6,10,15,21,6,10,15,21};
    for(i = 0; i < 64; i++){
        if(pass[i] == 10)break;
    }
    for(x = 0; x < (64-i) ; x++){ 
        pass[i+x+1] = 0;
    }
    x = 0;
    for(i = 0; i < 64; i = i+4){
        bits[x] = (pass[i] << 24) | (pass[i+1] << 16) | (pass[i+2]  << 8)  |  pass[i+3];
        x = x + 1;
    }
    for(i = 0, x = 0; i < 16; i = i + 4){
        keys[x] = (key[i] << 24) | (key[i+1] << 16) | (key[i+2]  << 8)  |  key[i+3];
        x = x + 1;
    }
    
    for(i = 0; i < 64; i++){
        k[i] = (unsigned int)minum(232 * absolute(sin(i+1)));
    }
    
    for(i = 0; i < 64; i++){
        if((i >= 0)&&(i <= 15)){
            f = (keys[1] & keys[2]) | ((~keys[1]) & keys[3]);
            g = i;
        }
        else if(i <= 31){
            f = (keys[3] & keys[1]) | (keys[2] & (~keys[3]));
            g = ((5*i)+1) % 16;
        }
        else if(i <= 47){
            f = keys[1] ^ keys[2] ^ keys[3];
            g = ((3*i)+5) % 16;
         }
        else if(i <= 63){
            f = keys[2] ^ (keys[1] | (~keys[3]));
            g = (7*i) % 16;
        }
        trans =  keys[3];
        keys[3] = keys[2];
        keys[2] = keys[1];
        keys[1] = keys[1] + ((keys[0] + f + k[i] + bits[g]) << s[i]);
        keys[0] = trans;
    }
    memcpy(res, &keys, sizeof(keys));
}

int minum(float a){
    int b;
    if(a < 0){
        b = ((int)a)-1;
    }
    else{
        b = (int)a;
    }
    return(b);
}

float absolute(float num){
    float b;
    if(num < 0){
        b = num * (-1);
    }
    else{
        b = num;
    }
    return(b);
}
