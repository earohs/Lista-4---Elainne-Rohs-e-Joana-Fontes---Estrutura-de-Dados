#include <iostream>
#include <string>
#include <vector>
#include "Trie.hpp"
#include "GamesDatabase.hpp"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Usage: ./app k prefix" << std::endl;
        return 1;
    }

    int k = std::stoi(argv[1]);

    std::string prefix = argv[2];

    Trie trie;

    //inserção dos jogos feita passando ponteiros para os objetos existentes no array games
    for (int i = 0; i < numberOfGames; i++) {
        trie.insert(&games[i]);
    }

    std::vector<Game*> results = trie.autocomplete(prefix, k);

    // Exibição dos resultados
    if (results.empty()) {
        std::cout << "No results found" << std::endl;
    } else {
        for (Game* game : results) {
            std::cout << game->getTitle() << " | " 
                      << game->getShortDescription() << " | " 
                      << game->getPopularity() << "\n" << std::endl;
        }
    }

    return 0;
}