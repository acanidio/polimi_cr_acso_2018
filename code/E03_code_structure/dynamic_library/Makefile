# MAKEFILE usato per compilare il progetto di esempio

# Regola che fa il linking di tutti gli eseguibili del progetto
all: dynfatt

# Regola che fa il linking del programma example
dynfatt: main.o libfatt.so
	gcc $< -L. -lfatt -o $@

# Regola per la compilazione della libreria statica lib.a
lib: libfatt.so

# Regola che crea la libreria dinamica
libfatt.so: fatt_inter.o fatt_utils.o
	gcc -shared fatt_inter.o fatt_utils.o -o libfatt.so 

# Regola che genera tutti gli object file dati i c files
%.o: %.c
	gcc -c -fPIC $< -o $@

# Regola che fa il clean dell'intero progetto
clean:
	rm -f *.o dynfatt *.so

# Regole autogenerate ( gcc -MM *.c ) che creano le dipendenze tra file .h e .c
fatt_inter.o: fatt_inter.c fatt.h
fatt_utils.o: fatt_utils.c fatt.h
main.o: main.c fatt.h
