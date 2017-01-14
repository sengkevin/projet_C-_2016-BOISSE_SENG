#include "GameState.hpp"

GameState::GameState() : m_currentState(INIT){}
GameState::GameState(G_States state) : m_currentState(state){}
