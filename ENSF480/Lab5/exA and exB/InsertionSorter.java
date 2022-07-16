import java.util.ArrayList;

//insersion sort - inserts unsorted values from right into its correct position on the left
public class InsertionSorter<E extends Number & Comparable<E>> implements Sorter<E> {
    @Override
    public void sort(ArrayList<Item<E>> arr) {
        //iterates all but first value
        for(int i = 1; i < arr.size(); i++) {
            Item<E> key = arr.get(i); //key stores the current item
            int j = i-1; //the element before i

            //pushes key back until it finds its place
            while(j >= 0 && arr.get(j).getItem().compareTo(key.getItem()) > 0) {
                arr.set(j + 1, arr.get(j));
                j--;
            }
            arr.set(j + 1, key);
        }
    }
}
