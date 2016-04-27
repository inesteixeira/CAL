Instruções de compilação:

São necessários três ficheiros para a execução do programa:
1º - AllPOI.txt lê todos os Ponto de Interesse existentes no mapa e as suas respecivas coordenadas;
2º - Distances.txt lê todas as distâncias existentes no mapa entre os diversos Pontos de Interesse para poder crias as arestas entre os vértices;
3º - POI.txt lê passageiros para colocar no autocarro desde início já com Pontos de Interesse definidos para o autocarro passar.

Nas propriedade do Projeto adicionar:
Project-> Properties->C/C++ Build-> Settings, e escolha a opção add nas "libraries" e escreva ws2_32;
Project -> Properties -> C/C++ build -> Settings -> MinGW C++ Linker -> Miscellaneous -> Other objects: MinGW path + \libwsock32.a  Neste caso: C:\MinGW\lib\libwsock32.a;
Project-> Properties->C/C++ Build-> Settings, e escreva "-static" na Linker Flags de Miscelaneous.

Ficheiros fornecidos:
São usados os ficheiros fornecidos no Moodle: graphviewer.h, graphviewer.cpp, Graph.h, edgetype.h, connection.h e connection.cpp.