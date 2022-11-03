#include "nonogram.hpp"

Nonogram::Nonogram() : h_{5}, w_{5}, cells_(std::vector<cellVal>(h_*w_, cellVal::UNKNOWN)) {
}

Nonogram::Nonogram(int h, int w): h_{h}, w_{w}, cells_(std::vector<cellVal>(h_*w_, cellVal::UNKNOWN))
{
}

cellVal Nonogram::getCell(int row, int col) {
    return cells_[row*w_ + col];
}

void Nonogram::setCell(int row, int col, cellVal new_val) {
    cells_[row*w_ + col] = new_val;
}

void Nonogram::flipCell(int row, int col) {
    cells_[row*w_+col] = (cellVal)((cells_[row*w_+col]+1)%2);
}

void Nonogram::randomizeCells() {
    for (int i = 0; i < cells_.size(); ++i) {
        cells_[i] = ( rand() % 2 == 0 ) ? cellVal::UNFILLED : cellVal::FILLED;
    }
}