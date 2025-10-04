### O Que Foi Feito Neste Projeto?

Este projeto é um gerenciador de playlists musicais que roda no terminal (console), criado para demonstrar e praticar conceitos fundamentais da linguagem C.

#### Funcionalidades Implementadas

O programa oferece um menu interativo com as seguintes funcionalidades:

* **Adicionar Música:** Cadastra uma nova música (título, artista, gênero e ano de lançamento) na playlist.
* **Exibir Playlist:** Lista todas as músicas ativas, mostrando todos os seus detalhes.
* **Buscar Música:** Permite ao usuário pesquisar por uma música específica pelo seu **título**.
* **Editar Música:** Encontra uma música pelo seu **ID** e permite alterar individualmente cada um de seus campos (título, artista, etc.).
* **Ordenar por Ano:** Exibe a playlist com as músicas organizadas em ordem crescente pelo ano de lançamento.
* **Excluir Música:** Realiza a **exclusão lógica** da música, marcando-a como inativa (`status = 0`) sem removê-la fisicamente da memória.

#### Aspectos Técnicos e Estrutura do Código

Para construir essas funcionalidades, foram aplicados os seguintes conceitos técnicos da linguagem C:

* **Estrutura de Dados (`struct`):** Foi usada uma `struct` chamada `TMusica` para modelar os dados de cada música, agrupando informações como `id`, `status`, `titulo`, `artista`, `genero` e `ano_lancamento`.
* **Alocação Dinâmica de Memória:** O programa não usa um vetor de tamanho fixo. Em vez disso, ele aloca memória dinamicamente com `malloc` para a primeira música e `realloc` para cada nova música adicionada. Isso torna o uso da memória mais eficiente.
* **Manipulação de Strings:** Foram utilizadas funções da biblioteca `<string.h>`, como `strcmp`, para comparar os títulos na funcionalidade de busca.
* **Algoritmo de Ordenação:** A funcionalidade de ordenar a playlist por ano foi implementada usando o algoritmo de ordenação **Bubble Sort**, que compara e troca elementos adjacentes até que a lista esteja ordenada.
* **Interface de Console com Cores:** Para uma melhor experiência do usuário no terminal, foram utilizadas macros com códigos de escape ANSI para adicionar cores à interface, melhorando a legibilidade das informações.
* **Lógica de Exclusão com `status`:** A exclusão de itens é feita de forma lógica, alterando um campo `status`. Essa é uma estratégia comum para evitar a complexidade de remover um elemento do meio de um vetor alocado dinamicamente.
