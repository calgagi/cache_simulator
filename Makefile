##########################################################
# Proj: Cache Simulator
# File: Makefile
# Auth: Calvin Gagliano
##########################################################
COMPILER = g++ --std=c++11

sim_cache: driver.o simulator.o cache.o
	$(COMPILER) driver.o simulator.o cache.o -o sim_cache

driver.o: driver.cpp
	$(COMPILER) -c driver.cpp

simulator.o: simulator.cpp
	$(COMPILER) -c simulator.cpp

cache.o: cache.cpp
	$(COMPILER) -c cache.cpp

clean:
	rm -f *.o sim_cache
