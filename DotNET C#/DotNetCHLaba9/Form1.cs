using System;
using System.Windows.Forms;

namespace SortingAlgorithmComparison
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private void btnCompare_Click(object sender, EventArgs e)
        {
            const int arraySize = 500000;
            const int minValue = 0;
            const int maxValue = 1000000;

            int[] randomArray = GenerateRandomArray(arraySize, minValue, maxValue);

            double quickSortTime = MeasureSortTime(() => QuickSort((int[])randomArray.Clone()));
            lblQuickSortTime.Text = $"Quick Sort: {quickSortTime} ms";

            double bubbleSortTime = MeasureSortTime(() => BubbleSort((int[])randomArray.Clone()));
            lblBubbleSortTime.Text = $"Bubble Sort: {bubbleSortTime} ms";

            double insertionSortTime = MeasureSortTime(() => InsertionSort((int[])randomArray.Clone()));
            lblInsertionSortTime.Text = $"Insertion Sort: {insertionSortTime} ms";

            double selectionSortTime = MeasureSortTime(() => SelectionSort((int[])randomArray.Clone()));
            lblSelectionSortTime.Text = $"Selection Sort: {selectionSortTime} ms";

            double shellSortTime = MeasureSortTime(() => ShellSort((int[])randomArray.Clone()));
            lblShellSortTime.Text = $"Shell Sort: {shellSortTime} ms";
        }

        private int[] GenerateRandomArray(int size, int minValue, int maxValue)
        {
            Random random = new Random();
            int[] array = new int[size];
            for (int i = 0; i < size; i++)
            {
                array[i] = random.Next(minValue, maxValue);
            }
            return array;
        }

        private void QuickSort(int[] array)
        {
            QuickSort(array, 0, array.Length - 1);
        }

        private void QuickSort(int[] array, int left, int right)
        {
            if (left < right)
            {
                int pivotIndex = Partition(array, left, right);
                QuickSort(array, left, pivotIndex - 1);
                QuickSort(array, pivotIndex + 1, right);
            }
        }

        private int Partition(int[] array, int left, int right)
        {
            int pivot = array[right];
            int i = left - 1;

            for (int j = left; j < right; j++)
            {
                if (array[j] < pivot)
                {
                    i++;
                    Swap(array, i, j);
                }
            }

            Swap(array, i + 1, right);
            return i + 1;
        }

        private void Swap(int[] array, int i, int j)
        {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }

        private void BubbleSort(int[] array)
        {
            int n = array.Length;
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (array[j] > array[j + 1])
                    {
                        int temp = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = temp;
                    }
                }
            }
        }

        private void InsertionSort(int[] array)
        {
            int n = array.Length;
            for (int i = 1; i < n; i++)
            {
                int key = array[i];
                int j = i - 1;

                while (j >= 0 && array[j] > key)
                {
                    array[j + 1] = array[j];
                    j = j - 1;
                }

                array[j + 1] = key;
            }
        }

        private void SelectionSort(int[] array)
        {
            int n = array.Length;
            for (int i = 0; i < n - 1; i++)
            {
                int minIndex = i;

                for (int j = i + 1; j < n; j++)
                {
                    if (array[j] < array[minIndex])
                    {
                        minIndex = j;
                    }
                }
            }

            int temp = array[minIndex];
            array[minIndex] = array[i];
            array[i] = temp;
        }
    }

    private void ShellSort(int[] array)
    {
        int n = array.Length;
        for (int gap = n / 2; gap > 0; gap /= 2)
        {
            for (int i = gap; i < n; i++)
            {
                int temp = array[i];
                int j;
                for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
                {
                    array[j] = array[j - gap];
                }
                array[j] = temp;
            }
        }
    }

    private double MeasureSortTime(Action sortingMethod)
    {
        var watch = System.Diagnostics.Stopwatch.StartNew();
        sortingMethod.Invoke();
        watch.Stop();
        return watch.Elapsed.TotalMilliseconds;
    }
}