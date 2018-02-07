#include "solution.h"
#include <iostream>

using namespace std;

int main(int argc, char**argv)
{
  vector<vector<int>> sudoku =
    {
      {0,0,0, 0,0,0, 7,8,0},
      {0,0,5, 0,0,0, 0,1,0},
      {0,9,4, 0,7,0, 0,3,5},
      
      {0,0,0, 8,0,4, 3,0,0},
      {0,0,6, 0,0,2, 0,5,1},
      {6,0,0, 6,5,0, 8,0,0},
      
      {5,0,0, 2,0,7, 0,0,0},
      {6,7,2, 0,9,0, 0,0,0},
      {0,0,3, 0,6,0, 0,0,0}
    };

  Solution s;
  s.detectBlank(sudoku);
  s.solve(sudoku);
  s.show(sudoku);
}
