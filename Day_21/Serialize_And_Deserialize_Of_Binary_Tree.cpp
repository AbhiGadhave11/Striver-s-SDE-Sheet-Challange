/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    private:
    void serializehelp(TreeNode *root,string &str)
    {
        if(root == NULL)
        {
            str += "NULL,";
            return;
        }
        str += to_string(root->val)+",";
        serializehelp(root->left,str);
        serializehelp(root->right,str);
    }
    int idx = 0;
    TreeNode* deserializehelp(vector<string>&arr)
    {
        if(idx>= arr.size() || arr[idx] == "NULL"){
            idx++;
            return NULL;
        }
        TreeNode *root = new TreeNode(stoi(arr[idx++]));
        root->left = deserializehelp(arr);
        root->right = deserializehelp(arr);
        return root;                              
    }
public:

    // Encodes a tree to a single string.
    
    string serialize(TreeNode* root) {
        string str = "";
        
        serializehelp(root,str);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string str) {
        vector<string>arr;
        int startIndex = 0, endIndex = 0;
        for (int i = 0; i <= str.size(); i++) 
        {

            // If we reached the end of the word or the end of the input.
            if (str[i] == ',' || i == str.size()) 
            {
                endIndex = i;
                string temp;
                temp.append(str, startIndex, endIndex - startIndex);
                arr.push_back(temp);
                startIndex = endIndex + 1;
            }
        }
        for(auto &it : arr)
        {
            cout<<it<<" ";
        }
        return deserializehelp(arr);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
