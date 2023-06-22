# deposito_v1.c
Example of stack data structure, using the C language in the CodeBlocks IDE

### Container Storage Warehouse

A system that simulates a warehouse with 3 areas, each area having a storage capacity of up to 3 containers.
The program implements a stack data structure for each area of the warehouse, where containers are stacked and unstacked on top of each other.

The program interface consists of the following options:

* `Push`: Allows the user to push a new container into the warehouse. The user enters the container code and selects the area where they want to stack it.

* `Pop`: Allows the user to pop a container from a specific area. The user selects the area from which they want to unstack the container.

* `Print`: Displays the current content of the warehouse, showing a table with the areas and their respective stacked containers. The table is displayed from bottom to top, as if it were a real stacking.

* `Exit`: Terminates the program.

<p align="center">
  <img src= https://github.com/andresima0/deposito_v1.c/assets/111400782/0a9fda7f-a21f-4581-a006-8fbee0130842)" alt="Deposito interface")>
</p>

When pushing a container, the program checks if the selected area has reached its maximum capacity. If the area is full, the program displays a message informing that it is not possible to stack more containers in that area.

When popping a container, the program checks if the selected area has containers to unstack. If the area is empty, the program displays a message informing that it is not possible to unstack containers from that area.

At the end of the program execution, all allocated memory for the stacks is deallocated.

##

### Portuguese version:

### Depósito de Armazenamento de Containers

Sistema que simula um depósito com 3 áreas, sendo cada área com capacidade de armazenamento de até 3 containers.
O programa implementa uma estrutura de dados do tipo pilha para cada área do depósito, onde os containers são empilhados e desempilhados um sobre o outro.

A interface do programa é composta pelas seguintes opções:

* `Empilhar`: Permite ao usuário empilhar um novo container no depósito. O usuário informa o código do container e seleciona a área em que deseja empilhá-lo;

* `Desempilhar`: Permite ao usuário desempilhar um container de uma determinada área. O usuário seleciona a área em que deseja desempilhar o container;

* `Imprimir`: Mostra o conteúdo atual do depósito, exibindo uma tabela com as áreas e seus respectivos containers empilhados. A tabela é exibida de baixo para cima, como se fosse um empilhamento real.

* `Sair`: Encerra o programa.

<p align="center">
  <img src= https://github.com/andresima0/deposito_v1.c/assets/111400782/0a9fda7f-a21f-4581-a006-8fbee0130842)" alt="Deposito interface")>
</p>

Ao empilhar um container, o programa verifica se a área selecionada já atingiu sua capacidade máxima. Caso a área esteja cheia, o programa exibe uma mensagem informando que não é possível empilhar mais containers naquela área.

Ao desempilhar um container, o programa verifica se a área selecionada possui containers para desempilhar. Caso a área esteja vazia, o programa exibe uma mensagem informando que não é possível desempilhar containers daquela área.

No final da execução do programa, toda a memória alocada para as pilhas é desalocada.
