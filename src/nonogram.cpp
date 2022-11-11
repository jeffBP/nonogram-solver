#include "nonogram.hpp"

Nonogram::Nonogram() : h_{5}, w_{5}, cells_(std::vector<cellVal>(h_*w_, cellVal::UNKNOWN)) {
    init();
}

Nonogram::Nonogram(int h, int w): h_{h}, w_{w}, cells_(std::vector<cellVal>(h_*w_, cellVal::UNKNOWN))
{
    init();
}

cellVal Nonogram::getCell(int row, int col) {
    return getCell(row*w_ + col);
}

void Nonogram::setCell(int row, int col, cellVal new_val) {
    cells_[row*w_ + col] = new_val;
}

void Nonogram::flipCell(int row, int col) {
    flipCell(row*w_+col);
}

void Nonogram::flipCell(int idx) {
    cells_[idx] = (cellVal)((cells_[idx]+1)%2);
}

void Nonogram::init() {
    for (int i = 0; i < cells_.size(); ++i) {
        cells_[i] = ( rand() % 2 == 0 ) ? cellVal::UNFILLED : cellVal::FILLED;
    }
}
// Will in case of even size, will return size/2
// For odd size, will return size/2 + 1
std::vector<cellVal> Nonogram::getFrontHalf() {
    if (cells_.size()%2==0) {
        return std::vector<cellVal>(cells_.begin(), cells_.begin()+(cells_.size()/2));
    } else {
        return std::vector<cellVal>(cells_.begin(), cells_.begin()+(cells_.size()/2)+1);
    }
}

void Nonogram::replaceFrontHalf(std::vector<cellVal> new_half) {
    if (cells_.size()%2==0) {
        cells_.erase(cells_.begin(), cells_.begin()+(cells_.size()/2));
        cells_.insert(cells_.begin(), new_half.begin(), new_half.end());
    } else {
        cells_.erase(cells_.begin(), cells_.begin()+(cells_.size()/2)+1);
        cells_.insert(cells_.begin(), new_half.begin(), new_half.end());
    }
}

std::vector<cellVal> Nonogram::getBackHalf() {
    if (cells_.size()%2==0) {
        return std::vector<cellVal>(cells_.begin()+(cells_.size()/2), cells_.end());
    } else {
        return std::vector<cellVal>(cells_.begin()+(cells_.size()/2)+1, cells_.end());
    }
}

void Nonogram::replaceBackHalf(std::vector<cellVal> new_half) {
    if (cells_.size()%2==0) {
        cells_.erase(cells_.begin()+(cells_.size()/2), cells_.end());
        cells_.insert(cells_.end(), new_half.begin(), new_half.end());
    } else {
        cells_.erase(cells_.begin()+(cells_.size()/2)+1, cells_.end());
        cells_.insert(cells_.end(), new_half.begin(), new_half.end());
    }
}

int Nonogram::flipRandomCell() {
    int cell_idx = rand()%cells_.size();
    flipCell(cell_idx);
    return cell_idx;
}

std::pair<int, int> Nonogram::transposeRandomCells() {
    int cell_idx1 = rand()%cells_.size();
    int cell_idx2 = cell_idx1;
    while (cell_idx2 == cell_idx1) {
        cell_idx2 = rand()%cells_.size();
    }
    cellVal cv1 = getCell(cell_idx1);
    cells_[cell_idx1] = getCell(cell_idx2);
    cells_[cell_idx2] = cv1;
    return {cell_idx1, cell_idx2};
}

int Nonogram::insertRandomCellValAtRandomIdx() {
    cellVal cv = (cellVal)(rand()%2);
    int idx = rand()%cells_.size();
    cells_.pop_back();
    cells_.insert(cells_.begin()+idx, cv);
    return idx;
}

void Nonogram::mutate() {
    switch ( rand()%3 ) {
        case 0:
            flipRandomCell();
            break;
        case 1: 
            transposeRandomCells();
            break;
        case 2: 
            insertRandomCellValAtRandomIdx();
            break; 
    }
}