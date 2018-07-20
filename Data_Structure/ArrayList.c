#include<stdio.h>
#define MAX 100

typedef struct List {
	int list[MAX];
	int curposition;
}AL;

void init(AL*L);
void Add(AL*L,int value);
void Delete(AL*L, int value);
int Search(AL*L, int value);

int main() {
	AL List;
	init(&List);
	int value, num;
	while (1) {
		printf("1.Add\n2.Delete\n3.Search\n4.Show Data\n5.Exit\n");
		scanf("%d", &num);
		printf("------------------------------------------------------------\n");

		switch (num) {
		case 1:
			printf("Input Data : \n");
			scanf("%d", &value);
			printf("------------------------------------------------------------\n");
			Add(&List, value);
			break;

		case 2:
			printf("Input Data : \n");
			scanf("%d", &value);
			printf("------------------------------------------------------------\n");
			Delete(&List, value);
			break;

		case 3:
			printf("Input Data : \n");
			scanf("%d", &value);
			printf("------------------------------------------------------------\n");
			while (1) {
				int ret;
				ret = Search(&List, value);
				if (ret != -1) {
					printf("Data index : %d\n", ret);
					printf("------------------------------------------------------------\n");
					break;
				}
				else {
					printf("No search Data\n");
					printf("------------------------------------------------------------\n");
					break;
				}
			}
			break;

		case 4:
			for (int j = 0; j < List.curposition; j++) {
				printf("%d", List.list[j]); //list¿¡ Á¢±Ù
				printf(" ");
			}
			printf("\n");
			break;

		case 5:
			exit(0);
			break;
		
		default:
			printf("Put a number from 1 to 5\n"); 
			printf("------------------------------------------------------------\n");

		}
	}
	return 0;
}
void init(AL * L)
{
	L->curposition = 0;
}

void Add(AL *L, int value) {
	if (L->curposition == 0) {
		L->list[0] = value;
	}
	else {
		if (L->list[L->curposition -1] < value) {
			L->list[L->curposition] = value;
		}
		else if (L->list[0] > value) {
			for (int j = L->curposition; j >0; j--) {
				L->list[j] = L->list[j-1];
			}
			L->list[0] = value;
		}
		else {
			for (int i = L->curposition -1; i >= 0; i--) {
				if (L->list[i] == value) {
					printf("That Data was existed\n");
					printf("------------------------------------------------------------\n");
					L->curposition--;
					break;
				}
				else if (L->list[i] > value && L->list[i - 1] < value) {
					for (int k = L->curposition -1; k >= i; k--) {
						L->list[k + 1] = L->list[k];
						}
					L->list[i] = value;
					break;
				}

			}
		}
	}
	L->curposition ++;
}

void Delete(AL*L, int value) {
	int boolist = 0;
	for (int i = 0; i < L->curposition; i++) {
		if (L->list[i] == value) {
			for (int j = i; j < L->curposition; j++) {
				L->list[j] = L->list[j + 1];
			}
			boolist = 1;
			L->curposition--;
		}
	}
	if (boolist == 0) {
		printf("There is no data which you want to delete\n");
	}
}
	
int Search(AL*L, int value) {
	int low = 0, high = L->curposition - 1, mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (L->list[mid] > value) 
			high = mid - 1;
		else if (L->list[mid] < value) 
			low = mid + 1;
		else return mid;
	}
	return - 1;
}