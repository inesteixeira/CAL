Instru��es de compila��o:

S�o necess�rios tr�s ficheiros para a execu��o do programa:
1� - AllPOI.txt l� todos os Ponto de Interesse existentes no mapa e as suas respecivas coordenadas;
2� - Distances.txt l� todas as dist�ncias existentes no mapa entre os diversos Pontos de Interesse para poder crias as arestas entre os v�rtices;
3� - POI.txt l� passageiros para colocar no autocarro desde in�cio j� com Pontos de Interesse definidos para o autocarro passar.

Nas propriedade do Projeto adicionar:
Project-> Properties->C/C++ Build-> Settings, e escolha a op��o add nas "libraries" e escreva ws2_32;
Project -> Properties -> C/C++ build -> Settings -> MinGW C++ Linker -> Miscellaneous -> Other objects: MinGW path + \libwsock32.a  Neste caso: C:\MinGW\lib\libwsock32.a;
Project-> Properties->C/C++ Build-> Settings, e escreva "-static" na Linker Flags de Miscelaneous.

Ficheiros fornecidos:
S�o usados os ficheiros fornecidos no Moodle: graphviewer.h, graphviewer.cpp, Graph.h, edgetype.h, connection.h e connection.cpp.