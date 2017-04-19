bool checkIncreasingSequence(std::vector<int> seq) {
  for(int i=1;i<seq.size();i++)
    if(seq[i]-seq[i-1]<=0)
      return false;
  return true;
}
