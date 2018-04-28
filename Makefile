CC = g++
ODIR = obj
PROG = main
CXXFLAG = -std=c++11

$(PROG) : $(ODIR) $(ODIR)/Frac.o $(ODIR)/Matrix.o $(ODIR)/main.o 
	$(CC) -o $@ $(ODIR)/Frac.o $(ODIR)/Matrix.o $(ODIR)/main.o $(CXXFLAG)

$(ODIR)/Frac.o : ./src/Frac.cpp ./include/Frac.h 
	$(CC) -c $< -o $@ $(CXXFLAG)

$(ODIR)/Matrix.o : ./src/Matrix.cpp ./include/Matrix.h ./include/Frac.h 
	$(CC) -c $< -o $@ $(CXXFLAG)

$(ODIR)/main.o : ./src/main.cpp ./include/Matrix.h 
	$(CC) -c $< -o $@ $(CXXFLAG)

$(ODIR) :
	if [ ! -d $(ODIR) ]; then mkdir $(ODIR); fi

.PHONY : clean
clean :
	if [ -d $(ODIR) ]; then rm $(ODIR) -r; fi
	if [ -f $(PROG) ]; then rm $(PROG); fi

