#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>


#define ALPHA_SIZE (26)
#define CHAR_TO_INDEX(x) ((int)x-(int)'a')

struct trie{

	struct trie *children[ALPHA_SIZE];
	bool isLeaf;
};

struct trie * getNode()
{
	struct trie * n = (struct trie *)malloc(sizeof(struct trie));
	int i;
	for (i = 0; i < ALPHA_SIZE; i++)
		n->children[i] = NULL;
	n->isLeaf = false;
	return n;
}

int strlen(char *arr)
{
	int i = 0;
	while (arr[i]!=NULL){
		i++;
	}
	return i;
}

void insert(struct trie *root, char *key)
{
	int i;
	int l = strlen(key);
	struct trie *traverse = root;
	for (i = 0; i < l; i++)
	{
		int c = CHAR_TO_INDEX(key[i]);
		if (!traverse->children[c])  // If the node is not present.
			traverse->children[c] = getNode();
		traverse = traverse->children[c];
	}
	traverse->isLeaf = true;
}

bool search(struct trie *root,char *key)
{
	int level;
	int length = strlen(key);
	int index;
	struct trie *traverse = root;

	for (level = 0; level < length; level++)
	{
		index = CHAR_TO_INDEX(key[level]);

		if (!traverse->children[index])
			return false;

		traverse = traverse->children[index];
	}

	return (traverse != NULL && traverse->isLeaf);
}

int main()
{
	struct trie *root = getNode();
	char arr[6] = { 'h', 'e', 'l', 'l', 'o' ,'\0'};
	char arr1[7] = { 'h', 'e', 'l', 'l', 'o', 'o', '\0' };
	insert(root, arr);
	if (search(root, arr1))
		printf("Working");
	else
		printf("Not working");
	return 0;
}
