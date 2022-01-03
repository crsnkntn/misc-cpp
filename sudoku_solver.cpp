// make this into a 3d sudoku solver, lol

#include <iostream>
#include <fstream>
#include <vector>

class Sudoku{
    private:
    std::vector<std::vector<int>> grid;
    std::vector<std::vector<int>> solution;
    public:
        Sudoku(){}

        Sudoku(std::vector<std::vector<int>> sudoku){
            grid = sudoku;
            solution = grid;
        }

        bool is_valid(int x, int y, int val){
            return check_col(y, val) && check_row(x, val) && check_block(x, y, val);
        }

        void solve(){
            for(int i = 0; i < 9; ++i){
                for(int j = 0; j < 9; ++j){
                    if(grid[i][j] == 0){
                        for(int k = 1; k < 10; ++k){
                            if(is_valid(i, j, k)){
                                std::cout << i << ", " << j << " || " << k << std::endl;
                                grid[i][j] = k;
                                solve();
                                grid[i][j] = 0;
                            }
                        }
                        return;
                    }
                }
            }
            for(int i = 0; i < 9; ++i){
                for(int j = 0; j < 9; ++j){
                    solution[i][j] = grid[i][j];
                }
            }
        }

        bool check_row(int y, int val){
            for(int i = 0; i < 9; ++i){
                int j = grid[y][i];
                if(j == val){
                    return false;
                }
            }
            return true;
        }

        bool check_col(int x, int val){
            for(int i = 0; i < 9; ++i){
                int j = grid[i][x];
                if(j == val){
                    return false;
                }
            }
            return true;
        }

        bool check_block(int x, int y, int val){
            int vert_left_bound, vert_right_bound, horz_left_bound, horz_right_bound;
            if(x < 3){
                vert_left_bound = 0;
                vert_right_bound = 2;
            }
            else if(x > 2 && x < 6){
                vert_left_bound = 3;
                vert_right_bound = 5;
            }
            else if(x > 5){
                vert_left_bound = 6;
                vert_right_bound = 8;
            }
            
            if(y < 3){
                horz_left_bound = 0;
                horz_right_bound = 2;
            }
            else if(y > 2 && y < 6){
                horz_left_bound = 3;
                horz_right_bound = 5;
            }
            else if(y > 5){
                horz_left_bound = 6;
                horz_right_bound = 8;
            }
            
            //check the block
            for(int i = vert_left_bound; i <= vert_right_bound; ++i){
                for(int j = horz_left_bound; j <= horz_right_bound; ++j){
                    int num = grid[i][j];
                    if(num == val){
                        return false;
                    }
                }
            }
            return true;
        }
    
void print(){
        for(int i = 0; i < solution.size(); ++i){
            for(int j = 0; j < solution.size(); ++j){
                std::cout << solution[i][j] << " ";
            }
            std::cout << "\n";
        }
}
};



int main(){
    std::vector<std::vector<int>> grid = {{0, 0, 0, 8, 0, 0, 1, 0, 4},
                                {0, 2, 0, 0, 0, 4, 8, 0, 7},
                                {8, 0, 7, 0, 0, 0, 9, 5, 3},
                                {0, 5, 0, 0, 6, 0, 0, 4, 1},
                                {0, 0, 0, 4, 0, 1, 0, 0, 0},
                                {4, 7, 0, 0, 2, 0, 0, 9, 0},
                                {3, 1, 2, 0, 0, 0, 5, 0, 8},
                                {6, 0, 4, 7, 0, 0, 0, 1, 0},
                                {7, 0, 5, 0, 0, 2, 0, 0, 0}};
    Sudoku s(grid);
    s.solve();
    s.print();
}
