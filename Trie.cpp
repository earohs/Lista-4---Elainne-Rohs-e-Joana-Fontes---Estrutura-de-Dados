#include "Trie.hpp"

TrieNode::TrieNode() {
    isEndOfTitle = false;
    game = nullptr;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        children[i] = nullptr;
    }
}

TrieNode::~TrieNode() {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (children[i] != nullptr) {
            delete children[i];
        }
    }
}

Trie::Trie() {
    root = new TrieNode();
}

Trie::~Trie() {
    delete root;
}

int Trie::getCharIndex(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a';
    } 
    //Se não for letra minúscula, é número 
    return c - '0' + 26;
}

std::string Trie::toSearchKey(std::string text) {
    std::string key = "";

    for (char c : text) {
        //ignorar espaços em branco
        if (c == ' ') continue;
        
        // Em ASCII, 'A' = 65 e 'Z' = 90, assim como 'a' = 97 e 'z' = 122
        // Portanto, por exemplo, 'n'-'a' = 'N' - 'A'
        //não diferenciar maiúsculas/minúsculas
        if (c <= 'Z' && c >= 'A') {
            key += c - 'A' + 'a';
        }
        //preservar letras e números, apenas
        else if ((c <= 'z' && c >= 'a') || (c >= '0' && c <= '9')) {
            key += c;
        }
    }
    return key;
}

//O parâmetro game é um ponteiro para um objeto Game já existente no array fornecido em GamesDatabase.cpp
bool Trie::insert(Game* game) {
    if (game == nullptr) return false;

    std::string key = toSearchKey(game->getTitle());
    TrieNode* current = root;

    for (char c : key) {
        int index = getCharIndex(c); 

        if (current->children[index] == nullptr) {
            current->children[index] = new TrieNode();
        }
        current = current->children[index];
    }

    current->isEndOfTitle = true;
    current->game = game;
    return true;
}

bool Trie::contains(std::string title) {
    std::string key = toSearchKey(title);
    TrieNode* current = root;

    for (char c : key) {
        int index = getCharIndex(c);

        if (current->children[index] == nullptr) {
            return false;
        }
        current = current->children[index];
    }

    return current->isEndOfTitle;
}

void Trie::sortResults(std::vector<Game*>& games) {
    // Utilizando Insertion Sort
    for (size_t i = 1; i < games.size(); i++) {
        Game* keyGame = games[i];
        int j = i - 1;

        while (j >= 0) {
            bool swap = false;

            //maior popularidade
            if (games[j]->getPopularity() < keyGame->getPopularity()) {
                swap = true;
            } else if (games[j]->getPopularity() == keyGame->getPopularity()) {
                
                // ordem alfabética pela chave de busca do título
                if (toSearchKey(games[j]->getTitle()) > toSearchKey(keyGame->getTitle())) {
                    swap = true;
                }
            }

            if (swap) {
                games[j + 1] = games[j];
                j--;
            } else {
                break;
            }
        }
        games[j + 1] = keyGame;
    }
}

void Trie::collectGames(TrieNode* node, std::vector<Game*>& results) {
    if (node == nullptr) return;

    if (node->isEndOfTitle && node->game != nullptr) {
        results.push_back(node->game);
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i] != nullptr) {
            collectGames(node->children[i], results);
        }
    }
}

std::vector<Game*> Trie::autocomplete(std::string prefix, int k) {
    std::vector<Game*> results;
    if (k <= 0) return results;

    std::string key = toSearchKey(prefix);
    TrieNode* current = root;

    // Navega até o final do prefixo
    for (char c : key) {
        int index = getCharIndex(c);

        if (current->children[index] == nullptr) {
            return results; // Prefixo não encontrado
        }
        current = current->children[index];
    }

    // Coleta todos os jogos na subárvore
    collectGames(current, results);

    // Ordena os resultados por popularidade (decrescente) 
    //ou ordem alfabética pela chave de busca do título, em caso de empate em popularidade.
    sortResults(results);

    if (k <= 0) return {};
    // Saída de no máximo 'k' elementos
    if (results.size() > k) { 
        results.resize(k);
    }

    return results;
}