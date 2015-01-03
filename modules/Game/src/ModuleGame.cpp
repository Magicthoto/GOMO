#include <functional>
#include <iostream>

#include "ModuleGame.hpp"
#include "Human.hpp"

#include <iostream>

ModuleGame::ModuleGame(void) :
  _printer(_goban),
  _black(nullptr),
  _white(nullptr)
{
}

void      ModuleGame::initPlayer(PlayerType black, PlayerType white) {
  std::function<APlayer *(PlayerColor)> playerFactory[] =
    {
      [](PlayerColor c){ return new Human(c); },
      [](PlayerColor c){ return new Human(c); } // replace with AI
    };

  _black.reset(playerFactory[static_cast<unsigned>(black) - 1](PlayerColor::BLACK));
  _white.reset(playerFactory[static_cast<unsigned>(white) - 1](PlayerColor::WHITE));
}

PlayerColor	ModuleGame::run(unsigned int x, unsigned int y, bool player)
{
  APlayer *currentPlayer = nullptr;
  if (player == false) {
    currentPlayer = _black.get();
  } else {
    currentPlayer = _white.get();
  }

  if (not _goban.isGameOver()) {
    //move = currentPlayer->getMove();
      if (not _goban.setStone(currentPlayer->getColor(), x, y)) {
        _printer.printIllegalMove();
        return PlayerColor::ERROR;
      }
      _printer.print();
      return (PlayerColor::WHITE);
      //currentPlayer = (currentPlayer == _black.get() ? _white.get() : _black.get());
    }
  return (PlayerColor::END);
  // else {
  //    _printer.printVictory(_goban.isGameOver());
  //     return (PlayerColor::END);
//  }
  // APlayer *currentPlayer = nullptr;
  // if (player == false) {
  //   currentPlayer = _black.get();
  // }
  // else {
  //   currentPlayer = _white.get();
  // }
  // if (not _goban.isGameOver()) {
  //   if (not _goban.setStone(currentPlayer->getColor(), x, y)) {
  //      _printer.printIllegalMove();
  //     return PlayerColor::ERROR;
  //   }
  //   currentPlayer = (currentPlayer == _black.get() ? _white.get() : _black.get());
  // }
  // else
  //   return (PlayerColor::END);
  // return _goban.isGameOver();
}

unsigned int *ModuleGame::getIndex()
{
  //return (_goban.getIdx());
}
