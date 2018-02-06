#ifndef __HASH_H_
#define __HASH_H_

#include "list.h"
#include "mconfig.h"
#include <stdio.h>
#include <assert.h>
#define TableSize 16384
struct list_head FuncListHead;

typedef struct IdNode
{
	char *name;
	char *type;
	char *reg;
	int father;
	bool init;	
	union
 		{
			float f;	
		}val;
	struct list_head InSList;	
	struct list_head HashList;	
};
typedef struct IdNode IdNode;
struct list_head IdTable[TableSize];

typedef struct FuncNode
{
	char *name;
	char *type;
	struct list_head ScopeListHead;
	struct list_head FuncList;
};
typedef struct FuncNode FuncNode;

typedef struct ScopeNode
{
	int ID;
	struct list_head ScopeList;		
	struct list_head ScopeNodeList;	
};
typedef struct ScopeNode ScopeNode;


void init();	
unsigned int hash_pjw(char* name);	
void AddIdNodeList(IdNode *node);	
void AddScopeNode();	
void DelScope();		
bool ReDefine(IdNode *node);	
IdNode* CheckDefine(char *name);	
void analysis(TreeNode *root);		
void analysisDefSeq(TreeNode *root);
void analysisParam(TreeNode *root);
void analysisDef(TreeNode *root);
void analysisFun(TreeNode *root);
TreeNode* analysisExp(TreeNode *root);
int CalcuNode(TreeNode *root);		
bool CheckInit(char *name);		
void InitIdNode(char *name, float i);	
FuncNode *GetFirstFunNode();
struct list_head *GetScopeHead();
void analysisReturn(TreeNode *root);

int ID;

char *Rstack[9];
char *ParamRstack[4];
int RstackTop; 
void GetReg(char **reg);
void FreeReg(char **reg);
void GenFuncCode(TreeNode *root);
int ParamRegFlag;

#endif
