OPT=-g -Wall
# OPT=-g -O3
CFLAGS=$(OPT) -Wall -fdiagnostics-color=always

#####################
# Llista d'utilitats
#####################
UTILS=pcl pmul pder paval prand

##################
# Primer objectiu
##################
tot : $(UTILS)

############
# Utilitats
############
# Combinació lineal de polinomis
pcl : pcl.c pol.o
	gcc -o $@ $(CFLAGS) $^
# Producte de polinomis
pmul : pmul.c pol.o
	gcc -o $@ $(CFLAGS) $^
# Derivada d'un polinomi
pder : pder.c pol.o
	gcc -o $@ $(CFLAGS) $^
# Avaluació d'un polinomi
paval : paval.c pol.o
	gcc -o $@ $(CFLAGS) $^
# Polinomi amb coeficients aleatoris
prand : prand.c pol.o
	gcc -o $@ $(CFLAGS) $^

##############
# Bibilioteca
##############
pol.o : pol.c
	gcc -c $(CFLAGS) $<

#########
# Neteja
#########
clean :
	rm -f *.o
realclean : clean
	rm -f $(UTILS)
