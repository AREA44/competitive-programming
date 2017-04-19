// Given a position of a knight on the standard chessboard, find the number of different moves the knight can perform.
// The knight can move to a square that is two squares horizontally and one square vertically, or two squares vertically and one square horizontally away from it.
// The complete move therefore looks like the letter L.
// Check out the image below to see all valid moves for a knight piece that is placed on one of the central squares.
// https://cloud.githubusercontent.com/assets/16760489/20532138/86b74988-b10b-11e6-9f79-3bb7a819585a.png
// Example
// * For cell = "a1", the output should be
// chessKnightMoves(cell) = 2.
// https://cloud.githubusercontent.com/assets/16760489/20532162/9b24a6cc-b10b-11e6-996d-6dc27141bd78.png

// * For cell = "c2", the output should be
// chessKnightMoves(cell) = 6.
// https://cloud.githubusercontent.com/assets/16760489/20532204/ba323a16-b10b-11e6-9307-37c59dc1c004.png

bool isValid(int x, int y) {
    return x >= 0 && x <= 7 && y >= 0 && y <= 7;
}

int chessKnightMoves(std::string cell) {
      int x = cell[0] - 'a',
          y = cell[1] - '0' - 1;
      int c = 0;
      for (int dx = -2; dx <= 2; dx++){
        for (int dy = -2; dy <= 2; dy++) {
          if (abs(dx * dy) == 2)
            if (isValid(x + dx, y + dy))
              c++;
        }
      }
      return c;
}
