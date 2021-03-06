/* Copyright 2016 Ghabriel Nunes <ghabriel.nunes@gmail.com>
                  Marleson Graf <aszdrick@gmail.com> */

#include <chrono>
#include "AI/ai_utils.hpp"
#include "extra/macros.hpp"
#include "gomoku/Command.hpp"
#include "gomoku/StateGenerator.hpp"
#include "gomoku/Traits.hpp"

template<unsigned id>
RatingFunction<go::State, short> Gomoku::AIHandler<id>::heuristicFn = ai_utils::heuristic<id>;
template<unsigned id>
RatingFunction<go::State, short> Gomoku::AIHandler<id>::utilityFn = ai_utils::utility<id>;

template<unsigned id>
Gomoku::AIHandler<id>::AIHandler()
 : decisionTree(heuristicFn, utilityFn) {

}

template<unsigned id>
typename Gomoku::AIHandler<id>::Product
Gomoku::AIHandler<id>::doUpdate(Agent& board, Element& events) {
    auto analysis = decisionTree.analyze<StateGenerator>(board, board.currentPlayer());
    analysis.move.setIterations(analysis.iterations);
    return analysis.move;
}
