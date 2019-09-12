make -C ../../../
gcc behavior_memchr.c ../testing_utilities.c -I../ ../../../libft.a -I../../../includes -o behavior
./behavior 0char 1
./behavior 0char 0
./behavior 1size 1
./behavior 1size 0
./behavior 2misaligned 1
./behavior 2misaligned 0
./behavior 3undefined 1
./behavior 3undefined 0
./behavior 4undefined 1
./behavior 4undefined 0
./behavior 5undefined 1
./behavior 5undefined 0
./behavior 6undefined 1
./behavior 6undefined 0
rm ./behavior
