#include "mconfig.h"
#include "hash.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{   int m=5;
	debug = 0;
	int OpenFlag = 1;
	DEBUG printf("before check debug\n");
	if( argc>1 && strcmp( argv[1], "-debug")==0)
	{
		debug = 1;
		OpenFlag = 2;
	}
	FILE *f;
	if(argc == 1 || (argc == 2 && debug) )
	{
		DEBUG printf("before CreatNonTreeNode guard\n");
		guard = CreatNonTreeNode("guard");
		f = fopen("./vlez.txt","r");
		root = NULL;
		assert(f!=NULL);
		printf("Leksicka analiza\n\n\n");
		yyrestart(f);
		printf("Sintaksna i semanticka analiza\n\n\n");
		m=yyparse();
		if(m==0){printf("Uspeshno parsiranje\n\n\n");}
		
		printf("Masinski kod:\n\n\n");
		init();
		analysis(root);
		fclose(f);
	}
	return 0;
	
};
