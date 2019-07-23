make -C ../../ $2 >> /dev/null
gcc ./$1/speed_$1.c ../../libft.a -I../../includes -o speed
printf "$1:\n"
./speed 1
./speed 10
./speed 100
./speed 1000
./speed 10000
./speed 100000
./speed 1000000
rm ./speed
