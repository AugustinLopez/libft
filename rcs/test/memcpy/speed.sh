make -C ../../../
gcc speed_memcpy.c ../../../libft.a -I../../../includes -o speed
./speed $1
rm ./speed
