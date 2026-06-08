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

- ```check_database.cpp```: (Pode ignorar) Retorna os títulos, descrições e popularidades dos ```n``` primeiros jogos do banco de jogos no ```GamesDatabase.cpp```, usando o comando ```./check_database n```. Trata entradas ```n``` inválidas. 
- ```Game.cpp```: Implementação da classe ```Game```.
- ```Game.hpp```: Declaração da classe ```Game```, seus atributos e getters.
- ```GamesDatabase.cpp```: Banco de jogos no sistema de autocomplete.
- ```GamesDatabase.hpp```: Declaração desse database.
- ```main.cpp```: Arquivo principal responsável por carregar a lista inicial de jogos, inserir os jogos na Trie e executar a busca usando os argumentos da linha de comando.
- ```Trie.cpp```: Implementação das classes ```Trie``` e ```TrieNode```.
- ```Trie.hpp```: Declaração das classes ```Trie``` e ```TrieNode```, seus atributos e métodos.

### Exemplos de uso

#### Exemplo 1: Sucesso, k > results.size()

Comando: ```./app 3 holl```

Output:
```
Hollow Knight | Forge your own path in Hollow Knight An epic action adventure through a vast ruined kingdom of insects and heroes Explore twisting caverns battle tainted creatures and befriend bizarre bugs all in a classic hand drawn 2D style | 269812

```
Repare que na saída aparece o único jogo no database com tal prefixo, mesmo com k=3.

#### Exemplo 2: Sucesso, k < results.size()

Comando: ```./app 4 lit```

Output:
```
Little Nightmares | Immerse yourself in Little Nightmares a dark whimsical tale that will confront you with your childhood fears Help Six escape The Maw a vast mysterious vessel inhabited by corrupted souls looking for their next meal | 36745

Little Nightmares II | Little Nightmares II is a suspense adventure game in which you play as Mono a young boy trapped in a world that has been distorted by an evil transmission Together with new friend Six he sets out to discover the source of the Transmission | 23954

Little Witch Nobeta | Control the lovely little witch Nobeta explore the unknown mysterious castle and gradually discover the truth | 8604

Little Inferno | Throw your toys into your fire and play with them as they burn An adventure that takes place almost entirely in front of a fireplace about looking up up up out of the chimney and the cold world just on the other side of the wall From the creators of World of Goo and Human Resource Machine | 7030

```
Foram exibidos 4 resutados, quando na verdade ```results.size() = 11```, neste caso.

#### Exemplo 3 (argumentos insuficientes)

Comando: ```.\app 15```

Output:

```
Usage: ./app k prefix
```

#### Exemplo 4 (Sem correspondência)

Comando: ```.\app 10 fgv```

Output:

```
No results found
```

#### Exemplo 5 (k <= 0)

Comando: ```.\app 0 hol```

Output:

```
No results found
```
