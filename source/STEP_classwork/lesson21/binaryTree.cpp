#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node<T> *left;
    Node<T> *right;

    Node() : left(nullptr), right(nullptr), data() {}
    Node(const T &data) : left(nullptr), right(nullptr), data(data) {}
};

template <class T>
class BinaryTree
{
private:
    Node<T> *root;
    int size;
    void pusher(Node<T> *&node, const T &value)
    {
        if (node == nullptr)
        {
            node = new Node<T>(value);
            size++;
        }
        else if (value != node->data)
        {
            value < node->data ? pusher(node->left, value) : pusher(node->right, value);
        }
    }

    const T &finder(Node<T> *node, const T &value)
    {
        if (value == node->data)
        {
            return node->data;
        }
        else if (value != node->data)
        {
            value < node->data ? finder(node->left, value) : finder(node->right, value);
        }
    }

    void show(Node<T> *node)
    {
        int count = 0;
        for (auto i = node; i->left != nullptr; ++i)
        {
            count++;
        }

        if (node->left != nullptr && node->right != nullptr)
        {
            cout << node->left->data << " " << node->right->data << endl;
        }
        else if (node->left != nullptr && node->right == nullptr)
        {
            cout << node->left->data << " "
                 << "null" << endl;
        }
        else if (node->left == nullptr && node->right != nullptr)
        {
            cout << "null"
                 << " "
                 << node->right->data << endl;
        }
        else
        {
            show(node);
        }
    }

public:
    BinaryTree() : root(nullptr), size() {}
    BinaryTree(const BinaryTree<T> &bt) {}
    BinaryTree(BinaryTree<T> &&bt) {}
    ~BinaryTree() {}

    void operator=(const BinaryTree<T> &bt) {}
    void operator=(BinaryTree<T> &&bt) {}

    void push(const T &value)
    {
        pusher(root, value);
    }

    const T &find(const T &value)
    {
        return finder(root, value);
    }

    void showSorted() const {}

    void showAsTree() const
    {
        if (root != nullptr)
        {
            int size = 1;
            bool run = true;
            vector<Node<T> *> cur_nodes;
            vector<Node<T> *> next_nodes;
            cur_nodes.resize(size);
            cur_nodes[0] = root;

            while (run)
            {
                for (int i = 0; i < cur_nodes.size(); i++)
                {
                    if (cur_nodes[i] != nullptr)
                    {
                        cout << cur_nodes->data << endl;
                    }
                    else
                    {
                        cout << "null" << endl;
                    }

                    size *= 2;
                    next_nodes.resize(size);
                    for (itn i = 0, j = 0; i < cur_nodes.size(); i++)
                    {
                        if (cur_nodes[i] != nullptr)
                        {
                            if (cur_nodes[i]->left != nullptr)
                            {
                                next_nodes[j++] = cur_nodes[i]->left;
                            }
                            else
                            {
                                next_nodes[j++] = nullptr;
                            }


                        }

                        if (cur_nodes[i])
                    }
                }
            }
        }
    }

    int treeSize()
    {
        return size;
    }
};

int main()
{
    BinaryTree<int> tree;

    tree.push(50);
    tree.push(69);
    tree.push(27);
    tree.push(420);

    //tree.showAsTree();

    cout << tree.find(69) << endl;

    tree.showAsTree();
}