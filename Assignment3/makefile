all: gendata readfile printstuff fork

gendata: gendata.c
	gcc -o gendata gendata.c

readfile: readfile.c
	gcc -o readfile readfile.c

printstuff:
	gcc -o printstuff printstuff.c

printstuff:
	gcc -o fork fork.c

clean:
	rm gendata readfile printstuff fork
