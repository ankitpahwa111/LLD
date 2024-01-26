class LockHelper{
    public synchronized void func1() {
        System.out.println("inside func1");
        try{
            Thread.sleep(5000);
            System.out.println("inside func1, after");
        } catch (InterruptedException ex){
            System.out.println(ex);
        }
    }
    public void func2() {
        System.out.println("inside func2");
        synchronized (this) {
            System.out.println("inside func2, inside lock");
        }
    }
    public void func3() {
        System.out.println("inside func3");
    }
}
public class locks {
    public static void main(String[] args) {
        LockHelper lockHelper = new LockHelper();
        Thread t1 = new Thread(() -> lockHelper.func1());
        Thread t2 = new Thread(() -> lockHelper.func2());
        Thread t3 = new Thread(() -> lockHelper.func3());
        t1.start();
        t2.start();
        t3.start();
    }
}
