/* 矩阵中的路径*/
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(matrix == NULL || rows<1 || cols<1|| str == NULL)// 边界条件
            return false;

        bool *visited = new bool[rows*cols];               // 创建路径数组
        memset(visited,0,rows*cols);                       // 清空路径数组

        int pathLength = 0;                                // 字符串下标
        int row = 0;                                       // 矩阵下标
        int col = 0;                                       // 矩阵下标
        for(int row=0;row<rows;++row)                      // 遍历矩阵
            for(int col=0;col<cols;++col){
                if(hasPathCore(matrix,rows,cols,row,col,str,pathLength,visited)){
                    return true;
                }
            }

        delete[] visited;                                  // 销毁路径数组

        return false;
    }

private:
    // 递归实现回朔法
    bool hasPathCore(char* matrix,int rows,int cols,int row,int col,
                     char* str,int &pathLength,bool* visited){

        // 矩阵存在字符串路径（递归出口）
        if(str[pathLength] == '\0')
            return true;

        bool hasPath = false;
        if(row >= 0 && row < rows && col >= 0 && col < cols
           && matrix[row*cols+col] == str[pathLength] && !visited[row*cols+col])
        {
            ++pathLength;                 // 矩阵中找到元素str[pathLength]，应该找元素str[pathLength+1]
            visited[row*cols+col] = true; // 路径矩阵做标记

            // 查找矩阵坐标(row，col)上下左右是否存在与str[pathLength+1]相同的元素
            hasPath = hasPathCore(matrix, rows, cols, row-1, col, str, pathLength, visited)
                || hasPathCore(matrix, rows, cols, row+1, col, str, pathLength, visited)
                || hasPathCore(matrix, rows, cols, row, col-1, str, pathLength, visited)
                || hasPathCore(matrix, rows, cols, row, col+1, str, pathLength, visited);

            // 矩阵坐标(row，col)上下左右不存在与str[pathLength+1]相同的元素
            if(!hasPath){
                --pathLength;                 // 条件不符合，还原为str[pathLength]
                visited[row*cols+col] = false;// 条件不符合，标记数组标记row*cols+col为未被标记
            }
        }
        return hasPath;
    }
};
