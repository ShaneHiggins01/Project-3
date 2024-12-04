struct Node {
    Star* star;
    Node* left, * right;

    Node(Star* data) {
        star = data;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
public:
    BinaryTree();
    bool SameFloat(float, float);
    Node* BreathFirstSearch(Node*, float);
    Node* DepthFirstSearch(Node*, float);
    //TODO functions
    //void insert();
};
