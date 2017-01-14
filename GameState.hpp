#ifndef _GAMESTATE_H
#define _GAMESTATE_H

class GameState{
public:
    enum G_States{
        INIT,
        LOAD,
        MENU,
        GAME,
        EXIT
    };

    GameState();
    GameState(G_States state);

    G_States getCurrentState(void){ return m_currentState; }
    void setCurrentState(G_States state) { m_currentState = state; }

private:
    G_States m_currentState;

};

#endif
