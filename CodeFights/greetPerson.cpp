// Greet a person given their name.
// Example
// * For name = "Polly", the output should be
// greetPerson(name) = "Hello, Polly".

std::string greetPerson(std::string name) {

  std::vector<std::string> answerParts(2);
  answerParts[0] = "Hello", answerParts[1] = name;
  return answerParts[0] + ", " + answerParts[1];
}
