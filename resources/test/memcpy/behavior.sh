make -C ../../../
gcc behavior_memcpy.c ../testing_utilities.c -I../ ../../../libft.a -I../../../includes -o behavior
./behavior 0general 1
./behavior 0general 0
./behavior 1memory 1
./behavior 1memory 0
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
./behavior 7undefined 1
./behavior 7undefined 0
./behavior 8undefined 1
./behavior 8undefined 0
./behavior 9undefined 1
./behavior 9undefined 0
rm ./behavior
