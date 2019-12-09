##########################################################
# Proj: Cache Simulator
# File: Makefile
# Auth: Calvin Gagliano
##########################################################
COMPILER = g++ --std=c++11

cache_simulator: driver.o simulator.o cache.o lru_cache.o
	$(COMPILER) driver.o simulator.o cache.o lru_cache.o -o cache_simulator

driver.o: driver.cpp
	$(COMPILER) -c driver.cpp

simulator.o: simulator.cpp
	$(COMPILER) -c simulator.cpp

cache.o: cache.cpp
	$(COMPILER) -c cache.cpp

lru_cache.o: lru_cache.cpp
	$(COMPILER) -c lru_cache.cpp

clean:
	rm -f *.o sim_cache
