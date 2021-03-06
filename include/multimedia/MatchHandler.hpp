/* Copyright 2016 Ghabriel Nunes <ghabriel.nunes@gmail.com>
                  Marleson Graf <aszdrick@gmail.com> */

#ifndef GOMOKU_MATCH_HANDLER_HPP
#define GOMOKU_MATCH_HANDLER_HPP

#include "gomoku/Match.hpp"

class Match::Handler : public InputComponent {
 private:
    struct Pixel;
    Product doUpdate(Agent&, Element&) override;
    go::Position pixelToPosition(const Pixel&);
};

struct Match::Handler::Pixel {
    float x;
    float y;
};

#endif /* GOMOKU_MATCH_HANDLER_HPP */