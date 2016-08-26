/* Copyright 2016 Ghabriel Nunes, Marleson Graf
   <ghabriel.nunes@gmail.com>, <aszdrick@gmail.com> */

#ifndef GOMOKU_BOT_HPP
#define GOMOKU_BOT_HPP

#include "Bot.hpp"
#include "GomokuState.hpp"
#include <memory>

class GomokuBot : public Bot<GomokuState> {
 public:
    GomokuBot();
    std::unique_ptr<Command<GomokuState>> play(const GomokuState&) override;

 private:
    MiniMaxTree<GomokuState> decisionTree;
};

#endif /* GOMOKU_BOT_HPP */
