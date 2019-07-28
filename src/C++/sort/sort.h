

class sort
{
    private:
        /* data */
        static void swap(int* arr, int i, int j)
        {
            arr[i]=arr[i] + arr[j];
            arr[j]=arr[i] - arr[j];
            arr[i]=arr[i] - arr[j];
        }

    public:
        sort(/* args */);
        ~sort();
        static void insert_sort(int* arr, int length);
        static void shell_sort(int* arr, int length);
        static void choose_sort(int* arr, int length);
        static void heap_sort(int* arr, int length);
        static void bubble_sort(int* arr, int length);
        static void quit_sort(int* arr, int length);
        static void quit_sort_no(int* arr, int length);//非递归版
        static void merge_sort(int* arr, int length);
        static void merge_sort_no(int* arr, int length);//非递归版
    };

sort::sort(/* args */)
{
}

sort::~sort()
{
}

void sort::bubble_sort(int* arr, int length){

}

void sort::insert_sort(int* arr, int length){
    for(int i=1;i<length;i++){
        int temp=arr[i];
        int j=i;
        for(;j>0 && temp<arr[j-1];--j){
            arr[j] = arr[j-1];
        }
        arr[j] = temp;
    }
}

void sort::shell_sort(int* arr, int length){
    int gap=length/2;
    while(gap>0){
        for(int i=gap;i<length;++i){
            int temp = arr[i];
            int j = i;
            for(;j>0 && temp < arr[j-gap];j -= gap){
                arr[j] = arr[j-gap];
            }
        }
        gap /= 2;
    }
}

void sort::choose_sort(int* arr, int length){
    for(int i=length-1;i>0;i--){
        int max = i;
        for(int j=0;j<=i;++i){
            if(arr[j] > arr[max])
                max = j;
        }
        swap(arr, max, i);
    }
}
void sort::heap_sort(int* arr, int length){

}

void sort::quit_sort(int* arr, int length){

}
void sort::merge_sort(int* arr, int length){

}

void sort::quit_sort_no(int* arr, int length){

}

void sort::merge_sort_no(int* arr, int length){

}