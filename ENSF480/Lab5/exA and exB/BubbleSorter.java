import java.util.ArrayList;

//bubble sort - iterates, comparing with the next element and swapping until sorted
public class BubbleSorter<E extends Number & Comparable<E>> implements Sorter<E> {
    @Override
    public void sort(ArrayList<Item<E>> arr) {
        //iterates each element except the last
        for(int i = 0; i < arr.size() - 1; i++){
            //iterates to the end for each i - nested loop
            for(int j = 0; j < arr.size() - i - 1; j++) {
                //if the left element is bigger than the right, swap them
                if(arr.get(j).getItem().compareTo(arr.get(j + 1).getItem()) > 0) {
                    Item<E> temp = arr.get(j);
                    arr.set(j, arr.get(j + 1));
                    arr.set(j + 1, temp);
                }
            }
        }
    }
}
