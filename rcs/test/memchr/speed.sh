make -C ../../../
gcc speed_memchr.c ../../../libft.a -I../../../includes -o speed
./speed $1
rm ./speed
