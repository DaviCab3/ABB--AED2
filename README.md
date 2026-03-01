# ABB--AED2


1️⃣ Explicação da estrutura BST utilizada

A estrutura utilizada no trabalho é uma Árvore Binária de Busca (BST – Binary Search Tree).

Uma BST é uma árvore binária em que, para cada nó:

Todos os elementos da subárvore esquerda possuem chave menor que a do nó atual

Todos os elementos da subárvore direita possuem chave maior que a do nó atual


2️⃣ Justificativa da escolha do nome como chave

O nome do município foi escolhido como chave de ordenação pelos seguintes motivos:

É um identificador natural e intuitivo para cidades

Facilita a listagem em ordem alfabética, que é um requisito do trabalho

Evita ambiguidades comuns em outros atributos, como área ou população

Permite buscas e inserções baseadas em comparações lexicográficas (strcmp)

Além disso, como o trabalho exige exibição organizada e leitura clara dos dados, ordenar pelo nome torna a saída mais compreensível para o usuário.

a) O que acontece se os nomes forem inseridos já em ordem alfabética?

Se os municípios forem inseridos já em ordem alfabética, a BST se degenera.

Em vez de formar uma árvore balanceada, a estrutura passa a se comportar como uma lista encadeada, onde:

Cada novo elemento é inserido sempre à direita (ou à esquerda)

A altura da árvore passa a ser proporcional ao número de elementos

b) Qual seria a vantagem de usar uma AVL nesse caso?

Uma AVL é uma árvore binária de busca auto-balanceada.

Sua principal vantagem é que, após cada inserção ou remoção, a árvore realiza rotações automáticas para manter o balanceamento.

Vantagens da AVL nesse cenário:

Garante que a altura da árvore seja sempre O(log n)

Mantém bom desempenho independentemente da ordem de inserção

Evita a degeneração da árvore mesmo com dados já ordenados



