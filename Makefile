# Starter Makefile
# add .cpp and .h files as specified in each task. 

OBJECTS = main.o reservoir.o reverseorder.o
CIXX = g++ #could be useful if you are using multiple compilers
LDFLAGS = -lm
CXXFLAGS = Wall –Wpedantic –O2 #the o stands for optimization

main: main.o reservoir.o reverseorder.o
	$(CIXX) -o main $(CIXXFLAGS) $(LDFLAGS) $(OBJECTS)

main.o: main.cpp reservoir.h reverseorder.h
	$(CIXX) $(CIXXFLAGS) -c main.cpp

reservoir.o: reservoir.cpp reservoir.h
	$(CIXX) $(CIXXFLAGS) -c reservoir.cpp reservoir.h

reverseorder.o: reverseorder.cpp reverseorder.h
	$(CIXX) $(CIXXFLAGS) -c reverseorder.cpp reverseorder.h

clean:
	rm -f $(OBJECTS) reservoir.h.gch reverseorder.h.gch
