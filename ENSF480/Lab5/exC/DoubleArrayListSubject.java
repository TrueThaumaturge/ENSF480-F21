/* ENSF 480 - Lab 5 - Exercise C
    File: DoubleArrayListSubject.java
    Written By: Quentin J, Beau M
 */
import java.util.ArrayList;

public class DoubleArrayListSubject implements Subject {
    private ArrayList<Double> data; // our data
    private ArrayList<Observer> observers; // observers of this subject

    // initializes data members to new ArrayLists<>
    public DoubleArrayListSubject() {
        data = new ArrayList<Double>();
        observers = new ArrayList<Observer>();
    }

    // adds a data point, notifies observers
    public void addData(double d) {
        this.data.add(d);
        notifyAllObservers();
    }

    // adds a data point, notifies observers
    public void setData(double d, int index) {
        data.set(index, d);
        notifyAllObservers();
    }

    // populates data with an array, notifies all observers
    public void populate(double [] arr) {
        data.clear();
        
        for (double d : arr) {
            data.add(d);
        }
        notifyAllObservers();
    }

    // adds an observer to the array
    public void registerObserver(Observer o) {
        observers.add(o);
        o.update(data);
    }

    // removes an observer from the array
    public void remove(Observer o) {
        observers.remove(o);
    }

    // notifies all observers
    public void notifyAllObservers() {
        for (Observer o : observers) {
            o.update(data);
        }
    }

    // observes all display methods
    public void display() {
        if (observers.isEmpty()) {
            System.err.println("Empty List ...");
        } else {
            for (Observer o : observers) {
                o.display();
            }
        }
    }
}
