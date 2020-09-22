#include <stdio.h>
#include <stdarg.h>

#define QUEUE_MAX_SIZE 100

typedef struct Queue {
	int qu[QUEUE_MAX_SIZE];
	int tail;
} Qu;

void initQueue(Qu* queue, int defElementsNumber, ...) {
	queue->tail = defElementsNumber;
	va_list factor;
	va_start(factor, defElementsNumber);  
	for (int i = 0; i < defElementsNumber ; i++) {
		queue->qu[i] = va_arg(factor, int);
	}
	va_end(factor);
	return;
}

void addElementQueue(Qu* queue, int value) {
	if (queue->tail == QUEUE_MAX_SIZE) {
		printf("Queue is overflowed\n");
		return;
	}
	queue->qu[queue->tail] = value;
	queue->tail++;
}

int isEmpty(Qu* queue) {
	if (queue->tail) {
		return 0;
	}
	else {
		return 1;
	}

}

int deleteElementQueue(Qu* queue) {
	int deletedElement = queue->qu[0];

	for (int i = 0; i <= queue->tail; i++) {
		queue->qu[i] = queue->qu[i + 1];
	}

	queue->tail--;
	return deletedElement;
}

void showQueue(Qu* queue) {
		printf("Queue = ");
	for (int i = 0; i < queue->tail; i++) {
		printf("%d[%d] ", queue->qu[i], i);
	}
	printf("\n");
}

void changeElementQueue(Qu* queue, int index, int value) {
	if (index < queue->tail) {
		printf("Empty slot");
	}
	queue->qu[index] = value;
}

int main(void) {
	Qu q;
	initQueue(&q, 0);
	int menuNum, value, test;
	for (;;) {
		printf("\033[2J");
		printf("1. Add element\n2. Delete element\n3. Show queue\n4. Exit\n\nEnter: ");
		if (scanf("%d", &menuNum) != 1) {
			while (getchar() != '\n');
			continue;
		}
		switch (menuNum) {
		case 1:
			printf("\033[2J");
			printf("Add value: ");
			if (scanf("%d", &value) != 1) {
				while (getchar() != '\n');
				printf("Wrong value\nPress enter");
				getchar();

			} else {
				addElementQueue(&q, value);
			}
			break;
		case 2:
			printf("\033[2J");
			if (isEmpty(&q)) {
				printf("Queue is empty\nPress enter");
				while (getchar() != '\n');
				getchar();
				break;
			}
			printf("Deleted element = %d\nPress enter", deleteElementQueue(&q));
			while (getchar() != '\n');
			getchar();
			break;
		case 3:
			printf("\033[2J");
			showQueue(&q);
			printf("\nPress enter");
			while (getchar() != '\n');
			getchar();
			break;
		case 4:
			return 0;
		default:
			while (getchar() != '\n');
			break;
		}
	}
	return 0;
}