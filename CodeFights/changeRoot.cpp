// You are given an array parent of length N specifying a tree. The vertices of the tree are numbered from 0 to N-1 and parent[i] is the parent of the ith node. The root of the tree is its own parent (i.e. parent[i] = i if and only if i is a root).
// What will the parent array look like if the edges remain the same but tree is rooted at the vertex newRoot?
// Example
// * For parent = [0, 0, 0, 1] and newRoot = 1, the output should be
// changeRoot(parent, newRoot) = [1, 1, 0, 1].
// Check out the image below for better understanding: https://cloud.githubusercontent.com/assets/16760489/20264302/6a229198-aa9d-11e6-8399-239f67a4088c.png

typedef std::vector<int> vect;
typedef std::vector<std::vector<int>> vect2D;

vect changeRoot(vect parent, int newRoot) {

  struct Helper {
    void dfs(int cur, int prev, vect2D& graph, vect& answer) {
      answer[cur] = prev;
      for (int i = 0; i < graph[cur].size(); i++) {
        int to = graph[cur][i];
        if (to != prev) {
          dfs(to, cur, graph, answer);
        }
      }
    }
  };
  vect answer(parent.size());
  vect2D graph(parent.size());

  for (int i = 0; i < parent.size(); i++) {
    if (parent[i] != i) {
      graph[i].push_back(parent[i]);
      graph[parent[i]].push_back(i);
    }
  }

  Helper h;
  h.dfs(newRoot, newRoot, graph, answer);

  return answer;
}
