/* ENSF 480 - Lab 5 - Exercise A and B
    File: SelectionSorter.java
    For: Lab 5 Exercise B
    Written By: Quentin J, Beau M
 */

import java.util.ArrayList;

//selection sort - selects the smallest element for the current slot and swaps, iterates left to right
public class SelectionSorter<E extends Number & Comparable<E>> implements Sorter<E> {
    @Override
    public void sort(ArrayList<Item<E>> arr) {
        //iterates all but the last value
        for(int i = 0; i < arr.size() - 1; i++) {
            int min = i; //index of smallest item
            //finds the smallest item past i
            for(int j = i + 1; j < arr.size(); j++) {
                if(arr.get(j).getItem().compareTo(arr.get(min).getItem()) < 0)
                    min = j;
            }
            //swaps smallest index and current index items
            Item<E> temp = arr.get(i);
            arr.set(i, arr.get(min));
            arr.set(min, temp);
        }
    }
}
