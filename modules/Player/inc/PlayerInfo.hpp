#ifndef	PLAYERINFO_H
# define PLAYERINFO_H

// Do not change values for PlayerColor,
// it is important that they be this way
// because they are used with Flags
// inside bitmasks and other values are
// probably already used
enum PlayerColor
  {
    NONE	= 0,
    WHITE	= 1,
    BLACK	= 2,
    ERROR,
    END
  };

enum class PlayerType : char
  {
    NONE,
    HUMAN,
    AI
  };

#endif /* PLAYERINFO_H */
