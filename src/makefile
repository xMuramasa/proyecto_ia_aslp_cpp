CPP=g++

nInstancia= 1

MAX_NEIGHBORS=500
T_MAX=1000
SEED=123

make:
	$(CPP) -o obj/out main.cpp functions.cpp

clean:
	rm -rf obj/*

run:
	./obj/out $(MAX_NEIGHBORS) $(T_MAX) $(SEED) < ../Instancias_ALSP/Txt/airland$(nInstancia).txt
