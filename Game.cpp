#include "GamesDatabase.hpp"

Game games[] = {
    Game("Hades", "Roguelike de acao baseado na mitologia grega", 95),
    Game("Hollow Knight", "Metroidvania de exploracao e combate", 90),
    Game("Halo", "FPS futurista com campanha e multiplayer", 85),
    Game("Half Life", "FPS classico de ficcao cientifica", 92),
    Game("Harvest Moon", "Jogo de fazenda e simulacao", 70),
    Game("Stardew Valley", "Jogo de fazenda, exploracao e relacionamentos", 88),
    Game("Portal 2", "Jogo de puzzle em primeira pessoa", 91),
    Game("Team Fortress 2", "FPS em equipes com classes diferentes", 86),
    Game("Civilization 6", "Jogo de estrategia baseado em turnos", 89),
    Game("Resident Evil 4", "Jogo de acao e survival horror", 93)
};

int numberOfGames = sizeof(games) / sizeof(games[0]);