make -C ../../../
gcc -g3 speed_memcmp.c ../../../libft.a -I../../../includes -o speed

./speed 1
echo ''

./speed 10
echo ''

./speed 100
echo ''

./speed 1000
echo ''

./speed 10000
echo ''

./speed 100000
echo ''

./speed 1000000
echo ''
rm ./speed
