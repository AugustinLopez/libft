make -C ../../../
gcc behavior_memset.c ../testing_utilities.c -I../ ../../../libft.a -I../../../includes -o behavior
./behavior 0 1 0
./behavior 0 0 0
printf '\n'
./behavior 1 1 0
./behavior 1 0 0
printf '\n'
./behavior 2 1 0
./behavior 2 0 0
printf '\n'
./behavior 3 1 0
./behavior 3 0 0
printf '\n'
./behavior 3 1 1
./behavior 3 0 1
printf '\n'
./behavior 3 1 2
./behavior 3 0 2
printf '\n'
./behavior 3 1 3
./behavior 3 0 3
rm ./behavior
