#include <string>

using namespace std;

class TreeNode
{
public:
    string value;
    unsigned count;
    TreeNode *left;
    TreeNode *right;

    TreeNode(string &value = string(""), unsigned count = 1, TreeNode *left = nullptr, TreeNode *right = nullptr) : value(value), count(count), left(left), right(right), use(new unsigned(1)) {}

    TreeNode(TreeNode &node) : left(node.left), right(node.right), value(node.value), count(node.count)
    {
        *node.use++;
        use = node.use;
    }

    TreeNode &operator=(TreeNode &node)
    {
        *node.use++;

        if (--*use == 0)
        {
            delete left;
            delete right;
            delete use;
        }

        use = node.use;
        value = node.value;
        count = node.count;
        left = node.left;
        right = node.right;
        return *this;
    }

    ~TreeNode()
    {
        if (--*use == 0)
        {
            delete left;
            delete right;
            delete use;
        }
    }

private:
    unsigned *use;
};