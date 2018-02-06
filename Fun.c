#include "mconfig.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>


TreeNode* CreatNode(char *name, char *context, char* type)
{
  if(debug)
    printf("CreateNode %s\n",context);
  TreeNode *tmp = (TreeNode *) malloc(sizeof(TreeNode));
  tmp->terminal = 1;
  tmp->sibling = NULL;
  tmp->child = NULL;
  tmp->name = NULL;
  tmp->type=NULL;
  tmp->name = MyStrCpy(name);
  
  tmp->type = MyStrCpy(type);
  assert(strcmp(tmp->name,name)==0);
  

  if(strcmp(type,"INT")==0)
    tmp->val.f = atoi(context);
  else  if(strcmp(type,"FLOAT")==0)
    tmp->val.f = atof(context);
  else  if(context != NULL)
    tmp->val.s = MyStrCpy(context);

  return tmp;
}

TreeNode *CreatNonTreeNode(char *name)
{
    if(debug)
      printf("CreateNonTreeNode %s\n",name);
    TreeNode *tmp = (TreeNode *) malloc(sizeof(TreeNode));
    if(tmp == NULL)
      printf("err in malloc\n");
    tmp->terminal = 0;
    tmp->sibling = NULL;
    tmp->child = NULL;
    tmp->name = MyStrCpy(name);
    DEBUG printf("name is %s\n", tmp->name);
    assert(strcmp(tmp->name,name)==0);
    return tmp;
}

TreeNode *LastSibling(TreeNode *p)
{
      TreeNode *q = p;
      while(q->sibling!=NULL)
            q = q->sibling;
      return q;
}

void AddNode(TreeNode *parent, ...)
{
      if(debug)
        printf("in AddNode parent is %s\t",parent->name);
      va_list VarList;
      va_start(VarList, parent);
      TreeNode *tmp = va_arg(VarList,TreeNode*);
      while(tmp == guard)
            tmp = va_arg(VarList,TreeNode*);
      if(!parent->child)
      {
            parent->child = tmp;
            tmp = va_arg(VarList,TreeNode*);
      }
      TreeNode *p = parent->child;
      if(debug)
        printf("child is %s\t",p->name);
      while(tmp != NULL)
      {
              if(tmp != guard)
              {
                 TreeNode *q = LastSibling(p);
                 assert(q->sibling == NULL);
                 q->sibling = tmp;
                 p = tmp;
                 if(debug)
                    printf("sibling is %s\t",q->sibling->name);
           
              }
              tmp = va_arg(VarList,TreeNode*);
              
      }
      va_end(VarList);
      DEBUG printf("\n");
}

void AddSibling(TreeNode* s1, ...)
{
      if(debug)
        printf("in AddSibling s1 is %s\t",s1->name);
      va_list VarList;
      va_start(VarList, s1); 
      TreeNode *tmp = va_arg(VarList,TreeNode*);
      TreeNode *p = s1;
      while(tmp)
      {
             if(tmp != guard)
              {
                 TreeNode *q = LastSibling(p);
                 assert(q->sibling == NULL);
                 q->sibling = tmp;
                 p = tmp;
                 if(debug)
                    printf("sibling is %s\t",q->sibling->name);
              }
              tmp = va_arg(VarList,TreeNode*);
             
      }
      DEBUG printf("\n");
      va_end(VarList);
} 

void GetAttributes(TreeNode* s1, TreeNode* s2)
{
    assert(strcmp(s1->type,"INT")||strcmp(s1->type,"FLOAT"));
    s2->val.s = MyStrCpy(s1->type);
}

void TravelTree(TreeNode* root, int lev)
{
      if(wrong) return;
      TreeNode* p = root;
      while(p != NULL)
      {     
		  
            int count = lev;
            while(count--)
                  printf("  ");
            printf("%s\n",p->name);
            if(p->child);
                  TravelTree(p->child,lev+1);
            p = p->sibling;
      }
}

char* MyStrCpy(char *src)
{
    assert(src != NULL);
    DEBUG printf("in MyStrCpy src is %s\n",src);
    char* dst = malloc((strlen(src)+1)*sizeof(char));
    return strcpy(dst,src);
   
}





