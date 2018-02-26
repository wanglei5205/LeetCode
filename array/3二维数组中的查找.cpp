#include <iostream>
#include <vector>

using namespace std;

// �����Ͻ�Ԫ�رȽ�
bool right_corner_find(int target, vector<vector<int>> vec) {

	// �ж��Ƿ�Ϊ��vector
	if (!vec.empty()) {

		// ��ά������ȡ���д�С
		int rows = vec.size();
		int cols = vec[0].size();

		// 
		if (rows!=0 && cols!=0) {
			// ���Ͻ�Ԫ������
			int corner_row = 0;
			int corner_col = cols - 1;

			while ((corner_row < rows) && (corner_col >= 0)) {
				if (target < vec[corner_row][corner_col])
					corner_col = corner_col - 1;
				else if (target > vec[corner_row][corner_col])
					corner_row = corner_row + 1;
				else
					return true;
			}
		}
	}
	return false;
}

// �����Ͻ�Ԫ�رȽ�
bool left_corner_find(int target, vector<vector<int>> vec) {
	if (!vec.empty()) {
		int rows = vec.size();
		int cols = vec[0].size();
		if ((rows > 0) && (cols > 0)) {
			int corner_row = rows - 1;
			int corner_col = 0;
			while ((corner_row >= 0) && (corner_col < cols)) {
				if (target > vec[corner_row][corner_col])
					corner_col = corner_col + 1;
				else if (target < vec[corner_row][corner_col])
					corner_row = corner_row - 1;
				else
					return true;
			}
		}
	}
	return false;
}

int main() {
	int target;
	cin >> target;
	vector<vector<int>> vec = { { 1, 2, 8, 9 },
								{ 2, 4, 9, 12 },
								{ 4, 7, 10, 13 }, 
								{ 6, 8, 11, 15 } };
	cout << right_corner_find(target, vec) << endl;
	cout << left_corner_find(target, vec) << endl;
	system("pause");
	return 0;
}