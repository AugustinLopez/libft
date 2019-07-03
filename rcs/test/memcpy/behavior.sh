make -C ../../../
gcc behavior_memcpy.c ../testing_utilities.c -I../ ../../../libft.a -I../../../includes -o behavior
printf 'GENERAL -        '
./behavior 0
printf 'System result is '
./behavior 1
printf '\nLIMITED MEMORY - '
./behavior 2
printf 'System result is '
./behavior 3
printf '\nMISALIGNED -     '
./behavior 4
printf 'System result is '
./behavior 5
printf '\n"","1",1 -       '
./behavior 6
printf 'System result is '
./behavior 7
printf '\nNULL, NULL, 1 -  '
./behavior 8
printf 'System result is '
./behavior 9
printf '\nNULL, "1", 1 -   '
./behavior a
printf 'System result is '
./behavior b
printf '\n"1", NULL, 1 -   '
./behavior c
printf 'System result is '
./behavior d
printf '\nNULL, NULL, 0 -  '
./behavior e
printf 'System result is '
./behavior f
printf '\nNULL, "1", 0 -   '
./behavior g
printf 'System result is '
./behavior h
printf '\n"1", NULL, 0 -   '
./behavior i
printf 'System result is '
./behavior j

rm ./behavior
