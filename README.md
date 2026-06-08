# Lista-4---Elainne-Rohs-e-Joana-Fontes---Estrutura-de-Dados

Professor: Matheus Werner

Implementação de um sistema simples de autocomplete de jogos utilizando a estrutura de dados Trie.

O sistema permite:

- inserir jogos na Trie;
- buscar um jogo pelo título;
- buscar jogos por prefixo;
- retornar até k sugestões de jogos por prefixo;
- ordenar os resultados do autocomplete;
- exibir os resultados encontrados;
- converter títulos e prefixos para a chave de busca utilizada internamente.

### Instruções de compilação

A compilação do código é feita pelo seguinte comando:

```g++ main.cpp Game.cpp Trie.cpp GamesDatabase.cpp -o app```

A implementação desse comando gerará um arquivo ```app.exe```.

### Instruções de execução

Rode o arquivo executável com o seguinte comando:

```./app k prefixo```

Sendo:
- ```prefixo```: prefixo do(s) título(s) a ser(em) buscado(s) pelo autocomplete.
- ```k```: quantidade máxima de repostas do autocomplete desejada no output.

### Organização dos arquivos

- ```check_database.cpp```: (Pode ignorar) Retorna os títulos, desrições e popularidades dos ```n``` primeiros jogos do banco de jogos no ```GamesDatabase.cpp```, usando o comando ```./check_database x```. Trata entradas ```x``` inválidas. 
- ```Game.cpp```: Implementação da classe ```Game```.
- ```Game.hpp```: Declaração da classe ```Game```, seus atributos e getters.
- ```GamesDatabase.cpp```: Banco de jogos no sistema de autocomplete.
- ```GamesDatabase.hpp```: Declaração desse database.
- ```main.cpp```: Arquivo principal responsável por carregar a lista inicial de jogos, inserir os jogos na Trie e executar a busca usando os argumentos da linha de comando.
- ```Trie.cpp```: Implementação das classes ```Trie``` e ```TrieNode```.
- ```Trie.hpp```: Declaração das classes ```Trie``` e ```TrieNode```, seus atributos e métodos.

### Exemplos de uso

#### Exemplo 1



#### Exemplo 2



#### Exemplo 3
