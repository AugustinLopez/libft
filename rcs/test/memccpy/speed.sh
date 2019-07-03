make -C ../../../
gcc speed_memccpy.c ../../../libft.a -I../../../includes -o speed
./speed $1
rm ./speed
