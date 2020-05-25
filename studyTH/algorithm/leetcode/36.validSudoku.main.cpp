class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool check_col[9][9] = {false,};
        bool check_row[9][9] = {false,};
        bool check_3[9][9] = {false,};
        bool ret = true;
        
        // Column 조사
        for (int i = 0; i < 9 ; i++)
        {
            for (int j=0; j< 9 ; j++)
            {
                if (board[i][j] == '.')
                    continue;
                int temp = board[i][j] - '0'-1;
                
                if (check_col[i][temp])
                    return false;
                else
                    check_col[i][temp] = true;
            }          
        }
        
        // Row 조사
        for (int j = 0; j < 9 ; j++)
        {
            for (int i=0; i< 9 ; i++)
            {
                if (board[i][j] == '.')
                    continue;
                int temp = board[i][j] - '0'-1;
                
                if (check_row[temp][j])
                    return false;
                else
                    check_row[temp][j] = true;
            }          
        }
        
        // 3*3 조사: for문 3개 이상 돌려야 함. 
        // 3*3매트릭스가 9개 있고, 각각의 i, j 인덱스에 특정 value를 더해주는 방식
        
        return ret;
    }
};