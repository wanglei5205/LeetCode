/* �����е�·��*/
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(matrix == NULL || rows<1 || cols<1|| str == NULL)// �߽�����
            return false;

        bool *visited = new bool[rows*cols];               // ����·������
        memset(visited,0,rows*cols);                       // ���·������

        int pathLength = 0;                                // �ַ����±�
        int row = 0;                                       // �����±�
        int col = 0;                                       // �����±�
        for(int row=0;row<rows;++row)                      // ��������
            for(int col=0;col<cols;++col){
                if(hasPathCore(matrix,rows,cols,row,col,str,pathLength,visited)){
                    return true;
                }
            }

        delete[] visited;                                  // ����·������

        return false;
    }

private:
    // �ݹ�ʵ�ֻ�˷��
    bool hasPathCore(char* matrix,int rows,int cols,int row,int col,
                     char* str,int &pathLength,bool* visited){

        // ��������ַ���·�����ݹ���ڣ�
        if(str[pathLength] == '\0')
            return true;

        bool hasPath = false;
        if(row >= 0 && row < rows && col >= 0 && col < cols
           && matrix[row*cols+col] == str[pathLength] && !visited[row*cols+col])
        {
            ++pathLength;                 // �������ҵ�Ԫ��str[pathLength]��Ӧ����Ԫ��str[pathLength+1]
            visited[row*cols+col] = true; // ·�����������

            // ���Ҿ�������(row��col)���������Ƿ������str[pathLength+1]��ͬ��Ԫ��
            hasPath = hasPathCore(matrix, rows, cols, row-1, col, str, pathLength, visited)
                || hasPathCore(matrix, rows, cols, row+1, col, str, pathLength, visited)
                || hasPathCore(matrix, rows, cols, row, col-1, str, pathLength, visited)
                || hasPathCore(matrix, rows, cols, row, col+1, str, pathLength, visited);

            // ��������(row��col)�������Ҳ�������str[pathLength+1]��ͬ��Ԫ��
            if(!hasPath){
                --pathLength;                 // ���������ϣ���ԭΪstr[pathLength]
                visited[row*cols+col] = false;// ���������ϣ����������row*cols+colΪδ�����
            }
        }
        return hasPath;
    }
};
