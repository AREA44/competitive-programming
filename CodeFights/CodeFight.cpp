// Given a positive integer n, output the string representation of all the numbers from 1 to n inclusive while replacing multiples of 5 with Code, multiples of 7 with Fight and multiples of both 5 and 7 with CodeFight.
// Example
// For n = 15, the output should be
// CodeFight(n) = 
// [
//     "1",
//     "2",
//     "3",
//     "4",
//     "Code",
//     "6",
//     "Fight",
//     "8",
//     "9",
//     "Code",
//     "11",
//     "12",
//     "13",
//     "Fight",
//     "Code"
// ]

std::vector<std::string> CodeFight(int n) {
    std::vector<std::string> res;
    for(int i=1; i<=n; i++){
        if(i%35==0)
            res.push_back("CodeFight");
        else if(i%5==0)
            res.push_back("Code");
        else if(i%7==0)
            res.push_back("Fight");
        else
            res.push_back(std::to_string(i));
    }
    return res;
}
