#pragma once

#include <vector>

enum cellVal {UNKNOWN=-1, UNFILLED=0, FILLED=1};

class Nonogram {
  public:
    Nonogram();
    Nonogram(int h, int w);
    const int getHeight() { return h_; };
    const int getWidth() { return w_; };
    const int getSize() { return cells_.size(); };
    const std::vector<cellVal> getCells() { return cells_; };
    cellVal getCell(int row, int col);
    void randomizeCells();
    void flipCell(int row, int col);
    void flipCell(int idx);
    void setCell(int row, int col, cellVal new_val);
    std::vector<cellVal> getFrontHalf();
    void replaceFrontHalf(std::vector<cellVal> new_half);
    std::vector<cellVal> getBackHalf();
    void replaceBackHalf(std::vector<cellVal> back_half);
    void mutateRandomCell(); 

  private:
    const int h_; // height
    const int w_; // width
    std::vector<cellVal> cells_;
};