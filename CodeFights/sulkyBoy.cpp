// Little boy's mother didn't buy him a candy, so now he's sulky and moody. He turns everything you say upside down!
// If you say that something is true, he'll say it's false, and vice versa.
// Find out what the boy will say about the statement you're about to make.
// Example
// * For statement = false, the output should be
// sulkyBoy(statement) = true;
// * For statement = true, the output should be
// sulkyBoy(statement) = false

bool sulkyBoy(bool statement) {
  bool boys_statement = statement;
  return !boys_statement;
}
