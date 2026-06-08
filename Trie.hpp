#ifndef TRIE_HPP
#define TRIE_HPP

#include "Game.hpp"
#include <vector>
#include <string>

// Tamanho do alfabeto: 26 letras (minúsculas) + 10 números (0 a 9) = 36


// Escolhemos as 26 letras do alfabeto que possuem representação na tabela ASCII
//pelos números na base decimal de 97 ('a') a 122 ('z').

// Optamos por ignorar caracteres especiais, 
//dado que alguns deles (com % ou \) possuem significado especial em certas funções, o que pode gerar confusões.
//Ignoramos também acentos, dado que palavras acentuadas ocupam mais de um byte e às vezes usam codificações diferentes, dependendo também do compilador.
// Assim, poderíamos acrescentar talvez caracteres não suscetíveis a erros de codificação, como '!', '?', '.', ':', ',' e ';', 
// mas, mesmo assim, não são caracteres essenciais para diferenciação de títulos neste contexto (além de que neste banco de jogos nem há).
const int ALPHABET_SIZE = 36;

class TrieNode {
public:
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfTitle;
    Game* game; //aponta para o jogo associado àquele título.

    TrieNode();
    ~TrieNode();
};

class Trie {
private:
    TrieNode* root;

    // Outros métodos auxiliares, se necessário
    // Como escolhemos ALPHABET_SIZE com 36 caracteres, precisamos definir 
    // os índices de cada um deles no array children[ALPHABET_SIZE].
    // Por isso, a função getCharIndex os mapeia de maneira que 
    // 'a'=1, 'b'=2, ..., 'z'=25, '0'=26, '1'=27, ..., '9'=35.
    int getCharIndex(char c);
    void collectGames(TrieNode* node, std::vector<Game*>& results);

public:
    Trie();
    ~Trie();

    bool insert(Game* game);
    bool contains(std::string title);

    std::vector<Game*> autocomplete(std::string prefix, int k);

    std::string toSearchKey(std::string text);
    void sortResults(std::vector<Game*>& games);
};

#endif