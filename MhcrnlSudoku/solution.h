#include <vector>
#include <utility>

class Solution
{
 public:
  bool isValid(const std::vector<std::vector<int> >& sudoku, int row, int col, int value);
  void detectBlank(const std::vector<std::vector<int> >& sudoku);
  bool solve(std::vector<std::vector<int> >& sudoku);
  void show(std::vector<std::vector<int> >& sudoku);

 private:
  std::vector<std::pair<int, int> > _blank_tab;
  decltype(_blank_tab)::iterator _it_blank_tab;
};
