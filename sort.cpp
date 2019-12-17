#include <iostream>
#include <vector>

// 输出数组
template <class T>
void outputArray(std::vector<T>& arr)
{
	for (int i = 0; i < arr.size(); ++i) {
		std::cout << arr.at(i) << " ";
	}
	std::cout << std::endl;
}

/*
	冒泡排序，稳定排序，O{n} ~ O(n^2)
	从末尾开始，与上个元素比较并交换
	每轮都将最小的元素换到首位
*/
template <class T>
void bubbleSort(std::vector<T> &arr)
{
	for (int i = 0; i < arr.size(); ++i) {
		for (int j = arr.size() - 1; j > i; --j) {
			if (arr.at(j) < arr.at(j - 1)) {
				std::swap(arr.at(j), arr.at(j - 1));
			}
		}
	}
}

/*
	选择排序，稳定排序，O{n^2} ~ O{n^2}
	从首位开始，循环一次找出一个比首位小的值交换
*/
template <class T>
void selectionSort(std::vector<T>& arr)
{
	for (int i = 0; i < arr.size(); ++i) {
		int min = i;

		for (int j = i + 1; j < arr.size(); ++j) {
			if (arr.at(j) < arr.at(min)) {
				min = j;
			}
		}

		std::swap(arr.at(i), arr.at(min));
	}
}

/*
	插入排序，稳定排序，O(N^2)
*/
template <class T>
void insertSort(std::vector<T>& arr)
{
	int j, k;

	for (int i = 1; i < arr.size(); ++i) {

		// 为arr[i]在前面的a[0...i - 1]有序区间中找一个合适的位置
		for (j = i - 1; j >= 0; --j)
			if (arr[j] < arr[i])
				break;

		// 如找到了一个合适的位置
		if (j != i - 1) {
			// 将比a[i]大的数据向后移
			int temp = arr[i];
			for (k = i - 1; k > j; k--) {
				arr[k + 1] = arr[k];
			}
			//将a[i]放到正确位置上
			arr[k + 1] = temp;
		}
	}
}

int main(int argc, char* arg[])
{
	std::vector<int> array = { 9, 2, 3, 8, 5, 6, 88, 12, 1 };

	insertSort(array);
	outputArray(array);

	system("pause");
	return 0;
}
