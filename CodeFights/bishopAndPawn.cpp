// Given the positions of a white bishop and a black pawn on the standard chess board, determine whether the bishop can capture the pawn in one move.
// The bishop has no restrictions in distance for each move, but is limited to diagonal movement. Check out the example below to see how it can move:
// https://cloud.githubusercontent.com/assets/16760489/20531875/ad2164b0-b10a-11e6-8644-1f0275f4e14e.png
// Example
// * For bishop = "a1" and pawn = "c3", the output should be
// bishopAndPawn(bishop, pawn) = true.
// https://cloud.githubusercontent.com/assets/16760489/20531918/d74c37c4-b10a-11e6-8f63-ba02f7021dc9.png

// * For bishop = "h1" and pawn = "h3", the output should be
// bishopAndPawn(bishop, pawn) = false.
// https://cloud.githubusercontent.com/assets/16760489/20531948/e950b65c-b10a-11e6-9a8c-26a61bb1e56d.png

bool bishopAndPawn(std::string bishop, std::string pawn) {
  struct Parser {
    int getX(char pos) {
      return pos - 'a';
    }

    int getY(char pos) {
      return pos - '1';
    }
  };

  Parser myParser;
  int x1 =  myParser.getX(bishop[0]) ,
      y1 = myParser.getY(bishop[1]),
      x2 = myParser.getX(pawn[0]),
      y2 = myParser.getY(pawn[1]);

  if (x1 + y1 == x2 + y2 || x1 - y1 == x2 - y2) {
    return true;
  }

  return false;
}
