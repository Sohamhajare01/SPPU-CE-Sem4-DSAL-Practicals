#include <iostream>
#include <cstring>
using namespace std;

class Node
{
private:
    char *name;
    Node **children;
    int numChildren;
    int capacity;

public:
    Node(const char *nodeName) : numChildren(0), capacity(2)
    {
        name = new char[strlen(nodeName) + 1];
        strcpy(name, nodeName);
        children = new Node *[capacity];
    }

    ~Node()
    {
        delete[] name;
        delete[] children;
    }

    void addChild(Node *child)
    {
        if (numChildren == capacity)
        {
            capacity *= 2;
            Node **newChildren = new Node *[capacity];
            memcpy(newChildren, children, numChildren * sizeof(Node *));
            delete[] children;
            children = newChildren;
        }
        children[numChildren++] = child;
    }

    const char *getName() const
    {
        return name;
    }

    Node **getChildren() const
    {
        return children;
    }

    int getNumChildren() const
    {
        return numChildren;
    }
};

void printNodes(const Node *node, int depth = 0)
{
    if (node == nullptr)
    {
        return;
    }

    for (int i = 0; i < depth; ++i)
    {
        cout << "  ";
    }
    cout << "- " << node->getName() << std::endl;

    for (int i = 0; i < node->getNumChildren(); ++i)
    {
        printNodes(node->getChildren()[i], depth + 1);
    }
}

int main()
{
    Node *book = new Node("Book");

    Node *chapter1 = new Node("Chapter 1");
    Node *chapter2 = new Node("Chapter 2");
    book->addChild(chapter1);
    book->addChild(chapter2);

    Node *section1_1 = new Node("Section 1.1");
    Node *section1_2 = new Node("Section 1.2");
    chapter1->addChild(section1_1);
    chapter1->addChild(section1_2);

    Node *subsection1_1_1 = new Node("Subsection 1.1.1");
    Node *subsection1_1_2 = new Node("Subsection 1.1.2");
    section1_1->addChild(subsection1_1_1);
    section1_1->addChild(subsection1_1_2);

    Node *subsection1_2_1 = new Node("Subsection 1.2.1");
    section1_2->addChild(subsection1_2_1);

    std::cout << "Book Structure:" << std::endl;
    printNodes(book);

    delete book;

    return 0;
}