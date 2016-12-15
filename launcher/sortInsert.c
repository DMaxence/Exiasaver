void sortInsert(int arr[], int size)
{
   int i, j;

   for (i = 1; i < size; ++i) {

       int elem = arr[i];

       for (j = i; j > 0 && arr[j-1] > elem; j--)

           arr[j] = arr[j-1];

       arr[j] = elem;

   }
}