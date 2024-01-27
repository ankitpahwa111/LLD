import java.util.concurrent.Semaphore;

class SharedResource{
    Semaphore lock = new Semaphore(2);
    void criticalSection() {
        try {
            lock.acquire();
            System.out.println("Lock acquired by thread: " + Thread.currentThread().getName());
            Thread.sleep(3000);
        }catch(Exception e){}
        finally {
            lock.release();
            System.out.println("Lock released by thread: " + Thread.currentThread().getName());
        }
    }
}

public class SemaphoreLock {
    public static void main(String[] args) {
        SharedResource sharedResource = new SharedResource();
        new Thread(() -> sharedResource.criticalSection()).start();
        new Thread(() -> sharedResource.criticalSection()).start();
        new Thread(() -> sharedResource.criticalSection()).start();
        new Thread(() -> sharedResource.criticalSection()).start();
    }
}
