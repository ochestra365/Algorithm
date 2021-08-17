//힙은 최솟값이나 최댓값을 빠르게 찾아내기 위해 완전 이진 트리를 기반으로 하는 트리이다. 부모노드가 자식노드보다 큰 힙이다.
//별도의 추가적인 배열이 필요하지 않으므로 메모리 측면에서 몹시 효율적이다.
/*#include <stdio.h>
int number = 9;
int heap[9] = { 7,6,5,8,3,5,9,1,6 };

int main(void)
{
	for (int i = 1; i < number; i++) {
		int c = i;
		do {
			int root = (c - 1) / 2;
			if (heap[root] < heap[c]) {
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			c = root;
		} while (c != 0);
	}
	for (int i = number - 1; i >= 0; i--) {
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		int root = 0;
		int c = 1;
		do {
			c = 2 * root + 1;
			if (c < i - 1 && heap[c] < heap[c + 1]) {
				c++;
			}
			if (c < i && heap[root] < heap[c]) {
				temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			root = c;
		} while (c < i);
		for (int i = 0; i < number; i++)printf("%d\t", heap[i]);
	}
	return 0;
}*/