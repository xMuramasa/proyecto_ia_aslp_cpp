nInstancia ?= 1

make:
	g++ alsp.cpp -o out
run:
	./out < Instancias_ALSP/Txt/airland$(nInstancia).txt