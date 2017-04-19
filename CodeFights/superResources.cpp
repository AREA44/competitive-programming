// There is a supercomputer that has many super resources. It allows many super programs to be launched at the same time. However, each super program requires one of the super resources.
// The workflow is as follows: one day each super program sends requests for the resources it will need, and the next day the supercomputer gives a sorted list of resources allocated to the super programs. The super computer deals with requests rather straightforward: the first program to require a resource gets it.
// Given a list of requests, return a list of resources for the next day.
// No super program requests one resource more than once.
// Example
// * For requests = [["3", "game"], ["3", "web"], ["1", "web"], ["1", "game"]], the output should be
// superResources(requests) = [["1", "web"], ["3", "game"]].

typedef std::vector<std::string> elemT;
typedef std::vector<elemT> listT;
listT superResources(listT requests) {

  struct Helper {
    bool le(std::string const & a, std::string const & b) {
      return std::stoi(a) <= std::stoi(b);
    }
  };
  Helper h;

  if (requests.size() < 2) {
    return requests;
  }
  listT parts[2] = {
      listT(requests.begin(), requests.begin() + requests.size() / 2),
      listT(requests.begin() + requests.size() / 2, requests.end())
  };
  parts[0] = superResources(parts[0]);
  parts[1] = superResources(parts[1]);

  listT result;
  int idx[2] = {0, 0};
  int len[2] = {parts[0].size(), parts[1].size()};
  std::string last = "";
  while (idx[0] < len[0] || idx[1] < len[1]) {
    int k;
    if (idx[1] >= len[1] || idx[0] < len[0] &&
        h.le(parts[0][idx[0]][0], parts[1][idx[1]][0])) {
      k = 0;
    } else {
      k = 1;
    }
    elemT element = parts[k][idx[k]++];
    if (element[0] != last) {
      result.push_back(element);
      last = element[0];
    }
  }

  return result;
}
