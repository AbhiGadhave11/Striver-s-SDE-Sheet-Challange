vector<int> leftView(Node *root)
{
    vector<int> vobj;
    queue<Node*>q;
    if(!root)
     return vobj;
   q.push(root);
   while(q.empty()!=true)
   {
       int size = q.size();
       vobj.push_back(q.front()->data);
       while(size--)
       {
           Node* front = q.front();
           q.pop();
           if(front->left!=NULL)
           {
                q.push(front->left);
           }
           if(front->right!=NULL)
           {
                q.push(front->right);
           }
       }
   }
   return vobj;
}
