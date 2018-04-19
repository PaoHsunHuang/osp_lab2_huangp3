new_cat: new_cat.c new_echo new_tail new_wc
	gcc -o new_cat new_cat.c
new_echo:
	gcc -o new_echo new_echo.c
new_tail:
	gcc -o new_tail new_tail.c
new_wc:
	gcc -o new_wc new_wc.c 
clean:
	rm -f new_cat new_echo new_tail new_wc
