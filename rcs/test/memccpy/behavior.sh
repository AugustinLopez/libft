make -C ../../../
gcc behavior_memccpy.c ../testing_utilities.c -I../ ../../../libft.a -I../../../includes -o behavior
./behavior 0memcpy 1
./behavior 0memcpy 0
./behavior 1memchr_char 1
./behavior 1memchr_char 0
./behavior 2memchr_size 1
./behavior 2memchr_size 0
./behavior 3memory 1
./behavior 3memory 0
./behavior 4misaligned 1
./behavior 4misaligned 0
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
./behavior aundefined 1
./behavior aundefined 0
./behavior bundefined 1
./behavior bundefined 0
rm ./behavior
