#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:
    class Node {
    public:
        Node(int data) : data_(data) {}
        int data_;
        vector<int> adjacent;
    };
    Graph(int size) {
        for(int i=0; i<size; i++) {
            nodes.push_back(Node(i));
        }
    }
    void addEdge(int i1, int i2) {
        Node& n1 = nodes[i1];
        Node& n2 = nodes[i2];

        n1.adjacent.push_back(i2);
        n2.adjacent.push_back(i1);
    }

    vector<Node> nodes;
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
