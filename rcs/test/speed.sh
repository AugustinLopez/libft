make -C ../../
gcc $1/speed_$1.c ../../libft.a -I../../includes -o speed
./speed 1
./speed 10
./speed 100
./speed 1000
./speed 10000
./speed 100000
./speed 1000000
rm ./speed
