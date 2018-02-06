#ifndef __MCONFIG_H_
#define __MCONFIG_H_

#define bool int
#define true 1
#define false 0
#define NO_SIMI 1000
#define SIMI 1001
bool look_fwd(int flag);
bool in_follow_set(const char c);
void err_handle();
char* up_char(char *buf);

typedef struct TreeNode {
		bool terminal;	
    	char *type; 	 
    	
    	char *name;
    	union
 		{
			
			float f;
			char * s;
		}val;
    	struct TreeNode *child;	
    	struct TreeNode *sibling;	
 };
typedef struct TreeNode TreeNode;

TreeNode *CreatNode(char *name, char *context, char* type);
TreeNode *CreatNonTreeNode(char *name);
TreeNode *LastSibling(TreeNode *p);
void AddNode(TreeNode *parent, ...);
void AddSibling(TreeNode* s1, ...);
void TravelTree(TreeNode* root, int lev);
char *MyStrCpy(char *src);
void GetAttributes(TreeNode* s1, TreeNode* s2);

TreeNode *root;
TreeNode *guard;
bool wrong;
bool debug;
#define DEBUG if(debug)
#endif
