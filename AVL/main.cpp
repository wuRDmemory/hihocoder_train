#include <iostream>

using namespace std;

typedef int Element;

typedef struct Node_t {
    int bf;
    Element data;
    // struct Node_t* parent;
    struct Node_t* l_child;
    struct Node_t* r_child;
}Node, *NodePtr;

NodePtr create_new_node(Element data) {
    NodePtr  T = (NodePtr)calloc(sizeof(Node), 1);
    T->bf = 0;
    T->data = data;
    T->l_child = NULL;
    T->r_child = NULL;
    return T;
}

int left_rotated(NodePtr* T) {
    NodePtr r_child = (*T)->r_child;
    (*T)->r_child = r_child->l_child;
    r_child->l_child = (*T);
    (*T) = r_child;
    return 1;
}

int right_rotated(NodePtr* T) {
    NodePtr  l_child = (*T)->l_child;
    (*T)->l_child = l_child->r_child;
    l_child->r_child = (*T);
    (*T) = l_child;
    return 1;
}


int balance_left(NodePtr* T) {
    NodePtr* l_child = &((*T)->l_child);
    switch ((*l_child)->bf) {
        case -1:  // 要平衡左树的时候，左孩子是右边沉，先左旋转左孩子再右旋转根
            {
                NodePtr lr_child = (*l_child)->r_child;
                switch (lr_child->bf) {
                    case 0:
                        (*T)->bf = 0;
                        (*l_child)->bf = 0;
                        break;
                    case 1:
                        (*T)->bf = -1;
                        (*l_child)->bf = 0;
                        break;
                    case -1:
                        (*T)->bf =0;
                        (*l_child)->bf = 1;
                        break;
                }
                left_rotated(l_child);
                right_rotated(T);
            }
            break;
        case 1:   // 要平衡左树的时候，左孩子是左边沉，那么直接对根节点右旋转
            {
                (*T)->l_child->bf = 0;
                (*T)->bf = 0;
                right_rotated(T);
            }
            break;
        case 0:   //
            {
                (*T)->bf = 0;
                (*T)->l_child->bf = -1;
                right_rotated(T);
            }
            break;
    }
    return 1;
}

int balance_right(NodePtr* T) {
    NodePtr* r_child = &((*T)->r_child);
    switch ((*r_child)->bf) {
        case 1:  // 要平衡右树的时候，右孩子是左边沉，先右旋转右孩子再左旋转根
            {
                // 修改平衡因子
                NodePtr rl_child = (*r_child)->l_child;
                switch (rl_child->bf) {
                    case 0:
                        (*T)->bf = 0;
                        (*r_child)->bf = 0;
                        break;
                    case 1:
                        (*T)->bf = 0;
                        (*r_child)->bf = -1;
                        break;
                    case -1:
                        (*T)->bf = 1;
                        (*r_child)->bf = 0;
                        break;
                }
                right_rotated(r_child);
                left_rotated(T);
            }
            break;
        case -1:   // 要平衡右树的时候，右孩子是右边沉，那么直接对根节点左旋转
            {
                // 修改平衡因子
                (*T)->bf = 0;
                (*T)->r_child->bf = 0;
                left_rotated(T);
            }
            break;
        case 0:
            {
                (*T)->bf = -1;
                (*T)->r_child->bf = 1;
                left_rotated(T);
            }
            break;
    }
    return 1;
}

// pro是为了返回给根节点让根节点改变自己的平衡银子的
int insert_node(NodePtr* T, Element data, bool& pro) {
    if (*T == NULL) {
        *T = create_new_node(data);
        pro = true;
    } else if (data == (*T)->data) {
        // 当数据等于该节点的值的时候
        pro = false;
        return 0;
    } else if (data < (*T)->data) {
        // 插入左孩子
        if (!insert_node(&((*T)->l_child), data, pro)) {
            return 0;
        }
        if (pro) {
            switch ((*T)->bf) {
                case -1:   // 根节点是右边多的，此时插入了左边的左孩子，那么就平衡了
                    (*T)->bf = 0;
                    pro = true;
                    break;
                case 0:    // 根节点是平衡的，此时插入了左孩子，那么就是左边沉了
                    (*T)->bf = 1;
                    pro = true;  // 返回给根节点让根节点进行平衡的调节
                    break;
                case 1:    // 根节点本身有左孩子，又往左孩子这边进行插入，此时要平衡左边的树
                    balance_left(T);
                    pro = false; // 这个不会影响到自己父节点的状态，因此不用矫正父节点的状态
                    break;
            }
        }
    } else {
        // 插入右孩子
        if (!insert_node(&((*T)->r_child), data, pro)) {
            return 0;
        }
        if (pro) {
            switch ((*T)->bf) {
                case 1:   // 根节点是左边多的，此时插入了左边的左孩子，那么就平衡了
                    (*T)->bf = 0;
                    pro = true;
                    break;
                case 0:    // 根节点是平衡的，此时插入了左孩子，那么就是左边沉了
                    (*T)->bf = -1;
                    pro = true;  // 返回给根节点让根节点进行平衡的调节
                    break;
                case -1:    // 根节点本身有左孩子，又往左孩子这边进行插入，此时要平衡左边的树
                    balance_right(T);
                    pro = false; // 这个不会影响到自己父节点的状态，因此不用矫正父节点的状态
                    break;
            }
        }
    }
    return 1;
}

NodePtr root = NULL;
int main() {
    std::cout << "Hello, World!" << std::endl;
    int a[]={16,10,17,8,13,11,12};
    root = create_new_node(a[0]);
    bool pro = true;
    for (int i = 1; i < 7; ++i) {
        insert_node(&root, a[i], pro);
    }

    return 0;
}