#include "solution.h"
#include <iostream>

bool Solution::isValid(const std::vector<std::vector<int>>& sudoku, int row, int col, int value)
{
  int row_index, col_index;
  //Check row
  for(col_index = 0; col_index < 9; ++col_index)
    if(value == sudoku[row][col_index])
      return false;

  //Check column
  for(row_index = 0; row_index < 9; ++row_index)
    if(value == sudoku[row_index][col])
      return false;

  //Check perimeter
  int row_l = row / 3 * 3;
  int row_h = row_l + 3;
  
  int col_l = col / 3 * 3;
  int col_h = col_l + 3;

  for(row_index = row_l; row_index < row_h; ++row_index)
    for(col_index = col_l; col_index < col_h; ++col_index)
      if(value == sudoku[row_index][col_index])
	return false;

  return true;
}

void Solution::detectBlank(const std::vector<std::vector<int>>& sudoku)
{
  int row = 0;
  int col = 0;
  for(row = 0; row < 9; ++row)
    for(col = 0; col < 9; ++col)
      if(sudoku[row][col] == 0)
	_blank_tab.push_back(std::make_pair(row, col));

  _it_blank_tab = _blank_tab.begin();
}

bool Solution::solve(std::vector<std::vector<int>>& sudoku)
{
  //Mo more blanks, terminate recursion
  if(_it_blank_tab == _blank_tab.end())
    return true;

  int row = _it_blank_tab->first;
  int col = _it_blank_tab->second;
  //Try all possible values
  for(int value = 1; value < 10; ++value)
    //Valid value
    if(isValid(sudoku, row, col, value))
      {
	sudoku[row][col] = value;
	++_it_blank_tab;
	if(solve(sudoku))
	  return true;
      }

  sudoku[row][col] = 0;
  --_it_blank_tab;
  return false;
}

void Solution::show(std::vector<std::vector<int>>& sudoku)
{
  for(int row = 0; row < 9; ++row)
    {
      for(int col = 0; col < 9; ++col)
	std::cout << sudoku[row][col] << " ";
      std::cout << std::endl;
    }
  std::cout << std::endl;
}

