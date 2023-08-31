import java.util.ArrayList;
import java.util.List;

public class IphoneObservable implements ObservableInterface{
    int stockCount = 0;
    public List<ObserverInterface> observers = new ArrayList<>();

    @Override
    public void addObserver(ObserverInterface obj) {
        this.observers.add(obj);
    }

    @Override
    public void removeObserver(ObserverInterface obj) {
        this.observers.remove(obj);
    }

    @Override
    public void notifyObservers() {
        for(ObserverInterface obj : observers) {
            obj.update(this);
        }
    }

    public void addStock(int newStock) {
        this.stockCount += newStock;
        if(this.stockCount>0) notifyObservers();
    }

    public int getStockCount() {
        return this.stockCount;
    }
}
