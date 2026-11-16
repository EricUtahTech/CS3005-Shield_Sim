all: shield-sim

shield.o: shield.h shield.cpp
	g++ -c shield.cpp

shot-blaster.o: shot-blaster.h shot-blaster.cpp
	g++ -c shot-blaster.cpp

shield-sim.o: shield.h shot-blaster.h shield-sim.cpp
	g++ -c shield-sim.cpp

shield-sim: shield.o shot-blaster.o shield-sim.o
	g++ -o shield-sim shield-sim.o shield.o shot-blaster.o

clean:
	rm -f *.o shield-sim