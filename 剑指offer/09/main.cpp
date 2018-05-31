/* 09 用两个栈实现队列的插入和删除*/
#include <iostream>
#include <stack>
using namespace std;

class Solution
{
    public:
        void push(int node)
        {
            stack1.push(node);
        }

        int pop()
        {
            if(stack2.empty())
            {
                while(!stack1.empty())
                {
                    stack2.push(stack1.top());
                    stack1.pop();
                }
            }

            int temp = stack2.top();
            stack2.pop();
            return temp;
        }

    private:
        stack<int> stack1;
        stack<int> stack2;
};

int main()
{
    Solution solution;
    solution.push(3);
    solution.pop();
    stack<int>stack1;
    cout<<stack1.top()<<endl;
    return 0;
}
