#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


vector <int> bottomView(Node *root);

Node* buildTree(string str)
{
   
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

   
    Node* root = newNode(stoi(ip[0]));

    
    queue<Node*> queue;
    queue.push(root);

    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        Node* currNode = queue.front();
        queue.pop();
        string currVal = ip[i];

        if(currVal != "N") {

            currNode->left = newNode(stoi(currVal));

            queue.push(currNode->left);
        }

        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        if(currVal != "N") {

            currNode->right = newNode(stoi(currVal));

            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> r;
        map<int,int> m;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(q.empty()==false){
            auto p=q.front();
            int hd=p.second;
            Node *curr=p.first;
            m[hd]=curr->data;
            q.pop();
            if(curr->left!=NULL)
            q.push({curr->left,hd-1});
            if(curr->right!=NULL)
            q.push({curr->right,hd+1});
        }
        for(auto it: m)
        r.push_back(it.second);
        return r;
    }
};


int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.bottomView(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
