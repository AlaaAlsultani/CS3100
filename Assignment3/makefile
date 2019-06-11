all: gendata readfile printstuff hw3 fork

gendata: gendata.c
	gcc -o gendata gendata.c

hw3: hw3.c
	gcc -o hw3 hw3.c

printstuff:
	gcc -o printstuff printstuff.c

fork:
	gcc -o fork fork.c

clean:
	rm gendata hw3 printstuff fork
