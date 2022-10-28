distclean: clean
	rm -r ../bin
clean: install
	rm E04.o
install: target
	mkdir ../bin
	mv Eseguibile ../bin
target:
	gcc -c E04.c
	gcc -o Eseguibile E04.o
