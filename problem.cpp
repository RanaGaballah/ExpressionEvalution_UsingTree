#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    string value;
    Node* left=NULL;
    Node*right=NULL;
    Node(string exp)
    {
        value=exp;
    }

};
int toIntger(string exp)
{
    int x=0;
    if(exp[0]!='-')
    {
        for (int i=0; i<exp.length(); i++)
        {
            x = x*10 + (int(exp[i])-48);
        }
    }
    else
    {
      for (int i=1; i<exp.length(); i++)
      {
         x = x*10 + (int(exp[i])-48);
      }
      x = x*-1;
    }
    return x;
}
int evaluationPreOrder(Node* root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return toIntger(root->value);
    // Evaluate left subtree
    int left_value = evaluationPreOrder(root->left);
    // Evaluate right subtree
    int right_value = evaluationPreOrder(root->right);
    if (root->value=="*")
    {
       return left_value*right_value;
    }
    else if (root->value=="/")
    {
        return left_value/right_value;
    }
    else if (root->value=="+")
    {
        return left_value+right_value;
    }
    else if(root->value=="-")
    {
        return left_value-right_value;
    }
}
int main()
{
    // create a syntax tree
    //first test case
    Node *root = new Node("+");
    root->left = new Node("3");
    root->right= new Node("*");
    root->right->left = new Node("4");
    root->right->right = new Node("/");
    root->right->right->left = new Node("8");
    root->right->right->right = new Node("2");
    cout << "the result of [+ 3 * 4 / 8 2] is : " <<evaluationPreOrder(root) << endl;
    delete(root);
    //////////////////////////////////////////////////////////
    //second test case
    root = new Node("+");
    root->left = new Node("*");
    root->right = new Node("4");
    root->left->left = new Node("3");
    root->left->right = new Node("/");
    root->left->right->left = new Node("10");
    root->left->right->right = new Node("20");
    cout << "the result of [+ * 3 / 10 20 4] is : " <<evaluationPreOrder(root) << endl;
    ///////////////////////////////////////////////////////////
    //third test case
    root = new Node("-");
    root->left = new Node("*");
    root->left->left = new Node("62");
    root->left->right = new Node("9");
    root->right = new Node("+");
    root->right->left = new Node("3");
    root->right->right = new Node("/");
    root->right->right->left = new Node("60");
    root->right->right->right = new Node("80");
    cout << "the result of [- * 62 9 + 3 / 60 80] is : " <<evaluationPreOrder(root) << endl;
    //////////////////////////////////////////////////////////
    //fourth test case
    root = new Node("-");
    root->left = new Node("7");
    root->right= new Node("30");
    root->left->left = new Node("+");
    root->left->right = new Node("6");
    cout << "the result of [- 7 + 6 30 ] is : " <<evaluationPreOrder(root) << endl;
    ///////////////////////////////////////////////////////////
    //fifth test case
    root = new Node("+");
    root->left = new Node("3");
    root->right= new Node("10");
    root->left->left = new Node("*");
    root->left->right = new Node("4");
    cout << "the result of [+ 3 * 4 10 ] is : " <<evaluationPreOrder(root) << endl;
}
