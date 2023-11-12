#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int IsLeafNode(int num, int relation[], int len);

void ChildSearch(int targetNode,int relation[], int len, int result[]);

void Append(int appendArr, int arr[], int len);

int main() {
	int numNode = 0;
	int relation[50] = { 0, };
	int deleteNode = 0;
	scanf("%d", &numNode);

	for (int index = 0; index < numNode; index++) {
		scanf("%d", &relation[index]);
	}

	scanf("%d", &deleteNode);

	int child[50] = { 0, };
	ChildSearch(deleteNode, relation, numNode, child);
	relation[deleteNode] = deleteNode;

	int count = 0;
	for (int index = 0; index < numNode; index++) {	
		if (IsLeafNode(index, relation, numNode) == 1) {
			count++;
		}
	}
	
	printf("%d", count);
	return 0;
}


int IsLeafNode(int num, int relation[], int len) {
	for (int index = 0; index < len; index++) {
		if (num == relation[index]) {
			return 0; // 자식이 있으면 0
		}
	}
	return 1; // 자식이 없으면 1
}


void ChildSearch(int targetNode, int relation[], int len, int result[]) {
	// * 부모 , 자식 조부모 관계까지 생각하기 *
	for (int index = 0; index < len; index++) {
		if (relation[index] == targetNode) {
			Append(index, result, len);
			ChildSearch(index, relation, len, result);
			relation[index] = index;
		}
	}
}


void Append(int appendArr, int arr[], int len) {
	for (int index = len - 1; index > -1; index--) {
		arr[index + 1] = arr[index];
	}
	arr[0] = appendArr;
}
