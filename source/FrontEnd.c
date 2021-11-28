#include <MainBase.h>

/*Aqui es donde iran sus codigos, todo estara lo mas explicado posible
y con cada cambio en el repositorio se vera reflejado en la rama main del
repositorio, en caso de que no puedan usar la plataforma de git avisenme 
para yo integrar sus cambios*/

/* En esta parte viene las declaraciones de las funciones*/

int login();


void adminmenu(int id);

void usermenu(int id);

/* Aqui vienen sus definiciones, cada declaracion viene acompañada con su
respectiva definicion, y pueden declara aqui cuantas y definir cuantas funciones
sean necesarias */




/* login debera pedir al usuario que ingrese su nombre y contraseña, para leer
tales datos no usaran scanf si no la funcion getlogin(), tambien tendran que 
hacer un array para el nombre y para la contraseña, el array sera un 
vector (array simple) del tamaño COUNTS para el nombre de usuario y PASSL 
para la contraseña

getlogin() regresa un valor de tipo int que sera 0 en caso de fallar la verificacion
o el id del usuario en caso de autentificar correctamente

el uso de getlogin es getlogin(&username, &password); , siendo username y password
los arrays en cuestion*/

int login(){}

/* adminmenu es del tipo void, asi que no regresa nada, no necesita del return
aqui deberas crear el menu de opciones de este menu, pero antes debes incluir 
la funcion printdata(id); que imprimira los datos de la id correspondiente
en el pdf de requerimientos viene como debe estructurarse este menu

usermenu igualmente es del tipo void y comparte funciones con admin, asi que
las instrucciones para cada uno seran las mismas

para cada grupo de menu habra funciones a los cuales invocas con argumentos de 
arrays
por ejemplo

Catalogo de departamento = depcat(&info[10]); , siendo info un array de tamaño
info[10][INFOS], esta variable es de tipo char, osea que es un string, cada 
string del 0 al 9 tendra el nombre de los departamentos

Catalogo de productos = prodcat(&info[50][6]); , basicamente los mismo pero 
ahora son 50 produtos con 6 strings diferente cada uno, representando en orden
la informacion de los productos, el array a declarar sera info[50][6][INFOS] de 
tipo char

Catalogo de descuentos = desccat(&info[10][4]); , lo mismo que la anterior opcion
ahora con un array de tipo info[10][4][INFOS]

Numero de productos por departamento = depprod(&info[5][2], dep); , esta funcion 
regresa la informacion de los productos del departamento que se especifica, dep
es el numero de departamento y es un int, info es un array de la forma 
info[5][2][INFOS]

precio unitario por un producto = prodpre(id); Esta funcion regresa un float con
el valor del precio de venta del producto, id debe ser un array del tipo char de
tamaño id[COUNTS] que contiene el string id del producto, en caso de que esta funcion
regrese 0 significara que la id del producto estuvo mal escrita

En los reportes solo deberan invocar las funciones, pues yo (Dyter) me encargare
de ello
para la i sera repprod();
para la ii sera repdep();
para la iii sera repvent();

Para la venta de producto ustedes deberan hacer toda la interracion con la funcion
ventprod(idprod); que recibe un array char con el nombre del producto, idprod es
un array de la forma idprod[COUNTS]; , cada vez que se invoque esta funcion se le
restara 1 al valor de cantidad en la base de datos del producto de la id introducida
esta funcion regresa un valor de tipo int, 1 si se logro restar y 0 en caso de que 
el stock del producto este agotado, pueden integrarla en un for o while infinito

Compra de productos debera abrir otro menu, la funcion para este menu sera 
checkprod(&infos[50][2], &cant); que al invocarse guardara en cant la cantidad de 
productos con menos de 50 en stock y en infos guardara tanto el nombre como la cantidad
actual del producto, el resto de la funcion en este programa deberan hacerlo ustedes

Nota especial: en este ultimo si la variable cant tiene un valor menor a 50 significa
que solo esos espacios tienen informacion en el array, lo demas seran espacios vacios

cant es una variable int simple, infos es de tipo char

Ustedes deberan encargarse de lo que se refiere a el cambio de usuario, regresar a menu
anterior y salir del programa, funciones

*/

void adminmenu(int id){}

void usermenu(int id){}