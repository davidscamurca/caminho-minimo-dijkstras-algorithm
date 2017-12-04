# caminho-minimo-dijkstras-algorithm


 * David Sobrinho Camurca
 * Implementacao algoritmo de Dijkstra com C++
 * Analise de Algoritmos: Metodo Guloso
 * Professor: Dr. Rainer Xavier Amorim
 * FUCAPI - 05/12/2017
 * Engenharia de Software

# Testes

Os testes realizados simulam uma rede de computadores de pequeno, médio e grande porte das empresas X, Y e Z. Ao todo foram realizados 3 testes, o primeiro com um grafo de 9 vértices, numerados de 0 a 8, simulando uma rede com 9 computadores conectados. O segundo foi o 5 vezes o tamanho do anterior ou seja, de 0 a 44, simulando 45 computadores conectados, e por último, um teste foi estudado simulando uma empresa de grande porte (Ex.: Microsoft), onde a rede contém mais de 500 computadores conectados em várias redes internas, sendo mais específico foram 512 computadores representados por vértices. Veja abaixo os grafos que foram usados nos testes.

![alt text](https://github.com/davidscamurca/caminho-minimo-dijkstras-algorithm/blob/master/T1.png "grafo1")



O objetivo do teste 1 é enviar um pacote de dado de um PCX para um PCY, os vértices que escolhidos foram PCX (vértice 0) e PCY (vértice 6). Ná próxima seção serão descritos com mais detalhes cada teste, o tópico 5 contém apenas os testes sem os resultados.

![alt text](https://github.com/davidscamurca/caminho-minimo-dijkstras-algorithm/blob/master/T2.png "grafo2")

O teste 2, realizado em uma empresa de médio porte, a mesma tem 45 computadores conectados dentro da rede interna, diferente do teste 1, os vértices escolhidos foram PCX (vértice 21) e PCY (vértice 11).


![alt text](https://github.com/davidscamurca/caminho-minimo-dijkstras-algorithm/blob/master/T3.png "grafo3")

O objetivo do último teste, é ir do PCX (vértice 45) e chegar no PCY (vértice 136).

# Resultados obtidos
A seguir mostraremos os resultados que obtivemos com os testes, consideramos três variáveis importante durante os testes, o tamanho da instância, o caminho percorrido e o tempo para a finalização da operação. Os tempos foram medidos em microssegundos. Para os testes utilizamos uma máquina com as seguintes configurações: Intel Core i5 4ª geração, 8GB RAM, Ubuntu 16.04.3 LTS 64 bits, GCC 5.4. Veja nas figuras 5, 6 e 7 os resultados.


Figura 5: Resultado teste 1
Fonte: Autor

O primeiro teste FIGURA 5, obtivemos os seguintes resultados: 
Tamanho da instância: 9,
Caminho percorrido (custo): 12
Tempo de execução para esse teste: 133 microssegundos.


Figura 6: Resultado teste 2
Fonte: Autor
O segundo teste FIGURA 6, obtivemos os seguintes resultados: 
Tamanho da instância: 44
Caminho percorrido (custo): 61
Tempo de execução para esse teste: 200 microssegundos.


Figura 7: Resultado teste 3
Fonte: Autor

O terceiro teste FIGURA 7, obtivemos os seguintes resultados: 
Tamanho da instância: 205
Caminho percorrido (custo): 52
Tempo de execução para esse teste: 700 microssegundos.

Sendo assim, podemos concluir que o teste 1, levou 133 microssegundos para finalizar o caminho com custo 12. O teste 2, precisou de 200 microssegundos e teve um custo de 61. O teste 3, precisou de aproximadamente 700 microssegundos com um custo de 52 passos.
T1 - teste 1, T2 - teste 2, T3 - teste 3
Testes ordenados do maior para menor por INSTÂNCIAS: T3 > T2 > T1
Testes ordenados do maior para menor por CUSTO: T2 > T3 > T1
Testes ordenados do maior para menor por TEMPO: T3 > T2 > T1

Assim, o T3 foi o teste que teve uma maior instância 205, o T2 teve o maior custo 61 e o T3 teve o maior tempo 700 microssegundos para finalizar a operação.

Esse algoritmo foi aplicado em um problema de rede de computadores, onde o mesmo e encarregado de encontrar o menor caminho entre um vertice A e B.

Algoritmo originalmente desenvolvido pelo professor [Marcos Castro](https://github.com/marcoscastro), e foi adaptado para o problema de redes aplicado.  

[Programação em C++ - Algoritmo de Dijkstra](https://gist.github.com/marcoscastro/d4e0df5b134c2cd63cf2)

# MIT License

Copyright (c) 2017 David Camurça

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
