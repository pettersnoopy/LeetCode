//
//  main.cpp
//  WordSearch
//
//  Created by pettersnoopy on 14-12-12.
//  Copyright (c) 2014年 ZheJiang University Luop. All rights reserved.
//

//    Given a 2D board and a word, find if the word exists in the grid.
//
//    The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
//
//    For example,
//    Given board =
//
//    [
//     ["ABCE"],
//     ["SFCS"],
//     ["ADEE"]
//     ]
//    word = "ABCCED", -> returns true,
//    word = "SEE", -> returns true,
//    word = "ABCB", -> returns false.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int px[4] = {1, -1, 0, 0};
    int py[4] = {0, 0, 1, -1};
    bool DFS(int x, int y, vector<vector<char>> &board, string word, int ith) {
        if (board[x][y] != word[ith]) {
            return false;
        }
        if (ith == word.length() - 1) {
            return true;
        }
        board[x][y] = '.';
        for (int i = 0; i < 4; ++i) {
            int nx = x + px[i];
            int ny = y + py[i];
            if (nx > 0 && ny > 0 && nx < board.size() && ny < board.size()) {
                if (DFS(nx, ny, board, word, ith + 1)) {
                    board[x][y] = word[ith];
                    return true;
                }
            }
        }
        board[x][y] = word[ith];
        return false;
    }
    
    bool exist(vector<vector<char> > &board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (DFS(i, j, board, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

