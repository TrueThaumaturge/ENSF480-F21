/* ENSF 480 - Lab 5 - Exercise C
    File: Subject.java
    Written By: Quentin J, Beau M
 */
public interface Subject {
    public void registerObserver(Observer o);
    public void remove(Observer o);
    public void notifyAllObservers();
}
