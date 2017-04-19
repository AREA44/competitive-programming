// Given the final position and score of a CodeFighter in a tournament, return the number of coins and XP they will get.
// Here is how these values can be calculated:
// + coins: 2000 * (1 / 2)position, where / is integer division;
// + XP: 2 * score if position equals 1 and score otherwise.
// Example
// * For position = 1 and score = 500, the output should be
// codefightsTournament(position, score) = [2000, 1000].

// * For position = 6 and score = 100, the output should be
// codefightsTournament(position, score) = [62, 100].

std::vector<int> codefightsTournament(int position, int score) {
    std::vector<int> result(2);
    result[0] = 2000 / pow(2, position - 1);
    (position==1) ? result[1] = 2 * score : result[1] = score;
    return result;
}
