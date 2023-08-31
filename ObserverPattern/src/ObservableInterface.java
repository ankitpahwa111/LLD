
public interface ObservableInterface {
    void addObserver(ObserverInterface obj);
    void removeObserver(ObserverInterface obj);
    void notifyObservers();
}
