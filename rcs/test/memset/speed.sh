make -C ../../../
gcc speed_memset.c ../../../libft.a -I../../../includes -o speed
./speed $1
rm ./speed
