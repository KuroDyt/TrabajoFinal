gcc -I$(pwd)/include -lm source/BackEnd.c source/FrontEnd.c source/md5hash.c StartPoint.c -o bin/Program.elf

x86_64-w64-mingw32-gcc -I$(pwd)/include -lm source/BackEnd.c source/FrontEnd.c source/md5hash.c StartPoint.c -o bin/Program.exe

gcc -I$(pwd)/include -lm source/BackEnd.c source/md5hash.c DataBaseStart.c -o bin/DataBaseStart.elf

x86_64-w64-mingw32-gcc -I$(pwd)/include -lm source/BackEnd.c source/md5hash.c DataBaseStart.c -o bin/DataBaseStart.exe