#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;

template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode*>children;

    TreeNode(T element){
        data = element;
    }

    ~TreeNode(){
        for(int i = 0;i<children.size();i++){
            delete children[i];
        }
    }
};

void printTree(TreeNode<int> *root){
    if(root == NULL) return;
    cout<<root->data<<" : ";
    for(int i = 0;i < root->children.size();i++){
        cout<<root->children[i]->data<<", ";
    }
    cout<<endl;
    for(int i = 0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}

TreeNode<int>* takeInput(){
    int rootData;
    cout<<"Input Data"<<endl;
    cin>>rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    int n;
    cout<<"Enter num of children of "<<rootData<<endl;
    cin>>n;
    for(int i = 0;i<n;i++){
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }

    return root;
}

TreeNode<int>* takeInputRecur(){
    int data;
    cout<<"Enter root data : ";
    cin>>data;
    TreeNode<int> *root = new TreeNode<int>(data);

    cout<<endl<<"Enter num of children of "<<data<<" : ";
    int num;
    cin>>num;
    for(int i = 0;i<num;i++){
        root->children.push_back(takeInputRecur());
    }
    return root;
}

TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter Root Data"<<endl;
    cin>>rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter the num of children of "<<front->data<<" : ";
        int numChild;
        cin>>numChild;
        for(int i = 0;i<numChild;i++){
            cout<<"Enter "<<i+1<<"th children of "<<front->data<< " : ";
            int childData;
            cin>>childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

void printTreeLevelWise(TreeNode<int> *root){
    if(root==NULL) return;
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0){
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<" : ";
        for(int i = 0;i<front->children.size();i++){
            cout<<front->children[i]->data<<", ";
            pendingNodes.push(front->children[i]);
        }
        cout<<endl;
    }
}

void printTreeRecur(TreeNode<int> *root){
    if(root == NULL) return;
    cout<< root->data << " : ";
    for(int i = 0;i<root->children.size();i++){
        cout<<root->children[i]->data <<" ";
    }
    cout<<endl;
    for(int i = 0; i < root->children.size();i++){
        printTreeRecur(root->children[i]);
    }
}

int numNodes(TreeNode<int> *root){
    if(root==NULL) return 0;
    int ans = 1;
    for(int i = 0; i<root->children.size();i++){
        ans += numNodes(root->children[i]);
    }
    return ans;
}

int SumofAllNodes(TreeNode<int> *root){
    if(root == NULL) return 0;
    int sum = root->data;
    for(int i = 0;i<root->children.size();i++){
        sum += SumofAllNodes(root->children[i]);
    }
    return sum;
}

int LargestDataNodeRecur(TreeNode<int> *root){
    if(root == NULL){return -1;}
    int max = root->data;
    for(int i = 0;i<root->children.size();i++){
        if(root->children[i]->data > max){
            max = root->children[i]->data;
        }
        int x = LargestDataNodeRecur(root->children[i]);
        if(x > max){
            max = x;
        }
    }
    return max;
}

int LargestDataNode(TreeNode<int> *root){
    if(root == NULL) return -1;
    int max = root->data;
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    
    while(pendingNodes.size()!=0){
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        if(front->data > max){
            max = front->data;
        }
        for(int i = 0;i<front->children.size();i++){
            pendingNodes.push(front->children[i]);
        }
    }
    return max;
}

int treeHeight(TreeNode<int> *root){
    if(root == NULL){
        return 0;
    }
    int height = 0;
    for(int i = 0;i<root->children.size();i++){
        int x = treeHeight(root->children[i]);
        if(x>height){
            height = x;
        }
    }
    return height+1;
}

void printAtLevelK(TreeNode<int> *root, int k){
    if (root == NULL) return;
    if(k == 0) cout<<root->data<<", ";
    for(int i = 0;i<root->children.size();i++){
        printAtLevelK(root->children[i], k-1);
    }
}

int numLeaves(TreeNode<int> *root){
    if(root->children.size() == 0){
        return 1;
    }
    int leaves = 0;
    for(int i = 0;i<root->children.size();i++){
        leaves += numLeaves(root->children[i]);
    }
    return leaves;
}

void preOrder(TreeNode<int> *root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    for(int i = 0;i<root->children.size();i++){
        preOrder(root->children[i]);
    }
}

void postOrder(TreeNode<int> *root){
    if(root == NULL){return ;}
    for(int i = 0;i<root->children.size();i++){
        postOrder(root->children[i]);
    }
    cout<<root->data<<", ";
}

bool containsRecur(TreeNode<int> *root, int k){
    if(root == NULL){return false;}
    bool have = false;
    for(int i = 0;i<root->children.size();i++){
        have = have or containsRecur(root->children[i], k);
    }
    if(root->data == k){
        return true;
    }
    return have;
}

bool contains(TreeNode<int> *root, int k){
    if(root == NULL){return false;}
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0){
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        if(front->data == k){
            return true;
        }
        for(int i = 0;i<front->children.size();i++){
            pendingNodes.push(front->children[i]);
        }
    }
    return false;
}

