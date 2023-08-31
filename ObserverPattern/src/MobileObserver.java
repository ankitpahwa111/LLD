public class MobileObserver implements ObserverInterface{

    ObservableInterface observableInterface;
    String phoneNumber;

    MobileObserver(String phoneNumber, ObservableInterface observableInterface) {
        this.phoneNumber = phoneNumber;
        this.observableInterface = observableInterface;
    }
    @Override
    public void update(ObservableInterface obj) {
        this.sendSMS();
    }

    private void sendSMS() {
        System.out.println("Stock message sent to " + phoneNumber);
    }
}
