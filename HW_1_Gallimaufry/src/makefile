OBJS = main.o service.o

build : $(OBJS)
	g++-8 -o executable $(OBJS)
	./executable

main.o : main.cpp 
	g++-8 -c main.cpp

service.o : service.cpp
	g++-8 -c service.cpp