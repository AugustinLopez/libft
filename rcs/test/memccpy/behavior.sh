make -C ../../../
gcc behavior_memccpy.c ../testing_utilities.c -I../ ../../../libft.a -I../../../includes -o behavior
printf 'MEMCPY GENERAL -    '
./behavior 0
printf 'System result is    '
./behavior 1
printf '\nMEMCHR CHAR -       '
./behavior 2
printf 'System result is    '
./behavior 3
printf '\nMEMCHR SIZE -       '
./behavior 4
printf 'System result is    '
./behavior 5
printf '\nLIMITED MEMORY -    '
./behavior 6
printf 'System result is    '
./behavior 7
printf '\nMISALIGNED -        '
./behavior 8
printf 'System result is    '
./behavior 9
printf '\n"","1",10, 1 -      '
./behavior a
printf 'System result is    '
./behavior b
printf '\nNULL, NULL, 10, 1 - '
./behavior c
printf 'System result is    '
./behavior d
printf '\nNULL, "1", 10, 1 -  '
./behavior e
printf 'System result is    '
./behavior f
printf '\n"1", NULL, 10, 1 -  '
./behavior g
printf 'System result is    '
./behavior h
printf '\nNULL, NULL, 10, 0 - '
./behavior i
printf 'System result is    '
./behavior j
printf '\nNULL, "1", 10, 0 -  '
./behavior k
printf 'System result is    '
./behavior l
printf '\n"1", NULL, 10, 0 -  '
./behavior m
printf 'System result is    '
./behavior n
rm ./behavior
