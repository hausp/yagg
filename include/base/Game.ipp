/* Copyright 2016 Ghabriel Nunes, Marleson Graf
   <ghabriel.nunes@gmail.com>, <aszdrick@gmail.com> */

#include "GameState.hpp"

template <typename R, typename E>
Game<R,E>::Game(State* const initial)
 : current(*initial), _closed(false) {
    states.emplace_front(std::move(initial));
}

template <typename R, typename E>
void Game<R,E>::close() {
    _closed = true;
}
template <typename R, typename E>
bool Game<R,E>::closed() {
    return _closed;
}

template <typename R, typename E>
typename Game<R,E>::State& Game<R,E>::currentState() {
    return states.front();
}

template <typename R, typename E>
void Game<R,E>::updateRenderer(R& renderer) {
    current.updateRenderer(renderer);
    updateGraphics(renderer);
}

template <typename R, typename E>
void Game<R,E>::processEvents(E& provider) {
    current.processEvents(provider);
    processInput(provider);
}

template <typename R, typename E>
void Game<R,E>::updateLogic() {
    current.updateLogic();
    update();
}

template <typename R, typename E>
void Game<R,E>::pushState(State* const state) {
    states.emplace_front(std::move(state));
}

template <typename R, typename E>
void Game<R,E>::popState() {
    states.pop_front();
}