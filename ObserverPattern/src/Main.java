public class Main {
    public static void main(String[] args) {
        IphoneObservable iphoneObservable = new IphoneObservable();
        MobileObserver mobileObserver1 = new MobileObserver("9899429440", iphoneObservable);
        MobileObserver mobileObserver2 = new MobileObserver("9289962515", iphoneObservable);
        iphoneObservable.addObserver(mobileObserver1);
        iphoneObservable.addObserver(mobileObserver2);
        iphoneObservable.addStock(10);
        iphoneObservable.removeObserver(mobileObserver2);
        iphoneObservable.addStock(-10);
        iphoneObservable.addStock(10);
    }
}