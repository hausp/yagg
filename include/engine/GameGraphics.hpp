/* Copyright 2016 Ghabriel Nunes, Marleson Graf
   <ghabriel.nunes@gmail.com>, <aszdrick@gmail.com> */

#ifndef GAME_GRAPHICS_HPP
#define GAME_GRAPHICS_HPP

#include "base/GraphicalComponent.hpp"
#include <SFML/Graphics.hpp>

class GomokuGame;
struct Stone;

template<>
class GraphicalComponent<GomokuGame, sf::RenderWindow> {
 public:
    GraphicalComponent();

    void update(const GomokuGame&, sf::RenderWindow&);
 
 private:
    const float BOARD_SIZE = 15;
    const float SQUARE_SIZE = 48;
    const float BORDER_WIDTH = SQUARE_SIZE;
    const static sf::Color WHITE_COLOR;
    const static sf::Color BLACK_COLOR;

    void drawBoard(sf::RenderWindow&) const;
};

using GameGraphics = GraphicalComponent<GomokuGame, sf::RenderWindow>;

#endif /* GAME_GRAPHICS_HPP */