# MAKEFILE usato per compilare il progetto di esempio

# Regola che fa il linking di tutti gli eseguibili del progetto
all: stfatt

# Regola che fa il linking del programma example
stfatt: main.o libfatt.a
	gcc $< -L. -lfatt -o $@

# Regola per la compilazione della libreria statica lib.a
lib: libfatt.a

# Regola che crea la libreria statica lib.a
libfatt.a: fatt_inter.o fatt_utils.o
	ar -r libfatt.a fatt_inter.o fatt_utils.o

# Regola che genera tutti gli object file dati i c files
%.o: %.c
	gcc -c $< -o $@

# Regola che fa il clean dell'intero progetto
clean:
	rm -f *.o stfatt *.a

# Regole autogenerate ( gcc -MM *.c ) che creano le dipendenze tra file .h e .c
fatt_inter.o: fatt_inter.c fatt.h
fatt_utils.o: fatt_utils.c fatt.h
main.o: main.c fatt.h
