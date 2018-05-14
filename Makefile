CC = g++
ODIR = obj
PROG = main
CXXFLAGS = -Wall -Wextra -std=c++11

OBJS = $(ODIR)/frac.o $(ODIR)/main.o $(ODIR)/matrix.o $(ODIR)/utils.o
$(PROG) : $(ODIR) $(OBJS)
	$(CC) -o $@ $(OBJS) $(CXXFLAGS)

$(ODIR)/frac.o : ./src/frac.cpp ./include/frac.h
	$(CC) -c ./src/frac.cpp -o $@ $(CXXFLAGS)

$(ODIR)/main.o : ./src/main.cpp ./include/matrix.h ./include/frac.h ./include/utils.h
	$(CC) -c ./src/main.cpp -o $@ $(CXXFLAGS)

$(ODIR)/matrix.o : ./src/matrix.cpp ./include/matrix.h ./include/frac.h
	$(CC) -c ./src/matrix.cpp -o $@ $(CXXFLAGS)

$(ODIR)/utils.o : ./src/utils.cpp ./include/utils.h
	$(CC) -c ./src/utils.cpp -o $@ $(CXXFLAGS)

$(ODIR) :
	if [ ! -d $(ODIR) ]; then mkdir $(ODIR); fi

.PHONY : clean
clean :
	if [ -d $(ODIR) ]; then rm $(ODIR) -r; fi
	if [ -f $(PROG) ]; then rm $(PROG); fi