int NodeWithMaxSum(TreeNode<int> *root){
    if(root==NULL) return -1;
    int sum = 0;

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while(not pendingNodes.empty()){
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int tempsum = front->data;
        for(int i = 0;i<front->children.size();i++){
            tempsum += front->children[i]->data;
            pendingNodes.push(front->children[i]);
        }
        if(tempsum > sum){
            sum = tempsum;
        }
    }
    return sum;
}

int NodesGreaterThanK(TreeNode<int> *root, int k){
    if(root == NULL){return -1;}
    queue<TreeNode<int>* > pendingNodes;
    pendingNodes.push(root);
    int count = 0;
    while(pendingNodes.size() != 0){
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        if(front->data > k){
            count += 1;
        }
        for(int i = 0;i<front->children.size();i++){
            pendingNodes.push(front->children[i]);
        }
    }
    return count;
}

int NodeWithMaxChildSum(TreeNode<int> *root){
    if (root == NULL){
        return 0;
    }
    int sum = 0;
    for(int i = 0;i<root->children.size();i++){
        sum += root->children[i]->data;
    }
    int maxsumNode = 0;
    for(int i = 0; i < root->children.size() ; i++){
        if(NodeWithMaxChildSum(root->children[i]) < sum){
            maxsumNode = root->children[i]->data;
        }
    }
    return maxsumNode;
}

int main(){
    // TreeNode<int> *root = new TreeNode<int>(1);
    // TreeNode<int> *root1 = new TreeNode<int>(2);
    // TreeNode<int> *root2 = new TreeNode<int>(3);
    // root->children.push_back(root1);
    // root->children.push_back(root2);

    TreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
    cout<<"Number of Nodes is : "<<numNodes(root)<<endl;
    cout<<"Sum of All Nodes is : "<<SumofAllNodes(root)<<endl;
    cout<<"lagest of All Nodes is : "<<LargestDataNode(root)<<endl;
    cout<<"values at level "<<2<<" are "; printAtLevelK(root, 0); cout<<endl;
    cout<<"Number of leaves are "<<numLeaves(root)<<endl;
    preOrder(root); cout<<endl;
    postOrder(root); cout<<endl;
    cout<<"The tree contains "<<"6 ? "<<contains(root, 0)<<endl;
    cout<<"Maximum sum of a Node in the tree is "<<NodeWithMaxSum(root)<<endl;
    cout<<"Node With Max children sum in the tree is "<<NodeWithMaxChildSum(root)<<endl;
    delete root;  // root will not be deleted before its destructor completely runs
    return 0;
}

// int main(){
    // TreeNode<int> *root = takeInputLevelWise();
    // printTreeLevelWise(root);
    // cout<<countNodes(root)<<endl;
    // cout<<sumAllNodes(root)<<endl;
    // cout<<LargestDataNodeRecur(root)<<endl;
    // cout<<LargestDataNode(root)<<endl;
    // cout<<treeHeight(root)<<endl;
    // printAtLevelK(root, 1);
    // cout<<countLeaves(root)<<endl;
    // preOrder(root);
    // postOrder(root);
    // cout<<containsRecur(root, 10)<<endl;
    // cout<<contains(root, 10)<<endl;
    // cout<<NodesGreaterThanK(root, 40)<<endl;
    // cout<<NodesGreaterThanKRecur(root, 10)<<endl;

    // delete root;
//     return 0;
// }