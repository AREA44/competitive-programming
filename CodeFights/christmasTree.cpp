// It's Christmas time! To share his Christmas spirit with all his friends, young Christmas elf decided to send each of them a Christmas e-mail with a nice Christmas tree.
// Unfortunately, Internet traffic is very expensive in the North Pole, so instead of sending an actual image he decided to draw the tree using only asterisks ('*' symbols). He has given you the specs (see below) and your task is to write a program that would generate trees following the spec and some initial parameters.
// Here is a formal definition of how the tree should be built but before you read it the elf HIGHLY recommends looking first at the examples that follow:

// 1. Each tree has a crown, that looks as follows:
//  *
//  *
// ***

// 2. Define a line as a horizontal group of asterisks and a level as a collection of levelHeight lines stacked one on top of the other.

// 3. Below the crown there are levelNum levels.

// 4. The tree is perfectly symmetric so all the middle asterisks of the lines lie on the center of the tree.

// 5. Each line of the same level (excluding the first one) has two more asterisks than the previous one (one on each end);

// 6. The number of asterisks in the first line of each level is chosen as follows:
//   6.1. the first line of the first level has 5 asterisks;
//   6.2. the first line of each consecutive level contains two more asterisks than the first line of the previous level.

// 7. And finally there is the tree foot which has a height of levelNum and a width of:
//   7.1. levelHeight asterisks if levelHeight is odd;
//   7.2. levelHeight + 1 asterisks if levelHeight is even.
// Given levelNum and levelHeight, return the Christmas tree of the young elf.

// Example
// * For levelNum = 1 and levelHeight = 3, the output should be
// christmasTree(levelNum, levelHeight) =
//     ["    *",
//      "    *",
//      "   ***",
//      "  *****",
//      " *******",
//      "*********",
//      "   ***"]
// , which represents the following tree:

//             ___
//       *        |
//       *        |-- the crown      
//      ***    ___|       
//     *****      |
//    *******     |-- level 1
//   ********* ___|
//      ***    ___|-- the foot

// * For levelNum = 2 and levelHeight = 4, the output should be
// christmasTree(levelNum, levelHeight) = 
//     ["      *", 
//      "      *", 
//      "     ***", 
//      "    *****", 
//      "   *******", 
//      "  *********", 
//      " ***********", 
//      "   *******", 
//      "  *********", 
//      " ***********", 
//      "*************", 
//      "    *****", 
//      "    *****"]
// , which represents the following tree:

//                 ___ 
//         *          |
//         *          | -- the crown
//        ***      ___|
//       *****        |
//      *******       | -- level 1
//     *********      |
//    ***********  ___|
//      *******       |
//     *********      | -- level 2
//    ***********     |
//   ************* ___|
//       *****        | -- the foot
//       *****     ___|

std::vector<std::string> christmasTree(int levelNum, int levelHeight) {
  struct Helper {
    std::string makeLine(int spaces, int asterisks) {
      return std::string(spaces, ' ') + std::string(asterisks, '*');
    }
  };

  Helper h;
  int maxSpaces = levelNum + levelHeight;
  int indent = levelHeight - 2;
  std::vector<std::string> res = {h.makeLine(maxSpaces, 1),
                                  h.makeLine(maxSpaces, 1),
                                  h.makeLine(maxSpaces - 1, 3)};

  int curSpaces = maxSpaces - 1;
  int curAsterisks = 3;

  for (int i = 0; i < levelNum; i++) {
    if (i == 0) {
      curAsterisks += 2;
      curSpaces--;
    } else {
      curAsterisks -= indent * 2;
      curSpaces += indent;
    }
    res.push_back(h.makeLine(curSpaces, curAsterisks));

    for (int j = 0; j < levelHeight - 1; j++) {
      curAsterisks += 2;
      curSpaces--;
      res.push_back(h.makeLine(curSpaces, curAsterisks));
    }
  }

  curSpaces = maxSpaces - levelHeight / 2;
  curAsterisks = levelHeight + 1 - levelHeight % 2;
  for (int i = 0; i < levelNum; i++) {
    res.push_back(h.makeLine(curSpaces, curAsterisks));
  }

  return res;
}

