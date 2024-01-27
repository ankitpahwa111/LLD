import java.util.concurrent.locks.ReentrantLock;

class ReentrantLockHelper{
    void producEvent(ReentrantLock lock) {
        lock.lock();
        System.out.println("Inside produce: " + Thread.currentThread().getName());
        try{
            Thread.sleep(2000);
            System.out.println("Lock released by: " + Thread.currentThread().getName());
            lock.unlock();
        } catch (Exception e) {}
    }
}

public class ReentrantLocks {
    public static void main(String[] args) {
        // Reentrant lock does not depend on object, an independent object is passed
        ReentrantLock lock  = new ReentrantLock();
        ReentrantLockHelper lockHelper = new ReentrantLockHelper();
        new Thread(()->lockHelper.producEvent(lock), "Thread1").start();
        new Thread(()->lockHelper.producEvent(lock), "Thread2").start();
    }
}
