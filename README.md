# Proyecto Para Inteligencia Artificial INF295 2020-2
# Aircraft Landing Scheduling Problem

Martin Alonso Salinas Scussolin
201773557-0

#### IMPORTANTE: No modificar los directorios incluidos

Son necesarios los siguientes archivos para el correcto funcionamiento del código:
- headerfile.h
- functions.cpp
- main.cpp
- Instancias_ALSP/Txt/*

Para las instancias, se consideran los archivos dentro del directorio: 'Instancias_ALSP/Txt/', con nombre:
- airland(n).txt
  
Donde (n) representa la cantidad de aeronaves por instancia.

Compilación:
- Para compilar el código, dentro del directorio 'src/':
  - make

Para la ejecución del código, dentro del directorio 'src/':

- Se pueden incluir los vecinos máximos permitidos por vecindario, iteraciones de hillclimbing, semilla y número de instancia. De lo contrario, hace los defaults MAX_NEIGHBOURS=500, T_MAX=1000, SEED=123

  - se ejecuta con los comandos:
      - make run
  
      - make run MAX_NEIGHBOURS=(numero vecinos) T_MAX=(máximo iteraciones) SEED=(número semilla) nInstancia=(numero instancia)
        - ejemplo:
          - make run  MAX_NEIGHBOURS=10000 T_MAX=1000 SEED=321 nInstancia=1
      
