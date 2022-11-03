#include <vector>

enum cellVal {UNKNOWN=-1, UNFILLED=0, FILLED=1};

class Nonogram {
  public:
    Nonogram();
    Nonogram(int h, int w);
    const int getHeight() { return h_; };
    const int getWidth() { return w_; };
    const int getSize() { return cells_.size(); };
    cellVal getCell(int row, int col);
    void randomizeCells();
    void flipCell(int row, int col);
    void setCell(int row, int col, cellVal new_val);

  private:
    const int h_; // height
    const int w_; // width
    std::vector<cellVal> cells_;
};