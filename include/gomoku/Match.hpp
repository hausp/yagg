/* Copyright 2016 Ghabriel Nunes <ghabriel.nunes@gmail.com>
                  Marleson Graf <aszdrick@gmail.com> */

#ifndef GOMOKU_MATCH_HPP
#define GOMOKU_MATCH_HPP

#include <array>
#include "base/Component.hpp"
#include "Player.hpp"
#include "State.hpp"

class Match : public mbe::Game::State {
    class Graphics;
    class Handler;
 public:
    using GraphicalComponent = base::Component<Match, Renderer>;
    using InputComponent = base::Component<Match, Input>;
    using Transition = Response::Type;

    enum class Type {
        PLAYER_VS_BOT, PLAYERS_ONLY, BOTS_ONLY
    };

 public:
    Match(Player&&, Player&&);
    
    void updatePlayers(Player::Input&);
    void restart();
    go::Team currentTeam() const;
    go::Team winnerTeam() const;
    bool over() const;
    bool hasWinner() const;
    bool full() const;
    unsigned iterations() const;

 private:
    std::unique_ptr<GraphicalComponent> graphicsPtr;
    std::unique_ptr<InputComponent> inputPtr;
    GraphicalComponent& graphics;
    InputComponent& input;

    std::array<Player,2> players;
    go::State state;
    unsigned moveIterations = 0;

    void onUpdateRenderer(Renderer&) override;
    Response onProcessInput(Input&) override;
};

#endif /* GOMOKU_MATCH_HPP */
